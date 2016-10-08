#include <algorithm>
#include <cstdio>
#include <stack>
#include <iostream>
using namespace std;

long long int grid[105][105];

int main() {
    int t,n,m,b,caso=0;
    cin >> t;
    while(t--){
        cin >> n >> m >> b;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                scanf("%lld",&grid[i][j]);
                if(i>0) grid[i][j] += grid[i-1][j];
            }   

        long long int budget=1e8, subRect, area, areamax = 0, start;
        for(int l = 0; l < n; l++)
            for(int i = l; i < n; i++){
                subRect = 0;
                start = 0;
                for(int j = 0; j < m; j++){
                    subRect += grid[i][j];
                    if(l>0) subRect -= grid[l-1][j];
                    for(; start < j && subRect > b; start++){
                        subRect -= grid[i][start];
                        if(l>0) subRect += grid[l-1][start];
                    }
                    area = (i-l+1)*(j-start+1);
                    if(area > areamax)
                        areamax = area, budget = subRect;
                    else if(area == areamax)
                        budget = min(budget, subRect);
                }
            }
        printf("Case #%d: %lld %lld\n",++caso,areamax, budget);
    }
    return 0;
}
