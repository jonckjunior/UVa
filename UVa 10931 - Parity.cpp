#include <bits/stdc++.h>

using namespace std;
#define bit(i) (1<<(i))
int main(){
    int n;
    while(scanf("%d",&n) && n!=0){
        int k = 0;
        string s;
        for(int i = 31; i >= 0; i--){
            if(bit(i)&n) k++,s += "1";
            else if(s.size() > 0) s += "0";
        }
        printf("The parity of %s is %d (mod 2).\n",s.c_str(),k);
    }
}
