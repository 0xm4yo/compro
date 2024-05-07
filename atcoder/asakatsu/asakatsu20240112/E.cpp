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
    vector<ll>a(n),b(n),c(m),d(m);
    rep(i,0,n)cin>>a[i];
    rep(i,0,n)cin>>b[i];
    rep(i,0,m)cin>>c[i];
    rep(i,0,m)cin>>d[i];
    bool flag = true;
    
    vector<tuple<ll,ll,ll>> tp;
    rep(i,0,n){
        tp.push_back({a[i],b[i],0});
    }
    rep(i,0,m){
        tp.push_back({c[i],d[i],1});
    }
    sort(all(tp));
    reverse(all(tp));
    multiset<ll> box;

    for (auto [x,y,c]: tp){
        if (c==0){
            auto itr = box.lower_bound(y);
            if (itr==box.end()){
                flag = false;
                break;
            }else{
                box.erase(itr);
            }
        }else{
            box.insert(y);
        }
    }

    YesNo(flag);
    

    return 0;
}