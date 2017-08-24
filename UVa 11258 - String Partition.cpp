#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int len;
ll dp[300];
ll maxint = (1LL << 31LL) - 1;
string s;
ll solve(int pos){
  if(pos >= len) return 0;
  if(dp[pos] != -1) return dp[pos];
  ll res = 0;
  string res_s;
  for(int i = 10; i > 0; i--){
    string aux = s.substr(pos, i);
    ll v = stoll(aux);
    if(v < maxint){
      ll x = solve(pos+i) + v;
      if(x > res) res = x, res_s = aux;
    }
    else{
      aux.pop_back();
      v = stoll(aux);
      ll x = v + solve(pos+i-1);
      if(x > res) res = x, res_s = aux;
    }
    //if(pos+i > s.size()) break;
  }
  // printf("para pos %d com res = %lld aux = %s\n",pos,res,res_s.c_str());
  return dp[pos] = res;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    memset(dp, -1, sizeof dp);
    cin >> s;
    len = s.size();
    //solve(0);
    cout << solve(0) << endl;
  }
  return 0;
}
