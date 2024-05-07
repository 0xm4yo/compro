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
const ll INF = (ll)1e9+10;

int main()
{
    ll t;
    cin>>t;
    while(t){
        t--;
        ll L,R;
        cin>>L>>R;
        bool flag = true;
        ll l = L-1;
        ll r = R;
        while (r-l>1){
            ll mid = (l+r)/2;
            bool flag = true;
            string t = to_string(mid);
            string s1 = "1";
            s1 += t;
            string s2 = t;
            s2 += '0';
            if (L<=stoll(s1) && stoll(s1)<=R) flag = false;
            if (L<=stoll(s2) && stoll(s2)<=R) flag = false;
            if (flag) r = mid;
            else l = mid;
        }
        cout << R - r + 1 << endl;
    }
    return 0;
}