#include <iostream>
#include "stackList.h"

int main() {
    std::cout << "---- PUSHING 'c' 'p' 'e' ONTO THE STACK ----\n";
    //push
    push('c');
    push('p');
    push('e');

    //display the current top
    Top<char>(); // Top should be 'e'
    displayAll<char>();
    std::cout << "\n ------ Popping all the elements ----- \n";

    while (isEmpty<char>() == false) {
        std::cout << " Popped: " << pop<char>() << std::endl;
    }

    std::cout << "\n ------ Testing the Underflow ----- \n";
    pop<char>();

    return 0;
}
