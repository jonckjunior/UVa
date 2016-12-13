#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int t,n,p[1005];
vii vp;
vector< pair< double, ii > > ve;
double dist(const ii &a, const ii &b){
    return sqrt(pow(a.first-b.first,2)+pow(a.second-b.second,2));
}

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
    int caso = 0, x, y;
    double r;
    cin >> t;
    while(t--){
        cin >> n >> r;
        for(int i = 0; i < n; i++){
            cin >> x >> y;
            vp.push_back(ii(x,y));
            p[i] = i;
        }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                ve.push_back(make_pair(dist(vp[i], vp[j]) , ii(i,j) ) );
            }
        sort(ve.begin(), ve.end());
        double road=0, rail=0;
        UnionFind UF(n);
        int state = 1;
        for(int i = 0; i < ve.size(); i++){
            int u = ve[i].second.first, v = ve[i].second.second;
            double w = ve[i].first;
            if(!UF.isSameSet(u,v)){
                if(w <= r) road += w;
                else       rail += w, state++;
                UF.unionSet(u,v);
            }
        }

        printf("Case #%d: %d %.0lf %.0lf\n",++caso,state,road,rail);

        vp.clear();
        ve.clear();
    }
    return 0;
}
