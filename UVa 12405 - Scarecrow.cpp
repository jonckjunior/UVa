#include <iostream>
#include <cstdio>
#include <vector>
#define UNVISITED -1
#define BLACK 1
#define WHITE 0
using namespace std;

int n;

char sc[105];
int p[105];

void changesc(int i){
    if(i>0 && sc[i-1] == '.') sc[i-1] = '#';
    if(sc[i] == '.') sc[i] = '#';
    if(i < n-1 && sc[i+1] == '.') sc[i+1] = '#';
}

int main() {
    int t,caso=0;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> sc[i];
        int num = 0;
        for(int i = 0; i < n; i++){
            if(sc[i] != '.') continue;
            num++;
            if(i+1 < n)changesc(i+1);
            else changesc(i);
        }
        printf("Case %d: %d\n",++caso,num);
    }    
    return 0;
}
