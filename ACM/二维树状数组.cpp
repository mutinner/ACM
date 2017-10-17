#include<cstdio>
#include<cstring>

typedef int status;
const int maxn=1000;
status c[maxn][maxn];
int n,m;

int lowbit(int x){
	return x&(-x);
}

void add(int x,int y,status num){
	for(int i=x;i<=n;i+=lowbit(i)){
		for(int j=y;j<=m;j+=lowbit(j)){
			c[i][j]+=num;
		}
	}
}

status sum(int x,int y){
	status ans=0;
	for(int i=x;i>0;i-=lowbit(i)){
		for(int j=y;j>0;j-=lowbit(j)){
			ans+=c[i][j];
		}
	}
	return ans;
}

status getsum(int x1,int y1,int x2,int y2){
	return sum(x2,y2)-sum(x1-1,y2)-sum(x2,y1-1)+sum(x1-1,y1-1);
}

int main(){
	
}
