#include <bits/stdc++.h>

using namespace std;

string parser(string s, int& pos){
	string term1 = "";
	if(s[pos] == '('){
		string term1 = "(";
		int pilha = 1;
		pos++;
		while(1){
			if(s[pos] == '(') pilha++;
			if(s[pos] == ')') pilha--;
			term1 += s[pos];
			if(pilha == 0) break;
			pos++;
		}
		pos++;
		pos++;
		return term1;
	}
	else{
		string num = "";
		for(; pos < s.size(); pos++){
			if(isdigit(s[pos]) || s[pos] == '.' || s[pos] == '-') num += s[pos];
			else break;
		}
		pos++;
		return num;
	}
}

double solve(string s){
	if(s[0] == '('){
		int pos = 1;
		string term1 = parser(s, pos);
		string term2 = parser(s, pos);
		string term3 = parser(s, pos);
		double tt1 = solve(term1), tt2 = solve(term2), tt3 = solve(term3);
		return tt1*(tt2+tt3)+(1-tt1)*(tt2-tt3);
	}
	else{
		int pos = 0;
		string res = parser(s, pos);
		return stod(res);
	}
}

int main(){
	string s;
	while(getline(cin, s), s != "()")
		printf("%.2f\n",solve(s));
}
