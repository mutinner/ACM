#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=5005;
int c[maxn];
int n;

int lowbit(int x){
	return x&(-x);
}

void add(int x,int num){
	while(x>0){
		c[x]+=num;
		x-=lowbit(x);
	}
}

int sum(int x){
	int ans=0;
	while(x<=n){
		ans+=c[x];
		x+=lowbit(x);
	}
	return ans;
}

int main(){
	
}
