#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cin>>n;
    vector <long long int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(), a.end(), greater<long long int>());
    long long int ans=a[0];
    for(int i=1;i<n/2;i++){
        ans+=2*a[i];
    }
    if(n&1)ans+=a[n/2];
    cout<<ans;
    return 0;
}