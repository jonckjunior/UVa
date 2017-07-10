#include <bits/stdc++.h>

using namespace std;

int Pow(int x, int y) {
    if(y == 0)
        return 1;
    if(y&1)
        return x*Pow(x*x, y/2);
    else
        return Pow(x*x, y/2);
}

int solve(string s){
    int res = 0;
    for(int i = s.size()-1, k = 0; i >= 0; i--, k++){
        int v;
        if(s[i] == 'V') v = 0;
        else if(s[i] == 'U') v = 1;
        else if(s[i] == 'C') v = 2;
        else if(s[i] == 'D') v = 3;
        res += v*Pow(4,k);
    }
    return res;
}

int calc(int n1, int n2, char op){
    if(op == 'L') return n2 *= 4;
    else if(op == 'R') return n2 /= 4;
    else if(op == 'A') return n1+n2;
    else return n2;
}


int main(){
    int t;
    cin >> t;
    printf("COWCULATIONS OUTPUT\n");
    while(t--){
        string s1,s2,final;
        char op1,op2,op3;
        cin >> s1 >> s2;
        cin >> op1 >> op2 >> op3;
        cin >> final;
        int n1 = solve(s1);
        int n2 = solve(s2);
        int res = solve(final);
        n2 = calc(n1,n2,op1);
        n2 = calc(n1,n2,op2);
        n2 = calc(n1,n2,op3);
        if(n2 == res) printf("YES\n");
        else          printf("NO\n");
    }
    printf("END OF OUTPUT\n");
}
