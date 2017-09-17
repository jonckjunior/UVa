#include <bits/stdc++.h>

using namespace std;

#define NOTHING 0
#define CHANGETO1 1
#define CHANGETO2 2
#define FLIP 3

string entrada;

int tree[4000005], lazy[4000005];

int left(int p){return (p << 1);}
int right(int p){return (p << 1) + 1;}

void build(int p, int L, int R){
	if(L == R) tree[p] = (entrada[L] == '1' ? 1 : 0);
	else{
		int mid = (L+R)/2;
		build(left(p), L, mid);
		build(right(p), mid+1, R);
		tree[p] = tree[left(p)] + tree[right(p)];
	}
}

void update(int p, int L, int R, int i, int j, int comm){
	if(lazy[p] != NOTHING){
		if(lazy[p] == CHANGETO1) tree[p] = R-L+1;
		else if(lazy[p] == CHANGETO2) tree[p] = 0;
		else if(lazy[p] == FLIP) tree[p] = (R-L+1)-tree[p];
		if(L != R){
			if(lazy[p] == CHANGETO1 || lazy[p] == CHANGETO2){
				lazy[left(p)] = lazy[p];
				lazy[right(p)] = lazy[p];
			}
			else{
				if(lazy[left(p)] == CHANGETO1) lazy[left(p)] = CHANGETO2;
				else if(lazy[left(p)] == CHANGETO2) lazy[left(p)] = CHANGETO1;
				else if(lazy[left(p)] == FLIP) lazy[left(p)] = NOTHING;
				else if(lazy[left(p)] == NOTHING) lazy[left(p)] = FLIP;

				if(lazy[right(p)] == CHANGETO1) lazy[right(p)] = CHANGETO2;
				else if(lazy[right(p)] == CHANGETO2) lazy[right(p)] = CHANGETO1;
				else if(lazy[right(p)] == FLIP) lazy[right(p)] = NOTHING;
				else if(lazy[right(p)] == NOTHING) lazy[right(p)] = FLIP;

			}
		}
		lazy[p] = NOTHING;
	}
	if(L > j || R < i) return;
	if(L >= i && R <= j){
		if(comm == CHANGETO1) tree[p] = R-L+1;
		else if(comm == CHANGETO2) tree[p] = 0;
		else if(comm == FLIP) tree[p] = (R-L+1)-tree[p];
		if(L != R){
			if(comm == CHANGETO1 || comm == CHANGETO2){
				lazy[left(p)] = comm;
				lazy[right(p)] = comm;
			}
			else{
				if(lazy[left(p)] == CHANGETO1) lazy[left(p)] = CHANGETO2;
				else if(lazy[left(p)] == CHANGETO2) lazy[left(p)] = CHANGETO1;
				else if(lazy[left(p)] == FLIP) lazy[left(p)] = NOTHING;
				else if(lazy[left(p)] == NOTHING) lazy[left(p)] = FLIP;

				if(lazy[right(p)] == CHANGETO1) lazy[right(p)] = CHANGETO2;
				else if(lazy[right(p)] == CHANGETO2) lazy[right(p)] = CHANGETO1;
				else if(lazy[right(p)] == FLIP) lazy[right(p)] = NOTHING;
				else if(lazy[right(p)] == NOTHING) lazy[right(p)] = FLIP;
			}
		}
		return;
	}
	int mid = (L+R)/2;
	update(left(p), L, mid, i, j, comm);
	update(right(p), mid+1, R, i, j, comm);
	tree[p] = tree[left(p)] + tree[right(p)];
}

int query(int p, int L, int R, int i, int j){
	//printf("%d %d %d %d %d\n",p,L,R,i,j);
	if(L > j || R < i) return 0;
	if(lazy[p] != NOTHING){
		if(lazy[p] == CHANGETO1) tree[p] = R-L+1;
		else if(lazy[p] == CHANGETO2) tree[p] = 0;
		else if(lazy[p] == FLIP) tree[p] = (R-L+1)-tree[p];
		if(L != R){
			if(lazy[p] == CHANGETO1 || lazy[p] == CHANGETO2){
				lazy[left(p)] = lazy[p];
				lazy[right(p)] = lazy[p];
			}
			else{
				if(lazy[left(p)] == CHANGETO1) lazy[left(p)] = CHANGETO2;
				else if(lazy[left(p)] == CHANGETO2) lazy[left(p)] = CHANGETO1;
				else if(lazy[left(p)] == FLIP) lazy[left(p)] = NOTHING;
				else if(lazy[left(p)] == NOTHING) lazy[left(p)] = FLIP;

				if(lazy[right(p)] == CHANGETO1) lazy[right(p)] = CHANGETO2;
				else if(lazy[right(p)] == CHANGETO2) lazy[right(p)] = CHANGETO1;
				else if(lazy[right(p)] == FLIP) lazy[right(p)] = NOTHING;
				else if(lazy[right(p)] == NOTHING) lazy[right(p)] = FLIP;

			}
		}
		lazy[p] = NOTHING;
	}

	if(L >= i && R <= j) return tree[p];
	int mid = (L+R)/2;
	int p1 = query(left(p), L, mid, i, j);
	int p2 = query(right(p), mid+1, R, i, j);
	//printf("%d-%d e %d-%d = %d + %d\n",L,mid,mid+1,R,p1,p2);
	return p1+p2;
}

int main() {
	int t,caso=0;
	cin >> t;
	while(t--){
		int n,q,m,x,y,qry;
		memset(lazy, 0, sizeof lazy);
		string ss;
		entrada = "";
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> m >> ss;
			for(int j = 0; j < m; j++)
				entrada += ss;
		}
		n = entrada.size();
		build(1, 0, n-1);
		//cout << entrada << endl;
		printf("Case %d:\n", ++caso);
		cin >> q;
		qry = 1;
		for(int i = 0; i < q; i++){
			cin >> ss >> x >> y;
			//printf("%s %d %d\n",ss.c_str(), x, y);
			if(ss == "S"){
				printf("Q%d: %d\n",qry++,query(1,0,n-1,x,y));
			}
			else if(ss == "F"){
				update(1, 0, n-1, x, y, CHANGETO1);
			}
			else if(ss == "E"){
				update(1, 0, n-1, x, y, CHANGETO2);
			}
			else if(ss == "I"){
				update(1, 0, n-1, x, y, FLIP);
			}
		}
	}
    return 0;
}
