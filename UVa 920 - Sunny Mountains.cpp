#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
vector<ii> p;

double dist(ii a, ii b){
	return hypot(a.first-b.first, a.second-b.second);
}

int main(){
	int t,x,y,n;
	cin >> t;
	while(t--){
		cin >> n;
		p.clear();
		for(int i = 0; i < n; i++){
			cin >> x >> y;
			p.push_back(ii(x,y));
		}
		sort(p.rbegin(), p.rend());
		double maxi = 0, res = 0;
		for(int i = 0; i < n-1; i+=2){
			if(p[i+1].second > maxi){
				double d = dist(p[i], p[i+1]);
				d = d * (double)(p[i+1].second-maxi) / (p[i+1].second-p[i].second);
				res += d;
				maxi = p[i+1].second;
			}
		}
		printf("%.2f\n",res);
	}
}
