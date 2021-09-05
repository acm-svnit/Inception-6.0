#include <bits/stdc++.h>

#define ll long long int

#define MOD 1000000007

using namespace std;

ll dp[100000+10][10][2];

ll rec(int i,int n,int last,int streak)
{
    if(i==n)
    {
        return 1;
    }
    
    
    if(dp[i][last][streak]!=-1)
    return dp[i][last][streak];
    
    ll ans=0;
    for(int j=1;j<=9;++j)
    {
        if(streak==0)
        {
            if(j==last)
            ans=(ans+rec(i+1,n,j,1))%MOD;
            else
            ans=(ans+rec(i+1,n,j,0))%MOD;   
        }
        else if(streak==1)
        {
            if(j!=last)
            {
                ans=(ans+rec(i+1,n,j,0))%MOD;
            }
        }
    }
    
    return dp[i][last][streak]=ans;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    
    int n;
    cin>>n;
    
    cout<<rec(0,n,0,0)<<"\n";

}
