from flask import Flask, request, render_template
import datetime

# -*- coding: utf-8 -*-

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/saveData', methods=['POST'])
def save_data():
    if request.method == 'POST':
        data_to_save = request.form.get('data')

        if data_to_save:
            file_path = 'data.txt'
            timestamp = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
            data_to_save += " | {}\n".format(timestamp)

            with open(file_path, 'a') as file:
                file.write(data_to_save)

            return 'no'
        else:
            return 'no 400', 400
    else:
        return 'no 501', 501

if __name__ == '__main__':
    app.run(debug=True)
