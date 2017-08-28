#include <bits/stdc++.h>

using namespace std;

double const pi = acos(-1.0);

int main(){
	double a,b,c;
	while(cin >> a >> b >> c){
		double p = a + b + c;
		double sp = p/2.0;
		double areaTriangle = sqrt(sp * (sp-a) * (sp-b) * (sp-c));
		double inCircle = areaTriangle/sp;
		inCircle = pi*inCircle*inCircle;
		double circumCircle = a*b*c/(4*areaTriangle);
		circumCircle = pi*circumCircle*circumCircle - areaTriangle;
		areaTriangle = areaTriangle - inCircle;
		printf("%.4f %.4f %.4f\n", circumCircle, areaTriangle, inCircle);
	}
	return 0;
}
