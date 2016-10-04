#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#define LOL -1e9
using namespace std;

int main() {
    int n,l,w,x,r;
    while(cin >> n >> l >> w){
        vector< pair< double, double > > vp;
        for(int i = 0 ; i < n; i++){
            cin >> x >> r;
            if(r > w/2.0){
                double dx = sqrt(pow(r,2) - pow(w/2.0,2));
                vp.push_back(make_pair(x-dx,-x-dx));
            }
        }
        sort(vp.begin(), vp.end());
        double longest = 0;
        int nice = 0;
        for(int i = 0, j = 0; i < vp.size(); i++){
            double aux = longest;
            int indice = -1;
            while(j < vp.size() && vp[j].first <= longest){
                if(vp[j].second*-1 > aux){
                    aux = vp[j].second*-1;
                    indice = j;
                }
                j++;
            }
            if(aux >= l){
                cout << i+1 << endl;
                nice = 1;
                break;
            }
            if(indice == -1)
                break;
            longest = aux;
        }
        if(!nice) cout << -1 << endl;
    }
}
