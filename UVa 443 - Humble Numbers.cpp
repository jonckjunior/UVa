#include <bits/stdc++.h>
#define bit(i) (1<<(i))
using namespace std;

typedef vector<long long int> vi;
vi v;

void start(){
    v.push_back(0);
    v.push_back(1);
    while(v.size() < 5900){
        long long int s = 4e9;
        long long int mx = v.back();
        for(int i = 1; i < v.size(); i++){
            long long int u = v[i];
            if(u*2 > mx && u*2 < s) s = u*2;
            if(u*3 > mx && u*3 < s) s = u*3;
            if(u*5 > mx && u*5 < s) s = u*5;
            if(u*7 > mx && u*7 < s) s = u*7;
        }
        v.push_back(s);
    }
}

int main(){
    int n;
    start();
    while(cin >> n && n){
        int t = n%100;
        if(t == 0 || t%10 == 0) printf("The %dth humble number is %lld.\n",n,v[n]);
        else if(t >= 4 && t <= 19) printf("The %dth humble number is %lld.\n",n,v[n]);
        else if(t%10 == 1) printf("The %dst humble number is %lld.\n",n,v[n]);
        else if(t%10 == 2) printf("The %dnd humble number is %lld.\n",n,v[n]);
        else if(t%10 == 3) printf("The %drd humble number is %lld.\n",n,v[n]);
        else if(t%10 >= 4 && t%10 <= 9) printf("The %dth humble number is %lld.\n",n,v[n]);
    }
    
    return 0;
}
