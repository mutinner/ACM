#include<cstdio>
#include<cstring>
using namespace std;

typedef int status;
const int maxn=5000;
status c[maxn],a[maxn];
int n; 

int lowbit(int x){
	return x&(-x);
}

void add(int x,status num){
	while(x<=n){
		c[x]+=num;
		x+=lowbit(x);
	}
}

status sum(int x){
	status ans=0;
	while(x>0){
		ans+=c[x];
		x-=lowbit(x);
	}
	return ans;
}

status getsum(int L,int R){
	return sum(R)-sum(L-1);
}

int main(){
	
}
