#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int n;
    while(cin >> n && n != 0){
        int root = ceil(sqrt(n));
        long long int r2 = root*root;
        long long int res = r2 - root + 1;
        if(root&1){
            if(r2 == n) cout << 1 << " " << root << endl;
            else if(n > res) cout << root-(n-res) << " " << root << endl;
            else if(n <= res) cout << root << " " << root - (res-n) << endl;
        }
        else{
            if(r2 == n) cout << root << " " << 1 << endl;
            else if(n > res) cout << root << " " << root-(n-res) << endl;
            else if(n <= res) cout << root - (res-n) << " " << root << endl;
        }
    }
    return 0;
}
