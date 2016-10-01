#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int n;
	while(cin >> n && n){
		int num[n];
		vector<int> vi;
		for(int i = 0; i < n; i++){
			scanf("%d",&num[i]);
			if(num[i]) vi.push_back(num[i]);
		}
		if(vi.size() == 0) cout << 0 << endl;
		else{
			for(int i = 0; i < vi.size(); i++){
				if(i==0)
					printf("%d",vi[i]);
				else
					printf(" %d",vi[i]);
			}
			cout << endl;
		}
	}
	return 0;
}
