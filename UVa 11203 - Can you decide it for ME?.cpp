#include <bits/stdc++.h>
using namespace std;

bool isAxiom(string s){
	int pos = 0, a = 0, b = 0, c = 0;
	while(pos < s.size() && s[pos] == '?') pos++, a++;
	if(a > 0 && s[pos] == 'M'){
		pos++;
		while(pos < s.size() && s[pos] == '?') pos++, b++;
		if(b == 1 && s[pos] == 'E'){
			pos++;
			while(pos < s.size() && s[pos] == '?') pos++, c++;
			if(c-1 == a && pos == s.size()) return true;
		}
	}
	return false;
}

bool isTheorem(string s){
	int pos = 0, a = 0, b = 0, c = 0;
	while(pos < s.size() && s[pos] == '?') pos++, a++;
	if(a > 0 && s[pos] == 'M'){
		pos++;
		while(pos < s.size() && s[pos] == '?') pos++, b++;
		if(b > 0 && s[pos] == 'E'){
			pos++;
			while(pos < s.size() && s[pos] == '?') pos++, c++;
			if(c > 0 && pos == s.size()) return true;
		}
	}
	return false;
}

bool solve(string s){
	if(!isTheorem(s)) return false;
	if(isAxiom(s)) return true;
	int pos;
	for(pos = 0; pos < s.size(); pos++)
		if(s[pos] == 'M') break;
	pos++;
	s.erase(s.begin() + pos);
	s.pop_back();
	return solve(s);
}

int main() {
    int t;
    string s;
    cin >> t;
    getchar();
    while(t--){
    	cin >> s;    	
    	if(solve(s))
    		printf("theorem\n");
    	else
    		printf("no-theorem\n");
    }
    return 0;
}
