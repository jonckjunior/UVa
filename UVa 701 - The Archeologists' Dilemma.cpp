#include <bits/stdc++.h>

using namespace std;

int main() {
    string entrada;
    int n;
    while(cin >> n){
        int k = log10(n) + 2;
        double left=1,right=0;
        while(1){
            left = log2(n)+k*log2(10);
            right = log2(n+1)+k*log2(10);
            if((int)left<(int)right) break;
            k++;
        }
        cout << ceil(left) << endl;
    }
}
