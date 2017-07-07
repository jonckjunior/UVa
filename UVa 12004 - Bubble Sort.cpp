#include <bits/stdc++.h>

using namespace std;

int main(){
    int t,caso=0;
    long long int n;
    cin >> t;
    while(t--){
        cin >> n;
        long long int res = n*n - n;
        printf("Case %d: ",++caso);
        if(4*(res/4) == res){
        	res = n*(n-1)/4.0;
        	printf("%lld\n",res);
        }
        else
        	printf("%lld/%d\n",res/2,2);
	}
}
