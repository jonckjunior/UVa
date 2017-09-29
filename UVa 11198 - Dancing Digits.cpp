#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
map<vi, int> dist;
vi vv(10);
vi finalera(10);

bool isPrime(int a, int b){
  int res = abs(a) + abs(b);
  if(res == 2 || res == 3 || res == 5 || res == 7 || res == 11 || res == 13 || res == 17) return true;
  else return false;
}

/*
  2 -8 -4 5 6 7 3 -1 0
  2 -4 5 6 7 3 -8 -1 1
  -1 2 -4 5 6 7 3 -8 2
*/

int maxi = 30;
int solve(){
  queue<vi> q; q.push(vv);
  dist.clear();
  dist[vv] = 0;
  int k = 0;
  while(!q.empty()){
    vi front = q.front();q.pop();
    int d = dist[front];

    bool found = true;
    for(int i = 0; i < 8; i++)
      if(abs(front[i]) != i+1) found = false;
    if(found) return d;
    for(int i = 0; i < 8; i++){
      for(int j = 0; j < 8; j++){
        if((front[i] < 0 && front[j] > 0) || (front[i] > 0 && front[j] < 0)){
          if(isPrime(front[i], front[j])){
            vi esq(front);
            vi dir(front);
            esq.erase(esq.begin()+i);
            dir.erase(dir.begin()+i);
            if(i > j){
              esq.insert(esq.begin() + j, front[i]);
              dir.insert(dir.begin() + j+1, front[i]);
            }
            else{
              esq.insert(esq.begin() + max(j-1,0), front[i]);
              dir.insert(dir.begin() + j, front[i]);
            }

            if(dist[esq] == 0){
              q.push(esq);
              dist[esq] = d+1;
            }
            if(dist[dir] == 0){
              q.push(dir);
              dist[dir] = d+1;
            }
          }
        }
      }
    }
  }
  return -1;
}

int main(){
  int caso = 0;
  while(cin >> vv[0], vv[0]){
    for(int i = 1; i < 8; i++)
      cin >> vv[i];
    int res = solve();
    printf("Case %d: %d\n",++caso,res);
  }
  return 0;
}
