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
    map<char,char>mp;
    rep(i,0,26){
        mp[x[i]] = 'a'+i;
    }
    vector<pair<string,string>>arr;
    rep(i,0,n){
        ll sz = s[i].size();
        string t = "";
        rep(j,0,sz){
            t += mp[s[i][j]];
        }
        arr.push_back({t,s[i]});
    }
    sort(all(arr));
    for (auto [t,s]: arr){
        cout << s << endl;
    }

}