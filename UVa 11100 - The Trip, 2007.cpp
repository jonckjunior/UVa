#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef vector<int> vi;
int bag[10005], bagaux[10005];
bool espaco = false;
int main(){
	int n;
	while(cin >> n && n){
		if(espaco) cout << endl;
		for(int i = 0; i < n; i++)
			scanf("%d",&bag[i]);
		sort(bag,bag+n);
		for(int i = 0; i < n; i++)
			bagaux[i] = bag[i];
		int numbags = 0;
		for(int i = 0; i < n; i++){
			if(bagaux[i] == -1) continue;
			int x = bagaux[i], k = i;
			numbags++;
			for(int j = i; j < n; j++)
				if(bagaux[j] > x){
					x = bagaux[j];
					bagaux[j] = -1;
				}	
		}
		cout << numbags << endl;

		vector< vi > data(numbags,vi());
		int dbag = 0;
		for(int i = 0; i < n; i++){
			data[dbag].push_back(bag[i]);
			dbag = (dbag+1)%numbags;
		} 

		for(int i = 0; i < numbags; i++){
			for(int j = 0; j < data[i].size(); j++){
				if(j==0) printf("%d",data[i][j]);
				else printf(" %d",data[i][j]);
			}
			cout << endl;
		}
		espaco = true;
	}

	return 0;
}
