#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
    ll n;
    while(scanf("%lld",&n), n!=0){
        ll root = sqrt(n);
        if(root*root==n) printf("yes\n");
        else      printf("no\n");
    }
    return 0;
}
