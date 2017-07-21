#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll const p = 131071;

ll Pow(ll x, ll y, ll p) {
    if(y == 0)
        return 1;
    if(y&1)
        return ((x%p)*Pow(((x%p)*(x%p)), y/2, p))%p;
    else
        return Pow(((x%p)*(x%p)), y/2, p)%p;
}

bool solve(string s){
    ll res = 0;
    s.pop_back();
    reverse(s.begin(), s.end());
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '1')
            res += Pow(2,i,p);
    }
    res = res%p;
    return res == 0;
}

int main() {
    string s, final;
    while(getline(cin, s)){
        final += s;
        if(s[s.size()-1] == '#'){
            if(solve(final)) printf("YES\n");
            else         printf("NO\n");
            final = "";
        }
    }
    return 0;
}
