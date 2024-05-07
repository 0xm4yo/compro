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
const ll INF = (ll)1e18+1;

int main()
{
    ll t;
    cin>>t;
    vector<ll>pow3 = {1};
    while(pow3.back()<=INF){
        pow3.push_back(pow3.back()*3);
    }
    reverse(all(pow3));
    pow3.pop_back();
    while(t){
        t--;
        ll n,k;
        cin>>n>>k;
        ll cnt = 0;
        for (auto x: pow3){
            if (n<x) continue;
            cnt += n/x;
            n %= x;
        }
        cnt += n;
        if (cnt>k){
            cout << "No" << endl;
            continue;
        }
        if ((k-cnt)%2){
            cout << "No" << endl;
        }else{
            cout << "Yes" << endl;
        }
    }
    return 0;
}