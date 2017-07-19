#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vi v;

int gcd(int a, int b){if(a%b == 0) return b;return gcd(b, a%b);}
int lcm(int a, int b){return a * (b / gcd(a,b));}

int main(){
    int t;
    string entrada;
    cin >> t;
    getline(cin, entrada);
    while(t--){
        getline(cin, entrada);
        istringstream iss(entrada);
        v.clear();
        while(iss.good()){
            int x;
            iss >> x;
            v.push_back(x);
        }
        int res = 0;
        for(int i = 0; i < v.size(); i++)
            for(int j = i+1; j < v.size(); j++){
                res = max(res, gcd(v[i], v[j]));
            }
        printf("%d\n",res);
    }
    return 0;
}
