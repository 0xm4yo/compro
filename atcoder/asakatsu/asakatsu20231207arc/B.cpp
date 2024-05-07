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
    vector<ll>s(n),t(m);
    rep(i,0,n)cin>>s[i];
    rep(i,0,m)cin>>t[i];
    set<ll> ss, tt;
    rep(i,0,n)ss.insert(s[i]);
    rep(i,0,m)tt.insert(t[i]);
    if (ss.size()<tt.size()){
        cout << -1 << endl;
        return 0;
    }
    if (ss.size()==1 && tt.size()==1 && *ss.begin()!=*tt.begin()){
        cout << -1 << endl;
        return 0;        
    }

    ll init = 0;
    while(init<n){
        init++;
        ll l = n-init;
        ll r = init%n;
        if (s[l] != s[0] || s[r] != s[0]){
            break;
        }
    }
    bool flag = true;
    ll now = s[0];
    ll ans = 0;
    rep(i,0,m){
        if (t[i]!=now){
            now ^= 1;
            if (flag){
                ans += init+1;
                flag = false;
            }else{
                ans += 2;
            } 
        }else{
            ans += 1;
        }
    }
    cout << ans << endl;

    return 0;
}