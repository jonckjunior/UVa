#include <stdio.h>
#include <iostream>

using namespace std;

#define INF 1<<30

int g1,g2,g3,b1,b2,b3,c1,c2,c3;
int gbc,gcb,bgc,bcg,cbg,cgb;

int fgbc(){
    int total=0;
    total+=b1;
    total+=c1;
    total+=g2;
    total+=c2;
    total+=g3;
    total+=b3;
    return total;
}
int fgcb(){
    int total=0;
    total+=b1;
    total+=c1;
    total+=g2;
    total+=b2;
    total+=g3;
    total+=c3;
    return total;
}

int fbgc(){
    int total=0;
    total+=g1;
    total+=c1;
    total+=b2;
    total+=c2;
    total+=g3;
    total+=b3;
    return total;
}

int fbcg(){
    int total=0;
    total+=g1;
    total+=c1;
    total+=g2;
    total+=b2;
    total+=b3;
    total+=c3;
    return total;
}

int fcbg(){
    int total = 0;
    total+=g1;
    total+=b1;
    total+=g2;
    total+=c2;
    total+=b3;
    total+=c3;
    return total;
}

int fcgb(){
    int total = 0;
    total+=g1;
    total+=b1;
    total+=b2;
    total+=c2;
    total+=g3;
    total+=c3;
    return total;
}


int main(){
    while(scanf("%d %d %d %d %d %d %d %d %d",&b1,&g1,&c1,&b2,&g2,&c2,&b3,&g3,&c3) != EOF){
        int lower = fbcg();
        string s = "BCG";

        gcb = fgcb();
        gbc = fgbc();
        bgc = fbgc();
        cbg = fcbg();
        cgb = fcgb();


        if(bgc < lower){
            lower = bgc;
            s = "BGC";
        }
        if(cbg < lower){
            lower = cbg;
            s = "CBG";
        }
        if(cgb < lower){
            lower = cgb;
            s = "CGB";
        }
        if(gbc < lower){
            lower = gbc;
            s = "GBC";
        }
        if(gcb < lower){
            lower = gcb;
            s = "GCB";
        }
        printf("%s %d\n",s.c_str(),lower);

    }


return 0;
}
