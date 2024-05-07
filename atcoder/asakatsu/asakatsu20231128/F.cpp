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
    ll n,k;
    cin>>n>>k;

    vector<pair<ll,ll>> p;
    rep(i,0,n){
        ll t,d;
        cin>>t>>d;
        p.emplace_back(d,t);
    }
    sort(all(p));
    reverse(all(p));
    vector<pair<ll,ll>> hq, rem;
    vector<ll> cnt(n+1);

    ll init = 0;
    ll init_sz = 0;
    rep(i,0,k){
        cnt[p[i].second]++;
        init += p[i].first;
        if (cnt[p[i].second]==1) init_sz++;
        else hq.push_back(p[i]);
    }

    init += init_sz * init_sz;
    sort(all(hq));
    rep(i,k,n){
        auto [d,t] = p[i];
        cnt[t]++;
        if (cnt[t]==1) rem.push_back(p[i]);
    }

    ll kk = k - init_sz;
    ll m = min(kk, (ll)rem.size());
    ll now = 0;
    ll nex = 0;
    sort(all(rem));
    reverse(all(rem));
    ll ans = init;
    rep(i,0,m){
        now += hq[i].first;
        nex += rem[i].first;
        nex += (init_sz+i+1)*(init_sz+i+1) - init_sz*init_sz;
        chmax(ans, init-now+nex);
        nex -= (init_sz+i+1)*(init_sz+i+1) - init_sz*init_sz;
    }

    cout << ans << endl;

    return 0;
}