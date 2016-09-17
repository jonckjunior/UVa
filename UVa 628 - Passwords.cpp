#include <iostream>
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
#define INF 10000001
#define CTOI(c) c-'a'+1
  
using namespace std;
typedef pair<int,int> ii;
typedef vector< ii > vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef pair<int,vvi> ivvi;
int k = 15;
bool back_track(string s, string word, string rule, int pos){
    if(pos >= rule.size()) return true;
    if(rule[pos] == '#'){
        if(back_track(s+word,word,rule,pos+1))
            cout << s+word << endl;
    }
    else{
        for(char num = '0'; num <= '9'; num++){
            if(back_track(s+num,word,rule,pos+1))
                cout << s+num << endl;
            //cout << "num : " << num << endl;
        }
    }
    return false;
}


int main() {
    int n,m;
    string s, rule;
    bool espaco=false;
    printf("--\n");
    while(scanf("%d",&n) != EOF){
        getline(cin,s);
        if(espaco) printf("--\n");
        vector<string> vs,rules;
        for(int i = 0; i < n; i++)
            getline(cin,s),vs.push_back(s);
        scanf("%d",&m);
        getline(cin,s);
        for(int i = 0; i< m; i++)
            getline(cin,s),rules.push_back(s);

        for(int i =0 ; i < vs.size(); i++)
            for(int j = 0; j < rules.size(); j++)
                back_track("",vs[i],rules[j],0);

        espaco = true;
    }
}
