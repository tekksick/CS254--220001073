// To design an optimal solution strategy,
// you can use dynamic programming.
// The dynamic programming approach involves creating a 2D array where rows represent items
// and columns represent the weight capacity.
// By considering each item and each possible weight capacity,
// you can fill the array to find the maximum value achievable
// while staying within the weight limit.
// Once the array is filled, backtracking can be used to determine which items were included in the optimal solution.
// This approach guarantees the optimal solution for the knapsack problem.

#include <iostream>
#include <vector>

using namespace std;

vector<string> knapsackDynamic(vector<string> &items, vector<int> &weights, vector<int> &values, int weightLimit)
{
	int n = items.size();
	vector<vector<int>> dp(n + 1, vector<int>(weightLimit + 1, 0));
	vector<vector<bool>> keep(n + 1, vector<bool>(weightLimit + 1, false));
	int totalValue = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int w = 1; w <= weightLimit; ++w)
		{
			if (weights[i - 1] <= w)
			{
				int take = values[i - 1] + dp[i - 1][w - weights[i - 1]];
				int skip = dp[i - 1][w];
				dp[i][w] = max(take, skip);
				keep[i][w] = (take > skip);
			}
			else
			{
				dp[i][w] = dp[i - 1][w];
			}
		}
	}

	vector<string> selectedItems;
	int i = n, w = weightLimit;
	while (i > 0 && w > 0)
	{
		if (keep[i][w])
		{
			selectedItems.push_back(items[i - 1]);
			w -= weights[i - 1];
			totalValue += values[i - 1];
		}
		--i;
	}
	cout << "Total value: " << totalValue << endl;
	return selectedItems;
}

int main()
{
	vector<string> items = {"i1", "i2", "i3", "i4", "i5"};
	vector<int> weights = {2, 5, 7, 3, 1};
	vector<int> values = {10, 20, 15, 7, 5};
	int weightLimit = 10;

	vector<string> selectedItems = knapsackDynamic(items, weights, values, weightLimit);
	cout << "Selected items: ";
	for (string item : selectedItems)
	{
		cout << item << " ";
	}
	cout << endl;

	return 0;
}

// This code uses dynamic programming to find the optimal solution for the knapsack problem.
// It fills a 2D array dp where dp[i][w] represents the maximum value that can be achieved
// using the first i items and a weight capacity of w.
// The keep array is used to keep track of which items were included in the optimal solution.
// Finally, backtracking is performed to determine the selected items.