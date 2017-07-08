#include <bits/stdc++.h>

using namespace std;

double getX(int n){
    int rn = sqrt(n);
    int cn = rn*rn;
    int difn = n-cn;
    double x;
    if(cn%2 == n%2) x = difn/2 - (rn+1)/2.0 + 0.5;
    else            x = difn/2 -rn/2.0 + 0.5;
    return x;
}

double getY(int n){
    double ht = sqrt(3)/2.0;
    int rn = sqrt(n);
    int cn = rn*rn;
    int difn = n-cn;
    double y;
    if(cn%2 == n%2) y = ht/3.0 - (rn+1)*ht;
    else            y = -ht/3.0 - rn*ht;
    return y;
}

int main(){
    int a,b,n,m;
    while(cin >> a >> b){
        double xa,xb,ya,yb,ht;
        xa = getX(a);
        xb = getX(b);
        ya = getY(a);
        yb = getY(b);
        printf("%.3f\n",sqrt(pow(xb-xa,2)+pow(yb-ya,2)));
    }
}
