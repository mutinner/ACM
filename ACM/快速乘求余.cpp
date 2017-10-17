#include<iostream>
using namespace std;

long long multi(long long a,long long b,long long m){
	long long ans=0;
	while(b){
		if(b&1){
			(ans+=a)%=m;
		}
		(a*=2)%=m;
		b/=2;
	}
	return ans;
}

int main(){
	
}
