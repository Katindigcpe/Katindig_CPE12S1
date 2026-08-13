#include <iostream>
#include "queueLL.h"

int main(){
    qNode<char>* front = nullptr;
    qNode<char>* back = nullptr;

    std::cout<<"Testing the enqueue operator: \n";
    std::cout<<"enqueueing the following items: J, I, R, O\n";
    enqueue('J', &front, &back);
    std::cout<<"front: "<< front->data << " "<<"back: "<<back->data <<std::endl;
    enqueue('I', &front, &back);
    std::cout<<"front: "<< front->data << " "<<"back: "<<back->data <<std::endl;
    enqueue('R', &front, &back);
    std::cout<<"front: "<< front->data << " "<<"back: "<<back->data <<std::endl;
    enqueue('O', &front, &back);
    std::cout<<"front: "<< front->data << " "<<"back: "<<back->data <<std::endl;

    std::cout<< std::endl;
    std::cout<<"Testing the display all: \n";
    displayAll(front);
    std::cout<< std::endl;
    std::cout<<"Testing the isEmpty operator: \n";
    if(isEmpty(front, back)){
        std::cout<<"queue is empty!"<<std::endl;
    } else {
        std::cout<<"queue is not empty!"<<std::endl;
    }
    std::cout<< std::endl;

    std::cout<<"Testing the dequeue operator: \n";
    dequeue(&front, &back);
    if(!isEmpty(front, back)){
        std::cout<<"dequeueing the front, current front is: "<< front->data << " "<<"back: "<<back->data <<std::endl;
    } else {
        std::cout<<"dequeueing the front, queue is now empty."<<std::endl;
    }
    dequeue(&front, &back);
    if(!isEmpty(front, back)){
        std::cout<<"dequeueing the front, current front is: "<< front->data << " "<<"back: "<<back->data <<std::endl;
    } else {
        std::cout<<"dequeueing the front, queue is now empty."<<std::endl;
    }

    std::cout<< std::endl;
    std::cout<<"Testing the display all: \n";
    displayAll(front);

    std::cout<< std::endl;
    std::cout<<"Testing the isEmpty operator: \n";
    if(isEmpty(front, back)){
        std::cout<<"queue is empty!"<<std::endl;
    } else {
        std::cout<<"queue is not empty!"<<std::endl;
    }

    std::cout<< std::endl;
    dequeue(&front, &back);
    if(!isEmpty(front, back)){
        std::cout<<"dequeueing the front, current front is: "<< front->data << " "<<"back: "<<back->data <<std::endl;
    } else {
        std::cout<<"dequeueing the front, queue is now empty."<<std::endl;
    }
    dequeue(&front, &back);
    if(!isEmpty(front, back)){
        std::cout<<"dequeueing the front, current front is: "<< front->data << " "<<"back: "<<back->data <<std::endl;
    } else {
        std::cout<<"dequeueing the front, queue is now empty."<<std::endl;
    }

    std::cout<< std::endl;
    std::cout<<"Testing the display all: \n";
    displayAll(front);

    std::cout<< std::endl;
    std::cout<<"Testing the isEmpty operator: \n";
    if(isEmpty(front, back)){
        std::cout<<"queue is empty!"<<std::endl;
    } else {
        std::cout<<"queue is not empty!"<<std::endl;
    }

    return 0;
}