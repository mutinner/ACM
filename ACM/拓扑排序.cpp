#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

const int maxn=550;
vector<int> G[maxn];
int vis[maxn];
queue<int> q;

int main(){
	memset(vis,0,sizeof(vis));
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		vis[v]++;
	}
	int cnt=0;
	while(!q.empty())	q.pop();
	for(int i=1;i<=n;i++){
		if(vis[i]==0)	q.push(i);
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		cnt++;
		int sz=G[u].size();
		for(int j=0;j<sz;j++){
			int v=G[u][j];
			if(--vis[v]==0)	q.push(v);
		}
	}
	return 0;
}
