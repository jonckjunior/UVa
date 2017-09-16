#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int v[400000], freq[400000], cnt[400000], start[400000], end2[400000], tree[400005];

int const maxn = 100005;

void build(){

}

int left(int p){return (p << 1);}
int right(int p){return (p<<1) + 1;}

void build(int p, int L, int R){
	if(L == R) tree[p] = cnt[L];
	else{
		int mid = (L+R)/2;
		build(left(p), L, mid);
		build(right(p), mid+1, R);
		tree[p] = max(tree[left(p)], tree[right(p)]);
	}
}

int query(int p, int L, int R, int i, int j){
	if(i > R || j < L) return -1;
	if(L >= i && R <= j) return tree[p];
	int mid = (L+R)/2;
	int p1 = query(left(p), L, mid, i , j);
	int p2 = query(right(p), mid+1, R, i, j);
	return max(p1,p2);
}

int main() {
	ios::sync_with_stdio(false);
	int n,q,L,R,x,y;
	while(cin >> n >> q){
		memset(freq, 0, sizeof freq);
		for(int i = 0; i < n; i++){
			cin >> x;
			x += maxn;
			v[i] = x;
			freq[x]++;
			if(freq[x] == 1) start[x] = i;
		}

		for(int i = 0; i < n; i++){
			x = v[i];
			cnt[i] = freq[x];
			end2[x] = start[x] + freq[x] - 1;
		}

		build(1, 0, n-1);

		for(int i = 0; i < q; i++){
			cin >> L >> R;
			L--;R--;
			x = v[L], y = v[R];
			if(x == y) cout << (R-L+1) << endl;
			else{
				int esq = end2[x] - L + 1;
				int dir = R - start[y] + 1;
				int mid = -1;

				L = esq + L;
				R = R - dir;
				if(L <= R)
					mid = query(1, 0, n-1, L, R);
				esq = max(esq, dir);
				esq = max(esq, mid);
				cout << esq << endl;
			}
		}
	}
	return 0;
}
