#ifndef QUEUEARR_H
#define QUEUEARR_H
#include <iostream>

//array based circular queue
template <typename T>
class queueArr{
        private:
        //pointer to dynamically allocate array
        T* q_array;
        //maximum number of elements a queue can hold
        size_t q_capacity;
        //current number of the elements in the queue
        size_t q_size;
        //index of the front elemet
        int q_front;
        //index of the rear element
        int q_back;
    public:
        //constructor
        queueArr(size_t capacity = 10);
        //copy constructor
        queueArr(const queueArr& other);
        //copy assignment operator
        queueArr& operator=(const queueArr& other);
        //destructor
        ~queueArr();
        //queue operations: 
        bool Empty();
        bool Full();
        size_t Size();
        void Clear();
        T front();
        T back();
        void enqueue(T value);
        T dequeue();
};
//Constructor 
template <typename T>
queueArr<T>::queueArr(size_t capacity){
    //set capacity
    q_capacity = capacity;
    //allocated the array
    q_array = new T[q_capacity];
    q_front = 0;
    q_back = -1;
    q_size = 0;
}
//Destructor
template<typename T>
queueArr<T>::~queueArr(){
    delete[] q_array;
}

//Empty
template <typename T>
bool queueArr<T>::Empty(){
    return q_size == 0;
}
 
//Full
template <typename T>
bool queueArr<T>::Full(){
    return q_size == q_capacity;
}

//Size
template <typename T>
size_t queueArr<T>::Size(){
    return q_size;
}

//Front
template <typename T>
T queueArr<T>::front(){
    //check if the queue is empty
    if(Empty()){
        std::cout<<"Queue is empty.\n";
        return T();
    }
    //return
    return q_array[q_front];
}

//Back
template <typename T>
T queueArr<T>::back(){
    //Check if the queue is empty
    if(Empty()){
        std::cout<<"Queue is empty"<<std::endl;
        return T();
    }
    //return 
    return q_array[q_back];
}

//Clear
template <typename T>
void queueArr<T>::Clear(){
    //reset the q_size, q_front, q_back;
    q_front = 0;
    q_back = -1;
    q_size = 0;
}

//Enqueue 
template <typename T>
void queueArr<T>::enqueue(T value){
    //check if the queue is full
    if(Full()){
        std::cout<<"Queue is full."<<std::endl;
        return;
    }
    //move q_back circularly
    q_back = (q_back + 1) % q_capacity;
    //store the value to the back
    q_array[q_back] = value;
    //increment the q_size
    q_size++;
}

//Dequeue
template <typename T>
T queueArr<T>::dequeue(){
    //check if the queue is empty
    if(Empty()){
        std::cout<<"Queue is empty."<<std::endl;
        return T();
    }
    //create a temporary variable to store the current front
    T temp = q_array[q_front];
    ///move q_front circularly
    q_front = (q_front + 1) % q_capacity;
    //decrement the q_size
    q_size--;
    //reset the indexes if the queue become empty:
    if(Empty()){
        q_front = 0;
        q_back = -1;
    }
    //return temporary variable
    return temp;
}
#endif

