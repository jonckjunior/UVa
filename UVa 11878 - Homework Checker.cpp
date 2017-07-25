#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    char a[50],b[50],c[50],sinal;
    int res = 0;
    while(getline(cin,s)){
        sscanf(s.c_str(), "%[^+-]%c%[^=]%*c%s", a, &sinal,b,c);
        int na = atoi(a), nb = atoi(b), nc;
        if(strcmp(c,"?") == 0) nc = -1e9;
        else         nc = atoi(c);
        if(sinal == '+' && na+nb == nc) res++;
        if(sinal == '-' && na-nb == nc) res++;
    }
    printf("%d\n",res);
    return 0;
}
