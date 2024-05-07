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
    ll n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    queue<ll>q;
    rep(i,0,n-m+1){
        bool flag = true;
        rep(j,0,m){
            if (s[i+j]!=t[j]) flag = false;
        }
        if (flag) q.push(i);
    }
    vector<char> arr;
    rep(i,0,n)arr.push_back(s[i]);
    while(!q.empty()){
        ll now = q.front(); q.pop();
        rep(i,now,now+m){
            arr[i] = '#';
        }
        rep(i,max(0LL,now-m+1),now){
            bool flag = true;
            ll cnt = 0;
            rep(j,0,m){
                if (arr[i+j]!=t[j]){
                    if (arr[i+j]!='#'){
                        flag = false;
                    }else{
                        cnt++;
                    }
                }
            }
            if (flag && cnt<m) q.push(i);
        }
        rep(i,now+1,min(n-m+1,now+m)){
            bool flag = true;
            ll cnt = 0;
            rep(j,0,m){
                if (arr[i+j]!=t[j]){
                    if (arr[i+j]!='#'){
                        flag = false;
                    }else{
                        cnt++;
                    }
                }
            }
            if (flag && cnt<m) q.push(i);
        }        
    }
    bool flag = true;
    rep(i,0,n) if(arr[i]!='#') flag = false;
    YesNo(flag);

    return 0;
}