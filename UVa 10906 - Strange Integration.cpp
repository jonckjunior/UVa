#include <bits/stdc++.h>

using namespace std;

struct node{
	char op;
	string s;
};

map<string,node> mm;

node getNode(string a){
	if(mm.count(a))
		return mm[a];
	node n = {'!', a};
	return n;
}

void solve(string a, string b, char op, string c){
	node na = getNode(a), nb = getNode(b), nc;
	nc.op = op;
	if(na.op == '+' && op == '*')
		nc.s = "(" + na.s + ")";
	else
		nc.s = na.s;
	nc.s += op;
	if(nb.op == '+' || (op == '*' && nb.op == '*'))
		nc.s += "(" + nb.s + ")";
	else
		nc.s += nb.s;
	mm[c] = nc;
}

int main(){
	int t,n,caso=0;
	string a,b,c,lala;
	char op;
	cin >> t;
	while(t--){
		mm.clear();
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> c >> lala >> a >> op >> b;
			solve(a,b,op,c);
		}
		printf("Expression #%d: %s\n", ++caso, mm[c].s.c_str());
	}
}
