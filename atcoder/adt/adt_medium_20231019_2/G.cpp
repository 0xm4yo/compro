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

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<stack<ll>> s(m);
    rep(i,0,m){
        ll k;
        cin>>k;
        rep(j,0,k){
            ll a;
            cin>>a;
            a--;
            s[i].push(a);
        }
    }
    vector<vector<ll>> arr(n); 
    queue<tuple<ll,ll,ll>> q;
    rep(i,0,m){
        ll a = s[i].top();
        arr[a].push_back(i);
        if (arr[a].size()==2){
            q.push({a,arr[a][0],arr[a][1]});
        }
    }
    vector<bool>v(n);
    while (!q.empty()){
        auto [now, i1, i2] = q.front(); q.pop();
        v[now] = true;
        s[i1].pop();
        s[i2].pop();
        if (!s[i1].empty()){
            ll a = s[i1].top();
            arr[a].push_back(i1);
            if (arr[a].size()==2){
                q.push({a,arr[a][0],arr[a][1]});
            }
        }
        if (!s[i2].empty()){
            ll a = s[i2].top();
            arr[a].push_back(i2);
            if (arr[a].size()==2){
                q.push({a,arr[a][0],arr[a][1]});
            }
        }
    }
    YesNo(find(all(v), false)==v.end());
    return 0;
}