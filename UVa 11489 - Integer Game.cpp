#include <bits/stdc++.h>
using namespace std;

int solveT(string num);
int solveS(string num);

bool valid(string s, int pos){
    int sum = 0;
    for(int i = 0; i < s.size(); i++)
        if(i != pos) sum += s[i]-'0';
    return (sum%3==0);
}

int solve(string num){
    int v = -1;
    for(int i = 0; i < num.size() && v == -1; i++)
        if(valid(num,i)) v = i;
    if(v==-1) return (num.size()%2);
    char c = num[v];
    num.erase(num.begin()+v);
    int parity = 0;
    for(int i = 0; i < num.size(); i++){
        char at = num[i];
        if(at == '3' || at == '6' || at == '9') parity++;
    }
    return (parity%2);
}

int main(){
    int t,caso=0;
    cin >> t;
    while(t--){
        string num;
        cin >> num;
        int res = solve(num);
        printf("Case %d: %c\n",++caso, res == 0? 'S' : 'T');
    }
    return 0;
}
