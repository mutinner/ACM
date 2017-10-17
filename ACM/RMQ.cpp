#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

const int maxn=100005;
int dp[maxn][25],f[maxn];

void RMQ_init(int num){
	memset(dp,0,sizeof(dp));
	for(int i=0;i<num;i++)	dp[i][0]=f[i];
	for(int j=1;(1<<j)<=num;j++){
		for(int i=0;i+(1<<j)-1<num;i++){
			dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
		}
	}
}

int RMQ(int L,int R){
	int k=log(R-L+1)/log(2);
	return min(dp[L][k],dp[R-(1<<k)+1][k]);
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)	scanf("%d",f+i);
	RMQ_init(n);
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",RMQ(x-1,y-1));
	}
	return 0;
}
