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
    ll a,b;
    cin>>a>>b;
    ll g = gcd(a,b);

    auto isprime = eratosthenes(1000000);

    auto f = [&](ll n){
        ll res = 0;
        for (long long i = 1; i * i <= n; i++){
            if (n % i == 0) {
                if (isprime[i]){
                    res++;
                    while(n%i==0) n /= i;
                }
            }
        }
        if (n!=1) res++;
        return res;
    };

    cout << f(g)+1 << endl;

    return 0;
}