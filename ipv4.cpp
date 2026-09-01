#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d;
    char dot;

    cout << "Enter IP Address: ";
    cin >> a >> dot >> b >> dot >> c >> dot >> d;

    if (a < 0 || a > 255 || b < 0 || b > 255 ||
        c < 0 || c > 255 || d < 0 || d > 255)
    {
        cout << "Invalid IP Address";
    }
    else
    {
        cout << "Valid IP Address" << endl;
        cout << "First Byte = " << a << endl;

        if (a >= 1 && a <= 126)
        {
            cout << "Class A" << endl;
            cout << "Network ID = " << a << endl;
            cout << "Host ID = " << b << "." << c << "." << d;
        }
        else if (a >= 128 && a <= 191)
        {
            cout << "Class B" << endl;
            cout << "Network ID = " << a << "." << b << endl;
            cout << "Host ID = " << c << "." << d;
        }
        else if (a >= 192 && a <= 223)
        {
            cout << "Class C" << endl;
            cout << "Network ID = " << a << "." << b << "." << c << endl;
            cout << "Host ID = " << d;
        }
        else
        {
            cout << "Class D or E";
        }
    }
    return 0;
}
