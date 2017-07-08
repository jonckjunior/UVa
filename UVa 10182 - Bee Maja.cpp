#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        if(n == 1){printf("0 0\n");continue;}
        int r = ceil((3+sqrt(9+12*(n-1)))/6)-1;
        int r2 = r + 1;
        int m = 3*(r2*r2-r2) + 1;
        int dif = m-n;
        int x = r, y = 0;
        for(int i = 0; dif && i < r; i++)
            y--,dif--;
        for(int i = 0; dif && i < r; i++)
            x--,dif--;
        for(int i = 0; dif && i < r; i++)
            x--, y++, dif--;
        for(int i = 0; dif && i < r; i++)
            y++, dif--;
        for(int i = 0; dif && i < r; i++)
            x++, dif--;
        for(int i = 0; dif && i < r; i++)
            x++,y--, dif--;
        printf("%d %d\n",x,y);
    }
}
