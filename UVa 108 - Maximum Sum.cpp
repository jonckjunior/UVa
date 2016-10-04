#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int m[105][105];

int main() {
    int n;
    cin >> n;
    for(int i =0 ; i < n; i++)
        for(int j = 0; j < n; j++){
            scanf("%d",&m[i][j]);
            if(i > 0) m[i][j] += m[i-1][j];
            if(j > 0) m[i][j] += m[i][j-1];
            if(i > 0 && j > 0) m[i][j] -= m[i-1][j-1];
        }
    int maxSub = -127*100*100;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
    for(int k = i; k < n; k++) for(int l = j; l < n; l++){
        int subRect = m[k][l];
        if(i > 0) subRect -= m[i-1][l];
        if(j > 0) subRect -= m[k][j-1];
        if(i > 0 && j > 0) subRect += m[i-1][j-1];
        maxSub = max(maxSub,subRect);
    }
    cout << maxSub << endl;
}
