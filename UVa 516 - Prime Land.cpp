#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int const maxn = 200;
vi p;

void sieve(){
    bitset<maxn+5> bt;
    bt.set();
    bt[0] = bt[1] = 0;
    p.push_back(2);
    for(int i = 4; i <= maxn; i+=2) bt[i] = 0;
    for(int i = 3; i <= maxn; i+=2) if(bt[i]){
        p.push_back(i);
        for(int j = i*i; j <= maxn; j+=i)
            bt[j] = 0;
    }
}

void solve(int n){
    vi ans;
    int root = (int)sqrt(n);
    for(int i = 0; i < p.size() && p[i] <= root; i++){
        int v = p[i], c=0;
        while(n%v == 0) n/=v, c++;
        if(c)
            ans.push_back(c),ans.push_back(v);
    }
    if(n!=1) ans.push_back(1),ans.push_back(n);
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++){
        if(i == ans.size() - 1)
            printf("%d\n",ans[i]);
        else
            printf("%d ",ans[i]);
    }
}


int main(){
    sieve();
    string ss;
    while(getline(cin, ss) && ss != "0"){
        int n = 1;
        istringstream iss(ss);
        int base, num;
        while(iss >> base >> num) n *= ceil(pow(base, num));
        solve(n-1);
    }
    return 0;
}
