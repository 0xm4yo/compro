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
const ll INF = (ll)3e15;

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<string>s(n),t(m);
    rep(i,0,n)cin>>s[i];
    rep(i,0,m)cin>>t[i];
    sort(all(s));
    set<string> st;
    rep(i,0,m)st.insert(t[i]);
    ll sz = 0;
    rep(i,0,n)sz+=s[i].size();
    ll r = sz+n-1;
    do{
        queue<tuple<string,ll,ll>> q;
        q.push({"",-1,16-r});
        while(!q.empty()){
            auto [temp, pos, rem] = q.front(); q.pop();
            ll nex = pos+1;
            if (nex==n-1){
                temp += s[nex];
                if (3 <= temp.size() && st.find(temp)==st.end()){
                    cout << temp << endl;
                    return 0;
                }
            }else{
                temp += s[nex];
                temp += '_';
                rep(i,0,rem+1){
                    auto temp2 = temp;
                    rep(j,0,i) temp2 += '_';
                    q.push({temp2, nex, rem-i});
                }
            }
        }    
    }while(next_permutation(all(s)));
    cout << -1 << endl;

    return 0;
}