#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn=100;
vector<int> G[maxn];
int tot=0,L[maxn],R[maxn];

void dfs(int x){
	L[x]=++tot;
	for(auto it:G[x])	dfs(it);
	R[x]=tot;
}
