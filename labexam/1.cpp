#include<iostream>
using namespace std;

//using binary search
int max_val(int l,int r, int a[]) {

	if(l==r)
		return a[l];

	int mid = (l + r) / 2;
	
	if(a[mid] < a[mid+1] && mid+1<=r) {
		l = mid + 1;
		max_val(l, r, a);
	}
	else if (a[mid] < a[mid - 1] && mid-1>=l){
		r = mid - 1;
		max_val(l, r, a);
	}
	else
		return a[mid];
}

int main() {
	freopen("input_1.txt", "r", stdin);
	freopen("output_1.txt", "w", stdout);
	int t;  //testcases
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n;i++)
			cin >> a[i];
		cout<<max_val(0,n-1, a)<<endl;
	}
}

//TC: o(log n) --binary search
//SC: o(1)