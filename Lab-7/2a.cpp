//Greedy Approach

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

vector<char> scheduleJobsGreedy(vector<Job> &jobs)
{
	sort(jobs.begin(), jobs.end(), compare);

	vector<char> scheduledJobs;
	vector<bool> slots(jobs.size(), false);

	for (int i = 0; i < jobs.size(); ++i)
	{
		for (int j = min(jobs[i].deadline - 1, (int)jobs.size() - 1); j >= 0; --j)
		{
			if (!slots[j])
			{
				scheduledJobs.push_back(jobs[i].id);
				slots[j] = true;
				break;
			}
		}
	}

	return scheduledJobs;
}

int main()
{
	vector<Job> jobs = {
		{'a', 4, 20},
		{'b', 1, 10},
		{'c', 1, 40},
		{'d', 1, 30}};

	vector<char> scheduledJobs = scheduleJobsGreedy(jobs);

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

	int totalProfit = 0;
	for (char job : scheduledJobs)
	{
		for (const auto &j : jobs)
		{
			if (j.id == job)
			{
				totalProfit += j.profit;
				break;
			}
		}
	}

	cout << "Total profit = " << totalProfit << endl;

	return 0;
}
