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
    ll n;
    cin>>n;
    string s;
    cin>>s;
    vector<char> arr;
    rep(i,0,n){
        arr.push_back(s[i]);
        if (arr.size()<3)continue;
        ll sz = arr.size();
        if (arr[sz-3]=='f' && arr[sz-2]=='o' && arr[sz-1]=='x'){
            rep(_,0,3) arr.pop_back();
        }
    }
    cout << arr.size() << endl;
    return 0;
}