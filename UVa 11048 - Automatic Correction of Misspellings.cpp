#include <bits/stdc++.h>

using namespace std;

int const correct = -2, unknown = -1;
vector<string> vs;

int solve(string s){
    int res = unknown;
    for(int i = 0; i < vs.size(); i++){
        int len1 = s.size(), len2 = vs[i].size();
        if(abs(len1-len2) > 1) continue;
        if(s == vs[i]) return correct;
        if(s.size() == vs[i].size()){
            //printf("1 - testando %s com %s\n",s.c_str(),vs[i].c_str());
            int mistake = 0;
            for(int j = 0; j < s.size(); j++)
                if(s[j] != vs[i][j]) mistake++;
            if(mistake == 1 && res == unknown) res = i;
            mistake = 0;
            for(int j = 0; j < s.size(); j++){
                if(s[j] != vs[i][j]){
                    mistake++;
                    if(j < s.size() - 1 && s[j] == vs[i][j+1] && s[j+1] == vs[i][j]) j++;
                }
            }
            if(mistake == 1 && res == unknown) res = i;
        }
        else if(s.size() < vs[i].size()){
            //printf("2 - testando %s com %s\n",s.c_str(),vs[i].c_str());
            string aux = s;
            int mistake = 0;
            for(int j = 0; j < aux.size(); j++)
                if(aux[j] != vs[i][j]){
                    mistake++;
                    aux.insert(aux.begin() + j, vs[i][j]);
                    break;
                }
            //printf("adicionei em %s e ficou %s\n",s.c_str(), aux.c_str());
            if(aux == vs[i] && res == unknown) res = i;
            if(mistake == 0 && res == unknown) res = i;
        }
        else{
            //printf("3 - testando %s com %s\n",s.c_str(),vs[i].c_str());
            string aux = s;
            for(int j = 0; j < aux.size(); j++)
                if(aux[j] != vs[i][j]){
                    aux.erase(aux.begin() + j);
                    break;
                }
            if(aux == vs[i] && res == unknown) res = i;
        }
    }
    return res;
}

int main(){
    int n,q;
    string s;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> s, vs.push_back(s);
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> s;
        int res = solve(s);
        if(res == correct)
            printf("%s is correct\n",s.c_str());
        else if(res == unknown)
            printf("%s is unknown\n",s.c_str());
        else
            printf("%s is a misspelling of %s\n",s.c_str(), vs[res].c_str());
    }
    return 0;
}
