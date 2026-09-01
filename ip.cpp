
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string ip;
    cout << "Enter IPv4 Address: ";
    cin >> ip;

    stringstream ss(ip);
    string token;
    vector<int> octets;

    // Split IP into octets
    while (getline(ss, token, '.')) {
        try {
            int num = stoi(token);

            // Check range 0-255
            if (num < 0 || num > 255) {
                cout << "Invalid IP Address" << endl;
                return 0;
            }

            octets.push_back(num);
        }
        catch (...) {
            cout << "Invalid IP Address" << endl;
            return 0;
        }
    }

    // Check exactly 4 octets
    if (octets.size() != 4) {
        cout << "Invalid IP Address" << endl;
        return 0;
    }

    int first = octets[0];

    if (first >= 1 && first <= 126) {
        cout << "Class A" << endl;
        cout << "NetID : " << octets[0] << ".0.0.0" << endl;
        cout << "HostID: "
             << octets[1] << "."
             << octets[2] << "."
             << octets[3] << endl;
    }
    else if (first >= 128 && first <= 191) {
        cout << "Class B" << endl;
        cout << "NetID : "
             << octets[0] << "."
             << octets[1] << ".0.0" << endl;

        cout << "HostID: "
             << octets[2] << "."
             << octets[3] << endl;
    }
    else if (first >= 192 && first <= 223) {
        cout << "Class C" << endl;
        cout << "NetID : "
             << octets[0] << "."
             << octets[1] << "."
             << octets[2] << ".0" << endl;

        cout << "HostID: "
             << octets[3] << endl;
    }
    else if (first >= 224 && first <= 239) {
        cout << "Class D (Multicast)" << endl;
    }
    else if (first >= 240 && first <= 255) {
        cout << "Class E (Experimental)" << endl;
    }
    else {
        cout << "Invalid IP Address" << endl;
    }

    return 0;
}
```
