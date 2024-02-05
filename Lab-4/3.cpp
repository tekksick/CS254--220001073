#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("input3.txt", "r", stdin);
	freopen("output3.txt", "w", stdout);
	int N, K ;
	cin >> N >> K;
	int arr[N];
	for (int i = 0; i < N;i++)
		cin >> arr[i];
	sort(arr, arr + N);

	int ans = arr[N - K];
	cout <<K<< "th Largest element is "<< ans;
}
