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

vector<long long> divisor(long long n){
    vector<long long> res;
    for (long long i = 1; i * i <= n; i++){
        if (n % i == 0) {
            res.push_back(i);
            if (i * i != n) res.push_back(n / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main()
{
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    ll ans = n;

    auto arr = divisor(n);

    for (auto x: arr){
        ll c = 0;
        vector<string>arr;
        string now = "";
        rep(i,0,n){
            now += s[i];
            if (now.size()==x){
                arr.push_back(now);
                now = "";
            }
        }
        rep(i,0,x){
            vector<ll> cnt(26);
            for (auto temp: arr){
                cnt[temp[i]-'a']++;
            }
            sort(all(cnt));
            ll tot = 0;
            rep(i,0,25) tot += cnt[i];
            c += tot;
        }
        if (c<=k){
            chmin(ans, x);
        }
    }
    cout << ans << endl;
    
    return 0;
}