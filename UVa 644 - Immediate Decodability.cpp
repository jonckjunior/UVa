#include <bits/stdc++.h>

using namespace std;

vector<string> vs;

bool solve(){
    for(int i = 0; i < vs.size(); i++)
        for(int j = i + 1; j < vs.size(); j++)
            if(strncmp(vs[i].c_str(), vs[j].c_str(), min(vs[i].size(), vs[j].size())) == 0) return false;
    return true;
}

int main(){
    string s;
    int caso = 0;
    while(getline(cin,s)){
        if(s == "9"){
            if(solve())
                printf("Set %d is immediately decodable\n",++caso);
            else
                printf("Set %d is not immediately decodable\n",++caso);
            vs.clear();
        }
        else
            vs.push_back(s);
        
    }
    return 0;
}
