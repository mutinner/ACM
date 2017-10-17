#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=1e6+5;
int p[2*maxn+5];
char a[maxn+5],now[2*maxn+5];

int Manacher(char *s){
	int len=strlen(s+1);
	for(int i=1;i<=len;i++){
		now[2*i-1]='%';
		now[2*i]=s[i];
	}
	now[len=len*2+1]='%';
	int pos=0,R=0;
	for(int i=1;i<=len;i++){
		if(i<R)	p[i]=min(p[2*pos-i],R-i);
		else	p[i]=1;
		while(i-p[i]>=1&&i+p[i]<=len&&now[i-p[i]]==now[i+p[i]])	p[i]++;
		if(i+p[i]>R){
			pos=i;
			R=i+p[i];
		}
	}
	int MAX=0;
	for(int i=1;i<=len;i++)	MAX=max(MAX,p[i]-1);
//	for(int i=1;i<=len;i++)	printf("%d%c",p[i]-1," \n"[i==len]);
	return MAX;
}

int main(){
	while(scanf("%s",a+1)==1){
		printf("%d\n",Manacher(a));
	}
	return 0;
}
