#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#define BRANCO 1
#define PRETO 2
#define MISTO 3
#define INF 10001
 
using namespace std;

struct city{
    char r,o,y,g,b;
    city(char rf, char of, char yf, char gf, char bf){
        r = rf;
        o = of;
        y = yf;
        g = gf;
        b = bf;
    }
};

int main() {
    string s;
    int k = 0,fim=0;
    char r,o,y,g,b;
    char id[5],c[5];
    while(getline(cin,s) && s != "#"){
        vector<city> vc; // aqui comeca as gambiarra
        sscanf(s.c_str(),"%c/%c,%c/%c,%c/%c,%c/%c,%c/%c",&id[0],&c[0],&id[1],&c[1],&id[2],&c[2],&id[3],&c[3],&id[4],&c[4]);
            for(int i = 0; i < 5; i++){
                if(id[i] == 'r') r = c[i];
                if(id[i] == 'o') o = c[i];
                if(id[i] == 'y') y = c[i];
                if(id[i] == 'g') g = c[i];
                if(id[i] == 'b') b = c[i];
            }
        vc.push_back(city(r,o,y,g,b));

        while(getline(cin,s) && s[0] != 'e'){
            sscanf(s.c_str(),"%c/%c,%c/%c,%c/%c,%c/%c,%c/%c",&id[0],&c[0],&id[1],&c[1],&id[2],&c[2],&id[3],&c[3],&id[4],&c[4]);
            for(int i = 0; i < 5; i++){
                if(id[i] == 'r') r = c[i];
                if(id[i] == 'o') o = c[i];
                if(id[i] == 'y') y = c[i];
                if(id[i] == 'g') g = c[i];
                if(id[i] == 'b') b = c[i];
            }
            vc.push_back(city(r,o,y,g,b));
        }
        
        int mini=1e9, i_mini=0, dif;
        for(int i = 0; i < vc.size(); i++){
            dif = 0;

            for(int j = 0; j < vc.size(); j++){
                if(vc[i].r != vc[j].r) dif++;
                if(vc[i].o != vc[j].o) dif++;
                if(vc[i].y != vc[j].y) dif++;
                if(vc[i].g != vc[j].g) dif++;
                if(vc[i].b != vc[j].b) dif++;
            }
            //printf("r/%c,o/%c,y/%c,g/%c,b/%c\n",vc[i].r,vc[i].o,vc[i].y,vc[i].g,vc[i].b);
            if(dif < mini){
                mini = dif;
                i_mini = i;
            }
        }
        cout << i_mini+1 << endl;
        
    }
    return 0;
}
