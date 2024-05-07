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
    string s;
    cin>>s;
    ll n = s.size();
    ll cnt = 0;
    ll pos = n;
    while (pos-1>=0 && s[pos-1]=='a'){
        pos--;
        cnt++;
    }

    ll cnt1 = 0;
    ll pos1 = -1;
    while (pos1+1<n && s[pos1+1]=='a'){
        pos1++;
        cnt1++;
    }

    ll sz = cnt-cnt1;
    bool flag = false;
    if (sz>0){
        string temp = "";
        rep(i,0,sz) temp+='a';
        string b = temp+s;
        string c = b;
        reverse(all(c));
        if (b==c) flag = true;
    }else{
        string c = s;
        reverse(all(c));
        if (s==c) flag = true;
    }
    YesNo(flag);


    
    return 0;
}