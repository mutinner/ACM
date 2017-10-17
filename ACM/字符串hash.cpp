#include<cstdio>
#include<cstring>
using namespace std;

typedef long long ll;
const int maxn=1e5+10,top=1e5+10;
const ll mod=1e9+7,se=26;
char s[maxn],ss[maxn];
ll ans[maxn],hash[maxn];

ll hash_value(int L,int R){
	return (ans[R]-ans[L-1]*hash[R-L+1]%mod+mod)%mod;
}

int main(){
	hash[0]=1;
	for(int i=1;i<=top;i++)	hash[i]=hash[i-1]*se%mod;
	scanf("%s%s",s+1,ss+1);
	ll w=0;		ans[0]=0;
	for(int i=1;s[i];i++)	ans[i]=(ans[i-1]*se+s[i]-'a')%mod;
	for(int i=1;ss[i];i++)	w=(w*se+ss[i]-'a')%mod;
	while(1){
		int L,R;
		scanf("%d%d",&L,&R);
		ll cnt=hash_value(L,R);
		printf("%d %d\n",w,cnt);
		printf("%s\n",cnt==w?"YES\n":"NO\n");
	}
	return 0;
}
