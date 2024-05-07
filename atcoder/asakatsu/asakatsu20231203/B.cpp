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
    string s;
    cin>>s;
    bool flag = true;
    if (s[0]!='A') flag = false;
    string t = "";
    rep(i,2,s.size()-1){
        t += s[i];
    }
    if (t.find('C')==string::npos) flag = false;
    
    ll cnt = 0;
    rep(i,1,s.size()){
        if (s[i]=='C' && cnt==0){
            cnt++;
            continue;
        }
        rep(j,0,26){
            if (s[i]==char('A'+j)) flag = false;
        }
    }
    if(flag) cout << "AC" << endl;
    else cout << "WA" << endl;
    return 0;
}