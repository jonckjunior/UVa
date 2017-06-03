#include <bits/stdc++.h>
// Foi usado uma abordagem de programação dinâmica com busca em profundidade, pois há recomputação de estados
// Os estados podem ser vistos como nodos de um grafo e a função solve percorre esse grafo
//      para encontrar o "maior/melhor caminho" (bem similiar a um floodfill na minha opinião)
//      complexidade de Tempo O(nmt) onde n e m são as dimensões da matriz e t é o tempo máximo que uma maçã pode cair
//      pois percorre todos os estados possíveis (matriz DP) e devolve a melhor solução
// Como a matriz DP tem dimensões NxMxT logo, deve percorrer os NxMxT estados
// Complexidade de Espaço O(nmt) pois utiliza a matriz DP para evitar recomputação de estados
// A complexidade de tempo para uma versão sem programação dinâmica, vide, a tabela dinâmica (ha)
//      Seria O(2^t), onte t é o tempo máximo
//      Como cada estado cria 4 sub-estados e isso ocorre até alcançar o tempo máximo temos 4^t, logo, O(4^t) = O(2^t)
//Já a complexidade de espaço para uma versão sem programação dinâmica, seria O(t) que é a profundidade de um galho,
//      ou seja, o número máximo de vezes que a função solve será empilhada

// Retire o código comentado abaixo para transformar a abordagem com programação dinâmica
//      em uma abordagem de busca completa (Brute Force)
// *Não tente fazer isso em casa
using namespace std;
int const max_v = 30, max_t = 1005;


int n, m, k, tmaxi;
int res[max_v][max_v][max_t], DP[max_v][max_v][max_t*2];

bool valid(int x, int y, int t){
    if(x < 0 || x >= n || y < 0 || y >= m || t > tmaxi) return false;
    else                                                return true;
}

int solve(int x, int y, int t){
    int &value = DP[x][y][t]; // Retire aqui
    if(value != -1) return value; // Retire aqui
    int ans = 0;

    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            int xx = x + i, yy = y + j, tt = t+1;
            if(valid(xx, yy, tt)){
                ans = max(ans, solve(xx,yy,tt));
            }
        }
    }

    return value = ans + res[x][y][t]; // Retire aqui e troque por: return ans + res[x][y][t];
}

int main(){
    int x, y, t;
    while(cin >> n >> m >> k && n+m+k != 0){
        tmaxi = -1;
        memset(res, 0, sizeof res);
        memset(DP, -1, sizeof DP);
        for(int i = 0; i < k; i++){
            cin >> x >> y >> t;
            x--;y--;
            tmaxi = max(tmaxi, t);
            res[x][y][t] = 1;
        }
        cin >> x >> y;
        x--;y--;
        cout << solve(x,y,0) << endl;
    }
    return 0;
}
