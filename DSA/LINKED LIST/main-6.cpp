#include <iostream>
#include "singly_ll.h"

int main(){

    //creation of nodes for JIRO
    SingleList<char>* head = nullptr;
    SingleList<char>* second = nullptr;
    SingleList<char>* third = nullptr;
    SingleList<char>* fourth = nullptr;
    SingleList<char>* fifth = nullptr;
    SingleList<char>* sixth = nullptr;
    SingleList<char>* seventh = nullptr;

    //allocate 4 nodes in the heap
    head = new SingleList<char>;
    second = new SingleList<char>;
    third = new SingleList<char>;
    fourth = new SingleList<char>;
    fifth = new SingleList<char>;
    sixth = new SingleList<char>;
    seventh = new SingleList<char>;

    //storing data in nodes
    head->data = 'D';
    second->data = 'E';
    third->data = 'N';
    fourth->data = 'N';
    fifth->data = 'I';
    sixth->data = 'S';
    seventh->data = 'E';

    //linking nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = nullptr;

    std::cout<< "Testing of traversal: \n";
    ListTraversal(head);

    std::cout<< "Testing of sllInsertHead: \n";
    sllinsert('J', &head);
    ListTraversal(head);

    std::cout<< "Testing of sllGeneralInsert: \n";
    sllGeneralInsert('X', head->next->next);
    ListTraversal(head);

    std::cout<< "Testing of sllInsertEnd: \n";
    sllinsertEnd('U', &head);
    ListTraversal(head);

    std::cout<< "Testing of deleting the node: \n";
    sllDeleteNode('U', &head);
    ListTraversal(head);
    sllDeleteNode('Q', &head);
    ListTraversal(head);
    sllDeleteNode('X', &head);
    ListTraversal(head);

    std::cout<<"deleting all nodes \n";
    sllDeleteList(&head);
    ListTraversal(head);

    return 0;
}
