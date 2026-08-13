#ifndef QUEUELL_H
#define QUEUELL_H

//create a class node
template <typename T>
class qNode{
    public:
        T data;
        qNode* next;
};

// new node creator
template <typename T>
qNode<T>* new_node(T newData){
    //allocate a space for the new node
    qNode<T>* newNode = new qNode<T>;
    
    //store the newdata to the newNode
    newNode ->data = newData;
    
    //point the newNode next to null
    newNode ->next = nullptr;

    return newNode;

}

// enqueue
template <typename T>
void enqueue(T newData, qNode<T>** frontPtr, qNode<T>** backPtr ){
    //create a new node
    qNode<T>* newNode = new_node(newData);

    //check if the queue is empty
    if((*frontPtr)==nullptr && (*backPtr)== nullptr){
        (*frontPtr) = newNode;
        (*backPtr) = newNode;
        return;
    }
    // if not then insert at the back
    (*backPtr)->next = newNode;
    (*backPtr)= newNode;

}

// dequeue
template <typename T>
void dequeue(qNode<T>** frontPtr, qNode<T>** backPtr){

    //check if the queue is empty
    if((*frontPtr) == nullptr && (*backPtr) == nullptr){
        std::cout<< "the queue is empty"<<std::endl;
        return;
    }
    // create a temporary variable to store the node to be deleted
    qNode<T>* deleteTemp = nullptr;

    //assign the current front to the deleteTemp
    deleteTemp = (*frontPtr);

    // check if the queue has only 1 item
    if((*frontPtr)->next == nullptr && (*backPtr)->next == nullptr){
        //means only 1 item is inside the queue
        (*frontPtr) = nullptr;
        (*backPtr) = nullptr;
        delete deleteTemp;
        return;
    }

    (*frontPtr) = (*frontPtr)->next;
    deleteTemp->next = nullptr;

    // delete na node
    delete deleteTemp;
}

// display all
template <typename T>
void displayAll(qNode<T>* frontPtr){
    //check if the queue is empty
    if(frontPtr == nullptr){
        std::cout<<"the queue is empty"<<std::endl;
        return;
    }

    //create a temp pointer to walk through the queue
    qNode<T>* temp = frontPtr;

    //loop until temp reaches the end
    while(temp != nullptr){
        std::cout<< temp->data << " ";
        temp = temp->next;
    }
    std::cout<<std::endl;
}

// isEmpty
template <typename T>
bool isEmpty(qNode<T>* frontPtr, qNode<T>* backPtr){
    return (frontPtr == nullptr && backPtr == nullptr);
}

#endif