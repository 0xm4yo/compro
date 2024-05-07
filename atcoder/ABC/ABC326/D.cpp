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
    string r,c;
    cin>>n>>r>>c;
    bool ans = false;
    function<void(vector<string>)> dfs = [&](vector<string> v){
        string s = "ABC";
        rep(_,0,n-3) s += '.';
        sort(all(s));
        do{
            if (ans) break;
            char st;
            rep(i,0,n){
                if (s[i]=='.')continue;
                st = s[i];
                break;
            }
            ll raw = v.size()-1;
            if (r[raw] != st)continue;

            auto v2 = v;
            v2.push_back(s);
            bool flag = true;
            rep(j,0,n){
                vector<ll>cnt(3);
                rep(i,0,v2.size()){
                    if (v2[i][j] == '.')continue;
                    cnt[v2[i][j]-'A']++;
                }
                for (auto x: cnt){
                    if (x>1) flag = false;
                }
            }
            if (!flag) continue;
            vector<char> first(n, '.');
            rep(j,0,n)rep(i,0,v2.size()){
                if (v2[i][j]=='.')continue;
                first[j] = v2[i][j];
                break;
            }
            rep(j,0,n){
                if (first[j]=='.')continue;
                if (first[j]!=c[j]) flag = false; 
            }
            if (!flag) continue;
            if (v2.size()==n+1){
                cout << "Yes" << endl;
                rep(i,1,v2.size()){
                    cout << v2[i] << endl;
                    ans = true;
                }
                return ;
            }
            dfs(v2);
        }while(next_permutation(all(s)));
    };

    
    dfs({"....."});
    if (!ans) cout << "No" << endl;

    return 0;
}