#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int dragon[20005],knight[20005];

int main() {
    int n,m;
    while(cin >> n >> m && n+m!=0){
        for(int i = 0; i < n; i++)
            scanf("%d",&dragon[i]);
        for(int i = 0; i < m; i++)
            scanf("%d",&knight[i]);
        sort(dragon, dragon+n);
        sort(knight, knight+m);
        int i,k = 0, gold = 0;
        for(i = 0; i < n; i++){
            while(k < m && dragon[i] > knight[k]) k++;
            if(k==m) break;
            gold+=knight[k++];
        }
        if(i==n) printf("%d\n",gold);
        else printf("Loowater is doomed!\n");
    }
    return 0;
}
