#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#define INF 1e9
using namespace std;

int main() {
	int t,rocks,distance,d,caso=0;
	char c;
	string s;
	cin >> t;
	while(t--){
		scanf("%d %d",&rocks,&distance);
		getline(cin,s);
		int dist[rocks+5];
		char size_rock[rocks+5];
		dist[0] = 0;
		size_rock[0] = 'B';
		dist[rocks+1] = distance;
		size_rock[rocks+1] = 'S';
		for(int i = 1; i < rocks; i++){
			scanf("%c-%d ",&size_rock[i],&dist[i]);
		}
		scanf("%c-%d\n",&size_rock[rocks],&dist[rocks]);
		int x = 0, leap = 0;
		for(int i = 0; i <= rocks;i++){
				if(size_rock[i+1] == 'S' && i+2 <= rocks+1){
					leap = max(leap, dist[i+2]-x);
					//cout << "pulando de " << x << " para " << dist[i+2] << endl;
					x = dist[i+2];
					if(size_rock[i+2] == 'S') dist[i+2] = -1;
					i++;
					
				}
				else{
					leap = max(leap, dist[i+1]-x);
					//cout << "pulando de " << x << " para " << dist[i+1] << endl;
					x = dist[i+1];
					if(size_rock[i+1] == 'S') dist[i+1] = -1;
				}
		}
		x = distance;
		for(int i = rocks; i>=0; i--){
			if(dist[i] != -1 && dist[i] < x){
				leap = max(leap, x - dist[i]);
				x = dist[i];
				//cout << "Usando a pedra " << i << " com distancia de " << dist[i] << endl;
			}
		}
		printf("Case %d: %d\n",++caso,leap);
		
	}
	return 0;
}
