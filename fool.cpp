#include <bits/stdc++.h>

using namespace std;

string s;

bool sett(int i, int j);
bool listt(int i, int j);
bool elementt(int i, int j);
int dp[250][250];

bool sett(int i, int j){
    if(s[i] != '{') return false;
    if(s[j] != '}') return false;
    if(i+1 == j) return true;
    return listt(i+1,j-1);
}

bool listt(int i, int j){
    if(dp[i][j] == 1) return true;
    if(dp[i][j] == 0) return false;
    if(i == j) return dp[i][j] = 1;
    if(elementt(i,j)) return dp[i][j] = 1;
    for(int k = i+1; k < j; k++){
        if(s[k] != ',') continue;
        if(elementt(i,k-1) && listt(k+1,j))
            return dp[i][j] = 1;
    }
    return dp[i][j] = 0;
}

bool elementt(int i, int j){
    if(i == j) return true;
    return sett(i,j);
}

int main(){
    int t,caso=0;
    cin >> t;
    getchar();
    while(t--){
        getline(cin, s);
        memset(dp,-1,sizeof dp);
        for(int i = 0; i < 250; i++) dp[i][i] = 1;
        bool res = sett(0,s.size()-1);
        if(res) printf("Word #%d: Set\n",++caso);
        else    printf("Word #%d: No Set\n",++caso);
    }
}
