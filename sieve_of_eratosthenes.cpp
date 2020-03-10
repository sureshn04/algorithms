#include <stdio.h>
#include<vector>
#define ull unsigned long long
using namespace std;

void primeGen(vector<bool>& A){
	ull i, p, n = A.size();
	
	for(p=2; p*p<=n; ++p){
		if(A[p]){
			for(i=p*2; i<=n; i = i + p)
				A[i] = false;
		}
	}
}

int main() {
	ull S, F;
	scanf("%llu %llu", &S, &F);
	vector<bool> A(F+1, true);
	primeGen(A);
	
	for(ull i=S; i<= F; ++i){
		if(A[i])
		printf(" %llu ", i);
	}
	return 0;
}
	
