#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

#define rep(i, a, b) for(ll i=a; i<b; i++)
#define rrep(i, a, b) for(ll i=a; i>=b; i--)
#define all(a) (a).begin(), (a).end()
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

const double pi = 3.141592653589793;
const ll INF = (ll)1e18+10;

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<ll>a(m),b(m),c(m),d(m);
    rep(i,0,m)cin>>a[i]>>b[i];
    rep(i,0,m)cin>>c[i]>>d[i];
    rep(i,0,m){
        a[i]--;
        b[i]--;
        c[i]--;
        d[i]--;
    }
    vector<vector<ll>>gab(n);
    rep(i,0,m){
        gab[a[i]].push_back(b[i]);
        gab[b[i]].push_back(a[i]);
    }
    bool flag = false;
    vector<ll>arr;
    rep(i,0,n)arr.push_back(i);
    do{
        vector<vector<ll>>gcd(n);
        map<ll,ll>mp;
        rep(i,0,n){
            mp[i] = arr[i];
        }
        rep(i,0,m){
            gcd[mp[c[i]]].push_back(mp[d[i]]);
            gcd[mp[d[i]]].push_back(mp[c[i]]);
        }
        bool sc = true;
        rep(i,0,n){
            sort(all(gab[i]));
            sort(all(gcd[i]));
            if (gab[i]!=gcd[i]) sc = false;
        }
        if (sc) flag = true;
    }while(next_permutation(all(arr)));
    YesNo(flag);
    return 0;
}