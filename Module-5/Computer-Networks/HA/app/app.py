from flask import Flask, render_template

app = Flask(__name__)

# Sample network information data
network_info = {
    "special_hello_packets": [
        {"from": 1, "to": 2, "network_address": "192.168.1.1-2"},
        {"from": 1, "to": 4, "network_address": "192.168.1.1-4"},
        {"from": 1, "to": 5, "network_address": "192.168.1.1-5"},
        {"from": 2, "to": 1, "network_address": "192.168.1.2-1"},
        {"from": 2, "to": 3, "network_address": "192.168.1.2-3"},
        {"from": 3, "to": 2, "network_address": "192.168.1.3-2"},
        {"from": 3, "to": 4, "network_address": "192.168.1.3-4"},
        {"from": 3, "to": 5, "network_address": "192.168.1.3-5"},
        {"from": 4, "to": 1, "network_address": "192.168.1.4-1"},
        {"from": 4, "to": 3, "network_address": "192.168.1.4-3"},
        {"from": 5, "to": 1, "network_address": "192.168.1.5-1"},
        {"from": 5, "to": 3, "network_address": "192.168.1.5-3"}
    ],
    "link_state_packets": {
        1: {2: 1, 4: 1, 5: 1},
        2: {1: 1, 3: 2},
        3: {2: 2, 4: 3, 5: 3},
        4: {1: 1, 3: 3},
        5: {1: 1, 3: 3}
    },
    "link_state_database": {
        1: [(2, 1), (4, 1), (5, 1)],
        2: [(1, 1), (3, 2)],
        3: [(2, 2), (4, 3), (5, 3)],
        4: [(1, 1), (3, 3)],
        5: [(1, 1), (3, 3)]
    },
    "shortest_path": {
        "path": [1, 2, 3],
        "cost": 3
    },
    "routing_table": {
        1: [(("192.168.1.2-1", 1), "Router 2"),
            (("192.168.1.4-1", 1), "Router 4"),
            (("192.168.1.5-1", 1), "Router 5")]
    }
}


@app.route('/')
def index():
    return render_template('index.html', network_info=network_info)


if __name__ == '__main__':
    app.run(debug=True)

