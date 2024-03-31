// Dynamic Programming approach

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job
{
	char id;
	int deadline;
	int profit;
};

bool compare(Job a, Job b)
{
	return a.profit > b.profit;
}

int scheduleJobsOptimal(vector<Job> &jobs, vector<char> &scheduledJobs)
{
	sort(jobs.begin(), jobs.end(), compare);

	int maxDeadline = 0;
	for (const auto &job : jobs)
	{
		maxDeadline = max(maxDeadline, job.deadline);
	}

	vector<int> slots(maxDeadline, -1);

	int totalProfit = 0;
	for (const auto &job : jobs)
	{
		for (int j = job.deadline - 1; j >= 0; --j)
		{
			if (slots[j] == -1)
			{
				slots[j] = job.profit;
				scheduledJobs.push_back(job.id);
				totalProfit += job.profit;
				break;
			}
		}
	}

	return totalProfit;
}

int main()
{
	vector<Job> jobs = {
		{'a', 4, 20},
		{'b', 1, 10},
		{'c', 1, 40},
		{'d', 1, 30}};

	vector<char> scheduledJobs;
	int totalProfit = scheduleJobsOptimal(jobs, scheduledJobs);

	cout << "Maximum profit sequence of jobs: [";
	for (int i = 0; i < scheduledJobs.size(); ++i)
	{
		cout << scheduledJobs[i];
		if (i < scheduledJobs.size() - 1)
		{
			cout << ", ";
		}
	}
	cout << "]" << endl;

	cout << "Total profit = " << totalProfit << endl;

	return 0;
}
