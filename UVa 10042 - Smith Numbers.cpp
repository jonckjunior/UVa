#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
vi v;

int sumdigits(int a){
    string sss = to_string(a);
    int res = 0;
    for(int i = 0; i < sss.size(); i++)
        res += sss[i]-'0';
    return res;
}

int main(){
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = n+1; ; i++){
            int sum = sumdigits(i), res = 0, k = i;
            int root = sqrt(i) + 1, flag = 0;
            for(int j = 2; j < root && k != 1; j++)
                while(k%j == 0) res += sumdigits(j), k /= j, flag=1;
            if(k != 1) res += sumdigits(k);
            if(sum == res && flag){cout << i << endl;break;}
        }
    }
}
