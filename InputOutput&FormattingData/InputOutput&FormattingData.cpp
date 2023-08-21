/* Menu and the entry point to the program.
   Press 1 to execute on of the tasks: 1 - generate a matrix, 2 - format the array of characters.
   Press 2 to create an array of 5 structured variables, then write them into a file and determine an amount of purchase.
   Press 3 to exit the program. */  
#include <iostream>
#include "Matrix.h"
#include "StringFormatting.h"
#include "ProductList.h"

using namespace std;

// Check if the entered value is appropriate
void validateInput() {
    int ignoreValue = 1024;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(ignoreValue, '\n');
    }
};

// First task. Generate a matrix
void firstTask() {
    int number;
    cout << "Enter the initial value: ";
    // Input the initial value
    cin >> number;
    validateInput();
    Matrix matrix(number);
    matrix.generate();
    cout << "Generated matrix:" << endl;
    matrix.print();
};

// Second task. Format the string
void secondTask() {
    StringFormatting stringFormatting;
    string* src = stringFormatting.create("Two One Zero");
    string* dst = stringFormatting.format(src);
    cout << (*src) << " >> " << (*dst) << endl;
    stringFormatting.cleanup(src, dst);
}

int main() {
    // Boolean variable to check if the user wants to quit the program or is continuing the interaction with it
    bool loop = true;
    // Boolean variable to check if the user entered the correct value (1 or 2)
    bool innerLoop;
    // This is a variable to call methods or terminate the program. Variable's value is modified by the user in the loop
    int input;
    cout << "What do you want to do? Enter a number (1-3):" << endl;
    while (loop) {
        innerLoop = true;
        cin >> input;
        validateInput();
        switch (input) {
            // Execute one of the tasks according to the user's request
            case 1:
                while (innerLoop) {
                    // Choose which task to perform
                    int task;
                    cout << "Enter the number of the task you want to perform (1, 2):" << endl;
                    cin >> task;
                    validateInput();
                    switch (task) {
                        // First task. Generate a matrix
                        case 1:
                            firstTask();
                            cout << "\nWhat do you want to do? Enter a number (1-3):" << endl;
                            innerLoop = false;
                        break;
                        // Second task. Format the string
                        case 2:
                            secondTask();
                            cout << "\nWhat do you want to do? Enter a number (1-3):" << endl;
                            innerLoop = false;
                        break;
                        default:
                            cout << "Invalid input. Enter only numbers 1 or 2:" << endl;
                        break;
                    }
                }
            break;
            // Write 5 structural variables into a file
            case 2:
                ProductList myList;
                myList.write("list_of_goods.txt");
                myList.countPurchaseSum();
                cout << "\nWhat do you want to do? Enter a number (1-3):" << endl;
            break;
            // Exit the program
            case 3:
                loop = false;
            break;
            default:
                cout << "Invalid input. Enter only numbers from 1 to 3:" << endl;
            break;
        }
    }
}