#include <iostream>;
#include <iomanip>;

using namespace std;

double convertToMPH(int minutes, int seconds);
double convertToMPH(double kph);

int main() {
    int minutes = 0,
        seconds = 0;
    double kph = 0.0;
    // User enters minutes, seconds, and kph according to assignment 2
    cout << "Enter a mile-run pace, starting with minutes: " << endl;
    cin >> minutes;
    // Enter a number of minutes between 0 and 60
    while (minutes < 0 || minutes > 60) {
        cout << "Enter a number of minutes between 0 and 60:"<<endl;
        cin  >> minutes;
    }
    cout << "Enter the seconds: " << endl;
    cin >> seconds;
    // Enter a number of seconds between 0 and 60
    while (seconds < 0 || seconds > 60) {
        cout << "Enter a number of seconds between 0 and 60:"<<endl;
        cin  >> minutes;
    }

    cout << "Enter kilometers per hour (kph): " << endl;
    cin >> kph;

    // output both calculations since unspecified in assignment
    cout << "MPH from running pace: " << convertToMPH(minutes, seconds) << endl;
    cout << "MPH from KPH: " << convertToMPH(kph) << endl;

    return 0;
}

double convertToMPH(int minutes, int seconds) {
    // There are 3600 seconds in an hour
    return (3600.0 / ((minutes * 60) + seconds));
}

double convertToMPH(double kph) {
    // One mile is approx. 1.61 kilometers
    return (kph / 1.61);
}
