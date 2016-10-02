#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int street[25000];

int main() {
    int n,m,caso=0;
    cin >> n;
    while(n--){
        cin >> m;
        for(int i = 0; i < m-1; i++)
            scanf("%d",&street[i]);
        int sum = 0,res,first,firstfim,second,len; 
        res = first = firstfim = second = len = -1;
        for(int i = 0; i < m-1; i++){
            sum+=street[i];
            if(sum < 0) sum = 0, first = -1;
            else if(first == -1) first = i;
            if( sum > res || (sum  == res && i-first > len) ){
                firstfim = first;
                res = sum;
                second = i;
                len = second - firstfim;
            }
        }
        if(res <= 0) printf("Route %d has no nice parts\n",++caso);
        else printf("The nicest part of route %d is between stops %d and %d\n",++caso,firstfim+1,second+2);
    }    
}
