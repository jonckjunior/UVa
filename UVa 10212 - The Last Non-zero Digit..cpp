#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll const p = 1000000000;

int solve(int n, int m){
    ll res = 1;
    for(ll i = n; i >= n-m+1; i--){
        res = (( (res%p) * (i%p)));
        while(res%10 == 0 && res > 0) res/=10;
    }
    string s_res = to_string(res);
    reverse(s_res.begin(), s_res.end());
    for(int i = 0; i < s_res.size(); i++)
        if(s_res[i] != '0') return (s_res[i]-'0');
}

int main() {
    int n,m;
    while(scanf("%d %d",&n,&m) != EOF)
        printf("%d\n",solve(n,m));
    return 0;
}
