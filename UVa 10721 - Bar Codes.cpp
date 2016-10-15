#include <bits/stdc++.h>

long long int n,k,m, DP[55][55][55];

long long int solve(int id, int bar, int len){
    if(len > m || bar > k) return 0;
    if(id == n) return (bar == k);
    long long int &value = DP[id][bar][len];
    if(value != -1) return value;
    return value = solve(id+1,bar,len+1) + solve(id+1,bar+1,1);
}

int main(){
    ios::sync_with_stdio(false);
    while(cin >> n >> k >> m){
        memset(DP, -1, sizeof DP);
        cout << solve(1,1,1) << endl; 
    }
}
 
