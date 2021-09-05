#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
typedef pair<int,int> pp;
bool com(pp x, pp y){
    if(x.ff == y.ff) return x.ss < y.ss;
    return x.ff < y.ff;
}
ll power(ll x, ll y){
    ll prod = 1;
    while(y){
        if(y & 1) prod = (prod * x) % mod;
        x = (x * x) % mod;
        y /= 2;
    }
    return prod;
}
const int N = 2e5 + 7;
class seg_tree{
    public:
    int n;
    vector<pair<ll, int>> tree;
    seg_tree(int N){
        n = N;
        tree.resize(2 * N + 2);
    }
    void update(int p, ll val, int add){
        p += n;
        tree[p].first += val;
        tree[p].second += add;
        for(; p > 0; p /= 2){
            tree[p >> 1].first = tree[p].first + tree[p ^ 1].first;
            tree[p >> 1].second = tree[p].second + tree[p ^ 1].second;
        }
    }
    pair<ll,int> rangesum(int l, int r){
        ll sum = 0;
        int cnt = 0;
        for(l += n, r += n + 1; l < r; l /= 2, r /= 2){
            if(l & 1){
                sum += tree[l].first;
                cnt += tree[l].second;
                l++;
            }
            if(r & 1){
                r--;
                sum += tree[r].first;
                cnt += tree[r].second;
            }
        }
        return {sum % mod, cnt};
    }
};
void solve(){
    int n;
    cin >> n;
    //n = 2e5;
    ll ans = 0, sum = 0;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    map<ll, int> mp;
    for(int i = 0; i < n; i++) mp[a[i]]++;
    int cnt = 0;
    // data compression
    for(auto v : mp){
        mp[v.first] = cnt++;
    }
    // for leftsubarray
    seg_tree pre = seg_tree(N);
    // for rightsubarray
    seg_tree suff = seg_tree(N);
    for(int i = 0; i < n; i++) suff.update(mp[a[i]], a[i], 1);
    for(int i = 0; i < n; i++){
        pair<ll, int> left = pre.rangesum(0, mp[a[i]] - 1);
        pair<ll, int> right = suff.rangesum(mp[a[i]] + 1, N);
        ans += (((right.second * left.first) % mod )* 1ll + (left.second * right.first) % mod) % mod;
        ans += (((left.second * right.second) % mod) * a[i]) % mod;
        ans %= mod;
        // cout << ans << " ";
	  // when we go left to right we have to update the A[i] in leftsubarray
        pre.update(mp[a[i]], a[i], 1);
	  // here we are removing A[i] from right subarray as it is added in left subarray
        suff.update(mp[a[i]], -a[i], -1);
    }
    cout << ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0); 
    int t = 1;
    //cin >> t;
    while (t--) 
        solve();
    return 0; 
}
