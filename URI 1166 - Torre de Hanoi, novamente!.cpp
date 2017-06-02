#include <bits/stdc++.h>

using namespace std;

vector< stack<int> > vs;

bool quadradoPerfeito(int x, int y){
    int s = x+y;
    int res = sqrt(s);
    return (res*res == s);
}

int main(){
    int n,t;
    cin >> t;
    while(t--){
        cin >> n;
        vs.assign(n+1, stack<int> ());
        int bola = 1;
        for(int i = 0; i < n ; i++){
            if(vs[i].empty())
                vs[i].push(bola++), i = -1;
            else{
                int x = vs[i].top();
                if(quadradoPerfeito(x, bola)){
                    vs[i].push(bola);
                    i = -1;
                    bola++;
                }
            }            
        }
        cout << bola -1 << endl;
    }
}
