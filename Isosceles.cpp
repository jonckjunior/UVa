#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MIN(a,b) (a < b) ? (a) : (b)
#define MAX(a,b) (a > b) ? (a) : (b)

int main() {
    
    int n,i,mx;
    scanf("%d",&n);
    int v[n];
    for(i=0;i<n;i++){
    	scanf("%d",&v[i]);
    	if(i==0||i==n-1)v[i]=1;
    	else if(i>0) v[i] = MIN(v[i-1]+1,v[i]);
    }
    mx=0;
    for(i=n-2;i>=0;i--){
    	v[i]=MIN(v[i],v[i+1]+1);
    	mx=MAX(mx,v[i]);
    }
    printf("%d\n",mx);
    
    return 0;
  
}
