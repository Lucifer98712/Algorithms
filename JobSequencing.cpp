#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Structure to represent a job
struct Job {
    char id;       // Job ID
    int deadline;  // Deadline of the job
    int profit;    // Profit associated with the job
};

// Comparison function for sorting jobs based on profit in descending order
bool compare(Job a, Job b) {
    return (a.profit > b.profit);
}

// Function to perform job sequencing with deadlines
void jobSequencing(vector<Job>& jobs) {
    // Sort jobs based on profit in descending order
    sort(jobs.begin(), jobs.end(), compare);

    int n = jobs.size();
    vector<char> result(n, '0');  // To store the result (sequence of jobs)

    vector<bool> slot(n, false);  // To check if a slot is occupied

    // Iterate through each job and assign it to the latest available slot before its deadline
    for (int i = 0; i < n; ++i) {
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; --j) {
            if (!slot[j]) {
                result[j] = jobs[i].id;
                slot[j] = true;
                break;
            }
        }
    }

    // Display the result
    cout << "Job Sequence: ";
    for (char jobId : result) {
        cout << jobId << " ";
    }
    cout << endl;

    int totalProfit = 0;
    cout << "Selected Jobs and Their Profits:" << endl;
    for (int i = 0; i < n; ++i) {
        if (result[i] != '0') {
            cout << "Job " << result[i] << " with Profit " << jobs[i].profit << endl;
            totalProfit += jobs[i].profit;
        }
    }
    cout << "Total Profit: " << totalProfit << endl;
}

int main() {
    // Example jobs
    vector<Job> jobs = {
        {'a', 2, 100},
        {'b', 1, 19},
        {'c', 2, 27},
        {'d', 1, 25},
        {'e', 3, 15}
    };

    cout << "Given Jobs:" << endl;
    cout << "Job ID  Deadline  Profit" << endl;
    for (const Job& job : jobs) {
        cout << "   " << job.id << "        " << job.deadline << "         " << job.profit << endl;
    }

    // Perform Job Sequencing
    jobSequencing(jobs);

    return 0;
}
