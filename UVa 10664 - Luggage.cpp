#include <algorithm>
#include <cstdio>
#include <stack>
#include <iostream>
#include <string.h>
#include <vector>
#include <sstream>
#define MAX 300
using namespace std;

vector<int> V;
bool valid;
int soma;

void solve(int id, int w){
    if(w > soma || valid) return;
    if(w == soma) {valid = true;return;}
    if(id == V.size()) return;
    solve(id+1,w);
    if(V[id]+w <= soma)
        solve(id+1,w+V[id]);
}

int main() {
    int t,x;
    string s;
    cin >> t;
    getline(cin,s);
    while(t--){
        V.clear();
        getline(cin,s);
        istringstream iss(s);
        soma = 0;
        while(iss.good()){
            iss >> s;
            x = atoi(s.c_str());
            soma += x;
            V.push_back(x);
        }
        if(soma&1){cout << "NO" << endl;continue;}
        soma/=2;
        valid = false;
        solve(0,0);
        if(valid) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}
