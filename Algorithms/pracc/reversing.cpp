#include <bits/stdc++.h>

using namespace std;

int half(int x){
	return x>>1;
}

int power(int a, int b){
if(b == 1) return a;
auto res = power(a*a,b>>1);
return (b&1)?a*res:res;
}

void mojRev(string& s){
	auto start = s.begin();
	auto end  = s.end();
	
}

int main(void){
	std::cout << power(5,4) << std::endl;
	vector<int> w{1,2,3,4,5,6};
	string x = "zlatan";
	mojRev(x);
	cout << x;
}
