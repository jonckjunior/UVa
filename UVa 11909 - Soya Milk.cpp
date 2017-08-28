#include <bits/stdc++.h>

using namespace std;

double const pi = acos(-1.0);

#define DEG_TO_RAD(theta) (theta*pi/180.0)

int main(){
	double l,w,h,delta,a,b,c;
	while(cin >> l >> w >> h >> delta){
		a = l;
		b = tan(DEG_TO_RAD(delta))*a;
		c = sqrt(a*a + b*b);		
		double p = a + b + c;
		double s = p/2.0;
		double area = sqrt(s * (s-a) * (s-b) * (s-c)) * w;
		double areaTotal = l*w*h;
		if(b <= h)
			printf("%.3f mL\n",areaTotal-area);
		else{
			c = h * tan(pi/2.0 - DEG_TO_RAD(delta));
			printf("%.3f mL\n",h*w*c/2.0);
		}
	}
	return 0;
}
