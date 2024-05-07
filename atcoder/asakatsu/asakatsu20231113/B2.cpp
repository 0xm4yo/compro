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
    string x;
    cin>>x;
    ll n;
    cin>>n;
    vector<string>s(n);
    rep(i,0,n)cin>>s[i];
    map<char,char> mp, mp2;
    rep(i,0,26){
        mp[x[i]] = i+'a';
        mp2[i+'a'] = x[i];
    }
    vector<string>t(n);
    rep(i,0,n){
        rep(j,0,s[i].size()){
            t[i] += mp[s[i][j]];
        }
    }
    stable_sort(all(t));
    vector<string>ans(n);
    rep(i,0,n){
        rep(j,0,t[i].size()){
            ans[i] += mp2[t[i][j]];
        }
    }
    for (auto a: ans) cout << a << endl;

    return 0;
}