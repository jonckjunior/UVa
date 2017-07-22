#include <bits/stdc++.h>
using namespace std;
#define bit(i) (1<<(i))
int main() {
	string s;
	getline(cin,s);
	while(getline(cin,s) && strcmp(s.c_str(), "___________") != 0){
		char c = 0;
		int pos = 0;
		for(int i = s.size() - 2; i > 1; i--){
			if(s[i] == ' ') pos++;
			else if(s[i] == 'o')
				c += bit(pos), pos++;
		}
		printf("%c",c);
	}
    return 0;
}
