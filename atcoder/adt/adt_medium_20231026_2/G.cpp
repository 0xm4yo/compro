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
const ll INF = numeric_limits<ll>::max();

int main()
{
    ll n,x;
    cin>>n>>x;
    string s;
    cin>>s;
    string t = "";
    while (x){
        t += '0' + x%2;
        x /= 2;
    }
    reverse(all(t));

    vector<ll>arr;
    rep(i,0,t.size()) arr.push_back(t[i]-'0');
    rep(i,0,n){
        if (s[i]=='U'){
            arr.pop_back();
        }else if (s[i]=='L'){
            arr.push_back(0);
        }else{
            arr.push_back(1);
        }
    }
    reverse(all(arr));
    ll ans = 0;
    rep(i,0,arr.size()){
        ans += (ll)pow(2LL,i) * arr[i];
    }
    cout << ans << endl;

    return 0;
}