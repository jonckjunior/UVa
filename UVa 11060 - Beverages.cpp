#include <bits/stdc++.h>
using namespace std;
#define MAX_V 105
typedef vector<int> vi;
/*

3
vodka
wine
beer
2
wine vodka
beer wine

*/

map<string,int> m;

int n,e;
vector< vi > adj;
vi inEdge, res;
vector<string> resout;

void dfs(){
	
	priority_queue<int, vi , greater<int> > q;
	for(int i = 1; i <= n; i++)
		if(inEdge[i] == 0)
			q.push(i);
//	printf("here\n");
	while(!q.empty()){
//		printf("here2\n");
		int u = q.top(); q.pop(); res.push_back(u);
		for(int i = 0; i < adj[u].size(); i++){
			int v = adj[u][i];
			inEdge[v]--;
	    	if(inEdge[v] == 0)
	        	q.push(v);
	    }
	}
}


int main(){
	int caso = 0;
	while(cin >> n){
	    m.clear();
	    adj.assign(MAX_V, vi());
	    inEdge.assign(MAX_V, 0);
	    resout.clear();
	    res.clear();
	    int k = 1;
	    for(int i = 0; i < n; i++){
	      string s;
	      cin >> s;
	      m[s] = k++;
	      resout.push_back(s);
//		  cout << s << " com " << m[s] << endl;
	    }
	    cin >> e;
	    for(int i = 0; i < e; i++){
	    	string s1, s2;
			cin >> s1 >> s2;
			int x = m[s1], y = m[s2];
//			cout << x << " " << y << endl;
			adj[x].push_back(y);
			inEdge[y]++;
	    }
	    
	    dfs();
	    printf("Case #%d: Dilbert should drink beverages in this order:",++caso);
	    for(int i = 0; i < res.size(); i++){
			if(i == res.size() - 1)
				cout << " " << resout[res[i]-1] << "." << endl;
			else
				cout << " " << resout[res[i]-1];
		}
		cout << endl;
	    	
  }
}
