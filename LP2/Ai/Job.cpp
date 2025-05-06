#include <bits/stdc++.h>

using namespace std;

struct Job
{
    int id; 
    int processing_time;
    int profit;
    int deadline;
};

// Comparison function to sort jobs by deadline, and by profit if deadlines are equal
bool compareJobs(const Job &job1, const Job &job2)
{
    if (job1.deadline == job2.deadline)
        return job1.profit > job2.profit;
    return job1.deadline < job2.deadline;
}

pair<int, vector<Job>> greedyJobScheduling(vector<Job> &jobs)
{
    sort(jobs.begin(), jobs.end(), compareJobs);

    int current_time = 0;
    vector<Job> scheduled_jobs;
    int total_profit = 0;

    for (Job &job : jobs)
    {
        if (current_time + job.processing_time <= job.deadline)
        {
            // Schedule the job if it doesn't violate the deadline
            current_time += job.processing_time;
            scheduled_jobs.push_back(job);
            total_profit += job.profit;
        }
    }

    return make_pair(total_profit, scheduled_jobs);
}
int main()
{
    // Test Case 1: Basic test case
    vector<Job> jobs1 = {{1, 5, 20, 2}, {2, 2, 10, 1}, {3, 3, 15, 3}, {4, 2, 40, 3}};
    pair<int, vector<Job>> result1 = greedyJobScheduling(jobs1);
    cout << "Test Case 1:\n";
    cout << "Total profit earned: " << result1.first << endl;
    cout << "Scheduled jobs: \n";
    for (Job &job : result1.second)
    {
        cout << "Job ID: " << job.id << ", Processing time: " << job.processing_time
             << ", Profit: " << job.profit << ", Deadline: " << job.deadline << endl;
    }
    cout << endl;

    // Test Case 2: Jobs with overlapping deadlines
    vector<Job> jobs2 = {{1, 2, 50, 2}, {2, 1, 60, 2}, {3, 2, 30, 2}, {4, 1, 40, 2}};
    pair<int, vector<Job>> result2 = greedyJobScheduling(jobs2);
    cout << "Test Case 2:\n";
    cout << "Total profit earned: " << result2.first << endl;
    cout << "Scheduled jobs: \n";
    for (Job &job : result2.second)
    {
        cout << "Job ID: " << job.id << ", Processing time: " << job.processing_time
             << ", Profit: " << job.profit << ", Deadline: " << job.deadline << endl;
    }
    cout << endl;

    // Test Case 3: Jobs with zero profit
    vector<Job> jobs3 = {{1, 2, 0, 2}, {2, 1, 0, 1}, {3, 3, 0, 3}, {4, 2, 0, 3}};
    pair<int, vector<Job>> result3 = greedyJobScheduling(jobs3);
    cout << "Test Case 3:\n";
    cout << "Total profit earned: " << result3.first << endl;
    cout << "Scheduled jobs: \n";
    for (Job &job : result3.second)
    {
        cout << "Job ID: " << job.id << ", Processing time: " << job.processing_time
             << ", Profit: " << job.profit << ", Deadline: " << job.deadline << endl;
    }
    cout << endl;

    // Test Case 4: Jobs that cannot be scheduled due to tight deadlines
    vector<Job> jobs4 = {{1, 5, 50, 2}, {2, 6, 60, 3}, {3, 7, 70, 4}};
    pair<int, vector<Job>> result4 = greedyJobScheduling(jobs4);
    cout << "Test Case 4:\n";
    cout << "Total profit earned: " << result4.first << endl;
    cout << "Scheduled jobs: \n";
    for (Job &job : result4.second)
    {
        cout << "Job ID: " << job.id << ", Processing time: " << job.processing_time
             << ", Profit: " << job.profit << ", Deadline: " << job.deadline << endl;
    }
    cout << endl;

    // Test Case 5: Single job
    vector<Job> jobs5 = {{1, 2, 100, 5}};
    pair<int, vector<Job>> result5 = greedyJobScheduling(jobs5);
    cout << "Test Case 5:\n";
    cout << "Total profit earned: " << result5.first << endl;
    cout << "Scheduled jobs: \n";
    for (Job &job : result5.second)
    {
        cout << "Job ID: " << job.id << ", Processing time: " << job.processing_time
             << ", Profit: " << job.profit << ", Deadline: " << job.deadline << endl;
    }
    cout << endl;

    return 0;
}
