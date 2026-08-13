#include <iostream>
#include "singly_ll.h"
#include "doubly_ll.h"

int main(){
    // create a list 'C P E'
    DoubleList<char>* head = CreateNewNode('C');
    DoubleList<char>* second = CreateNewNode('P');
    DoubleList<char>* third = CreateNewNode('E');

    head->next = second;
    second->prev = head;

    second->next = third;   
    third->prev = second;

    //traversal
    std::cout<<"\n\n1. Testing the DLL Traversal"<<std::endl;
    dllTraverse(head);

    //testing the insert at the head
    std::cout<<"\n\n2. Testing the insertion at the head node"<<std::endl;
    dllInsertHead('X', &head);
    dllTraverse(head);

    //testing the insert at the end
    std::cout<<"\n\n3. Testing the insertion at the end"<<std::endl;
    dllInsertEnd('0', head);
    dllTraverse(head);

    //testing of general insert
    std::cout<<"\n\n4. Testing the general insertion"<<std::endl;
    dllGeneralInsert('Y', second);
    dllTraverse(head);
    
    //testing the deleting of node
    std::cout<<"\n\n5. Testing the deleting of node deleting '0' "<<std::endl;
    dllDeleteNode('0', &head);
    dllTraverse(head);

    return 0;

}