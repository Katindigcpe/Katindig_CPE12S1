#ifndef JOB_H
#define JOB_H

#include <string>

// class Job: represents one print job
class Job {
    public:
        int id;
        std::string userName;
        int numPages;

        // default constructor
        Job() : id(0), userName(""), numPages(0) {}

        // parameterized constructor, id gets assigned later by the Printer
        Job(std::string user, int pages)
            : id(0), userName(user), numPages(pages) {}
};

#endif