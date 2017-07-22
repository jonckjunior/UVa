#include <bits/stdc++.h>
using namespace std;

string qwe =  "1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./ `";
string dank = "123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg' `";
string capsqwe  = "~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";
string capsdank = "~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\"";

int main() {
	string s;
	while(getline(cin,s)){
		for(int i = 0; i < s.size(); i++){
			int pos = 0, caps = 0;
			for(int j = 0; j < qwe.size(); j++)
				if(s[i] == qwe[j]){pos=j;break;}
			for(int j = 0; j < capsqwe.size(); j++)
				if(s[i] == capsqwe[j]){pos=j;caps=1;break;}
			if(caps) printf("%c",capsdank[pos]);
			else	 printf("%c",dank[pos]);
		}
		cout << endl;
	}	
    return 0;
}
