#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    string ip;
    int a, b, c, d;

    cout << "Enter IP address: ";
    cin >> ip;

    char dot;

    stringstream ss(ip);

    if (!(ss >> a >> dot >> b >> dot >> c >> dot >> d) ||
        dot != '.' ||
        a < 0 || a > 255 ||
        b < 0 || b > 255 ||
        c < 0 || c > 255 ||
        d < 0 || d > 255)
    {
        cout << "Invalid IP Address";
        return 0;
    }

    cout << "Valid IP Address" << endl;
    cout << "First Byte = " << a << endl;

    if (a >= 1 && a <= 126)
    {
        cout << "Class = A" << endl;
        cout << "Network ID = " << a << endl;
        cout << "Host ID = " << b << "." << c << "." << d << endl;
    }
    else if (a >= 128 && a <= 191)
    {
        cout << "Class = B" << endl;
        cout << "Network ID = " << a << "." << b << endl;
        cout << "Host ID = " << c << "." << d << endl;
    }
    else if (a >= 192 && a <= 223)
    {
        cout << "Class = C" << endl;
        cout << "Network ID = " << a << "." << b << "." << c << endl;
        cout << "Host ID = " << d << endl;
    }
    else if (a >= 224 && a <= 239)
    {
        cout << "Class = D" << endl;
        cout << "Network ID and Host ID not applicable" << endl;
    }
    else if (a >= 240 && a <= 255)
    {
        cout << "Class = E" << endl;
        cout << "Network ID and Host ID not applicable" << endl;
    }
    else
    {
        cout << "Invalid/Reserved IP Address";
    }

    return 0;
}
