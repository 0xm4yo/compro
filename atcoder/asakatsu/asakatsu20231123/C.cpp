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

map<long long, int> primeFactorization(long long n){
    map<long long, int> res;
    for (long long i=2; i*i<=n; i++){
        while (n % i == 0){ res[i]++; n /= i;}
    }
    if(n != 1) res[n] = 1;
    return res;
}

int main()
{
    ll n;
    cin>>n;

    auto mp = primeFactorization(n);
    ll ans = 0;
    for (auto [key,cnt]: mp){
        ll l = 0;
        ll r = cnt+10;
        while(r-l>1){
            ll mid = (l+r)/2;
            ll temp = mid*(mid+1)/2;
            if (temp<=cnt) l= mid;
            else r = mid;
        }
        ans += l;
    }
    cout << ans << endl;
    return 0;
}