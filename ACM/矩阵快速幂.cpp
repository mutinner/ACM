#include<cstdio>
#include<cstring>
using namespace std;

typedef long long ll;
const int maxn=50,cnt=3;
const ll p=1e9+7;

struct Matrix{
	ll a[maxn][maxn];
	void init(){
		memset(a,0,sizeof(a));
		for(int i=0;i<cnt;i++)	a[i][i]=1;
	}
	void clear(){
		memset(a,0,sizeof(a));
	}
	void bug(){
		for(int i=0;i<cnt;i++){
			for(int j=0;j<cnt;j++){
				printf("%5lld ",a[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	Matrix operator *(const Matrix& x)const{
		Matrix ans;
		ans.clear();
		for(int k=0;k<cnt;k++)
		for(int i=0;i<cnt;i++){
			if()a[i][k]==0)	continue;
			for(int j=0;j<cnt;j++){
				ans.a[i][j]+=a[i][k]*x.a[k][j];
				ans.a[i][j]%=p;
			}
		}
		
		return ans;
	}
	Matrix operator +(const Matrix& x)const {
		Matrix ans;
		ans.clear();
		for(int i=0;i<cnt;i++){
			for(int j=0;j<cnt;j++){
				ans.a[i][j]=x.a[i][j]+a[i][j];
				ans.a[i][j]%=p;
			}
		}
		return ans;
	}
	Matrix operator ^(ll b)const {
		Matrix ans,x=*this;
		ans.init();
		while(b){
			if(b&1)	ans=ans*x;
			b>>=1;
			x=x*x;
		}
		return ans;
	}
}E;					//E的init必须要注意 

Matrix getsum(Matrix a,ll k){
	if(k==0)	return E;
	if(k==1)	return a;
	if(k&1==1)		return getsum(a,k-1)+(a^k);
	return	((a^(k>>1))+E)*getsum(a,k>>1);
}

int main(){
	
}
