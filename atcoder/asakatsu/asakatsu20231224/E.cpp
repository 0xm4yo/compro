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
    ll n;
    cin>>n;
    vector<vector<ll>>arr(n);
    rep(i,0,n){
        rep(j,0,5){
            ll a;
            cin>>a;
            arr[i].push_back(a);
        }
    };
    vector<ll> mx(1LL<<5);
    rep(s,0,1LL<<5){
        ll temp = 0;
        rep(i,0,n){
            ll temp2 = INF;
            rep(j,0,5){
                if (s&(1LL<<j)) chmin(temp2, arr[i][j]);
            }
            chmax(temp,temp2);
        }
        mx[s] = temp;
    }
    ll ans = 0;
    rep(s1,1,1LL<<5){
        rep(s2,1,1LL<<5){
            if (s1&s2)continue;
            rep(s3,1,1LL<<5){
                if ((s1&s2)&s3) continue;
                if ((s1|s2|s3)!=((1LL<<5)-1)) continue;
                ll temp = INF;
                chmin(temp, mx[s1]);
                chmin(temp, mx[s2]);
                chmin(temp, mx[s3]);
                chmax(ans, temp);
            }
        }
    }
    cout << ans << endl;

    return 0;
}