#include <bits/stdc++.h>
using namespace std;
long long int x, coin[10] = {1,5,10,25,50},n = 5, DP[10][8000];

long long int solve(int id, int sum){
    if(sum == 0)            return 1;
    if(id == n || sum < 0)  return 0;
    long long int &value = DP[id][sum];
    if(value != -1)         return value;
    return value = solve(id+1,sum) + solve(id, sum-coin[id]);
}

int main(){
    memset(DP,-1,sizeof DP);
    for(int i = 0; i <= 7500; i++)
        solve(0,i);
    while(cin >> x){
        printf("%lld\n",solve(0,x));
    }
}
