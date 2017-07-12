#include <bits/stdc++.h>

using namespace std;
int const maxn = 10000;
vector<int> prime;
int p[maxn];

int main(){
    int n;
    for(int i = 0; i < maxn; i++) p[i] = 1;
    p[0] = p[1] = 0;
    for(int i = 2; i < maxn; i++) if(p[i]){
        prime.push_back(i);
        for(int j = i; j < maxn; j += i)
            p[j] = 0;
    }
    while(scanf("%d",&n) && n!=0){
        int way = 0, root = sqrt(n);
        int last = 0, sum = 0;
        for(int i = 0; i < prime.size(); i++){
            int value = prime[i];
            sum += value;
            if(sum >= n){
                while(sum > n) sum -= prime[last++];
                if(sum == n) way++;
            }
        }
        printf("%d\n",way);
    }
    return 0;
}
