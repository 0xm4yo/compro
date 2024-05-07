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
    ll n,a,b;
    cin>>n>>a>>b;
    ll mode = 0;
    while(1){
        if (mode){
            if (a<b-1){
                b--;
                mode^=1;
            }else{
                cout << "Alice" << endl;
                break;
            }
        }else{
            if(a+1<b){
                a++;
                mode^=1;
            }else{
                cout << "Borys" << endl;
                break;
            }
        }
        
    }
    return 0;
}