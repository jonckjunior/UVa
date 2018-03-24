#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        int esq = 1, dir = 0;

        for(int j = i+1; j < n; j++){
            if(v[j] <= v[j-1])
                dir++;
            else
                break;
        }

        for(int j = i-1; j >= 0; j--){
            if(v[j] <= v[j+1])
                esq++;
            else
                break;
        }
        res = max(res, esq+dir);
    }
    cout << res << endl;
    return 0;
}
