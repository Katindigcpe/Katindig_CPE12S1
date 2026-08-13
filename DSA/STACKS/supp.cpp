#include <iostream>
#include <string>
#include "stackList.h"

using namespace std;

bool isOpenSymbol(char c) {
    return (c == '(' || c == '[' || c == '{');
}

bool isCloseSymbol(char c) {
    return (c == ')' || c == ']' || c == '}');
}

char getExpectedOpener(char closeSym) {
    switch (closeSym) {
        case ')': return '(';
        case ']': return '[';
        case '}': return '{';
    }
    return ' ';
}

void clearStack() {
    while (!isEmpty<char>()) pop<char>();
}

bool checkBalanced(string input) {
    clearStack();

    for (char symbol : input) {
        if (isOpenSymbol(symbol)) {
            push<char>(symbol);
            continue;
        }

        if (isCloseSymbol(symbol)) {
            if (isEmpty<char>()) return false;

            char lastOpened = pop<char>();
            if (lastOpened != getExpectedOpener(symbol)) return false;
        }
    }

    return isEmpty<char>();
}

int main() {
    string testCases[] = {
        "(A+B)+(C-D)",
        "((A+B)+(C-D)",
        "((A+B)+[C-D])",
        "((A+B]+[C-D]}"
    };

    int totalCases = 4;

    for (int i = 0; i < totalCases; i++) {
        cout << "\nExpression: " << testCases[i] << endl;

        if (checkBalanced(testCases[i]))
            cout << "Result: The symbols are BALANCED." << endl;
        else
            cout << "Result: The symbols are NOT BALANCED." << endl;
    }

    return 0;
}
