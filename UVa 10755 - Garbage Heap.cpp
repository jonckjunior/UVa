#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

long long int m[21][21][21];

int main() {
    int t,a,b,c;
    cin >> t;
    while(t--){
        cin >> a >> b >> c;
        for(int i = 0; i < a; i++)
            for(int j = 0; j < b; j++)
                for(int k = 0; k < c; k++){
                    scanf("%lld",&m[i][j][k]);
                    if(i > 0) m[i][j][k] += m[i-1][j][k];
                    if(j > 0) m[i][j][k] += m[i][j-1][k];
                    if(k > 0) m[i][j][k] += m[i][j][k-1];
                    if(i > 0 && j > 0) m[i][j][k] -= m[i-1][j-1][k];
                    if(i > 0 && k > 0) m[i][j][k] -= m[i-1][j][k-1];
                    if(j > 0 && k > 0) m[i][j][k] -= m[i][j-1][k-1];
                    if(i > 0 && j > 0 && k > 0) m[i][j][k] += m[i-1][j-1][k-1];
                }
        long long int maxSub = -9223372036854775807, subRect;
        for(int i = 0; i < a; i++) for(int j = 0; j < b; j++) for(int k = 0; k < c; k++)
        for(int l = i; l < a; l++) for(int q = j; q < b; q++) for(int p = k; p < c; p++){
                    subRect = m[l][q][p];
                    if(i > 0) subRect -= m[i-1][q][p];
                    if(j > 0) subRect -= m[l][j-1][p];
                    if(k > 0) subRect -= m[l][q][k-1];
                    if(i > 0 && j > 0) subRect += m[i-1][j-1][p];
                    if(i > 0 && k > 0) subRect += m[i-1][q][k-1];
                    if(j > 0 && k > 0) subRect += m[l][j-1][k-1];
                    if(i > 0 && j > 0 && k > 0) subRect -= m[i-1][j-1][k-1];
                    maxSub = max(maxSub, subRect);
        }
        cout << maxSub << endl;
        if(t>0) cout << endl;
    }
    return 0;
}
