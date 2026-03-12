#include <iostream>
using namespace std;

class Converter {
    public:
        
        void secondsToHMS(int totsec) {
            int hr = totsec / 3600;
            int min = (totsec % 3600) / 60;
            int sec = totsec % 60;

            cout << "HH:MM:SS => " << hr << ":" 
                << min << ":" << sec << endl;
        }

    void hmsToSeconds(int hr, int min, int sec) {
        int totsec = (hr * 3600) + (min * 60) + sec;
        cout << "Total seconds: " << totsec << endl;
    }
};

int main() {
    Converter tc;
    int ch;

    cout << "\t Time Converter \t" << endl;
    cout << "1. Convert Seconds to HH:MM:SS" << endl;
    cout << "2. Convert HH:MM:SS to Seconds" << endl;
    cout << "Enter your choice: ";
    cin >> ch;

    if (ch == 1) {
        int sec;
        cout << "Enter total seconds: ";
        cin >> sec;
        tc.secondsToHMS(sec);
    } 
    else if (ch == 2) {
        int h, m, s;
        cout << "Enter hours: ";
        cin >> h;
        cout << "Enter minutes: ";
        cin >> m;
        cout << "Enter seconds: ";
        cin >> s;
        tc.hmsToSeconds(h, m, s);
    } 
    else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
