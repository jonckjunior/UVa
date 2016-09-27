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

vector<string> g1,g2;
vector<char> vc;
int k, comb;
bool found;

bool isValid(int i, char c){
    for(int a = 0; a < 6; a++)
        if(g2[a][i] == c) return true;
    return false;
}

void backtrack(int i, map<string,bool> &used, string s){
    if(i >= 5 && !found){
        if(used[s]) return;
        used[s] = true;
        comb++;
        if(comb == k){
            cout << s << endl;
            found = true;
        }
        return;
    }
    for(int a = 0; a < 6 && !found; a++)
        if(isValid(i,g1[a][i])){
            res[i] = g1[a][i];
            backtrack(i+1,used,s+g1[a][i]);
        }
}

int main(){
    int t;
    cin >> t;
    string s;
    while(t--){
        cin >> k;
        map<string,bool> used;
        for(int i = 0; i < 6; i++)
            cin >> s,g1.push_back(s);
        for(int i = 0; i < 6; i++)
            cin >> s,g2.push_back(s);

        for(int i = 0; i < 5; i++){
            string strz="";
            for(int j = 0; j < 6; j++)
                strz+=g1[j][i];
            sort(strz.begin(),strz.end(),func);
            for(int j = 0; j < 6; j++)
                g1[j][i] = strz[j];
        }
        comb = 0;
        found = false;
        string strz="";
        backtrack(0,used,strz);
        if(!found)
            cout << "NO" << endl;
        vc.clear();
        g1.clear();
        g2.clear();
    }
}
