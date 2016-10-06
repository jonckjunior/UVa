#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
#define NOTVALID -1e7

int grid[50][50];

int main(){
	int n;
	string s;
	cin >> n;
	getline(cin,s);getline(cin,s);
	while(n--){
		int k = 0;
		while(getline(cin,s) && s.size() > 0){
			for(int i = 0; i < s.size(); i++){
				if(s[i] == '0') grid[k][i] = NOTVALID;
				else grid[k][i] = 1;
				if(k > 0) grid[k][i] += grid[k-1][i];
			}
			k++;
		}
		int maxRect = 0, subRect = 0;
		for(int l = 0; l < k; l++)
			for(int i = l; i < k; i++){
				subRect = 0;
				for(int j = 0; j < k; j++){
					subRect += grid[i][j];
					if(l > 0) subRect -= grid[l-1][j];
					if(subRect < 0) subRect = 0;
					else maxRect = max(maxRect, subRect);
				}
			}
		cout << maxRect << endl;
		if(n) cout << endl;
	}
}
