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

template <typename T> bool next_combination(const T first, const T last, int k) {
    const T subset = first + k;
    // empty container | k = 0 | k == n 
    if (first == last || first == subset || last == subset) {
        return false;
    }
    T src = subset;
    while (first != src) {
        src--;
        if (*src < *(last - 1)) {
            T dest = subset;
            while (*src >= *dest) {
                dest++;
            }
            iter_swap(src, dest);
            rotate(src + 1, dest + 1, last);
            rotate(subset, subset + (last - dest) - 1, last);
            return true;
        }
    }
    // restore
    rotate(first, subset, last);
    return false;
}

int main()
{
    ll n,m,k;
    cin>>n>>m>>k;
    vector<tuple<ll,ll,ll>> tp;
    rep(i,0,m){
        ll u,v,w;
        cin>>u>>v>>w;
        u--;v--;
        tp.push_back({u,v,w});
    }
    vector<ll>arr;
    rep(i,0,m)arr.push_back(i);
    ll ans = k;
    do{
        dsu uf(n);
        ll temp = 0LL;
        rep(i,0,n-1){
            auto [u,v,w] = tp[arr[i]];
            if (uf.same(u,v))break;
            uf.merge(u,v);
            temp += w;
            temp %= k;
        }
        if (uf.size(0)==n) chmin(ans,temp);
    }while(next_combination(all(arr), n-1));
    
    cout << ans << endl;
    return 0;
}