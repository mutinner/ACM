#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=1e5+10;
int dp[maxn],ans[maxn];

int main(){
	int len=0;
	dp[0]=ans[0];
	for(int i=1;i<n;i++){
		if(ans[i]>=dp[len])		dp[++len]=ans[i];
		else {
			int x=upper_bound(dp,dp+len+1,ans[i])-dp;
			dp[x]=ans[i];
		}
	}
	return 0;
}
