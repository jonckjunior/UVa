#include <bits/stdc++.h>

using namespace std;

long long int MEMO[1000005];

long long int solve(long long int x){
    if(x == 0)        return 1;
    if(MEMO[x] != -1) return MEMO[x];
    else              return MEMO[x] = (solve(x - sqrt(x))%1000000 + solve(log(x))%1000000 + solve(x*pow(sin(x),2))%1000000)%1000000;
}

int main(){
    long long int x;
    ios::sync_with_stdio(false);
    memset(MEMO, -1, sizeof MEMO);
    while(cin >> x && x >= 0)
        cout << solve(x) << endl;
    return 0;
}
