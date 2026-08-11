#include <iostream>
using namespace std;

int main() {
    int input[100], output[100];
    int n, count = 0, j = 0;

    cout << "Enter number of bits: ";
    cin >> n;

    cout << "Enter bit stream (0s and 1s):\n";
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    for (int i = 0; i < n; i++) {
        output[j] = input[i];
        j++;

        if (input[i] == 1) {
            count++;
            if (count == 5) {
                output[j] = 0;   
                j++;
                count = 0;
            }
        } else {
            count = 0;
        }
    }

    int stuffedLen = j;

    cout << "\nOriginal bit stream: ";
    for (int i = 0; i < n; i++)
        cout << input[i];

    cout << "\nStuffed bit stream:  ";
    for (int i = 0; i < stuffedLen; i++)
        cout << output[i];
    int result[100];
    int k = 0;
    count = 0;

    for (int i = 0; i < stuffedLen; i++) {
        if (output[i] == 1) {
            count++;
            result[k] = output[i];
            k++;

            if (count == 5) {
                i++;        
                count = 0;
            }
        } else {
            count = 0;
            result[k] = output[i];
            k++;
        }
    }

    cout << "\nDe-stuffed bit stream: ";
    for (int i = 0; i < k; i++)
        cout << result[i];

    bool match = true;
    if (k != n) {
        match = false;
    } else {
        for (int i = 0; i < n; i++) {
            if (input[i] != result[i]) {
                match = false;
                break;
            }
        }
    }

    if (match)
        cout << "\n\nSuccess: Receiver recovered the original data correctly.";
    else
        cout << "\n\nError: Mismatch between original and de-stuffed data.";

    cout << endl;
    return 0;
}
