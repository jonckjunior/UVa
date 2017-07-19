#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int gcd(int a, int b){if(a%b == 0) return b;return gcd(b, a%b);}
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

vi p;

int main(){
    int n;
    while(scanf("%d",&n) , n != 0){
        int root = sqrt(n);
        p.clear();
        for(int i = 1; i <= root; i++){
            if(n%i == 0) {
                p.push_back(i);
                if(i*i != n)
                    p.push_back(n/i);
            }
        }
        int c = 1;
        for(int i = 0; i < p.size(); i++){
            for(int j = i + 1; j < p.size(); j++)
                if(lcm(p[i],p[j]) == n)
                    c++;
        }
        printf("%d %d\n",n,c);
    }
    return 0;
}
