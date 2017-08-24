#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
const int maxn = 65505;
vi aux;
map<int,int> mm;
int L[maxn], L_id[maxn], P[maxn];
int solve(){
	int lis = 0, lis_end = 0;
	for(int i = 0; i < (int)aux.size(); i++){
		int pos = lower_bound(L, L+lis, aux[i]) - L;
		L[pos] = aux[i];
		L_id[pos] = i;
		P[i] = pos ? L_id[pos-1] : -1;
		if(pos+1 > lis){
			lis = pos+1;
			lis_end = i;
		}
	}
	return lis;
}

int main(){
	int t,n,p,q,x,caso=0;
	cin >> t;
	
	while(t--){
		mm.clear(); aux.clear();
		cin >> n >> p >> q;
		for(int i = 0; i <= p; i++){
			scanf("%d",&x);
			mm[x] = i+1;
		}
		for(int i = 0; i <= q; i++){
			scanf("%d",&x);
			int &v = mm[x];
			if(v != 0) aux.push_back(v-1);
		}
		/*for(int i = 0; i < (int)aux.size();i++)
			cout << aux[i] << " ";
		cout << endl;*/
		int res = solve();
		printf("Case %d: %d\n",++caso,res);
	}
	return 0;
}
