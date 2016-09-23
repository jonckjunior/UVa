#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string.h>
using namespace std;
typedef pair<int,int> ii;
int ca,cb,ct;
bool found;
vector<string> vs;
int k = 10;
int used[1001][1001];

void backtrack(int cap_a, int cap_b){
    if(found) return;
    //printf("---INFINITE---\n");
    //printf("(%d,%d)\n",cap_a,cap_b );
    used[cap_a][cap_b] = 1;
    //cout << vs.size() << endl;
    if(cap_a == ct || cap_b == ct){
        for(int i = 0 ; i < vs.size(); i++)
            cout << vs[i] << endl;
        cout << "success" << endl;
        found = true;
        return;
    }
    if(!used[ca][cap_b]){vs.push_back("fill A");backtrack(ca,cap_b);vs.pop_back();}
    if(!used[cap_a][cb]){vs.push_back("fill B");backtrack(cap_a,cb);vs.pop_back();}
    if(!used[0][cap_b]){vs.push_back("empty A");backtrack(0,cap_b);vs.pop_back();}
    if(!used[cap_a][0]){vs.push_back("empty A");backtrack(cap_a,0);vs.pop_back();}


    //pour A B
    if(cap_a + cap_b > cb && !used[cap_a+cap_b-cb][cb]){vs.push_back("pour A B");backtrack(cap_a+cap_b-cb,cb);vs.pop_back();}
    else if(cap_a + cap_b <= cb && !used[0][cap_a+cap_b]){vs.push_back("pour A B");backtrack(0,cap_a+cap_b);vs.pop_back();}
    //pour B A
    if(cap_a + cap_b > ca && !used[ca][cap_a+cap_b-ca]){vs.push_back("pour B A");backtrack(ca,cap_a+cap_b-ca);vs.pop_back();}
    else if(cap_a + cap_b <= ca && !used[cap_a + cap_b][0]){vs.push_back("pour B A");backtrack(cap_a + cap_b,0);vs.pop_back();}
}

int main(){
    while(scanf("%d %d %d",&ca,&cb,&ct) != EOF){
        found = false;
        vs.clear();
        memset(used,0,sizeof used);
        backtrack(0,0);
    }
}

