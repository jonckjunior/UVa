#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,last;
	string s;
	cin >> n;
	while(n--){
		cin >> s;
		last = 0;
		int len = (int)s.size();
		for(int i = 1; i <= s.size()/2; i++){
			string aux(s.begin(), s.begin() + i);
			string aux2(s.begin()+i, s.end());
			if(strncmp(aux.c_str(), aux2.c_str(), min(i,len-i)) == 0)
				last = i;	
		}
		int off = len%last;
		string res(s.begin(), s.begin()+last);
		while((int)res.size() < 8+off) res += res;
		for(int i = 0; i < 8; i++)
			printf("%c",res[off++]);
		printf("...\n");
	}
}
