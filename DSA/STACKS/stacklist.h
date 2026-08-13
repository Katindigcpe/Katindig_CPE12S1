#ifndef STACKLIST_H
#define STACKLIST_H

#include <iostream>

template <typename T>
struct Node {
    T data;
    Node<T>* next;
};

// variable templates so head/tail exist per type (C++14+)
template <typename T>
Node<T>* head = nullptr;

template <typename T>
Node<T>* tail = nullptr;

template <typename T>
bool isEmpty() {
    return head<T> == nullptr;
}

template <typename T>
void push(T newData) {
    Node<T>* newNode = new Node<T>;
    newNode->data = newData;
    newNode->next = nullptr;

    if (head<T> == nullptr) {
        head<T> = tail<T> = newNode;
    } else {
        newNode->next = head<T>;
        head<T> = newNode;
    }
}

template <typename T>
T pop() {
    if (isEmpty<T>()) {
        std::cout << "Stack Underflow." << std::endl;
        return T();
    }

    Node<T>* temp = head<T>;
    T tempVal = temp->data;
    head<T> = head<T>->next;
    if (head<T> == nullptr) tail<T> = nullptr;
    delete temp;
    return tempVal;
}

template <typename T>
void Top() {
    if (isEmpty<T>()) {
        std::cout << "Stack is Empty." << std::endl;
        return;
    }
    std::cout << "Top of Stack: " << head<T>->data << std::endl;
}

template <typename T>
void displayAll() {
    if (isEmpty<T>()) {
        std::cout << "The stack is empty." << std::endl;
        return;
    }

    std::cout << "Stack elements (top to bottom): " << std::endl;
    Node<T>* temp = head<T>;
    while (temp != nullptr) {
        std::cout << temp->data << std::endl;
        temp = temp->next;
    }
}

#endif