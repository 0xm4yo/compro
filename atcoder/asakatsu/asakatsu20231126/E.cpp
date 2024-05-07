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
    ll n,q;
    cin>>n>>q;
    vector<ll> cl(n);
    rep(i,0,n)cin>>cl[i];
    rep(i,0,n)cl[i]--;
    vector<map<ll,ll>> arr(n);
    rep(i,0,n){
        arr[i][cl[i]]++;
    }

    dsu uf(n);
    while(q){
        q--;
        ll c,a,b;
        cin>>c>>a>>b;
        a--;b--;
        if (c==1){
            if (uf.same(a,b))continue;
            ll l = uf.leader(a);
            ll r = uf.leader(b);
            if (arr[l].size() > arr[r].size()) swap(l,r);
            for (auto [key,cnt]: arr[l]){
                arr[r][key] += cnt;
            }
            uf.merge(a,b);
            ll par = uf.leader(a);
            swap(arr[par], arr[r]);
        }else{
            ll par = uf.leader(a);
            cout << arr[par][b] << endl;
        }
    }

    return 0;
}