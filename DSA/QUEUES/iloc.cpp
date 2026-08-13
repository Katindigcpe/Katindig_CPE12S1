#include <iostream>
#include "job.h"
#include "printer.h"

int main(){

    // create the printer object
    Printer officePrinter;
    std::cout << std::endl;

    std::cout << "Simulating multiple users sending print jobs...\n" << std::endl;

    // simulate different users sending jobs to the shared printer
    officePrinter.addJob(Job("Jiro", 5));
    officePrinter.addJob(Job("Luis", 12));
    officePrinter.addJob(Job("Dennise", 3));
    officePrinter.addJob(Job("Anne", 7));
    officePrinter.addJob(Job("Rochelle", 10));

    std::cout << std::endl;
    officePrinter.showStatus();
    std::cout << std::endl;

    std::cout << "Printer will now process the jobs in order (FCFS):\n" << std::endl;
    officePrinter.processAllJobs();

    officePrinter.showStatus();
    std::cout << std::endl;

    // try printing again even though the queue is already empty
    std::cout << "Trying to process another job after the queue is empty:" << std::endl;
    officePrinter.processNextJob();

    std::cout << std::endl;
    std::cout << "Is the printer queue empty now? "
               << (officePrinter.isEmpty() ? "yes" : "no") << std::endl;

    return 0;
}