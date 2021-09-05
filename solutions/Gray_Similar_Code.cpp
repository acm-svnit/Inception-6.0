#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e6+6;
ll mod = 1e9 + 7;
ll a[N];
ll b[N];

void power(ll n,ll m){
    b[0]=1;
	for(int i=1;i<=n;i++){
	    b[i] = (b[i-1] * 2)%m;
	}
}

void fac(ll n,ll mod){
	a[0] = 1;
	for(int i=1;i<=n;i++){
		a[i] = (a[i-1] * i)%mod;
	}
}

void solve(){
	ll n;
	cin>>n;
	ll ans = (a[n] * b[n])%mod;
	cout<<ans<<"\n";
}

int main(){
	int t;
	cin>>t;
	fac(1e6 + 5,mod);
	power(1e6+5,mod);
	while(t--){
		solve();
	}
	return 0;
}