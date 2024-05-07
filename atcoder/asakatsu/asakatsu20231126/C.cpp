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

vector<pair<char, int>> runLengthEncoding(string s){
    int n = s.length();
    vector<pair<char, int>> res;
    int l = 0;
    while (l < n){
        int r = l + 1;
        while (r < n && s[l] == s[r]) r++;
        res.push_back(make_pair(s[l], r-l));
        l = r;
    }
    return res;
}

int main()
{
    string s;
    cin>>s;
    ll k;
    cin>>k;
    ll n = s.size();
    vector<ll> cnt(2*(n+10));
    
    auto arr = runLengthEncoding(s);
    for (auto [ch,c]: arr){
        cnt[c] += k;
    }
    if (s[0]==s[n-1]){
        auto [ch1,c1] = arr[0];
        auto [ch2,c2] = arr.back();
        if (c1==n){
            cout << n*k/2 << endl;
            return 0;
        }
        cnt[c1] -= k-1;
        cnt[c2] -= k-1;
        cnt[c1+c2] += k-1;
    }
    
    ll ans = 0;
    rep(i,0,2*(n+10))ans+=(i/2)*cnt[i];

    cout << ans << endl;

    return 0;
}