#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

vi coef, poli;

int main(){
    string s1,s2;
    while(getline(cin,s1)){
        getline(cin,s2);
        coef.clear();
        poli.clear();
        
        istringstream iss1(s1);
        while(iss1.good()){
            int x;
            iss1 >> x;
            coef.push_back(x);
        }
        istringstream iss2(s2);
        while(iss2.good()){
            int x;
            iss2 >> x;
            poli.push_back(x);
        }
        for(int i = 0; i < poli.size(); i++){
            int s = 0;
            for(int j = 0; j < coef.size(); j++){
                int t = coef.size() - j - 1;
                s += coef[j]*pow(poli[i],t);
            }
            if(i != poli.size()-1) printf("%d ",s);
            else                   printf("%d\n",s);
        }
    }
}
