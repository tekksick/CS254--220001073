#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

struct Item
{
	int weight;
	int value;
};

bool compare(Item a, Item b)
{
	return (double)a.value / a.weight > (double)b.value / b.weight;
}

vector<string> knapsackGreedy(vector<string> &items, vector<int> &weights, vector<int> &values, int weightLimit)
{
	vector<Item> itemList;
	for (int i = 0; i < items.size(); ++i)
	{
		itemList.push_back({weights[i], values[i]});
	}
	sort(itemList.begin(), itemList.end(), compare);

	vector<string> selectedItems;
	int totalWeight = 0, totalValue = 0;
	for (int i = 0; i < items.size(); ++i)
	{
		if (totalWeight + itemList[i].weight <= weightLimit)
		{
			selectedItems.push_back(items[i]);
			totalWeight += itemList[i].weight;
			totalValue += itemList[i].value;
		}
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

	vector<string> selectedItems = knapsackGreedy(items, weights, values, weightLimit);
	cout << "Selected items: ";
	for (string item : selectedItems)
	{
		cout << item << " ";
	}
	cout << endl;

	return 0;
}
