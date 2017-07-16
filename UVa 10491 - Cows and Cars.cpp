#include <bits/stdc++.h>
#include <bitset>
#include <iterator>
using namespace std;

int main(){
    double cow,car,show;
    while(scanf("%lf %lf %lf",&cow,&car,&show) != EOF){
        double res = (cow*car)/( (cow+car) * (cow+car-1-show) );
        res += (car* (car-1))/( (cow+car)*(cow+car-1-show) );
        printf("%.5f\n",res);
    }    
}
