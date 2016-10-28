#include <bits/stdc++.h>
using namespace std;
long long int x, coin[25],n = 21, DP[25][10005];

long long int solve(int id, int sum){
    if(sum == x)            return 1;
    if(id == n || sum > x)  return 0;
    long long int &value = DP[id][sum];
    if(value != -1)         return value;
    return value = solve(id+1,sum) + solve(id, sum+coin[id]);
}

int main(){
    for(int i = 1; i <= 21; i++)
        coin[i-1] = pow(i,3);
    while(cin >> x){
        memset(DP,-1,sizeof DP);
        printf("%lld\n",solve(0,0));
    }
}
