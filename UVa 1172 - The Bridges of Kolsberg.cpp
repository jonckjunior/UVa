#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

vector<ii> vec_esq, vec_dir;

int n,m,t;

ii dp[1005][1005];

ii solve(int esq, int dir){
    if(esq < 0 || dir < 0) return ii(0,0);
    if(dp[esq][dir] != ii(-1,-1)) return dp[esq][dir];
    ii res  = solve(esq-1, dir);
    ii res2 = solve(esq, dir-1);
    if(res.second >= res2.second){
        if(res.second == res2.second)
            res.first = max(res.first, res2.first);
    }
    else
        res = res2;
    ii zero = ii(0,0);
    if(vec_esq[esq].first == vec_dir[dir].first){
        int v1 = vec_esq[esq].second, v2 = vec_dir[dir].second;
        zero = solve(esq-1, dir-1);
        zero.first+=1;
        zero.second+=v1+v2;
    }
    if(res.second >= zero.second){
        if(res.first == zero.first)
            res.first = max(res.first, zero.first);
    }
    else
        res = zero;
    return dp[esq][dir] = res;
}

map<string, int> mm;

int main(){
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--){
        memset(dp, -1, sizeof dp);
        cin >> n;
        // printf("n = %d\n",n);
        vec_esq.clear();
        vec_dir.clear();
        mm.clear();
        int k = 1;
        for(int i = 0; i < n; i++){
            string a; cin >> a;
            cin >> a;
            int x; cin >> x;
            int &v = mm[a];
            if(v == 0) v = k++;
            vec_esq.push_back(ii(v,x));
        }
        cin >> m;
        // printf("m = %d\n",m);
        for(int i = 0; i < m; i++){
            string a; cin >> a;
            cin >> a;
            int x; cin >> x;
            int &v = mm[a];
            if(v == 0) v = k++;
            vec_dir.push_back(make_pair(v,x));
        }
        ii res = solve(n-1,m-1);
        cout << res.second << " " << res.first << endl;
    }
    return 0;
}
