#include <bits/stdc++.h>

using namespace std;

map<int,int> mm;

int main(){
    int t,x,n,m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        mm.clear();
        for(int i = 0; i < n; i++){
            cin >> x;
            mm[x]++;
        }
        for(int i = 0; i < m; i++){
            cin >> x;
            mm[x]--;
        }
        map<int,int>::iterator it;
        int res = 0;
        for(it = mm.begin(); it != mm.end(); it++)
            res += abs(it->second);
        cout << res << endl;
    }
    return 0;
}
