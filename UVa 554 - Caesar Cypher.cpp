#include <bits/stdc++.h>

using namespace std;

vector<string> vs;
vector< pair<int,string> > res;

int solve(string s){
    istringstream iss(s);
    string aux;
    int c = 0;
    while(iss >> aux){
        for(int i = 0; i < vs.size(); i++)
            if(aux == vs[i]) {
                c++;
                break;
            }
    }
    return c;
}

int main(){
    
    string s;
    while(getline(cin,s), s != "#")
        vs.push_back(s);
    getline(cin, s);
    res.push_back(make_pair(solve(s),s));
    for(int k = 1; k <= 26; k++){
        string aux;
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            int c = 0;
            if(ch == ' ') c = 0;
            else          c = ch - 'A' + 1;
            c = (c+k)%27;
            if(c==0) ch = ' ';
            else     ch = 'A' + c - 1;
            aux.push_back(ch);
        }
        res.push_back(make_pair(solve(aux), aux));
    }
    sort(res.rbegin(), res.rend());
    istringstream iss(res[0].second);
    vector<string> final;
    while(iss >> s) final.push_back(s);
    s = "";
    for(int i = 0; i < final.size(); i++){
        string aux;
        if(i == 0) aux = final[i];
        else       aux = s + " " + final[i];
        if(aux.size() > 60){
            cout << s << endl;
            s = final[i];
        }
        else
            s = aux;
        if(i == final.size() - 1 && s.size() != 0)
            cout << s;
    }
    cout << endl;
    return 0;
}
