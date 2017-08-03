#include <bits/stdc++.h>

using namespace std;

vector< pair<int,pair<int,pair<int,pair<string,string> > > > > vp;
int main(){
	
	int n;
	
	string s, nome;
	int min,sec,mil;
	while(cin >> n){
		vp.clear();
		for(int i = 0; i < n; i++){
			cin >> nome >> s >> min >> s >> sec >> s >> mil >> s;
			string nova = "";
			for(int j = 0; j < nome.size(); j++)
				nova += toupper(nome[j]);
			vp.push_back(make_pair(min, make_pair(sec, make_pair(mil, make_pair(nova,nome)))));
		}
		sort(vp.rbegin(), vp.rend());
		int row = 1;
		while(!vp.empty()){
			pair<int,pair<int,pair<int,pair<string,string> > > > first = vp.back(); vp.pop_back();
			printf("Row %d\n", row++);
			cout << first.second.second.second.second << endl;
			if(!vp.empty()){
				pair<int,pair<int,pair<int,pair<string,string> > > > second = vp.back(); vp.pop_back();
				cout << second.second.second.second.second << endl;
			}
		}
		cout << endl;
	}

	return 0;
}
