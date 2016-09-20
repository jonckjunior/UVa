#include <iostream>
#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <algorithm>
#define bit(a) (1<<a)
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;

int n,m;
vector<int> num;
bool found;

bool func(const pair<vi,bool>& a, const pair<vi,bool>& b){
	vi auxa = a.first, auxb= b.first;
	int mini = min ((int)auxa.size(), (int)auxb.size());
    for(int i =0 ; i < mini; i++)
       	if(auxa[i] < auxb[i]) return false;
    if(auxa.size() < auxb.size()) return false;
    return true;

}

void backtrack(int i, int sum, int mark, map<vi,bool> &used){
	if(sum > n) return;
	if(sum == n){
		found = true;
		vector<int> ans;
			for(int j = 0; j < m; j++)
				if(bit(j)&mark) ans.push_back(num[j]);
		sort(ans.rbegin(), ans.rend());
		if(!used[ans]) used[ans] = true;
		return;
	}
	if(i == m) return;
	backtrack(i+1,sum,mark, used);
	backtrack(i+1,sum+num[i],mark|bit(i), used);
}

int main(){
	int x;
	while(scanf("%d %d",&n,&m) && n+m != 0){
		for(int i = 0; i < m; i++){
			scanf("%d",&x);
			num.push_back(x);
		}
		map<vi,bool> used;
		found = false;
		backtrack(0,0,0, used);
		printf("Sums of %d:\n",n );
		if(!found) {cout << "NONE" << endl;num.clear();continue;}
		vector< pair<vi,bool> > vetor(used.begin(), used.end());
		sort(vetor.begin(), vetor.end(), func);
		for(int j = vetor.size() - 1; j >= 0; j--){
			pair<vi,bool> ll = vetor[j];
			vi u = ll.first;
			bool first = true;
			for(int i = 0; i < u.size(); i++){
				if(i==0)
					printf("%d",u[i]);
				else
					printf("+%d",u[i]);
			}
			cout << endl;
		}


		num.clear();
	}
	return 0;
}
