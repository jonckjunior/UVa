#include <bits/stdc++.h>
#define INF 1e7
#define MAX_N 30
#define bit(i) (1<<i)
#define UNVISITED -1
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

struct Edge{
    int u,v,w;
    Edge(){}
    Edge(int a, int b, int c){u = a;v = b;w = c;}
    bool operator<(const Edge& b) const{return w < b.w;}
};

class UnionFind {
    private: vi p, rank;

    public:
        UnionFind(int N) { rank.assign(N, 0);
        p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }

    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
        int x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y])  p[y] = x;
        else {                  p[x] = y;
                                if (rank[x] == rank[y]) rank[y]++; }
} } };

int main(){
    int m,n,x,y,w,total,mst;
    ios::sync_with_stdio(false);
    while(cin >> m >> n && m+n != 0){
        total = mst = 0;
        vector<Edge> E;
        for(int i = 0; i < n; i++){
            cin >> x >> y >> w;
            total += w;
            E.push_back(Edge(x,y,w));
        }
        UnionFind UF(m);
        sort(E.begin(), E.end());

        for(int i = 0; i < n; i++){
            Edge front = E[i];

            if(!UF.isSameSet(front.u, front.v)){
                mst += front.w;
                UF.unionSet(front.u, front.v);
            }
        }
        cout << total - mst << endl;
    }
}
