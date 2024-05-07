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
    vector<ll>p(n),pos(n);
    rep(i,0,n)cin>>p[i];
    rep(i,0,n)p[i]--;

    vector<bool> v(n-1);
    vector<ll> ans;

    rep(i,0,n) pos[p[i]] = i;
    
    rep(i,0,n){
        ll now = pos[i];
        assert(now>=i);
        while(now>i){
            if (v[now-1]){
                cout << -1 << endl;
                return 0;
            }
            v[now-1] = true;
            swap(pos[p[now-1]], pos[p[now]]);
            swap(p[now-1],p[now]);
            ans.push_back(now);
            now--;
        }
    }
    
    rep(i,0,n-1){
        if (!v[i]){
            cout << -1 << endl;
            return 0;
        }
    }

    for (auto a: ans){
        cout << a << endl;
    }

    return 0;
}