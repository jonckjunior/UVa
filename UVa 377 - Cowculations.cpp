#include <bits/stdc++.h>

using namespace std;

pair<char,char> mt[4][4];

int getNum(char c){
    if(c == 'V') return 0;
    if(c == 'U') return 1;
    if(c == 'C') return 2;
    if(c == 'D') return 3;
}

string solve(string n1, string n2, char op){
    if(op == 'N') return n2;
    else if(op == 'A'){
        string mini, maxi,res="";
        if(n1.size() < n2.size()) mini = n1, maxi = n2;
        else                      mini = n2, maxi = n1;
        char carry = 'N';
        for(int i = 0; i < mini.size(); i++){
            int v1 = getNum(mini[mini.size()-1-i]);
            int v2 = getNum(maxi[maxi.size()-1-i]);
            //printf("analisando %c e %c\n",mini[mini.size()-1-i],maxi[maxi.size()-1-i]);
            pair<char,char> res1 = mt[v1][v2];
            //printf("<%c,%c>\n",res1.first,res1.second);
            if(carry == 'N'){
                carry = res1.second;
                res += res1.first;
            }
            else if(res1.second == 'N'){
                int vc = getNum(carry);
                pair<char,char> res2 = mt[vc][getNum(res1.first)];
                carry = res2.second;
                res += res2.first;
            }
            else if(res1.second != 'N'){
                int vc = getNum(carry);
                pair<char,char> res2 = mt[vc][getNum(res1.first)];
                carry = res1.second;
                res += res2.first;
            }
            //printf("foi adicionado %c na resposta com carry %c\n",res[res.size()-1],carry);
        }
        if(mini.size() == maxi.size())
            if(carry != 'N') res += carry;
        else{
            for(int i = mini.size(); i < maxi.size(); i++){
                if(carry == 'N') break;
                int v1 = getNum(carry);
                int v2 = getNum(maxi[i]);
                pair<char,char> ans = mt[v1][v2];
                res += ans.first;
                carry = ans.second;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
    else if(op == 'R'){
        string res = "V";
        n2.pop_back();
        res += n2;
        return res;
    }
    else if(op == 'L'){
        n2 += "V";
        return n2;
    }
}

int main(){
    
    mt[0][0] = make_pair('V','N');
    mt[0][1] = make_pair('U','N');
    mt[0][2] = make_pair('C','N');
    mt[0][3] = make_pair('D','N');
    mt[1][0] = make_pair('U','N');
    mt[1][1] = make_pair('C','N');
    mt[1][2] = make_pair('D','N');
    mt[1][3] = make_pair('V','U');
    mt[2][0] = make_pair('C','N');
    mt[2][1] = make_pair('D','N');
    mt[2][2] = make_pair('V','U');
    mt[2][3] = make_pair('U','U');
    mt[3][0] = make_pair('D','N');
    mt[3][1] = make_pair('V','U');
    mt[3][2] = make_pair('U','U');
    mt[3][3] = make_pair('C','U');
    
    int t;
    char op1,op2,op3;
    cin >> t;
    printf("COWCULATIONS OUTPUT\n");
    while(t--){
        string num1,num2,res;
        cin >> num1 >> num2;
        cin >> op1 >> op2 >> op3;
        cin >> res;

        num2 = solve(num1,num2,op1);

        num2 = solve(num1,num2,op2);

        num2 = solve(num1,num2,op3);

        string aux = "";
        for(int i = num2.size(); i < 8; i++) aux += 'V';
        num2 = aux + num2;
        if(num2 == res) printf("YES\n");
        
        else            printf("NO\n");
    }
    printf("END OF OUTPUT\n");
}
