#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
map<pair<int,int>, int> m;
int const max_v = 150;

double dist(ii &a, ii& b){
	return sqrt(pow(a.first-b.first,2) + pow(a.second-b.second,2));
}

int main(){
	int t,x1,x2,y1,y2,k,start_x, start_y;
	cin >> t;
	getchar();
	string entrada;
	getline(cin,entrada);
	double dist_total;
	while(t--){
		m.clear();
		k = 1;
		dist_total = 0;
		int primeiro = 1;
		while(getline(cin, entrada) && entrada.size() > 0){
			istringstream iss(entrada);
			if(primeiro) {
				iss >> start_x >> start_y, primeiro = 0;
			}
			else{
				iss >> x1 >> y1 >> x2 >> y2;	
				ii first = ii(x1,y1), second = ii(x2,y2);
				dist_total += dist(first,second);
			}

		}
		dist_total /= 500;
		int horas, minutos;
		horas = dist_total/20;
		minutos = round( 3*fmod(dist_total,20) );
		if(minutos == 60) horas++, minutos = 0;
		printf("%d:%02d\n",horas,minutos);
		if(t) cout << endl;
	}
}
