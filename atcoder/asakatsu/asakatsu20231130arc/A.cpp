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
    ll n;
    cin>>n;
    string s;
    cin>>s;

    auto arr = runLengthEncoding(s);
    ll ans = 0;
    for (auto [ch,cnt]: arr){
        ans += (ll)cnt*((ll)cnt-1)/2LL;
    }
    cout << ans << endl;

    return 0;
}