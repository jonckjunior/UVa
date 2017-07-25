#include <bits/stdc++.h>

using namespace std;
map<string,int> mm;

bool parse(string s){
    mm.clear();
    
    for(int i = 0; i < s.size(); i++){
        string var = "";
        while(i < s.size() && s[i] != '&') var += s[i], i++;
        if(var[0] == '~'){
            string notvar(var.begin()+1,var.end());
            if(mm[notvar]) return false;
        }
        else{
            string notvar = "~" + var;
            if(mm[notvar]) return false;
        }
        mm[var] = 1;
    }
    return true;
}

int main(){
    int t;
    string s;
    cin >> t;
    getchar();
    while(t--){
        getline(cin, s);
        int pos = 0;
        bool valid = false;
        for(int i = 0; i < s.size() && !valid; i++){
            if(s[i] == '('){
                string aux = "";
                i++;
                while(s[i] != ')') aux += s[i], i++;
                if(parse(aux)) valid = true;
            }
        }
        if(valid) puts("YES");
        else      puts("NO");
    }
    return 0;
}
