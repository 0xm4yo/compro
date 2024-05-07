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
    ll n,q;
    cin>>n>>q;
    vector<ll>c(n);
    rep(i,0,n)cin>>c[i];

    vector<set<ll>> arr(n);
    rep(i,0,n) arr[i].insert(c[i]);
    while(q){
        q--;
        ll a,b;
        cin>>a>>b;
        a--;b--;
        if (arr[a].size()<arr[b].size()){
            for (auto x: arr[a]){
                arr[b].insert(x);
            }
            arr[a] = set<ll>();
        }else{
            for (auto x: arr[b]){
                arr[a].insert(x);
            }
            arr[b] = set<ll>();
            swap(arr[a],arr[b]);
        }
        cout << arr[b].size() << endl;
    }

    return 0;
}