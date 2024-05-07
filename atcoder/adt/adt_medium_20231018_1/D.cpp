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
    vector<string>s(n);
    rep(i,0,n)cin>>s[i];
    bool flag = false;
    rep(i,0,n)rep(j,0,n){
        if (i==j)continue;
        string temp = s[i]+s[j];
        bool ff = true;
        rep(j,0,temp.size()){
            if (j>temp.size()-j-1)break;
            if (temp[j]!=temp[temp.size()-j-1]) ff = false;
        }
        if (ff) flag = true;
    }
    YesNo(flag);
    return 0;
}