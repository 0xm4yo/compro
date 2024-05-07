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
const ll INF = numeric_limits<ll>::max();

ll op(ll a, ll b){ return a+b; };
ll e(){ return 0; };

int main()
{
    string s;
    cin>>s;
    map<char,ll> mp = {{'a',0},{'t',1},{'c',2},
        {'o',3},{'d',4},{'e',5},{'r',6}};
    vector<ll>arr;
    rep(i,0,s.size()){
        arr.push_back(mp[s[i]]);
    }
    segtree<ll,op,e>seg(s.size());
    ll ans = 0;
    for (auto a: arr){
        ans += seg.prod(a, s.size());
        seg.set(a,1);
    }
    cout << ans << endl;
    return 0;
}