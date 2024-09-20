#include<iostream>
#include<String>

using namespace std;

// Fixed lowercase error in "isleapYear"
bool isLeapYear(int year);
int getCenturyValue (int year);
int getYearValue(int year);
int getMonthValue(int month, int year);

int main() {
    int month,
        day = 0,
        year = 0,
        sum = 0,
        day_of_week = 0;
    string day_string = "";

    // Enter a year value (no conditions on year values specified in assignment)
    cout << "enter the year"<< endl;

    cin >> year;

    cout << "enter the month"<< endl;

    cin >> month;

    while (month < 1 || month > 12){

        cout << "please give a valid month"<<endl;
        cin >> month;
    }

    cout << "enter a day" << endl;

    cin >> day;

    if (month == 4 || month == 6 || month == 9 || month == 11) {
        while (day < 1 || day > 30) {
            cout << "Enter a value between 1 and 30:"<<endl;
            cin  >> day;
        }
    }

    // Else, if month is February, check if leap year and take in number between 1 and either 28 or 29
    if (month == 2) {
        if (isLeapYear(year)) {
            while (day < 1 || day > 29) {
                cout << "Enter a value between 1 and 29:"<<endl;
                cin  >> day;
            }
        }
        else {
            while (day < 1 || day > 28) {
                cout << "Enter a value between 1 and 28:"<<endl;
                cin  >> day;
            }
        }
    }

    // Remaining months must all have 31 days, so else statement covers rest of possibilities
    
    else {
        while (day < 1 || day > 30) {
            cout << "Enter a value between 1 and 30:"<<endl;
            cin  >> day;
        }
    }
    // Calculate the day of week
    sum = day + getMonthValue(month,year) + getYearValue(year) + getCenturyValue(year);
    day_of_week = sum % 7;

    // Find corresponding day name
    switch(day_of_week) {

        case 0:
            day_string = "Sunday";
        break;

        case 1:
            day_string = "Monday";
        break;

        case 2:
            day_string = "Tuesday";
        break;

        case 3:
            day_string = "Wednesday";
        break;

        case 4:
            day_string = "Thursday";
        break;

        case 5:
            day_string = "Friday";
        break;

        case 6:
            day_string = "Saturday";
        break;
    }
    cout << day_string;
    return 0;

}

// Check if year is leap year or not
bool isLeapYear(int year) {
    // Leap year is divisible by 400 or divisible by 4 and not 100
    return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}

// Get the value for century using formula in assignment 2
int getCenturyValue(int year) {
    int century = 0,
        century_value = 0;

    century = year / 100;
    century_value = (3 - (century % 4)) * 2;
    return century_value;
}

// Get the value for year using formula in assignment 2
int getYearValue(int year) {
    int year_value = 0;
    // sum of last two digits (year mod 1000) and last two digits divided by four disregarding remainder (int division disregards remainder inherently)
    year_value = ((year % 1000) / 4)+(year % 1000);
    return year_value;
}

// Get the value for month using values listed in assignment 2
int getMonthValue(int month, int year) {
    switch(month) {
        // months 1 and 2 dependent on leap year
        case 1:
            if (isLeapYear(year))
                return 6;
            else
                return 0;
        case 2:
            if (isLeapYear(year))
                return 2;
            else
                return 3;
        case 3:
            return 3;
        case 4:
            return 6;
        case 5:
            return 1;
        case 6:
            return 4;
        case 7:
            return 6;
        case 8:
            return 2;
        case 9:
            return 5;
        case 10:
            return 0;
        case 11:
            return 3;
        case 12:
            return 5;
    }
}



