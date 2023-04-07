#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;

// Define a struct to hold process information
struct Process {
    string name;
    int time_left;
};

int main() {
    // Create a vector of processes
    vector<Process> processes = {
        {"Process 1", 5},
        {"Process 2", 10},
        {"Process 3", 3},
        {"Process 4", 7}
    };
    
    // Define the time quantum in seconds
    int time_quantum = 1;
    
    // Run the scheduler until all processes are complete
    while (!processes.empty()) {
        // Get the next process in the vector
        Process& current_process = processes.front();
        
        // Execute the process for one time quantum
        cout << "Running " << current_process.name << " for " << time_quantum << " second(s)..." << endl;
        this_thread::sleep_for(chrono::seconds(time_quantum));
        current_process.time_left -= time_quantum;
        
        // If the process has completed, print a message and remove it from the vector
        if (current_process.time_left <= 0) {
            cout << "Completed " << current_process.name << "!" << endl << endl;
            processes.erase(processes.begin());
        }
        // If the process still has work to do, move it to the back of the vector
        else {
            cout << current_process.name << " still needs " << current_process.time_left << " second(s) of work. Moving to end of queue." << endl << endl;
            processes.push_back(current_process);
            processes.erase(processes.begin());
        }
    }
    
    // All processes complete
    cout << "All processes have been completed!" << endl;
    
    return 0;
}
