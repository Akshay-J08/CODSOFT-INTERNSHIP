// Develop a calculator program that performs basic arithmetic
// operations such as addition, subtraction, multiplication, and
// division. Allow the user to input two numbers and choose an
// operation to perform.

#include <iostream>
using namespace std;

int main()
{
    double num1, num2, result;
    char operation;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    cout << "Choose operation (+, -, *, /): ";
    cin >> operation;

    switch (operation)
    {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        if (num2 != 0)
        {
            result = num1 / num2;
        }
        else
        {
            cout << "Error: Division by zero is undefined.\n";
            return 1;
        }
        break;
    default:
        cout << "Invalid operation. Please choose +, -, *, or /.\n";
        return 1;
    }

    cout << "Result: " << result << endl;

    return 0;
}
