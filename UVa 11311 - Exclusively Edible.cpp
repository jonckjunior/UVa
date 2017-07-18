#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

int n,m,a,b;

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m >> a >> b;
        int left, right, below, above;
        left = b;
        right = m - b - 1;
        below = n - a - 1;
        above = a;
        int res = 0;
        res ^= left;
        res^=right;
        res^=below;
        res^=above;
        if(res != 0) printf("Gretel\n");
        else         printf("Hansel\n");

    }
    return 0;
}
