#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

typedef long long ll;
const ll inf=1<<30;

struct sgetree{
	int L,R;
	ll sum,maxn,minn;
};

vector<sgetree> cnt;
vector<ll> add;

void pushup(int x){
	cnt[x].sum=cnt[x<<1].sum+cnt[x<<1|1].sum;
}

void pushdown(int x){
	if(add[x]!=0){
		add[x<<1]+=add[x];   add[x<<1|1]+=add[x];
		int mid=(cnt[x].L+cnt[x].R)>>1;
		cnt[x<<1].sum+=add[x]*(mid-cnt[x].L+1);
		cnt[x<<1|1].sum+=add[x]*(cnt[x].R-mid);
		add[x]=0;
	}
}

void build(int x,int L,int R){
	cnt[x]=sgetree{L,R,0,-inf,inf};
	add[x]=0;
	if(L==R)	return ;
	int mid=(L+R)>>1;
	build(x<<1,L,mid);
	build(x<<1|1,mid+1,R);
	pushup(x);
}

void insert(int x,int u,ll val){
	if(cnt[x].L==cnt[x].R){
		cnt[x].sum+=val;
		cnt[x].maxn+=val;
		cnt[x].minn+=val;
		return ;
	}
	int mid=(cnt[x].L+cnt[x].R)>>1;
	if(u<=mid)	insert(x<<1,u,val);
	else	insert(x<<1|1,u,val);
	pushup(x);
}

ll querysum(int x,int L,int R){
	if(L==cnt[x].L&&R==cnt[x].R)	return cnt[x].sum;
	int mid=(cnt[x].L+cnt[x].R)>>1;
	if(R<=mid)	return querysum(x<<1,L,R);
	else if(L>mid) return	querysum(x<<1|1,L,R);
	else	return querysum(x<<1,L,mid)+querysum(x<<1|1,mid+1,R);
}

void update(int x,int L,int R,ll val){
	if(L==cnt[x].L&&R==cnt[x].R){
		add[x]+=val;
		cnt[x].sum+=val*(R-L+1);
		return ;
	}
	pushdown(x);
	int mid=(cnt[x].L+cnt[x].R)>>1;
	if(R<mid+1)  update(x<<1,L,R,val);
	else if(L>mid)  update(x<<1|1,L,R,val);
	else {
		update(x<<1,L,mid,val);
		update(x<1|1,mid+1,R,val);
	}
	pushup(x);
}

ll query(int x,int L,int R){
	if(L==cnt[x].L&&R==cnt[x].R)    return cnt[x].sum;
	pushdown(x);
	int mid=(cnt[x].L+cnt[x].R)>>1;
	if(R<mid+1)  return query(x<<1,L,R);
	else if(L>mid)  return query(x<<1|1,L,R);
	else    return query(x<<1,L,mid)+query(x<<1|1,mid+1,R);
}

int main(){
	
}
