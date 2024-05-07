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
const ll INF = (ll)3e15;

int main()
{
    ll n;
    cin>>n;
    string s;
    cin>>s;
    stack<ll> q;
    vector<pair<ll,ll>>arr;
    ll pos = 0;
    while (pos < n){
        if (s[pos]=='(') q.push(pos);
        if (s[pos]==')'){
            if (!q.empty()){
                ll l = q.top(); q.pop();
                arr.push_back({l,pos+1});
            }
        }
        pos++;
    }
    vector<ll>flag(n);
    sort(all(arr));
    for(auto [l,r]: arr){
        if (flag[l])continue;
        rep(i,l,r){
            flag[i] = 1;
        }
    }
    string ans = "";
    rep(i,0,n)if(!flag[i])ans+=s[i];
    
    cout << ans << endl;
    return 0;
}