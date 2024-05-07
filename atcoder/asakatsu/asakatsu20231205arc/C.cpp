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
    ll n,a,b,c;
    cin>>n>>a>>b>>c;
    vector<ll>arr(n);
    rep(i,0,n)cin>>arr[i];

    using P = pair<ll,ll>;
    auto f3 = [&](ll x, ll y, ll z){
        if (arr.size()<3) return INF;
        vector<ll> v = {x,y,z};
        ll res = INF;
        vector<vector<P>> pos(3);
        rep(i,0,3){
            priority_queue<P,vector<P>,greater<P>> hq;
            rep(j,0,n){
                hq.push({(v[i]-(arr[j]%v[i]))%v[i], j});
            }
            rep(j,0,3){
                pos[i].push_back(hq.top());
                hq.pop();
            }
        }
        rep(i,0,3)rep(j,0,3)rep(k,0,3){
            if (pos[0][i].second == pos[1][j].second || pos[1][j].second == pos[2][k].second || pos[2][k].second == pos[0][i].second) continue;
            chmin(res, pos[0][i].first + pos[1][j].first + pos[2][k].first);         
        }
        return res;
    };

    auto f2 = [&](ll x, ll y){
        if (arr.size()<2) return INF;
        vector<ll> v = {x,y};
        ll res = INF;
        vector<vector<P>> pos(2);
        rep(i,0,2){
            priority_queue<P,vector<P>,greater<P>> hq;
            rep(j,0,n){
                hq.push({(v[i]-(arr[j]%v[i]))%v[i], j});
            }
            rep(j,0,2){
                pos[i].push_back(hq.top());
                hq.pop();
            }
        }
        rep(i,0,2)rep(j,0,2){
            if (pos[0][i].second == pos[1][j].second) continue;
            chmin(res, pos[0][i].first + pos[1][j].first);         
        }
        return res;
    };

    auto f1 = [&](ll x){
        if (arr.size()<1) return INF;
        vector<ll> v = {x};
        ll res = INF;
        vector<vector<P>> pos(2);
        rep(i,0,1){
            priority_queue<P,vector<P>,greater<P>> hq;
            rep(j,0,n){
                hq.push({(v[i]-(arr[j]%v[i]))%v[i], j});
            }
            rep(j,0,1){
                pos[i].push_back(hq.top());
                hq.pop();
            }
        }
        rep(i,0,1){
            chmin(res, pos[0][i].first);   
        }
        return res;
    };

    ll ans = INF;
    chmin(ans, f3(a,b,c));
    chmin(ans, f2(a,lcm(b,c)));
    chmin(ans, f2(lcm(a,b),c));
    chmin(ans, f2(lcm(a,c),b));
    ll abc = lcm(a,b);
    abc = lcm(abc,c);
    chmin(ans, f1(abc));
    cout << ans << endl;
    return 0;
}