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
    ll h,w;
    cin>>h>>w;
    vector<string> s(h);
    rep(i,0,h)cin>>s[i];
    vector<vector<ll>> ans(h,vector<ll>(w));
    vector<ll> dh = {0,0,-1,1};
    vector<ll> dw = {-1,1,0,0};
    rep(i,0,h)rep(j,0,w){
        if (s[i][j]=='.'){
            vector<ll> v(6);
            rep(k,0,4){
                ll nh = i + dh[k];
                ll nw = j + dw[k];
                if (nh<0 || nh>=h || nw<0 || nw>=w) continue;
                if (s[nh][nw]=='.'){
                    v[ans[nh][nw]] = true;
                }else{
                    v[s[nh][nw]-'0'] = true;
                }
                
            }
            rep(k,1,6){
                if (v[k]) continue;
                ans[i][j] = k;
                break;
            }
        }else{
            ans[i][j] = s[i][j] - '0';
        }
    }
    rep(i,0,h){
        rep(j,0,w){
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}