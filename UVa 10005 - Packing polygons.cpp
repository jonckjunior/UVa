#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<double, double> point;
typedef vector<point> vp;
#define TOL 1e-7
vp pontos;

double dist(point& p1, point& p2){
	return hypot(p1.first - p2.first, p1.second - p2.second);
}

bool circle2PtsRad(point p1, point p2, double r, point &c) {
  double d2 = (p1.first - p2.first) * (p1.first - p2.first) + 
              (p1.second - p2.second) * (p1.second - p2.second);
  double det = r * r / d2 - 0.25;
  if (det < 0.0) return false;
  double h = sqrt(det);
  c.first = (p1.first + p2.first) * 0.5 + (p1.second - p2.second) * h;
  c.second = (p1.second + p2.second) * 0.5 + (p2.first - p1.first) * h;
  return true; }


int main() {
	int n;
	double x,y,r,x2,y2,d,maxi;
	while(cin >> n, n != 0){
		pontos.clear();
		maxi = 0;
		for(int i = 0; i < n; i++){
			cin >> x >> y;
			pontos.push_back(point(x,y));
		}
		cin >> r;
		bool found = false;
		for(int i = 0; i < n && !found; i++) 
			for(int j = i+1; j < n && !found; j++){
				point aux;
				circle2PtsRad(pontos[i], pontos[j], r, aux);
				bool found2 = true;
				for(int k = 0; k < n && found2; k++){
					if(dist(pontos[k], aux) > r) found2 = false;
				}
				if(found2) found = true;
			}
		if(found) puts("The polygon can be packed in the circle.");
		else	  puts("There is no way of packing that polygon.");

	}
	return 0;
}
