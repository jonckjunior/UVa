#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CTOI(c) c-'0'
 

int main() {
    
    char s[9];
    int t, num, sum,found, i, j, res, atual, temp, valid,caso=0;
    while(scanf("%s",s) && strcmp(s,"0") != 0){
    	printf("Case %d: ",++caso);
	    sscanf(s,"%d",&num);
	   
        found = 0;
        for(i = num; !found ; i++){
        	res = 0;
        	temp = i;
        	valid = 1;
        	while(temp > 0){
        		if(res & 1 << temp%10) {valid=0;break;} 
        		res|= 1 << temp%10;
        		temp/=10;
        	}
        	if(!valid) continue;
			sprintf(s,"%d",i);
            t = strlen(s);
            s[t] = '\0';
           	res = atual = 0;
           	
            while(1){            
            	if(res & (1 << atual)) break;
            	
            	res|= (1 << atual);
            	atual = (atual+CTOI(s[atual]))%t;
            }
            

            if( atual == 0 && (1<<t) -1 == res) printf("%d\n",i),found=1;
        }
    }
    
    return 0;
}
