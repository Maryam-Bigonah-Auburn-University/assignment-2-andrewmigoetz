#include <iostream>;

using namespace std;

void computeCoin(int coinValue, int& number, int& amountLeft);
void printOutput(int coinValue, int number);

int main() {
    char compute_again = 'N';
    int number = 0,
        amountLeft = 0;

    do {
        cout << "Enter the amount of change:"<<endl;
        cin  >> amountLeft;
        // Change must be between 1 and 99 inclusive
        while (amountLeft < 1 || amountLeft > 99) {
            cout << "Enter a value between 1 and 99:"<<endl;
            cin  >> amountLeft;
        }

        // For each coin calculate how many of each coin to be given and print output
        cout << "Change can be given as:" << endl;
        computeCoin(25,number,amountLeft);
        printOutput(25,number);
        computeCoin(10,number,amountLeft);
        printOutput(10,number);
        computeCoin(1,number,amountLeft);
        printOutput(1,number);

        // User prompted to enter Y or y to run program again
        cout << endl << "Do you want to make change again?" << endl
             << "Enter Y to convert again and any other key to exit:" << endl;
        cin  >> compute_again;

    } while(compute_again == 'Y' || compute_again == 'y');


    return 0;
}

void computeCoin(int coinValue, int& number, int& amountLeft) {
        // reset number index for each coin computed
        number = 0;
        // amountLeft decreased by coinValue until amountLeft < coinValue
        // increment number by 1 for each time coinValue fits within amountLeft
        while (amountLeft > coinValue-1) {
            amountLeft -= coinValue;
            number += 1;
        }
}

void printOutput(int coinValue, int number) {
    // print number of coins and convert coinValue into text
    cout << number;
    switch(coinValue) {
        case 25:
            // consider plural/singular case
            if (number == 1) {
                cout << " quarter, ";
            }
            else cout << " quarters, ";
        break;
        case 10:
            if (number == 1) {
                cout << " dime, ";
            }
            else cout << " dimes, ";
        break;
        case 1:
            if (number == 1) {
                cout << " penny";
            }
            else cout << " pennies";
        break;
    }
}
