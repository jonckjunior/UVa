#include <bits/stdc++.h>

using namespace std;

double solve(int u){
    if(u == 1) return 0.0;
    else return log2(u) + solve(u-1);
}
int dp[20];

int main(){
    int n;
    for(int i = 0; i <= 20; i++) dp[i] = 3;
    for(int i = 1; i <= 20; i++){
        int s = i+1;
        s = pow(2,s+1);
        int res = 0;
        int low,high,mid,sm,sl,sh;
        low = dp[i-1];
        high = 254016+50;
        while(low <= high){
            mid = (low + high)/2;
            sl = ceil(solve(low));
            sm = ceil(solve(mid));
            sh = ceil(solve(high));
            if(sm <= s) res = max(res, mid);
            if(sm > s) high = mid - 1;
            else       low = mid + 1;
        }
        dp[i] = res;
    }
    while(cin >> n && n != 0){
        int s = n-1960;
        cout << dp[s/10] << endl;
    }
}
