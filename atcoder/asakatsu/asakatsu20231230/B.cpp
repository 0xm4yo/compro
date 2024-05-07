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
    ll n,m;
    cin>>n>>m;
    vector<ll>a(m);
    rep(i,0,m)cin>>a[i];
    vector<string>s(n);
    rep(i,0,n)cin>>s[i];
    vector<ll>arr;
    rep(i,0,n){
        ll temp = 0;
        rep(j,0,m){
            if (s[i][j]=='o'){
                temp += a[j];
            }
        }
        temp += i+1;
        arr.push_back(temp);
    }
    sort(all(arr));
    reverse(all(arr));
    rep(i,0,n){
        vector<ll>rem;
        ll now = i+1;
        rep(j,0,m){
            if (s[i][j]=='x'){
                rem.push_back(a[j]);
            }else{
                now += a[j];
            }
        }
        sort(all(rem));
        reverse(all(rem));
        ll ans = 0;
        ll pos = 0;
        while(now<arr[0]){
            now += rem[pos];
            ans++;
            pos++;
        }
        cout << ans << endl;
    }

    return 0;
}