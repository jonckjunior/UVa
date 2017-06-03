#include <bits/stdc++.h>
// Foi usado uma abordagem gulosa, tentando colocar em ordem crescente uma bola em cada torre Ti até Tn
// Quando não era possível colocar uma bola em uma determinada torre Ti, pulasse para a proxima torre
// Caso chegue na Tn e ainda não adicionou a bola, o programa termina
// Complexidade de Tempo O(mn) onde n são as torres e m é o número máximo de bolas que é possivel adicionar
// Complexidade de Espaço O(m+n) onde serão criados n pilhas, e serão distribuidas entre as n pilhas as m bolas
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
        vs.assign(n+1, stack<int> ()); // O(n)
        int bola = 1;
        for(int i = 0; i < n ; i++){ // O(mn) para cada bola m ira percorrer o for
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
