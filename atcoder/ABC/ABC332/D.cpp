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

ll op(ll a,ll b){ return a + b; }
ll e(){ return 0LL; }

int main()
{
    ll h,w;
    cin>>h>>w;
    vector<vector<ll>>a(h,vector<ll>(w)), b(h,vector<ll>(w));
    rep(i,0,h)rep(j,0,w)cin>>a[i][j];
    rep(i,0,h)rep(j,0,w)cin>>b[i][j];
    vector<ll>arr;
    rep(i,0,h)arr.push_back(i);
    ll cnt = 0;
    ll ans = INF;
    do{
        vector<ll>arr2;
        rep(i,0,w)arr2.push_back(i);
        do{
            cnt++;
            assert(cnt<1000000);
            vector<vector<ll>> c(h,vector<ll>(w));
            rep(i,0,h)rep(j,0,w){
                c[i][j] = a[arr[i]][arr2[j]];
            }
            if (c==b){
                ll temp = 0;
                auto z = arr;
                segtree<ll,op,e> segh(h),segw(w);
                rep(i,0,h){
                    temp += segh.prod(z[i],h);
                    segh.set(z[i],1);
                }
                auto z2 = arr2;
                rep(i,0,w){
                    temp += segw.prod(z2[i],w);
                    segw.set(z2[i],1);
                }                
                chmin(ans,temp);
            }
        }while(next_permutation(all(arr2)));
    }while(next_permutation(all(arr)));
    if (ans==INF){
        cout << -1 << endl;
    }else{
        cout <<ans << endl;
    }
    return 0;
}