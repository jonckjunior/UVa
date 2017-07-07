#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while(scanf("%d",&n) && n != 0){
        bitset<32> bt(n);
        int res = bt.count();
        if(res == 1) printf("%d\n",n);
        else{
            for(int i = 31; i >= 0; i--) if((1<<i)&n) {bt[i] = 0;break;}
            bt <<= 1;
            printf("%d\n",bt.to_ulong());
        }
        
    }
}
