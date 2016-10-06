#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

long long int grid[105][105];

int main() {
    int n;
    long long int maxRect = -127*100*100, subRect;
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            scanf("%lld",&grid[i][j]);
            maxRect = max(maxRect, grid[i][j]);
            if(i > 0) grid[i][j] += grid[i-1][j];
        }

    for(int l = 0; l < n; l++)
        for(int i = l; i < n; i++){
            subRect = 0;
            for(int j = 0; j < n; j++){
                subRect += grid[i][j];
                if(l > 0) subRect -= grid[l-1][j];
                if(subRect < 0) subRect = 0;
                maxRect = max(maxRect, subRect);
            }
        }
    cout << maxRect << endl;
    return 0;
}
