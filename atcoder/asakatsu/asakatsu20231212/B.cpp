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
    string s;
    cin>>s;
    ll ab = 0;
    ll bb = 1;
    string ans = "";
    rep(i,0,n){
        if (s[i]=='a'){
            if (ab<a+b){
                cout << "Yes" << endl;
                ab++;
            }else{
                cout << "No" << endl;
            }
        }else if(s[i]=='b'){
            if (ab<a+b && bb<=b){
                cout << "Yes" << endl;
                ab++;
                bb++;
            }else{
                cout << "No" << endl;
            }
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}