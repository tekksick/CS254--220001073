#include <iostream>
using namespace std;

long long f1(int n,int m) {
	if(n<=m)     
		return n * n;
	else
		return -1 * n * n;
}

long long f2(int n,int m)
{
	int e = 2.3;
	long long ans = 1;
	for (int i = 0; i < n;i++){
		ans *= e;
	}
	if(n<=m)
		return ans;
	else
		return -1 * ans;
}

long long f(int choice,int n) {
	if(choice==1)
		return f1(n);
	else
		return f2(n);
}

int max_val(int l, int r,int choice)
{
	if (f(choice,INT_MAX) > f(choice,INT_MAX - 1))
		cout << "Cannot be calculated by a computer, as the peak exceeds max integer limit of computer" << endl;
	else{
		if (l == r)
			return f(choice,l);

		int mid = (l + r) / 2;

		if (f(choice,mid) < f(choice,mid+1) && mid + 1 <= r)
		{
			l = mid + 1;
			max_val(l, r, choice);
		}
		else if (f(choice,mid) < f(choice,mid-1) && mid - 1 >= l)
		{
			r = mid - 1;
			max_val(l, r, choice);
		}
		else
			return f(choice,mid);
	}
}

int main()
{
	freopen("input_2.txt", "r", stdin);
	freopen("output_2.txt", "w", stdout);
	int t; // testcases
	cin >> t;
	while (t--)
	{
		int choice;
		cin >> choice;
		cout << max_val(1, 	INT_MAX, choice) << endl;
	}
}
//TC: o(log n) --binary search
//SC: o(1)