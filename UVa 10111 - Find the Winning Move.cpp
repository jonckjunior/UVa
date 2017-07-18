#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

vector<string> m;

ii bfsX();
int bfsO();
map< vector<string>, int > mm;
bool isOver(char c){
    bool v = false;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(m[i][j] != c) break;
            if(j == 3) v = true;
        }
        for(int j = 0; j < 4; j++){
            if(m[j][i] != c) break;
            if(j == 3) v = true;
        }
    }
    int local = 1;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if(i+j == 3 && m[i][j] != c)
                local = 0;
    if(local) v = true;
    local = 1;
    for(int i = 0; i < 4; i++)
        if(m[i][i] != c) local = 0;
    if(local) v = true;
    return v;
}

int bfsO(){
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if(m[i][j] == '.'){
                m[i][j] = 'o';
                if(isOver('o') || bfsX() == ii(-1,-1)){
                    m[i][j] =  '.';
                    return 1;
                }
                m[i][j] = '.';
            }
    return 0;
}

ii bfsX(){
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if(m[i][j] == '.'){
                m[i][j] = 'x';
                if(isOver('x') || !bfsO()){
                    m[i][j] = '.';
                    return ii(i,j);
                }
                m[i][j] = '.';
            }
    return ii(-1,-1);
}

int main(){
    
    char c;
    while(scanf("%c",&c), c == '?'){
        m.assign(4, string());
        getchar();
        for(int i = 0; i < 4; i++)
            getline(cin, m[i]);
        ii res = bfsX();
        if(res == ii(-1,-1)) printf("#####\n");
        else                 printf("(%d,%d)\n",res.first, res.second);
    }

    return 0;
}
