#include <bits/stdc++.h>

using namespace std;

typedef vector<long long int> vi;

vi coef;

long long int Pow(long long int x, long long int y) {
    if(y == 0)
        return 1;
    if(y&1)
        return x*Pow(x*x, y/2);
    else
        return Pow(x*x, y/2);
}

int main(){
    string s2;
    long long int p;
    while(cin >> p){
        getchar();
        getline(cin,s2);
        coef.clear();
        istringstream iss2(s2);
        while(iss2.good()){
            int x;
            iss2 >> x;
            coef.push_back(x);
        }
        long long int s = 0;
        int t = coef.size() - 1;
        for(long long int j = 0; j < coef.size() - 1 ; j++){
            long long int value = coef[j]*Pow(p,t-1)*t;
            s += value;
            t--;
        }
        printf("%lld\n",s);
        
    }
}
