#include<iostream>
using namespace std;

int PowerMod(int a,int b,int c){
	int ans=1;
	a%=c;
	while(b>0){
		if(b%2==1)
			ans=(ans*a)%c;
		b/=2;
		a=(a*a)%c;
	}
	return ans;
}

int Mod(int a,int b,int c){
	a%=c;
	int res=1;
	while(b){
		if(b&1){
			res*=a;
		}
		b>>=1;
		a*=a;
		a%=c;
	}
	return res;
}

int main(){
}
