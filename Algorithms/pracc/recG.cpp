#include <bits/stdc++.h>

using namespace std;

long long sum(int n){
	if(n==1) return 1;
	else return ((long long)pow(n,n)+sum(n-1));
}


int main(void){
	cout << sum(5) << endl;
	cout << lnFact(2) << endl;
	return 0;
}
