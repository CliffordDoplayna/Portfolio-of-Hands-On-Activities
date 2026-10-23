#include <iostream>
#include "stackList.h"

int main() {
    std::cout << "--- Testing Stack Operations ---\n\n";

    // Push elements onto the stack
    std::cout << "Pushing 10, 20, 30...\n";
    push(10);
    push(20);
    push(30);

    // Display top element and all elements
    Top<int>();
    displayALL<int>();

    // Pop an element
    std::cout << "Popping top element: " << pop<int>() << "\n\n";

    // Display stack state after pop
    Top<int>();
    displayALL<int>();

    // Test isEmpty
    std::cout << "Is stack empty? " << (isEmpty<int>() ? "Yes" : "No") << "\n";

    return 0;
}