#include <iostream>
#include <stack>

int main(){

    std::stack<int> stack1;
    std::cout<<"----Testing the stack STL----" <<std::endl;
    
    std::cout<<"\n========== STACK 1 ==========" <<std::endl;
    
    //isEmpty
    std::cout<<"is the stack 1 empty? " << stack1.empty() << std::endl;

    //push
    stack1.push(10);
    std::cout << "The top of the stack 1 is: " << stack1.top() <<std::endl;
    stack1.push(9);
    std::cout << "The top of the stack 1 is: " << stack1.top() <<std::endl;
    stack1.push(8);
    std::cout << "The top of the stack 1 is: " << stack1.top() <<std::endl;
    stack1.push(7);
    std::cout << "The top of the stack 1 is: " << stack1.top() <<std::endl;

    stack1.pop();
    std::cout << "Popped out previous top. The top of the stack 1 is: " << stack1.top() <<std::endl;
    std::cout<<"is the stack 1 empty? " << stack1.empty() <<std::endl;
    std::cout << "The size of the stack 1 is: " << stack1.size() <<std::endl;


    std::stack<int> stack2;
    std::cout<<"\n========== STACK 2 ==========" <<std::endl;

    stack2.emplace(1);
    std::cout << "Emplaced 1. The top of the stack 2 is: " << stack2.top() <<std::endl;
    stack2.emplace(2);
    std::cout << "Emplaced 2. The top of the stack 2 is: " << stack2.top() <<std::endl;
    stack2.emplace(3);
    std::cout << "Emplaced 3. The top of the stack 2 is: " << stack2.top() <<std::endl;
    stack2.emplace(4);
    std::cout << "Emplaced 4. The top of the stack 2 is: " << stack2.top() <<std::endl;
    
    std::cout << "\nBefore swap:" <<std::endl;
    std::cout << "The top of the stack 1 is: " << stack1.top() <<std::endl;
    std::cout << "The top of the stack 2 is: " << stack2.top() <<std::endl;
    
    stack1.swap(stack2);
    std::cout << "\nAfter swap:" <<std::endl;
    std::cout << "The top of the stack 1 is: " << stack1.top() <<std::endl;
    std::cout << "The top of the stack 2 is: " << stack2.top() <<std::endl;

}
