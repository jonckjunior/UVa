#include <bits/stdc++.h>
using namespace std;

vector<string> vs;

void createKey(string key){
	int v[50];
	memset(v,0,sizeof v);
	int line = 0, pos = 0;
	for(int i = 0; i < key.size(); i++){
		if(key[i] == ' ') continue;
		int c = key[i] - 'a';
		if(v[c] == 0){
			v[c] = 1;
			if(pos == 5) pos = 0, line++;
			pos++;
			vs[line].push_back(key[i]);
		}
	}
	for(int i = 0; i < 26; i++)
		if(v[i] == 0){
			v[i] = 1;
			if(pos == 5) pos = 0, line++;
			char ch = 'a' + i;
			if(ch == 'q') continue;
			pos++;
			vs[line].push_back(ch);
		}
}

int findColumn(char c){
	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)
			if(vs[i][j] == c)
				return j;
}

int findRow(char c){
	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)
			if(vs[i][j] == c)
				return i;
}

string createCipher(string s){
	int k = 0;
	char fst,snd;
	vector< pair<char,char> > vcc;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == ' ') continue;
		k++;
		if(k == 1) fst = s[i];
		else if(k == 2){
			snd = s[i];
			if(fst != snd) vcc.push_back(make_pair(fst, snd)), k = 0;
			else		   vcc.push_back(make_pair(fst, 'x')), fst = snd, k = 1;
		}
	}
	if(k == 1) vcc.push_back(make_pair(fst, 'x'));
	string res;
	for(int i = 0; i < vcc.size(); i++){
		char first = vcc[i].first, second = vcc[i].second;
		if(first == second) second = 'x';
		int rf = findRow(first), cf = findColumn(first);
		int rs = findRow(second), cs = findColumn(second);
		if(rf == rs){
			cf = (cf+1)%5;
			cs = (cs+1)%5;
		}
		else if(cf == cs){
			rf = (rf+1)%5;
			rs = (rs+1)%5;
		}
		else{
			int aux = cf;
			cf = cs;
			cs = aux;
		}
		res.push_back(toupper(vs[rf][cf]));
		res.push_back(toupper(vs[rs][cs]));
	}
	return res;
}


int main() {
	int t;
	string key, phrase;
	cin >> t;
	getchar();
	while(t--){
		vs.assign(10, string());
		getline(cin, key);
		getline(cin, phrase);
		createKey(key);		
		cout << createCipher(phrase) << endl;
	}    
    return 0;
}
