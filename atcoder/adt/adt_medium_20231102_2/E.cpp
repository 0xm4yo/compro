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
    ll n,m;
    cin>>n>>m;
    queue<vector<ll>> q;
    q.push({0});
    vector<vector<ll>> ans;
    while(!q.empty()){
        auto v = q.front(); q.pop();
        if (v.size()==n+1){
            ans.push_back(v);
            continue;
        }
        rep(i,v.back()+1,m+1){
            v.push_back(i);
            q.push(v);
            v.pop_back();
        }
    }
    for (auto a: ans){
        rep(i,1,n+1){
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}