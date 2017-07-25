#include <bits/stdc++.h>
using namespace std;

bool valid;

int expression(stringstream &s);
int component(stringstream &s);
int factor(stringstream &s);

int expression(stringstream &s){
	int res = component(s);
	if(s.peek() == '+'){
		s.get();
		return res + expression(s);
	}
	return res;
}

int component(stringstream &s){
	int res = factor(s);
	if(s.peek() == '*'){
		s.get();
		return res * component(s);
	}
	return res;
}

int factor(stringstream &s){
	int res = 0;
	if(s.peek() >= '0' && s.peek() <= '9'){
		s >> res;
		return res;
	}
	else if(s.peek() == '('){
		s.get();
		res = expression(s);
		if(s.get() != ')') valid = false;
	}
	else
		valid = false;
	return res;
}

int main() {
	int t;
	string s;
	cin >> t;
	getchar();
	while(t--){
		getline(cin,s);
		stringstream ss(s);
		valid = true;
		int res = expression(ss);
		if(!ss.eof() || !valid) printf("ERROR\n");
		else					printf("%d\n",res);
		

	}
    return 0;
}
