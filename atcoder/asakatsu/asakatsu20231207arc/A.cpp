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
    ll t;
    cin>>t;
    while(t){
        t--;
        ll n;
        cin>>n;
        ll cnt = 0;
        while(n%2==0){
            n /= 2;
            cnt++;
        }
        if (cnt==1){
            cout << "Same" << endl;
        }else if (cnt==0){
            cout << "Odd" << endl;
        }else{
            cout << "Even" << endl;
        }
    }
    return 0;
}