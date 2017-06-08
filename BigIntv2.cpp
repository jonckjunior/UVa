#include <bits/stdc++.h>

using namespace std;

typedef string BigInt;

bool IsBigger(BigInt a, BigInt b){
	if(a.size() > b.size()) return true;
	else if(a.size() < b.size()) return false;
	else{
		for(int i = 0; i < a.size(); i++){
			if(a[i] > b[i]) return true;
			else if(a[i] < b[i]) return false;
		}
	}
	return true;
}

bool isPositive(BigInt a){
	return a[0] != '-';
}

bool isNegative(BigInt a){
	return a[0] == '-';
}

BigInt addBigInt(BigInt a, BigInt b){
	int mini = min(a.size(), b.size()), na, nb, soma, rem;
	rem = 0;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	BigInt novoBig;
	for(int i = 0; i < mini; i++){
		na = a[i]-'0', nb = b[i]-'0';
		soma = na + nb + rem;
		if(soma>9){
			novoBig.push_back((soma%10)+'0');
			rem = soma/10;
		}
		else{
			novoBig.push_back(soma+'0');
			rem = 0;
		}
	}
	if(a.size() > b.size()){
		for(int i = mini; i < a.size(); i++){
			na = a[i]-'0';
			soma = na + rem;
			if(soma>9){
				novoBig.push_back((soma%10)+'0');
				rem = soma/10;
			}
			else{
				novoBig.push_back(soma+'0');
				rem = 0;
			}
		}
	}
	else{
		for(int i = mini; i < b.size(); i++){
			nb = b[i]-'0';
			soma = nb + rem;
			if(soma>9){
				novoBig.push_back((soma%10)+'0');
				rem = soma/10;
			}
			else{
				novoBig.push_back(soma+'0');
				rem = 0;
			}
		}
	}
	if(rem) novoBig.push_back(rem+'0');
	reverse(novoBig.begin(), novoBig.end());
	return novoBig;
}

BigInt MulBigInt(BigInt a, BigInt b){
	BigInt novoBig;
	int rem = 0, soma = 0;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	vector<BigInt> rs;
	for(int i = 0; i < b.size(); i++){
		novoBig = "";
		rem = 0;
		for(int j = 0; j < a.size(); j++){
			printf("fazendo %c %c\n",b[i],a[j]);
			soma = (a[j]-'0')*(b[i]-'0') + rem;
			printf("soma %d e rem era = %d\n",soma,rem);
			if(soma>9){
				novoBig.push_back((soma%10)+'0');
				rem = soma/10;
			}
			else{
				novoBig.push_back(soma+'0');
				rem = 0;
			}
			cout << novoBig << endl;
		}
		if(rem) novoBig.push_back(rem+'0');
		reverse(novoBig.begin(), novoBig.end());
		for(int k = 0; k < i; k++)
			novoBig.push_back('0');
		cout << "somou " << novoBig << endl;
		rs.push_back(novoBig);
	}
	novoBig = "0";
	for(int i = 0; i < rs.size(); i++)
		novoBig = addBigInt(novoBig, rs[i]);
	return novoBig;
}

BigInt SubtractBigInt(BigInt a, BigInt b){
	BigInt maior,menor, novoBig;
	if(IsBigger(a,b)) maior = a, menor = b;
	else	  		  maior = b, menor = a;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	reverse(maior.begin(), maior.end());
	reverse(menor.begin(), menor.end());
	int mini = min(maior.size(), menor.size());


	for(int i = 0; i < mini; i++){
		int na = maior[i]-'0', nb = menor[i]-'0';
		//printf("na = %d, nb = %d\n",na,nb);
		if(na >= nb){
			novoBig.push_back(na-nb+'0');
			//printf("colocando %d\n",na-nb);
		}
		else{
			maior[i+1] = maior[i+1] - 1;
			na+=10;
			novoBig.push_back(na-nb+'0');
			//printf("colocando %d\n",na-nb);
		}
	}
	if(IsBigger(a,b)){
		for(int i = mini; i < a.size(); i++)
			novoBig.push_back(maior[i]);
	}
	else{
		for(int i = mini; i < b.size(); i++)
			novoBig.push_back(maior[i]);	
	}
	//printf("Novo big = %s\n",novoBig.c_str());
	
	for(int i = novoBig.size() -1 ; i >= 0 ; i--){
		//printf("Analisando %c\n",novoBig[i]);
		if(novoBig[i] == '0' && novoBig.size() != 1) novoBig.pop_back();
		else{break;}
	}

	reverse(novoBig.begin(), novoBig.end());

	return novoBig;
}



BigInt addBigInteger(BigInt a, BigInt b){
	if(isPositive(a) && isPositive(b)){
		return addBigInt(a,b);
	}
	if(isPositive(a) && isNegative(b)){
		BigInt nb(b.begin()+1, b.end());
		if(IsBigger(nb,a)) return "-"+SubtractBigInt(a,nb);
		else			  return SubtractBigInt(a,nb);
	}
	if(isNegative(a) && isPositive(b)){
		BigInt na(a.begin()+1, a.end());
		if(IsBigger(na,b)) return "-"+SubtractBigInt(na,b);
		else			  return SubtractBigInt(na,b);
	}
	if(isNegative(a) && isNegative(b)){
		BigInt na(a.begin()+1, a.end());
		BigInt nb(b.begin()+1, b.end());
		return "-"+addBigInt(na,nb);
	}
}

BigInt SubtractBigInteger(BigInt a, BigInt b){
	if(isPositive(a) && isPositive(b)){
		if(IsBigger(a,b)) return SubtractBigInt(a,b);
		else			  return "-"+SubtractBigInt(a,b);
	}
	if(isPositive(a) && isNegative(b)){
		BigInt nb(b.begin()+1, b.end());
		return addBigInt(a,nb);
	}
	if(isNegative(a) && isPositive(b)){
		BigInt na(a.begin()+1, a.end());
		return "-"+addBigInt(na,b);
	}
	if(isNegative(a) && isNegative(b)){
		BigInt na(a.begin()+1, a.end());
		BigInt nb(b.begin()+1, b.end());
		if(IsBigger(nb,na)) return SubtractBigInt(nb,na);
		else				return "-"+SubtractBigInt(nb,na);
	}
}

BigInt MulBigInteger(BigInt a, BigInt b){
	if(a == "0" || b == "0") return "0";
	if(isPositive(a) && isPositive(b))
		return MulBigInt(a,b);
	else if(isPositive(a) && isNegative(b)){
		BigInt nb(b.begin()+1, b.end());
		return "-"+MulBigInt(a,nb);
	}
	else if(isNegative(a) && isPositive(b)){
		BigInt na(a.begin()+1, a.end());
		return "-"+MulBigInt(na, b);
	}
	else if(isNegative(a) && isNegative(b)){
		BigInt na(a.begin()+1, a.end());
		BigInt nb(b.begin()+1, b.end());
		return MulBigInt(na,nb);
	}
}

pair<BigInt,BigInt> DivideBigInt(BigInt a, BigInt b){
	if(b == "0"){printf("DIVISAO POR 0\n");exit(0);}
	if(a == "0") return make_pair("0","0");
	BigInt res = "0", div = b;

	while(IsBigger(a,b)){
		BigInt aux = "1";
		while(IsBigger(a,div)){
			div += "0";
			aux += "0";
		}
		div.pop_back();
		aux.pop_back();
		res = addBigInteger(res, aux);
		a = SubtractBigInteger(a,div);
		div = b;
	}
	return make_pair(res,res);
}

BigInt DivideBigInteger(BigInt a, BigInt b){
	if(isPositive(a) && isPositive(b)){
		return DivideBigInt(a,b).first;
	}
	else if(isPositive(a) && isNegative(b)){
		BigInt nb(b.begin()+1, b.end());
		return "-"+DivideBigInt(a,nb).first;
	}
	else if(isNegative(a) && isPositive(b)){
		BigInt na(a.begin()+1, a.end());
		return "-"+DivideBigInt(na, b).first;
	}
	else if(isNegative(a) && isNegative(b)){
		BigInt na(a.begin()+1, a.end());
		BigInt nb(b.begin()+1, b.end());
		return DivideBigInt(na,nb).first;
	}
}

BigInt ModuloBigInteger(BigInt a, BigInt b){
	BigInt res, adivb;
	adivb = DivideBigInteger(a,b);
	adivb = MulBigInteger(adivb, b);
	res = SubtractBigInteger(a, adivb);
	return res;
}

BigInt gcdBigInteger(BigInt a, BigInt b){
	if(b == "0") return a;
	else return gcdBigInteger(b, ModuloBigInteger(a,b));
}

pair< BigInt, pair<BigInt,BigInt> > ExtendedEuclides(BigInt a, BigInt b){
	if(b == "0") return make_pair(a, make_pair("1","0"));
	pair<BigInt, pair<BigInt,BigInt> > triple, triple2;
	triple = ExtendedEuclides(b, ModuloBigInteger(a,b));
	BigInt d = triple.first,y = triple.second.second,x = triple.second.first;
	BigInt adivb = DivideBigInteger(a,b);
	BigInt mulans = MulBigInteger(adivb, y);
	triple2 = make_pair(d, make_pair(y, SubtractBigInteger(x,mulans)   )  );
	return triple2;
}

BigInt ExponentiationBigInteger(BigInt a, BigInt b){
	if(b == "0") return "1";
	BigInt novoBig = a;
	for(BigInt i = "1"; i != b; i = addBigInteger(i, "1")){
		novoBig = MulBigInteger(novoBig, a);
	}
	return novoBig;
}

int main(){
	int choice = 1;
	BigInt a,b;
	while(choice){
		printf("1. Somar big int\n");
		printf("2. Multiplicar big int\n");
		printf("3. SubtractBigInt big int\n");
		printf("4. DivideBigInt big int\n");
		printf("5. ModuloBigInt big int\n");
		printf("6. Extended big int\n");
		printf("7. GCD big int\n");
		printf("8. Exp big int\n");
		cin >> choice;
		if(choice == 1){
			cin >> a >> b;
			cout << addBigInteger(a,b) << endl;
		}
		if(choice == 2){
			cin >> a >> b;
			cout << MulBigInteger(a,b) << endl;
		}
		if(choice == 3){
			cin >> a >> b;
			cout << SubtractBigInteger(a,b) << endl;
		}
		if(choice == 4){
			cin >> a >> b;
			cout << DivideBigInteger(a,b) << endl;
		}
		if(choice == 5){
			cin >> a >> b;
			cout << ModuloBigInteger(a,b) << endl;
		}
		if(choice == 6){
			cin >> a >> b;
			pair<BigInt, pair<BigInt,BigInt> > ans = ExtendedEuclides(a,b);
			cout << ans.first << " " << ans.second.first << " " << ans.second.second << endl;
		}
		if(choice == 7){
			cin >> a >> b;
			cout << gcdBigInteger(a,b) << endl;
		}
		if(choice == 8){
			cin >> a >> b;
			cout << ExponentiationBigInteger(a,b) << endl;
		}
	}
	return 0;
}
