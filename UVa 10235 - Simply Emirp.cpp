#include <bits/stdc++.h>
using namespace std;
bitset<1000001> bt;
int main() {
    int n;

   	bt.set();
   	bt[0] = bt[1] = 0;
   	for(int i = 2; i < 1000000; i++) if(bt[i] == 1)
   			for(int j = i + i; j < 1000000; j+=i) bt[j] = 0;
    while(scanf("%d",&n) != EOF){
    	string s1 = to_string(n);
   		string s2(s1.rbegin(), s1.rend());
   		int n2 = stoi(s2);
   		if(bt[n] == 0) printf("%d is not prime.\n",n);
   		else if(bt.test(n) && bt.test(n2) && n != n2) printf("%d is emirp.\n",n);
   		else if(bt.test(n)) printf("%d is prime.\n",n);
    }
    return 0;
}
