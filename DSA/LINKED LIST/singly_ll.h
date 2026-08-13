#ifndef SINGLY_LL_H
#define SINGLY_LL_H

//node creation
template <typename T>
class SingleList {
    public:
    T data; // this contains the data to be stored in node
    SingleList<T>* next = nullptr; // this contains the address of next node

};

template <typename T>
void ListTraversal(SingleList<T>* head) {

    while(head != nullptr) {
        //print data of n
        std::cout << head->data;

        if(head->next != nullptr) {
            std::cout << " -> ";
        }

        // go to the next node
        head = head->next;
    }

    std::cout << std::endl;

}

template <typename T>
void sllinsert(T newData, SingleList<T>** currenthead) {
    // 1. Allocate memory for new node
    SingleList<T>* newNode = new SingleList<T>;

    // 2. Put in the data
    newNode->data = newData;

    // 3. Set Next of the new node to point to the previous head
    newNode->next = *currenthead;

    // 4. Reset Head to point to the new node
    *currenthead = newNode;

}

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
void sllinsertEnd(T newData, SingleList<T>** head) {
    //1. Allocate a new node
    SingleList<T>* newNode = new SingleList<T>;
    //2. Dereference to the head node
    SingleList<T>* currentNode = *head;
    //3. Store data in new node
    newNode->data = newData;
    newNode->next = nullptr;
    //4. Point to Null

    //5. Traverse the list until next of the node is null
    while(currentNode->next != nullptr){
        currentNode = currentNode->next;
    }

    // 6. Point the next of the current node to the new node
    currentNode->next = newNode;

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

template <typename T>
void sllDeleteList(SingleList<T>** head) {
    SingleList<T>* current = *head;


    while (current != nullptr){
        SingleList<T>* temp = current;
        current = current->next;
        delete temp;

    }

    *head = nullptr;
}

#endif