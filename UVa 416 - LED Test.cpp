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

int n;
vector<string> vs;

int main(){
    string digits[10];
    digits[0] = "YYYYYYN";
    digits[1] = "NYYNNNN";
    digits[2] = "YYNYYNY";
    digits[3] = "YYYYNNY";
    digits[4] = "NYYNNYY";
    digits[5] = "YNYYNYY";
    digits[6] = "YNYYYYY";
    digits[7] = "YYYNNNN";
    digits[8] = "YYYYYYY";
    digits[9] = "YYYYNYY";
    while(cin >> n && n){
        string s;
        for(int i = 0; i < n; i++)
            cin >> s, vs.push_back(s);

        bool found = false;
        int j,k;
        for(int i = 9; i >= n-1; i--){
            int malfunction[10] = {};
            for(j = 0; j < n; j++){
                for(k = 0; k < vs[j].size(); k++){
                    if(malfunction[k] && vs[j][k] == 'Y') break;
                    if(vs[j][k] == 'N' && digits[i-j][k] == 'Y') malfunction[k]=1;
                    else if(vs[j][k] == 'Y' && digits[i-j][k] == 'N') break;
                }
                if(k!=7)break;
            }
            if(j==n) found = true;
        }
        if(found) cout << "MATCH" << endl;
        else cout << "MISMATCH" << endl;
        vs.clear();
    }
}
