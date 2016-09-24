#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string.h>
#include <bitset>
#include <algorithm>
using namespace std;
#define bit(i) (1<<i)
#define INF 1e8
#define MIN(a,b) (a) < (b) ? (a) : (b)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int numstation;
double distancia, capacity, milpergalon, origin, half;
vector< pair<double,double> >prices;

double convert(double a){
    int x = a*100;
    return (x/100.0)*0.01;
}

double backtrack(int u, double g){
    if(u == numstation+1) return 0.0;
    if(g < 0) return INF;
    double xi = prices[u].first, pi = prices[u].second, xj = prices[u+1].first;
    double gconsumed = (xj - xi)/milpergalon, esq = INF, dir = INF;
    if(gconsumed > g)
        esq = backtrack(u+1,capacity-gconsumed)+convert((capacity-g)*pi)+2;
    else{
        if(g <= half)
            esq = backtrack(u+1,capacity-gconsumed)+convert((capacity-g)*pi)+2;
        dir = backtrack(u+1,g - gconsumed);
    }
    return MIN(esq,dir);
}
    
int main(){
    int caso = 0;
    double d,x;
    while(cin >> distancia && distancia >= 0){
        cin >> capacity >> milpergalon >> origin >> numstation;
        prices.clear();
        prices.push_back(make_pair(0.0,origin));
        for(int i = 1 ; i <= numstation; i++){
            scanf("%lf %lf",&d,&x);
            prices.push_back(make_pair(d,x));
        }
        prices.push_back(make_pair(distancia,0.0));
        half = capacity/2.0;
        printf("Data Set #%d\n",++caso);
        printf("minimum cost = $%.2lf\n",backtrack(1,capacity-prices[1].first/milpergalon)+origin);
    }
}

