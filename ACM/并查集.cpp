#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=1e5+10;
int pre[maxn];

void init(){
	for(int i=0;i<maxn;i++)	pre[i]=i;
}

int find(int x){
	int u=x,v;
	while(x!=pre[x])	x=pre[x];
	while(u!=pre[u]){
		v=pre[v];
		pre[v]=x;
		u=v;
	}
	return x;
}

void Union(int u,int v){
	u=find(u);	v=find(v);
	if(u!=v)	pre[u]=v;
}
