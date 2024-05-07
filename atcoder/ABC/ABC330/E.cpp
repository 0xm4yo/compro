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

ll op(ll a, ll b){ return min(a, b); }
ll e(){ return INF; }

int main()
{
    ll n, q;
    cin>>n>>q;
    vector<ll>a(n);
    rep(i,0,n)cin>>a[i];

    map<ll,ll>cnt;
    rep(i,0,n)cnt[a[i]]++;

    segtree<ll,op,e>seg(200010);
    for (auto x: a){
        if (x<200001) seg.set(x, INF);
    }

    set<ll>st;
    rep(i,0,n)st.insert(a[i]);
    rep(i,0,200001){
        if (st.find(i)==st.end()) seg.set(i,i);
    }

    while(q){
        q--;
        ll idx,x;
        cin>>idx>>x;
        idx--;

        ll y = a[idx];
        cnt[y]--;
        if (cnt[y]==0){
            if (y<200001) seg.set(y,y);
        }

        a[idx] = x;
        if (x<200001){
            cnt[x]++;
            seg.set(x,INF);
        }
        cout << seg.all_prod() << endl;
    }

    
    return 0;
}