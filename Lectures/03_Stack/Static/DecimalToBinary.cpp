#include <iostream>
#include "Stack.h"

using namespace std;

void decimalToBinary(int num) {
    Stack stack;

    // Handle special case for 0
    if (num == 0) {
        cout << "Binary: 0" << endl;
        return;
    }

    // Push remainders onto stack
    while (num > 0) {
        stack.push(num % 2);  // Store remainder
        num /= 2;
    }

    // Pop and print values to get binary
    cout << "Binary: ";
    while (!stack.empty()) {
        cout << stack.pop();
    }
    cout << endl;
}
int main() {
    int number;
    cout << "Enter a decimal number: ";
    cin >> number;

    decimalToBinary(number);

    return 0;
}
