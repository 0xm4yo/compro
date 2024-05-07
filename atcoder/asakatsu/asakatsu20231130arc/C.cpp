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
    string s;
    cin>>s;

    ll l = 0;
    rep(i,0,n){
        if (s[i]=='p'){
            l = i;
            break;
        }
    }
    if (s.find('p') == string::npos){
        cout << s << endl;
        return 0;
    }
    vector<ll> rr;
    rep(i,0,n){
        if (s[i]=='p') rr.push_back(i);
    }
    vector<string> temp;
    for (auto r: rr){
        string t = "";
        string tt = "";
        rep(i,0,l) tt += s[i];
        t += tt;
        tt = "";
        rrep(i,r,l){
            if (s[i]=='d') tt += 'p';
            else tt += 'd';
        }
        t += tt;
        tt = "";
        rep(i,r+1,n) tt += s[i];
        t += tt;
        temp.push_back(t);
    }
    sort(all(temp));
    cout << temp[0] << endl;

    return 0;
}