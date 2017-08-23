#include <bits/stdc++.h>

using namespace std;

#define VERTICAL 1
#define HORIZONTAL 2
#define MATCH 3
#define REPLACE 4

int dp[100][100], res[100][100];
vector<string> vs;

int solve(string a, string b){
    memset(dp, 0, sizeof dp);
    int n = a.size(), m = b.size();
    for(int i = 0; i <= n; i++) dp[i][0] = i, res[i][0] = VERTICAL;
    for(int i = 0; i <= m; i++) dp[0][i] = i, res[0][i] = HORIZONTAL;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            int &v = dp[i][j];
            v = dp[i-1][j-1] + (a[i-1] == b[j-1] ? 0 : 1);
            res[i][j] = (a[i-1] == b[j-1] ? MATCH : REPLACE);
            if(dp[i][j-1] + 1 <= v){
                v = dp[i][j-1] + 1;
                res[i][j] = HORIZONTAL;
            }
            if(dp[i-1][j] + 1 <= v){
                v = dp[i-1][j] + 1;
                res[i][j] = VERTICAL;
            }
        }
    return dp[n][m];
}

void edit(string a, string b){
    int x = a.size(), y = b.size();
    while(x >= 0 && y >= 0 && x+y != 0){
        if(res[x][y] == MATCH) x--, y--;
        else if(res[x][y] == REPLACE){
            vs.push_back("Replace "+to_string(y)+","+b[y-1]);
            x--;y--;
        }
        else if(res[x][y] == HORIZONTAL){
            vs.push_back("Insert "+to_string(y)+","+b[y-1]);
            y--;
        }
        else if(res[x][y] == VERTICAL){
            vs.push_back("Delete "+to_string(y+1));
            x--;
        }
    }
}

int main(){
    string a,b;
    bool first = true;
    while(getline(cin,a) && getline(cin,b)){
        if(!first) cout << endl;
        vs.clear();
        int n = solve(a,b);
        cout << n << endl;
        edit(a,b);
        for(int i = vs.size() - 1, k = 1; i >= 0; i--, k++)
           printf("%d %s\n",k,vs[i].c_str());
        first = false;
    }
    return 0;
}
