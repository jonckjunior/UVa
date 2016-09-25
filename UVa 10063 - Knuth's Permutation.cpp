#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string.h>
#include <bitset>
#include <algorithm>
using namespace std;
#define bit(i) (1<<i)
#define INF 1e8
#define MIN(a,b) (a) < (b) ? (a) : (b)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

string original;
char last;

void backtrack(vector<char> &s, int u){
    if(u > original.size()) return;
    if(u == original.size()-1){
       // used[s] = true;
        for(int i = 0; i < s.size(); i++)
            cout << s[i];
        cout << endl;
        return;
    }
    for(int i = 0; i < s.size(); i++){
        s.insert(s.begin()+i,original[u+1]);
        backtrack(s,u+1);
        s.erase(s.begin()+i);
    }
    s.push_back(original[u+1]);
    backtrack(s,u+1);
    s.pop_back();
}

int main(){
    bool espaco = false;
    while(cin >> original){
        if(espaco) cout << endl;
        vector<char> vc;
        vc.push_back(original[0]);
        backtrack(vc,0);
        espaco = true;
    }    
    
}

