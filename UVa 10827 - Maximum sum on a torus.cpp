#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

long long int grid[160][160];

int main() {
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i =0 ; i < n;i++) for(int j =0 ; j < n; j++){
            scanf("%lld",&grid[i][j]);
            grid[i][j+n] = grid[i+n][j] = grid[i+n][j+n] = grid[i][j]; 
        }
        for(int i = 0; i < 2*n; i++) for(int j = 0; j < 2*n; j++){
            if(i > 0) grid[i][j] += grid[i - 1][j];
            if(j > 0) grid[i][j] += grid[i][j - 1];
            if(i > 0 && j > 0) grid[i][j] -= grid[i - 1][j - 1];
        }
        long long int maxRect = -100*75*75, subRect;
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
        for(int k = i; k < i+n; k++) for(int l = j; l < j+n; l++){
            subRect = grid[k][l];
            if(i > 0) subRect -= grid[i-1][l];
            if(j > 0) subRect -= grid[k][j-1];
            if(i > 0 && j > 0) subRect += grid[i-1][j-1];
            maxRect = max(maxRect, subRect);
        }
        cout << maxRect << endl;
    }
    return 0;
}
