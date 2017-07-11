#include <bits/stdc++.h>
using namespace std;
double v[1005];

int main(){
	int n;
	while(cin >> n && n != 0){
		double sum = 0, res = 0;
		for(int i = 0; i < n; i++) scanf("%lf",&v[i]), sum += v[i];
		sum /= n;
		double low=0, high=0;
		double sl = floor(sum*100)/100.0, sh = sl + 0.01;
		for(int i = 0; i < n; i++){	
			if(v[i] < sl) low += sl-v[i];
			else if(v[i] > sh) high += v[i]-sh;
		}
		printf("$%.2f\n",max(low,high));
	}
}
