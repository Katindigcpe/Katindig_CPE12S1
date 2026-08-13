#ifndef DOUBLY_LL_H
#define DOUBLY_LL_H

template <typename T>
class DoubleList{
    public:
        T data;
        DoubleList<T>* prev = nullptr;
        DoubleList<T>* next = nullptr;

};

//creating a node:
template <typename T>
DoubleList<T> *CreateNewNode(T newData){
    //dynamically allocate a new memory for the node
    DoubleList<T> *newNode = new DoubleList<T>;
    //store the data in the node
    newNode->data = newData;

    //point next and prev to null
    newNode->next = nullptr;
    newNode->prev = nullptr;

    //return the address of the newly created nod
    return newNode;
}

template <typename T>
void dllTraverse(DoubleList<T>* currentNode){
    
    //temp variable to store the last node visited
    DoubleList<T> *tail;

    //check if list is empty
    if(currentNode == nullptr){
        std::cout<<"The list is empty"<<std::endl;
        return;
    }
    //move forward
    std::cout<<"Fowrard: \n";
    while(currentNode != nullptr){
        std::cout<< currentNode->data << " ";
        tail = currentNode;
        currentNode = currentNode->next;

    }
    // add a next line
    std::cout<<std::endl;
    
    //move backward
    std::cout<<"Backward: \n";

    while(tail != nullptr){
        std::cout<<tail->data<<" ";
        tail = tail->prev;
    }
}

//inserting at the head of the list
template <typename T>
void dllInsertHead(T newData, DoubleList<T> ** currentHead){
    //creating a new node
    DoubleList<T>* newNode = CreateNewNode(newData);

    //new node should point to the current head
    newNode->next = *currentHead;

    //current Head should point back to the newNode
    (*currentHead)->prev = newNode;
    
    //update the pointer head
    *currentHead = newNode;
}

template <typename T>
void dllInsertEnd(T newData, DoubleList<T>* currentHead){
    //create a new node
    DoubleList<T>* newNode = CreateNewNode(newData);

    //traverse until we reach the last node
    while(currentHead->next != nullptr){
        currentHead = currentHead->next;
    }

    //connect the last node to the new node
    currentHead->next = newNode;

    //connect the new node back to last node
    newNode->prev = currentHead;
}

// GENERAL INSERT?

template <typename T>
void dllGeneralInsert(T newData, DoubleList<T>* prevNode) {
    if (prevNode == nullptr){
        std::cout << "Prevnode cannot be null" <<std::endl;
        return;
    }
    
    DoubleList<T>* newNode = CreateNewNode(newData);
    
    //point new node next to prev node next
    newNode->next = prevNode->next;

    //point new node next to prev node
    newNode->prev = prevNode;

    //if prenode isnt the last node, adjust the next node's prev pointer
    if (prevNode->next != nullptr){
        prevNode->next->prev = newNode;
    }

    //point prevnode next to the new node
    prevNode->next = newNode;

}
    

// DELETE A NODE?

template <typename T>
void dllDeleteNode(T findData, DoubleList<T>** head) {
    if (*head == nullptr) {
        std::cout <<"List is empty." << std::endl;
        return;
    }

    DoubleList<T>* currNode = *head;
    
    //search for the node
    while(currNode != nullptr && currNode->data != findData) {
        currNode = currNode->next;
    }

    //data not found
    if (currNode == nullptr) {
        std::cout << "Data '" << findData << "' not found in list.\n";
        return;
    }

    //if node to delete is the head
    if (*head == currNode) {
        *head = currNode->next;
    }

    //adjust next node's prev pointer if not deleting tail
    if (currNode->next != nullptr) {
        currNode->next->prev = currNode->prev;
    }

    //adjust previous node's next pointer if not deleting head
    if (currNode->prev != nullptr) {
        currNode->prev->next = currNode->next;
    }

    delete currNode;
}
#endif


/*
template <typename T>
void sllGeneralInsert(T newData, SingleList<T>* previousNode) {

    //1. Checkif its the head node or not
    if(previousNode == nullptr) {
        //2. If null, print "previous node cannot be null"
        std::cout << "previous node cannot be null" << std::endl;
        return;
    }

    //3. Allocate a new node
    SingleList<T>* newNode = new SingleList<T>;

    //4. Store data in the new node
    newNode->data = newData;

    //5. Point new node to the node previous node was pointing to
    newNode->next = previousNode->next;

    //6. Point previous node to the new node
    previousNode->next = newNode;
}




template <typename T>
void sllDeleteNode(T findData, SingleList<T>** head){

    //if there is nothing to be delete?
    if(*head == nullptr) return;
    SingleList<T>* currNode = *head;
    SingleList<T>* prevNode = nullptr;

    //searching the node: 1.the node doesnt exist + we found data
    while(currNode != nullptr && currNode->data != findData) {
        prevNode = currNode;
        currNode = currNode->next;
    }

    //if data not found currNode == nullptr in the while loop:
    if(currNode == nullptr) {
        std::cout<<"the data is not found \n"<<std::endl;
        return;
    }

    //if data was found:
    if(prevNode == nullptr){
        *head = currNode->next;
    }else{
        prevNode->next = currNode->next;
    }
    delete currNode;
}

*/