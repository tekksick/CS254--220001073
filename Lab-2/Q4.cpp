#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &a, int l , int r){
    int lst = a[r], p = l;
    for(int i = l; i <= r; i++){
        if(a[i] < lst)
            swap(a[i], a[p++]);
    }
    swap(a[r], a[p]);
    return p;
}

int random_partition(vector<int> &a, int l, int r){
    int n = r - l + 1;
    int p = (rand() % n);
    swap(a[l + p], a[r]);
    return partition(a, l, r);
}

void median(vector<int> &a, int l, int r, int k, int &md1, int &md2){
    if(l > r)
        return;
    int par = random_partition(a, l, r);
    if(par == k){
        md2 = a[par];
        if(md1 != -1)
            return;
    }
    else if(par == k-1){
        md1 = a[par];
        if(md2 != -1)
            return;
    }
    if(par >= k)
        median(a, l, par-1, k, md1, md2);
    else
        median(a, par+1, r, k, md1, md2);
}

void find_median(vector<int> &a){
    int md1 = -1, md2 = -1, n = a.size();
    median(a, 0, n-1, n/2, md1, md2);
    if(n%2)
        cout << "Median: " << md2 << endl;
    else
        cout << "Median: " << (md1+md2)/2.0 << endl;
}

int main(){
    freopen("test_cases_Q4.txt","r",stdin);
    freopen("output_Q4.txt","w",stdout);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++)
            cin >> a[i];
        find_median(a);
    }
}