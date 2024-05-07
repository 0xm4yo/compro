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
    vector<pair<ll,ll>> arr;
    set<string>st;
    rep(i,0,n){
        string s;
        ll t;
        cin>>s>>t;
        if (st.find(s)!=st.end())continue;
        st.insert(s);
        arr.push_back({t,-(i+1)});
    }
    sort(all(arr));
    reverse(all(arr));
    cout << -arr[0].second << endl;
    return 0;
}