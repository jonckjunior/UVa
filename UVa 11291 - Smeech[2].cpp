#include <bits/stdc++.h>

using namespace std;

double solve(stringstream &s){
	while(s && s.peek() == ' ') s.get();
	double res;
	if(s.peek() == '('){
		s.get();
		double a,b,p;
		s >> p;
		a = solve(s);
		b = solve(s);
		while(s && s.get() != ')');
		res = p*(a+b)+(1-p)*(a-b);
	}
	else
		s >> res;
	return res;
}

int main(){
	string s;
	while(getline(cin, s), s != "()"){
		stringstream ss(s);
		printf("%.2f\n",solve(ss));
	}
}
