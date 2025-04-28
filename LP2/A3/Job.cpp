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
    // id, processing_time, profit, deadline
    vector<Job> jobs = {{1, 5, 20, 2}, {2, 2, 10, 1}, {3, 3, 15, 3}, {4, 2, 40, 3}};

    pair<int, vector<Job>> result = greedyJobScheduling(jobs);

    cout << "Total profit earned: " << result.first << endl;
    cout << "Scheduled jobs: \n";
    for (Job &job : result.second)
    {
        cout << "Job ID: " << job.id << ", Processing time: " << job.processing_time
             << ", Profit: " << job.profit << ", Deadline: " << job.deadline << endl;
    }

    return 0;
}
