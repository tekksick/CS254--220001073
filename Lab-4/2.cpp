#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("input2.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);
	int m, n;
	cin >> m >> n;
	int a[m], b[n];
	vector<int> c;
	for (int i = 0; i < m; i++)
		cin >> a[i];
	for (int j = 0; j < n; j++)
		cin >> b[j];
	int i = 0, j = 0;
	while (i < m && j < n)
	{
		if (a[i] < b[j])
		{
			c.push_back(a[i]);
			i++;
		}
		else if (a[i] > b[j])
		{
			c.push_back(b[j]);
			j++;
		}
		else
		{
			c.push_back(a[i]);
			i++;
			j++;
		}
	}
	while (i < m)
	{
		c.push_back(a[i]);
		i++;
	}
	while (j < n)
	{
		c.push_back(b[j]);
		j++;
	}
	if ((c.size()) % 2 != 0)
	{
		cout << (double)c[(c.size()) / 2] << endl;
	}
	else
	{
		cout << (double)(c[((c.size()) - 1) / 2] + c[(c.size()) / 2]) / 2.0 << endl;
	}
}