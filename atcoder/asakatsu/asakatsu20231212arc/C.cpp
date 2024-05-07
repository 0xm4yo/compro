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
    ll b,c;
    cin>>b>>c;
    ll ans = 0;
    if (b>0){
        ans += 2;
        if (b-c/2>0){
            ans += (c/2)*2;
            if (c/2>0 && c%2==0) ans--;
        }else{
            ans += b*2;
            ans--;
        }
        c--;
        ans += (c/2)*2;
        if (c/2>0 && c%2==0) ans--;
    }else if(b<0){
        ans += 2;
        ans += (c/2)*2;
        if (c/2>0 && c%2==0) ans--;
        c--;
        if (-b-c/2>0){
            ans += (c/2)*2;
            if (c/2>0 && c%2==0) ans--;
        }else{
            ans += -b*2;
            ans--;
        }
    }else{
        ans += 1;
        if (c>=2){
            c--;
            c--;
            ans += 1;
            if (c){
                ans += 1;
                ans += (c/2)*2;
                if (c/2>0 && c%2==0) ans--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}