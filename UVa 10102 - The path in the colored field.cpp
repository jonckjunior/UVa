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


int main() {
    int n;
    string s;
    char c;
    while(scanf("%d",&n) != EOF){
        getline(cin,s);
        vector<ii> one;
        vector<ii> three;
        for(int i =0 ; i < n; i++){
            for(int j = 0; j < n; j++){
                scanf("%c",&c);
                if(c == '1') one.push_back(ii(i,j));
                if(c == '3') three.push_back(ii(i,j));
            }
            getline(cin,s);
        }
        int maxi = -1e9;
        for(int i = 0; i < one.size(); i++){
            int dist = 1e9;
            ii u = one[i];
            for(int j = 0; j < three.size(); j++){
                ii v = three[j];
                dist = min(dist,abs(u.first - v.first) + abs(u.second - v.second));
            }   
            maxi = max(maxi, dist);
        }
        cout << maxi << endl;
    }
}
