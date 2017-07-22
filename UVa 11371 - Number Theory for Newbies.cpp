#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
	ll n;
	while(scanf("%lld",&n) != EOF){
		string s = to_string(n);
		sort(s.rbegin(), s.rend());
		ll m = stoll(s);
		string ns = "";
		sort(s.begin(), s.end());
		for(int i = 0; i < s.size(); i++){
			if(s[i] != '0') {
				ns += s[i];
				s.erase(s.begin()+i);
				break;
			}
		}
		for(int i = 0; i < s.size(); i++)	
			ns += s[i];
		ll nn = stoll(ns);
		ll ans = m-nn;
		printf("%lld - %lld = %lld = 9 * %lld\n",m,nn,ans,ans/9);
	}    
    return 0;
}
