#include<iostream>
#include<random>
#include<algorithm>
#include<ctime>
#include<cmath>
using namespace std;

random_device seed;
mt19937 rd(time(NULL));
uniform_real_distribution<> dis(0,1);

double Tmin=1e-8,delta=0.98,T=100;
int k=100;

double getFun(double x,double y){
	return pow(x,7)*6+pow(x,6)*8+pow(x,3)*7+pow(x,2)*5-x*y;
}

double getSA(double y){
	double t=T;
	vector<double> x;
	for(int i=0;i<k;i++)	x.push_back(dis(rd)*100);
	while(t>Tmin){
		for(int i=0;i<k;i++){
			double tmp=getFun(x[i],y);
			double xnew=x[i]+(dis(rd)*2-1)*t;
			if(xnew>=0&&xnew<=100){
				double tmpnew=getFun(xnew,y);
				double dE=tmpnew-tmp;
				if(dE<0)	x[i]=xnew;
				else {
					double p=1.0/(1+exp(-dE/T));
					if(dis(rd)<p)	x[i]=xnew;
				}
			}
		}
		t*=delta;
	}
	double ans=(1<<30);
	for(auto it:x)	ans=min(ans,getFun(it,y));
	return ans;
}

int main(){
	cout<<getSA(1)<<endl;
	return 0;
}
