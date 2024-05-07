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
    vector<ll> arr;
    rep(i,1,15){
        string temp = "";
        rep(j,0,i){
            temp += '1';
        }
        arr.push_back(stoll(temp));
    }
    set<ll> st;
    rep(i,0,14){
        rep(j,0,14){
            rep(k,0,14){
                st.insert(arr[i]+arr[j]+arr[k]);
            }
        }
    }
    n--;
    auto itr = st.begin();
    rep(i,0,n) itr++;
    cout << *itr << endl;
    return 0;
}