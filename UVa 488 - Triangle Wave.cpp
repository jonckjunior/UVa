#include <bits/stdc++.h>

using namespace std;

int main(){
    int t,n,m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        string res = "";
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < i; j++)
                res += to_string(i);
            res += '\n';
        }
        for(int i = n-1; i >= 1; i--){
            for(int j = 0; j < i; j++)
                res += to_string(i);
            res += '\n';
        }
        for(int i = 0; i < m; i++){
            cout << res;
            if(i != m-1) cout << endl;
        }
        if(t) cout << endl;
    }
}
