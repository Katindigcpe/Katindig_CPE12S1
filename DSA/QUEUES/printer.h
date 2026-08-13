#ifndef PRINTER_H
#define PRINTER_H

#include <iostream>
#include <iomanip>
#include "job.h"

// class Printer: manages a queue of Jobs using a linked list (no STL)
class Printer {
    private:
        // node struct used internally to build the queue
        struct JobNode {
            Job data;
            JobNode* next;
        };

        JobNode* front;
        JobNode* back;

        int trackingID;   // auto increments every time a job is added
        int jobsLeft;      // how many jobs are still pending

        // small helper just to print a divider line
        void printDivider(char symbol = '-'){
            std::cout << std::string(50, symbol) << std::endl;
        }

    public:
        // constructor
        Printer() : front(nullptr), back(nullptr), trackingID(0), jobsLeft(0) {
            printDivider('=');
            std::cout << " PRINTER READY " << std::endl;
            printDivider('=');
        }

        // destructor, clears any remaining nodes so nothing leaks
        ~Printer(){
            while(front != nullptr){
                JobNode* temp = front;
                front = front->next;
                delete temp;
            }
            printDivider('=');
            std::cout << " PRINTER SHUT DOWN " << std::endl;
            printDivider('=');
        }

        // enqueue: add a new job to the back of the queue, ID is auto assigned
        void addJob(Job newJob){
            newJob.id = ++trackingID;

            JobNode* newNode = new JobNode;
            newNode->data = newJob;
            newNode->next = nullptr;

            if(front == nullptr){
                front = newNode;
                back = newNode;
            } else {
                back->next = newNode;
                back = newNode;
            }
            jobsLeft++;

            std::cout << "[QUEUED] Job #" << newJob.id << "  |  User: " << std::left << std::setw(10) << newJob.userName
                       << "|  Pages: " << newJob.numPages << std::endl;
        }

        // dequeue: process the job currently at the front (first come, first served)
        void processNextJob(){
            if(front == nullptr){
                std::cout << ">> No jobs left to print, printer is idle." << std::endl;
                return;
            }

            JobNode* temp = front;
            printDivider();
            std::cout << " PRINTING JOB #" << temp->data.id << std::endl;
            std::cout << "   User : " << temp->data.userName << std::endl;
            std::cout << "   Pages: " << temp->data.numPages << std::endl;
            printDivider();

            front = front->next;
            if(front == nullptr){
                back = nullptr;
            }

            delete temp;
            jobsLeft--;
            std::cout << ">> Job completed.\n" << std::endl;
        }

        // process every pending job in order
        void processAllJobs(){
            if(front == nullptr){
                std::cout << ">> No jobs in queue." << std::endl;
                return;
            }
            while(front != nullptr){
                processNextJob();
            }
        }

        // check if there are no pending jobs
        bool isEmpty(){
            return front == nullptr;
        }

        // print a quick status line, how many jobs are waiting
        void showStatus(){
            printDivider('*');
            std::cout << " STATUS: " << jobsLeft << " job(s) currently in queue" << std::endl;
            printDivider('*');
        }
};

#endif