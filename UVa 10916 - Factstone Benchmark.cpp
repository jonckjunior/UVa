#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, i;
    while(scanf("%d", &n) && n != 0) {
        n = (n-1960)/10+2;
        double m = 1<<n;
        for(i = 1; m > 0; i++)
            m -= log2(i);
        printf("%d\n", i-2);
    }
    return 0;
}
