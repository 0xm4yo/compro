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
    ll a,b,c,d;
    cin>>a>>b>>c>>d;

    vector<bool> pr = eratosthenes(500);
    rep(x,a,b+1){
        bool flag = true;
        rep(y,c,d+1){
            if (pr[x+y]) flag = false;
        }
        if (flag){
            cout << "Takahashi" << endl;
            return 0;
        }
    }
    cout << "Aoki" << endl;
    return 0;
}