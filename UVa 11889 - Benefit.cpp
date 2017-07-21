#include <bits/stdc++.h>
#include <bitset>
#include <iterator>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int const maxn = 100000;
vi p;
bitset<maxn+5> bt;
void sieve(){
    bt.set();
    bt[0] = bt[1] = 0;
    p.push_back(2);
    int root = sqrt(maxn);
    for(int i = 4; i <= maxn; i += 2) bt[i] = 0;
    for(int i = 3; i <= root; i += 2) if(bt[i]){
        for(int j = i * i; j <= maxn; j += i)
            bt[j] = 0;
    }
    for(int i = 3; i <= maxn; i += 2)
        if(bt[i])
            p.push_back(i);
}

vii factor(int n){
    int root = (int)sqrt(n);
    vii ans;
    int orig = n;
    for(int i = 0; i < p.size() && p[i] <= root; i++){
        int v = p[i], c = 0;
        while(n%v==0) n/=v,c++;
        if(c)
            ans.push_back(ii(v,c));
    }
    if(n!=1)
        ans.push_back(ii(n,1));    
    return ans;
}

int main() {
    int t,a,c;
    sieve();
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&a,&c);
        vii fct_a = factor(a), fct_c = factor(c);
        vii fct_b;
        bool flag=true;
        for(int i = 0; i < fct_a.size(); i++){
            bool found = false;
            for(int j = 0; j < fct_c.size() && !found; j++)
                if(fct_a[i].first==fct_c[j].first && fct_a[i].second <= fct_c[j].second) found = true;
            if(!found) {flag=false;break;}
        }
        if(flag){
            for(int i = 0; i < fct_c.size(); i++){
                bool found = false;
                int v1 = fct_c[i].first, c1 = fct_c[i].second;
                for(int j = 0; j < fct_a.size(); j++){
                    int v2 = fct_a[j].first, c2 = fct_a[j].second;
                    if(v1 == v2){
                        found=true;
                        if(c1 > c2)
                            fct_b.push_back(ii(v1,c1));
                    }
                }
                if(!found) fct_b.push_back(ii(v1,c1));
            }
            int sum = 1;
            for(int i = 0; i < fct_b.size(); i++)
                sum *= ceil(pow(fct_b[i].first, fct_b[i].second));
            printf("%d\n",sum);
        }
        else
            printf("NO SOLUTION\n");
    }
    return 0;
}
