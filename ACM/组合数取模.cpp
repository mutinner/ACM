#include<iostream>
using namespace std;

typedef long long ll;
const ll mod=1e9+7;
const int maxn 2e5=10;

ll fac[maxn],finv[maxn],inv[maxn];

void init(){
	inv[1]=1;
	for(int i=2;i<maxn;i++)	inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	fac[0]=finv[0]=1;
	for(int i=1;i<maxn;i++){
		fac[i]=fac[i-1]*i%mod;
		finv[i]=finv[i-1]*inv[i]%mod;
	}
}

ll comb(int n,int m){
	if(m<0||m>n)	return 0;
	return fac[n]*finv[n-m]%mod*finv[m]%mod;
}

#include<iostream>
using namespace std;

ll fac[maxn];

void init(){
	fac[0]=1;
	for(int i=1;i<maxn;i++)	fac[i]=fac[i-1]*i%mod;
}

ll pow(ll a,ll b){
	ll ans=1;	a%=mod;
	while(b){
		if(b&1)	ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}

ll comb(ll n,ll m){
	if(m>n)	return 0;
	return fac[n]*pow(fac[m]*fac[n-m],mod-2)%mod;
}
