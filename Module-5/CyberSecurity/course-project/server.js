import express from "express";
import mongoose from "mongoose";
import dotenv from "dotenv";
import bodyParser from "body-parser";
import path from 'path';


dotenv.config();

const app = express();
app.use(bodyParser.urlencoded({ extended: true }));
app.use(express.static('public'));

const port = process.env.PORT || 3000;
const mongoURI = process.env.MONGO_URI;

// Define a MongoDB schema and model
const userSchema = new mongoose.Schema({
  ip: String,
  visitCount: { type: Number, default: 0 }, // Individual visit count with default value 0
  userAgent: String,
  totalVisitCount: { type: Number, default: 0 }, // Total visit count with default value 0
  trust: { type: Number, default: 0 }, // Trust with default value 0
});

const UserIPCollection = mongoose.model("UserIPCollection", userSchema);


app.use(async (req, res, next) => {
  const forwardedFor = req.headers["x-forwarded-for"];
  const ips = forwardedFor ? forwardedFor.split(",") : [];
  const userIP = ips[0] || req.socket.remoteAddress;
  const userAgent = req.headers["user-agent"]; // Capture the User-Agent

  try {
    let user;

    if (userAgent) {
      // Find a user by User-Agent
      user = await UserIPCollection.findOne({ userAgent });
    } else {
      // If no User-Agent is provided, use the user's IP address
      user = await UserIPCollection.findOne({ ip: userIP });
    }

    if (user) {

      if(user.trust == 2) {
        return res.send("You are banned permanently");
      }

      if (user.visitCount > 20 && user.trust != 1) {
        // Send a response and return to prevent further execution
        return res.send("You are banned");
      }

      user.visitCount++;

      // Update the User-Agent, if available
      if (userAgent) {
        user.userAgent = userAgent;
      }

      await user.save();
    } else {
      user = new UserIPCollection({ ip: userIP, userAgent, visitCount: 1 });
      await user.save();
    }

    // Update totalVisitCount for all users
    await UserIPCollection.updateMany({}, { $inc: { totalVisitCount: 1 } });

    next();
  } catch (error) {
    console.error("Error tracking user visits:", error);
    // Continue with the next middleware even if there's an error
    next();
  }
});

// Route to display user information and handle redirection
app.get("/", async (req, res) => {
  const forwardedFor = req.headers["x-forwarded-for"];
  const userIP = forwardedFor
    ? forwardedFor.split(",")[0]
    : req.connection.remoteAddress;

  const totalVisits = await UserIPCollection.aggregate([
    {
      $group: {
        _id: null,
        totalVisits: { $sum: "$visitCount" },
      },
    },
  ]);

  // Find a user by IP address
  const user = await UserIPCollection.findOne({ ip: userIP });

  if (user && user.trust != 1) {
    if (user.visitCount > 20) {
      return res.send("You are banned"); // Banning users with individual visit count > 20

    }

  if (totalVisits.length > 0 && totalVisits[0].totalVisits > 15 && user.trust != 3) {
  // Reset individual visit counts to 0 for all users
  await UserIPCollection.updateMany({}, { $set: { visitCount: 0 } });

  // Wait for 5 seconds
  await new Promise(resolve => setTimeout(resolve, 5000));

  // Fetch users with the same IP address and sum their individual visit counts
  const usersWithSameIP = await UserIPCollection.find({ ip: userIP });
  const finalAdd = usersWithSameIP.reduce((sum, user) => sum + user.visitCount, 0);

  // If the sum of individual visit counts from all user agents >= 5, update trust level to 2
  if (finalAdd >= 5) {
    // Update trust level for all users with the same IP address
    await UserIPCollection.updateMany({ ip: userIP }, { $set: { trust: 2 } });
    return res.send("You are banned permanently.");
  } else {
    // Redirecting all users if total visit count > 1000
    return res.redirect("/recap");
  }
}

    res.json({
      status: "User Info",
      ip: user.ip,
      userAgent: user.userAgent,
      visitCount: user.visitCount,
      totalVisitCount: totalVisits.length > 0 ? totalVisits[0].totalVisits : 0,
    });
  } else {
    // Handle the case where the user is not found
    res.json({
      status: "User Info",
      ip: userIP, // Use the user's IP directly
      userAgent: null, // User-Agent is not available
      visitCount: 0, // No visits recorded for this user
      totalVisitCount: totalVisits.length > 0 ? totalVisits[0].totalVisits : 0,
    });
  }
});

// Route handler for /protection
const getRandomNumber = () => Math.floor(Math.random() * 10) + 1;

app.get('/recap', (req, res) => {
  const number1 = getRandomNumber();
  const number2 = getRandomNumber();

 const formHTML = `
    <!DOCTYPE html>
    <html lang="en">
    <head>
      <meta charset="UTF-8">
      <meta name="viewport" content="width=device-width, initial-scale=1.0">
      <title>Verify whether you are a human.</title>
      <style>
        body {
          font-family: Arial, sans-serif;
          text-align: center;
          margin: 20px;
        }
        form {
          margin-top: 20px;
        }
        label {
          margin-bottom: 10px;
          display: block;
        }
        input {
          margin-bottom: 10px;
          padding: 8px;
          font-size: 16px;
        }
        button {
          padding: 10px 20px;
          font-size: 18px;
        }
      </style>
    </head>
    <body>
      <h1>Verify wether you are a human.</h1>
      <form action="/recap" method="post">
        <label for="number1">Number 1:</label>
        <input type="text" id="number1" name="number1" value="${number1}" readonly><br>
        <label for="number2">Number 2:</label>
        <input type="text" id="number2" name="number2" value="${number2}" readonly><br>
        <label for="answer">Enter the sum of the numbers:</label>
        <input type="text" id="answer" name="answer" required>
        <button type="submit">Submit</button>
      </form>
    </body>
    </html>
  `;

  res.send(formHTML);
});

app.post('/recap', async (req, res) => {
  try {
    const ip = req.ip; 

    let user;

    if (ip) {
      user = await UserIPCollection.findOne({ ip });
    } else {s
    }

    const userAnswer = parseInt(req.body.answer, 10);
    const number1 = parseInt(req.body.number1, 10);
    const number2 = parseInt(req.body.number2, 10);
    const sum = number1 + number2;

    if (userAnswer === sum) {
      console.log('Congratulations! You got the correct answer.');
      res.send('Congratulations! You got the correct answer.');
      user.trust = 1;
    } else {
      console.log('FAILED. Your answer is incorrect.');
      res.send('FAILED. Your answer is incorrect.');
      user.trust = 3;
    }

    await user.save();

  } catch (error) {
    console.error('Error:', error.message);
    res.status(500).send('Internal Server Error');
  }
});


// Connect to the MongoDB database
mongoose.connect(mongoURI, {
  useNewUrlParser: true,
  useUnifiedTopology: true,
});

mongoose.connection.on("connected", () => {
  console.log("Connected to MongoDB");
  app.listen(port, process.env.SERVER_IP, () => {
    console.log(`Server is listening on port ${port}`);
  });
});

mongoose.connection.on("error", (err) => {
  console.error("MongoDB connection error:", err);
});

