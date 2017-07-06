#include <bits/stdc++.h>
using namespace std;
double const pi = acos(-1);
int main(){
	int a,b,v,delta,s;
	double vx,vy,dx,dy;
	while(cin >> a >> b >> v >> delta >> s && a + b + v + delta + s != 0){
		vx = cos( (delta*pi) / 180) * v;
		vy = sin( (delta*pi) / 180) * v;
		dx = s * vx/2.0 + a/2.0;
		dy = s * vy/2.0 + b/2.0;
		printf("%d %d\n", (int)dx/a, (int)dy/b);
	}
}
