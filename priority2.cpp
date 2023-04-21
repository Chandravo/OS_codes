// This code is made by Chandravo Bhattacharya
#include <bits/stdc++.h>
using namespace std;

class Process
{
public:
    int pid;          // process id
    int priority;     // priority of the process
    int burst_time;   // burst time of the process
    int burst_copy;   // burst time copy too retain original burst time after decreasing in algo
    int arrival_time; // arrival time of the process
    int start_time;   // start time of the process
    int end_time;     // end time of the process
    int waiting_time; // waiting time of the process
};

class comp
{
public:
    bool operator()(Process &a, Process &b)
    {
        return a.arrival_time < b.arrival_time;
    }
};

// Function to find the process with the highest priority
int findHighestPriority(Process proc[], int n, int time)
{
    int lowest = INT_MAX;
    int lowest_index = -1;
    for (int i = 0; i < n; i++)
    {
        if (proc[i].arrival_time <= time && proc[i].priority < lowest && proc[i].burst_time > 0)
        {
            lowest = proc[i].priority;
            lowest_index = i;
        }
    }
    return lowest_index;
}

// Function to perform pre-emptive priority scheduling
void priorityScheduling(Process proc[], int n)
{
    int time = 0;
    int done = 0;
    while (done != n)
    {
        int lowest_index = findHighestPriority(proc, n, time);
        // if no process available
        if (lowest_index == -1)
        {
            time++;
            continue;
        }
        // if process is just starting, we set the starting time
        if (proc[lowest_index].start_time == -1)
        {
            proc[lowest_index].start_time = time;
        }
        proc[lowest_index].burst_time--;
        time++;

        // burst_time==0, process has ended
        if (proc[lowest_index].burst_time == 0)
        {
            done++;
            // setting the end time
            proc[lowest_index].end_time = time;
            // waiting time = end time - (arrivaltime + cpu burst time)
            proc[lowest_index].waiting_time = proc[lowest_index].end_time - (proc[lowest_index].arrival_time + proc[lowest_index].burst_copy);
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    Process proc[n];

    // Input the process details
    for (int i = 0; i < n; i++)
    {
        proc[i].pid = i + 1;
        cout << "Enter the arrival time, burst time and priority of process " << proc[i].pid << ": ";
        cin >> proc[i].arrival_time >> proc[i].burst_time >> proc[i].priority;
        proc[i].burst_copy = proc[i].burst_time;
        proc[i].start_time = -1;
    }

    // Sort the processes based on their arrival time
    sort(proc, proc + n, comp());

    // call the function to start priority scheduling
    priorityScheduling(proc, n);

    // Print the waiting time for each process
    for (int i = 0; i < n; i++)
    {
        cout << "Waiting time for process " << proc[i].pid << " is " << proc[i].waiting_time << endl;
    }

    cout << "Process    "
         << "Arrival-Time "
         << "   CPU-Time "
         << "   Priority"
         << "   Waiting-time" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "   P" << proc[i].pid << "            " << proc[i].arrival_time << "            " << proc[i].burst_copy << "            " << proc[i].priority << "            " << proc[i].waiting_time << endl;
    }

    return 0;
}
