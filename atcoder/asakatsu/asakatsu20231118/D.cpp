#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

#define rep(i, a, b) for(ll i=a; i<b; i++)
#define rrep(i, a, b) for(ll i=a; i>=b; i--)
#define all(a) (a).begin(), (a).end()
#define YesNo(bool) if(bool){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

const double pi = 3.141592653589793;
const ll INF = (ll)1e18+10;

int main()
{
    ll n;
    cin>>n;
    ll a,b,c;
    cin>>a>>b>>c;
    vector<ll>arr;
    arr.push_back(a);
    arr.push_back(b);
    arr.push_back(c);
    sort(all(arr));
    if (find(all(arr), n)!=arr.end()){
        cout << "NO" << endl;
        return 0;
    }
    ll cnt = 0;
    while(n>0){
        if (find(all(arr), n-3)==arr.end()){
            cnt++;
            n-=3;
        }else if(find(all(arr), n-2)==arr.end()){
            cnt++;
            n-=2;
        }else if(find(all(arr), n-1)==arr.end()){
            cnt++;
            n-=1;
        }else{
            cout << "NO" << endl;
            return 0;
        }
    }
    YesNo(cnt<=100);
    return 0;
}