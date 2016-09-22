#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include <map>
#include <queue>
#define BRANCO 1
#define PRETO 2
#define MISTO 3
#define INF 1e9
#define NINF -1e9
#define CTOI(c) c-'a'+1
#define MAXIMO 100
#define bit(i) (1<<i)
using namespace std;
typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector< ii > vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef pair<int,vvi> ivvi;

int n,m,t_max;
bool found;
int k;
vector<char> vc;

void backtrack(int i, map<string,bool> &used){
    if(found) return;
    if(k == t_max){found = true;return;}
    string s = "";
    for(int j = i+1; j < vc.size(); j++)
        s+=vc[j];
    for(int j = 0; j < n  && !found; j++){
        string aux = s;
        aux+=(j + '0');
        //cout << aux << " ja foi usada" << endl;
        if(!used[aux]){
            used[aux] = true;
            vc.push_back((j + '0'));
            k++;
            backtrack(i+1,used);
            if(found) break;
            k--;
            vc.pop_back();
            used[aux] = false;
        }
    }
    if(found) return;
}
int main(){
    while(scanf("%d %d",&m,&n) != EOF){
        vc.clear();
        t_max = pow(n,m);
        k = 1;
        found = false;
        string s = "";
        for(int i = 0; i < m; i++)
            vc.push_back('0'),s+="0";
        map<string,bool> used;
        used[s] = true;
        backtrack(0,used);
        for(int i = 0; i < vc.size() - m + 1; i++)
            cout << vc[i];
        cout << endl;
    }
}

