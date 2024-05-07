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

vector<bool> eratosthenes(int N){
    vector<bool> isprime(N+1, true);
    isprime[0] = isprime[1] = false;
    rep(p, 2, N+1){
        if (!isprime[p]) continue;
        int q = p + p;
        while (q < N+1){isprime[q] = false; q += p;}
    }
    return isprime;
}

int main()
{
    ll n;
    cin>>n;

    auto v = eratosthenes(n);
    vector<ll>arr;
    rep(i,0,v.size()) if(v[i]) arr.push_back(i);
    ll m = arr.size();
    vector<ll>cnt(m);
    rep(i,0,m){
        ll p = arr[i];
        ll now = n;
        ll tot = 0;
        while(now){
            tot += now/p;
            now /= p;
        }
        cnt[i] = tot;
    }
    ll ans = 0;
    ll cnt75 = 0;
    rep(i,0,m)if(cnt[i]>=74)cnt75++;

    ll cnt25 = 0;
    rep(i,0,m)if(cnt[i]>=24)cnt25++;

    ll cnt3 = 0;
    rep(i,0,m)if(cnt[i]>=2)cnt3++;
    
    ll cnt15 = 0;
    rep(i,0,m)if(cnt[i]>=14)cnt15++;

    ll cnt5 = 0;
    rep(i,0,m)if(cnt[i]>=4)cnt5++;

    ans += cnt75;
    ans += cnt25 * (cnt3-1);
    ans += cnt15*(cnt5-1);
    ans += cnt5*(cnt5-1)/2*(cnt3-2);
    cout << ans << endl;   

    return 0;
}