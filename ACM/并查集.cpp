#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

vector<int> pre;

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
