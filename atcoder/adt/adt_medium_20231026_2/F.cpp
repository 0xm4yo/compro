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
    ll n;
    cin>>n;
    vector<ll> s;
    while (n){
        s.push_back(n%10);
        n /= 10;
    }
    sort(all(s));
    ll sz = s.size();
    ll ans = 0;
    do{
        if (s[0]==0)continue;
        rep(i,1,sz){
            ll a = 0;
            rep(k,0,i){
                a += s[k]*(ll)pow(10LL,k);
            }
            ll b = 0;
            rep(k,i,sz){
                b += s[k]*(ll)pow(10LL,k-i);
            }
            chmax(ans, a*b);            
        }

    }while(next_permutation(all(s)));
    cout << ans << endl;
    return 0;
}