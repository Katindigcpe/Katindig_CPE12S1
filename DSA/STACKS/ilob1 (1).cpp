#include <iostream>

//global declarations
#define maxCap 10


int stackArr[maxCap];
int top = -1, newData;

// prototype functions
void push();
void pop();
void Top();
bool isEmpty();
bool isFull();
void display();

int main(){
// main driver
    int choice;
    while (true){
        std::cout<<"\n====================="<<std::endl;
        std::cout<<"Stack operations \n";
        std::cout<<"1. Push\n2. Pop\n3. Top\n4. isEmpty\n5. isFull\n6. Display\n7. Exit program"<<std::endl;
        std::cout<<"====================="<<std::endl;
        std::cout<<"\nEnter your choice: ";
        std::cin >>choice;
        
        switch(choice){
            case 1: 
                push();
                break;
            case 2: 
                pop();
                break;
            case 3: 
                Top();
                break;
            case 4: 
                std::cout<<"is stack empty? "<< isEmpty()<<std::endl;
                break;
            case 5: 
                std::cout<<"is the stack full? "<< isFull()<<std::endl;
                break;
            case 6:
                display();
                break;
            case 7: 
                std::cout<<"Exiting program...";
                return 0;
            default: 
                std::cout<<"Invalid choice." <<std::endl;
                break;

        }
    }
}

//function definition

bool isEmpty(){
    //how do we verify if the stack is empty
    if(top == -1) return true;
    return false;
}

bool isFull(){
    //how do we verify if stack is full?
    if (top == maxCap -1) return true;
    return false;
}

void push(){
    //error checking ??
    if(isFull()){
        std::cout <<"Stack overflow" << std::endl;
        return;
    }
    //pushing to the stack
    std::cout<<"Enter a new Value: ";
    std::cin >> newData;
    std::cout<<"Successfuly pushed " << newData << std::endl; 
    
    // how do we insert the data into the stack?
    stackArr[++top] = newData;
}

void pop(){
    //error checking
    if(isEmpty()){
        std::cout<<"Stack underflow" <<std::endl;
    }

    //Display the value that we are going to pop:
    std::cout<<"Popping: "<<stackArr[top]<<std::endl;
    //Decrement the top value from the stack
    top--;
}

void Top(){
    //error catching:
    if(isEmpty()){
        std::cout<<"The stack is empty" <<std::endl;
        return;
    }
    //check the top value
    std::cout <<"top element: "<<stackArr[top]<<std::endl;
}

void display() {
    if (isEmpty()) {
        std::cout << "The stack is empty." << std::endl;
        return;
    }

    std::cout << "Stack elements (top to bottom):" << std::endl;
    for (int i = top; i >= 0; i--) {
        std::cout << stackArr[i] << std::endl;
    }
}
