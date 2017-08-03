#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

vi p, res;
vector<string> vs, finger;
map<string,int> mm;

int main(){
	int n,w,x;
	string s;
	finger.push_back("qaz");
	finger.push_back("wsx");
	finger.push_back("edc");
	finger.push_back("rfvtgb");
	finger.push_back(" ");
	finger.push_back(" ");
	finger.push_back("yhnujm");
	finger.push_back("ik,");
	finger.push_back("ol.");
	finger.push_back("p;/");
	while(cin >> n >> w){
		p.clear();
		vs.clear();
		res.clear();
		mm.clear();
		for(int i = 0; i < n; i++)
			cin >> x, p.push_back(x-1);
		for(int i = 0; i < w; i++){
			cin >> s;
			int &value = mm[s];
			if(value == 0)
				vs.push_back(s), value = 1;
		}
		int maxi = -1, nn = 0;
		for(int i = 0; i < vs.size(); i++){
			bool valid = true;
			for(int j = 0; j < n; j++){
				int v = p[j];
				for(int k = 0; k < finger[v].size(); k++)
					if(strchr(vs[i].c_str(), finger[v][k]) != 0) valid = false;
			}
			if(valid) res.push_back(i), maxi = max(maxi, (int)vs[i].size());
		}
		for(int i = 0; i < res.size(); i++)
			if((int)vs[res[i]].size() == maxi)
				nn++;
		cout << nn << endl;
		for(int i = 0; i < res.size(); i++)
			if((int)vs[res[i]].size() == maxi)
				cout << vs[res[i]] << endl;
	}
}
