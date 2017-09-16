#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define LSOne(S) (S & (-S))

int v[100005], tree[400005], n;
int left(int p){return (p << 1);}
int right(int p){return (p << 1)+1;}

void build(int p, int L, int R){
	if(L == R){
		if(v[L] == 0) tree[p] = 0;
		else if(v[L] > 0) tree[p] = 1;
		else tree[p] = -1;
	}
	else{
		int mid = (L+R)/2;
		build(left(p), L, mid);
		build(right(p), mid+1, R);
		tree[p] = tree[left(p)] * tree[right(p)];
	}
}

int query(int p, int L, int R, int i, int j){
	if(i > R || j < L) return 1;
	if(L >= i && R <= j) return tree[p];
	int mid = (L+R)/2;
	int p1 = query(left(p), L, mid, i, j);
	int p2 = query(right(p), mid+1, R, i, j);
	return p1*p2;
}

void update(int p, int L, int R, int i, int j, int val){
	if(i > R || j < L) return;
	if(L == R){
		if(val == 0) tree[p] = 0;
		else if(val > 0) tree[p] = 1;
		else tree[p] = -1;
	}
	else{
		int mid = (L+R)/2;
		update(left(p), L, mid, i, j, val);
		update(right(p), mid+1, R, i, j, val);
		tree[p] = tree[left(p)]*tree[right(p)];
	}
}

int main() {
	ios::sync_with_stdio(false);
	int q,L,R,x;

	while(cin >> n >> q){
		for(int i = 0; i < n; i++)
			cin >> v[i];
		string comm, res = "";
		build(1, 0, n-1);
		for(int i = 0; i < q; i++){
			cin >> comm;
			if(comm == "C"){
				cin >> L >> R;
				L--;
/*				if(v[L] == R) continue;
				if(v[L] > 0 && R > 0) continue;
				if(v[L] < 0 && R < 0) continue;*/
				update(1, 0, n-1, L, L, R);
			}
			else{
				cin >> L >> R;
				L--;R--;
				x = query(1, 0, n-1, L, R);
				//printf("query de %d-%d = %d\n",L,R,x);
				if(x == 0) res += "0";
				else if(x > 0) res += "+";
				else res += "-";
			}
		}
		cout << res << endl;
	}
	return 0;
}
