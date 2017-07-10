#include <bits/stdc++.h>

using namespace std;
#define bit(i) (1<<(i))

int main(){
    string s;
    while(cin >> s && s != "0"){
        int res = 0;
        reverse(s.begin(), s.end());
        for(int i = 0; i < s.size(); i++)
            res += (s[i]-'0')*(bit(i+1)-1);   
        printf("%d\n",res);
    }
}
