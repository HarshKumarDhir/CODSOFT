#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int selection, range, target_number, user_guess, attempts = 0;
    
    while (true) {
        cout << "===========================" << endl;
        cout << "-NUMBER-GUESSING-GAME-" << endl;
        cout << "===========================" << endl;
        cout << "1. Start the Game" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter Option: ";
        cin >> selection;
        
        switch (selection) {
            case 1: {
                attempts = 0;
                cout << "Specify the range of numbers: ";
                cin >> range;
                
                srand(static_cast<unsigned>(time(nullptr)));
                target_number = rand() % (range + 1);
                
                do {
                    cout << "Make a guess: ";
                    cin >> user_guess;
                    
                    if (user_guess > target_number) {
                        attempts++;
                        cout << "The number is lower than your guess." << endl;
                    } else if (user_guess < target_number) {
                        attempts++;
                        cout << "The number is higher than your guess." << endl;
                    } else {
                        attempts++;
                        cout << "\nCongratulations! You've guessed the correct number." << endl;
                        if (attempts == 1) {
                            cout << "It took you " << attempts << " attempt." << endl;
                        } else {
                            cout << "It took you " << attempts << " attempts." << endl;
                        }
                        break;
                    }
                } while (user_guess != target_number);
                
                break;
            }
            case 2:
                cout << "\nThank you for playing. Goodbye!" << endl;
                return 0;
            default:
                cout << "\nInvalid choice. Please try again." << endl;
                break;
        }
    }
    
    return 0;
}
