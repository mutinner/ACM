#include<iostream>
using namespace std;

typedef long long ll;
const int N=2005;
const ll p=1e9+7;
long long fac[N];

void init(long long p){
	fac[0]=1;
	for(long long i=1;i<=p;i++){
		fac[i]=fac[i-1]*i%p;
	}
}

long long exp_mod(long long a,long long b,long long p){
	long long tmp=a%p,ans=1;
	while(b){
		if(b&1){
			ans=ans*tmp%p;
		}
		tmp=tmp*tmp%p;
		b>>=1;
	}
	return ans;
}

long long comb(long long n,long long m){
	if(m>n){
		return 0;
	}
	return fac[n]*exp_mod(fac[m]*fac[n-m],p-2)%p;
}

long long Lucas(long long n,long long m){
	if(m==0)	return 1;
	return (comb(n%p,m%p)*Lucas(n/p,m/p)%p);
}

int main(){
	init(p);
	cout<<Lucas(n,m,p)<<endl;
	return 0;
}
