#include<iostream>
#include<cstring>
#include<iomanip>
#include<cmath> 
using namespace std;
int kuai(int a,int b,int c){
	a%=c;
	long long int ans=1,base=a;
	while(b>0){
		if(b&1){
			ans=(ans*base)%c;
		}
		base=(base*base)%c;
		b>>=1;
	}
	return ans;
}
int main(){
	int a,b,c,ans;
	cin>>a>>b>>c;
	ans=kuai(a,b,c);
	if(a==0){
		cout<<c;
		return 0;
	}
	cout<<a<<"^"<<b<<" mod "<<c<<"="<<ans;
} 