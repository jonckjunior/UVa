#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

long long int grid[105][105];

int main() {
    int t, caso = 0;
    cin >> t;
    while(t--){
        int n,m,b;
        cin >> n >> m >> b;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                scanf("%lld",&grid[i][j]);
                if(i > 0) grid[i][j] += grid[i-1][j];
                if(j > 0) grid[i][j] += grid[i][j-1];
                if(i > 0 && j >0) grid[i][j] -= grid[i-1][j-1];
            }
        long long int subRec,area, maxArea = 0, budget = 0;
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
        for(int k = i; k < n; k++) for(int l = j; l < m; l++){
            subRec = grid[k][l];
            if(i > 0) subRec -= grid[i-1][l];
            if(j > 0) subRec -= grid[k][j-1];
            if(i > 0 && j >0) subRec += grid[i-1][j-1];
            if(subRec > b) break;
            area = (k-i+1)*(l-j+1);
            if(area > maxArea){
                maxArea = area;
                budget = subRec;
            }
            else if(area == maxArea && subRec < budget) budget = subRec;
        }
        printf("Case #%d: %lld %lld\n",++caso,maxArea,budget);
    }
    return 0;
}
