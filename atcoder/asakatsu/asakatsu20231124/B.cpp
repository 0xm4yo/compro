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
    string s,t;
    cin>>s>>t;
    vector<ll>scnt(26), tcnt(26);
    ll n = s.size();
    ll srem = 0;
    ll trem = 0;
    rep(i,0,n){
        if(s[i]=='@') srem++;
        else scnt[s[i]-'a']++;
        if(t[i]=='@') trem++;
        else tcnt[t[i]-'a']++;
    }
    
    vector<char> arr = {'a','t','c','o','d','e','r'};
    bool flag = true;
    rep(i,0,26){
        if (scnt[i]==tcnt[i]) continue;
        if (find(all(arr), i+'a')!=arr.end()){
            if (scnt[i]<tcnt[i]){
                srem -= tcnt[i]-scnt[i];
            }else{
                trem -= scnt[i]-tcnt[i];
            }
        }else{
            flag = false;
        }
    }
    if (srem<0) flag = false;
    if (trem<0) flag = false;
    YesNo(flag);
    return 0;
}