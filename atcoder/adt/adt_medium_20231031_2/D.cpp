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
    ll h,m;
    cin>>h>>m;
    while (1){
        if (0<=h/10*10+m/10 && h/10*10+m/10<24 && 0<=(h%10)*10+m%10 && (h%10)*10+m%10 <60){
            cout << h << " " << m << endl;
            return 0;
        }
        if (m==59){
            h++;
            h%=24;
            m=0;
        }else{
            m++;
        }
    }
    return 0;
}