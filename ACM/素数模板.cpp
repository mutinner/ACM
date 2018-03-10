#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=1e5+10;
int prime[maxn];
bool vis[maxn*1000];

void init(){
	int cnt=0;
	memset(vis,0,sizeof(vis));
	memset(prime,0,sizeof(prime));
	for(int i=2;i<maxn;i++){
		if(vis[i]==false)	prime[++cnt]=i;
		for(int j=1;j<=cnt&&i*prime[j]<=maxn;j++){
			vis[i*prime[j]]=true;
			if(i%prime[j]==0)	break;
		}
	}
}
