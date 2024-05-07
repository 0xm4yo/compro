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
    ll k;
    cin>>k;
    auto mp = primeFactorization(k);
    ll l = 1;
    ll r = INF;
    auto f = [&](ll x){
        bool flag = true;
        for (auto [key,cnt]: mp){
            ll y = x;
            ll temp = 0;
            while (y){
                temp += y/key;
                y/=key;
            }
            if (temp<cnt) flag=false;
        }
        return flag;
    };
    while(r-l>1){
        ll mid = (l+r)/2;
        if (f(mid)){
            r = mid;
        }else{
            l = mid;
        }
    }
    cout << r << endl;
    return 0;
}