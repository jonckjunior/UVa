#include <bits/stdc++.h>

using namespace std;

struct state{
    int x, y;
    double res;
    state(){} state(int X, int Y, double R) : x(X), y(Y), res(R){}
};

bool func(state &a, state &b){
    return a.res < b.res;
}

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

vector<state> v;

int main(){
    int n,k;
    while(cin >> n >> k){
        v.clear();
        for(int i = 1; i < n ; i++){
            for(int j = i + 1; j <= n; j++)
                if(gcd(i,j) == 1)
                    v.push_back(state(i,j,i/(double)j));
        }
        sort(v.begin(), v.end(), func);
        v.push_back(state(1,1,1/1));
        printf("%d/%d\n",v[k-1].x,v[k-1].y);
    }
    return 0;
}
