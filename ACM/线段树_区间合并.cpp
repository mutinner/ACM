#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

struct sgetree{
	int L,R,ls,rs,ms;
};

vector<sgetree> cnt;
stack<int> tmp;

void build(int x,int L,int R){
	cnt[x]=sgetree{L,R,R-L+1,R-L+1,R-L+1};
	if(L==R)    return ;
	int mid=(L+R)>>1;
	build(x<<1,L,mid);
	build(x<<1|1,mid+1,R);
}

void insert(int x,int u,int val){
	if(cnt[x].L==cnt[x].R){
		cnt[x].ls=cnt[x].rs=cnt[x].ms=val;
		return ;
	}
	int mid=(cnt[x].L+cnt[x].R)>>1;
	if(u<=mid)
		insert(x<<1,u,val);
	else 
		insert(x<<1|1,u,val);
	cnt[x].ls=cnt[x<<1].ls;
	cnt[x].rs=cnt[x<<1|1].rs;
	cnt[x].ms=max({cnt[x<<1].ms,cnt[x<<1|1].ms,cnt[x<<1].ls+cnt[x<<1|1].rs});
	if(cnt[x<<1].ls==cnt[x<<1].R-cnt[x<<1].L+1)
		cnt[x].ls+=cnt[x<<1|1].ls;
	if(cnt[x<<1|1].rs==cnt[x<<1|1].R-cnt[x<<1|1].L+1)
		cnt[x].rs+=cnt[x<<1].rs;
}

int query(int x,int u){
	if(cnt[x].ms==0||cnt[x].L==cnt[x].R||cnt[x].ms==cnt[x].R-cnt[x].L+1)
		return cnt[x].ms;
	int mid=(cnt[x].L+cnt[x].R)>>1;
	if(u<=mid){
		if(u>cnt[x<<1].R-cnt[x<<1].rs)
			return query(x<<1,u)+query(x<<1|1,mid+1);
		else
			return query(x<<1,u);
	}else{
		if(u<cnt[x<<1|1].L+cnt[x<<1|1].ls)
			return query(x<<1|1,u)+query(x<<1,mid);
		else
			return query(x<<1|1,u);
	}
}

int main(){
	return 0;
}
