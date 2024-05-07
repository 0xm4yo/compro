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
    ll n;
    cin>>n;
    vector<vector<ll>>arr(n);
    rep(i,0,n){
        ll c;
        cin>>c;
        rep(j,0,c){
            ll a;
            cin>>a;
            arr[i].push_back(a);
        }
    }
    ll x;
    cin>>x;
    ll sz = INF;
    vector<ll>ans;
    rep(i,0,n){
        if (find(all(arr[i]),x) == arr[i].end())continue;
        if (sz<arr[i].size()) continue;
        if (sz==arr[i].size()){
            ans.push_back(i+1);
        }else{
            sz = arr[i].size();
            while(ans.size()) ans.pop_back();
            ans.push_back(i+1);
        }
    }
    cout << ans.size() << endl;
    for (auto a: ans) cout << a << endl;
    return 0;
}