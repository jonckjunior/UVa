#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int morning[105],evening[105];

int main() {
    int n,d,r;
    while(cin >> n >> d >> r && n + d + r != 0){
        for(int i = 0; i < n;i++)
            scanf("%d",&morning[i]);
        for(int i = 0; i < n;i++)
            scanf("%d",&evening[i]);
        sort(morning, morning+n);
        sort(evening, evening+n);
        int sum = 0;
        for(int i = 0; i < n; i++)
            if(morning[i] + evening[n-i-1] > d) sum+= (morning[i] + evening[n-i-1] - d);
        cout << sum*r << endl;

    }
    return 0;
}
