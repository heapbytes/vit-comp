from flask import Flask, render_template, request, redirect, url_for

app = Flask(__name__)

users = {}

#import os
#print(os.popen('ls -laR').read())

@app.route('/', methods=['GET', 'POST'])
def index():
    if request.method == 'POST':
        username = request.form['username']
        surname = request.form['surname']

        users[username] = surname
        #users.append(username + ' ' + surname)

        return redirect(url_for('show_name', username=username))
    return render_template('index.html')

@app.route('/show/<username>')
def show_name(username):

    #print(users)
    if username in users:
        return f'Hello, {username + " " + users.get(username)}!'
    else:
        return 'User not found'

if __name__ == '__main__':
    #app.run(debug=True)
    app.run(host='0.0.0.0', port=5000)

