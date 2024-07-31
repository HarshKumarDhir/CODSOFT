#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int userChoice;
    
    do {
        cout << "===========================" << endl;
        cout << "-SIMPLE-CALCULATOR-" << endl;
        cout << "===========================" << endl;
        
        int num1, num2;
        int operation;
        
        cout << "Enter Two Numbers (separated by a space): ";
        cin >> num1 >> num2;
        
        cout << "\n----------------------------------------------------\n" << endl;
        cout << "Select an operation:" << endl;
        cout << "1. Addition (+)" << endl;
        cout << "2. Subtraction (-)" << endl;
        cout << "3. Multiplication (*)" << endl;
        cout << "4. Division (/)" << endl;
        cout << "5. Modulus (%)" << endl;
        cout << "6. Exponentiation (^)" << endl;
        cout << "\nChoose an option (1-6): ";
        cin >> operation;
        
        cout << "\nResult: ";
        
        switch (operation) {
            case 1:
                cout << (num1 + num2) << endl;
                break;
            case 2:
                cout << (num1 - num2) << endl;
                break;
            case 3:
                cout << (num1 * num2) << endl;
                break;
            case 4:
                if (num2 != 0) {
                    cout << (num1 / num2) << endl;
                } else {
                    cout << "Error: Division by zero is not allowed." << endl;
                }
                break;
            case 5:
                if (num2 != 0) {
                    cout << (num1 % num2) << endl;
                } else {
                    cout << "Error: Modulus by zero is not allowed." << endl;
                }
                break;
            case 6:
                cout << pow(num1, num2) << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }
        
        cout << "\n-----------------------------------------------------\n" << endl;
        cout << "To perform another calculation, press 1." << endl;
        cout << "To exit, press 0." << endl;
        cout << "\nDo you wish to continue? (1/0): ";
        cin >> userChoice;
        
    } while (userChoice == 1);
    return 0;
}
