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
    ll n;
    cin>>n;
    vector<string> s(n);
    rep(i,0,n)cin>>s[i];
    set<string> st1,st2;
    rep(i,0,n){
        if (s[i][0]=='!'){
            string s2 = "";
            rep(j,1,s[i].size()) s2 += s[i][j];
            st2.insert(s2);
        }else{
            st1.insert(s[i]);
        }
    }
    for (auto ss: st1){
        if (st2.find(ss)==st2.end()) continue;
        cout << ss << endl;
        return 0;
    }
    cout << "satisfiable" << endl;
    return 0;
}