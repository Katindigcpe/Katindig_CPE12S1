#include<iostream>
#include<queue>

void display(std::queue<char> copyQ);
int main(){

    //create an object:
    std::queue<char> myQ;

    //use the enqueue operation
    myQ.push('J');
    myQ.push('I');
    myQ.push('R');
    std::cout<<"current size is: "<< myQ.size()<<std::endl;
    std::cout<<"current front is: "<< myQ.front()<<std::endl;
    std::cout<<"current back is: "<< myQ.back()<<std::endl;
    display(myQ);
    //use the dequeue operation
    myQ.pop();
    std::cout<<"after dequeue, current size is: "<< myQ.size()<<std::endl;
    std::cout<<"after dequeue, front is: "<< myQ.front()<<std::endl;
    std::cout<<"after dequeue, back is: "<< myQ.back()<<std::endl;
    

    display(myQ);
    
    //check the queue if it is empty
    std::cout<<"Is the queue empty? " << myQ.empty() <<std::endl;
    
    return 0;
}

//note noly use the member functions of the queue STL
void display(std::queue<char> copyQ){
    //create a copy of the queue
    std::queue<char> temp = copyQ;

    // loop until empty
    while(!temp.empty()){
        // display the front
        std::cout << temp.front() << " ";
        // dequeue the front
        temp.pop();
    }
    // add a new line
    std::cout << std::endl;
}
