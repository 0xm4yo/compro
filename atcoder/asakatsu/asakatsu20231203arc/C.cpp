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
    string s,t;
    cin>>s>>t;

    auto ss = s;
    auto tt = t;
    sort(all(ss));
    sort(all(tt));
    if (ss!=tt){
        cout << -1 << endl;
        return 0;
    }
    ll l = -1;
    ll r = n;
    while(r-l>1){
        ll mid = (l+r)/2;
        vector<ll>cnt(26);
        rep(i,0,mid){
            cnt[s[i]-'a']++;
        }
        ll pos = mid;
        bool flag = true;
        rep(i,0,n){
            if (pos==n) break;
            if (t[i]!=s[pos]){
                cnt[t[i]]--;
                if (cnt[t[i]]<0) flag = false;
            }else{
                pos++;
            }
        }
        if (pos!=n) flag = false;
        if (flag) r = mid;
        else l = mid;
    }
    cout << r << endl;

    

    return 0;
}