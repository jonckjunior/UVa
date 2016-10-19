#include <bits/stdc++.h>
#define INF 1e7
#define MAX_N 30
#define bit(i) (1<<i)
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

long long int n,k, DP[105][105];

long long int solve(int number, int used){
    if(number < 0 || used < 0) return 0;
    if(number == 0 && used == 0) return 1;
    long long int &value = DP[number][used];
    if(value != -1) return value;
    value = 0;
    for(int i = 0; i <= number; i++)
        value = (value + solve(number-i,used-1))%1000000;
    return value;
}

int main(){
    while(cin >> n >> k, n+k != 0){
        memset(DP, -1, sizeof DP);
        cout << solve(n,k) << endl;
    }
}
 
