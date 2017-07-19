#include <bits/stdc++.h>

using namespace std;

int v[50];

int main(){
    int t,caso=0;
    cin >> t;
    while(t--){
        string ss;
        cin >> ss;
        memset(v,0,sizeof v);
        int rep = 0;
        long long int ans = 1;
        for(int i = 0; i < ss.size(); i++){
            ans *= (i+1);
            v[ ss[i]-'A' ]++;
        }
        for(int i = 0; i <= 30; i++)
            if(v[i] > 1){
                long long int ft = 1;
                for(int j = 2; j <= v[i]; j++) ft *= j;
                ans /= ft;
            }
            
        printf("Data set %d: %lld\n",++caso,ans);
    }
    
    return 0;
}
