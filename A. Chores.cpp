#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main(){

    int n, k, x; cin >> n >> k >> x;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    for(int i = n-1, cnt = 0; i >= 0 && cnt < k; i--, cnt++)
        v[i] = x;
    int sum = 0;
    for(int val : v)
        sum += val;
    cout << sum << endl;
    return 0;
}
