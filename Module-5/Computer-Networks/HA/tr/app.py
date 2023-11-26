from flask import Flask, render_template

app = Flask(__name__)

# Load data from the file
with open("../OSPF.txt", "r") as file:
    data = file.read()

# Define a route for the home page
@app.route('/')
def index():
    return render_template('index.html', data=data)

if __name__ == '__main__':
    app.run(debug=True)

