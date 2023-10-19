import mongoose from "mongoose";

const ipSchema = new mongoose.Schema({
  ip: String,
  visitCount: Number,
});
//profs is the array of UIDs mapped to each faculty

const UserIPCollection = mongoose.model("UserIPs", ipSchema);

export default UserIPCollection;
