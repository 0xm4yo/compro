#include <bits/stdc++.h>
#include <atcoder/modint>

using namespace std;

#define rep(i, a, b) for(int i=a; i<b; i++)
#define rrep(i, a, b) for(int i=a; i>=b; i--)

using mint = atcoder::modint998244353;

int main()
{

    string s;
    cin>>s;
    int n = s.size();
    vector<vector<vector<vector<mint>>>> dp(n+1, vector<vector<vector<mint>>>(1<<10, vector<vector<mint>>(2, vector<mint>(2))));
    dp[n][0][1][1] = 1;
    rrep(i,n,1){
        int now = s[n-i]-'0';
        rep(j,0,1<<10){
            rep(mode,0,2){
                rep(l,0,2){
                    if (mode){
                        if (l){
                            rep(k,0,now+1){
                                if (k==0) dp[i-1][j][0][1] += dp[i][j][mode][l];
                                else if(k<now) dp[i-1][j^(1<<k)][0][0] += dp[i][j][mode][l];
                                else dp[i-1][j^(1<<k)][1][0] += dp[i][j][mode][l];
                            }
                        }else{
                            rep(k,0,now+1){
                                if(k<now) dp[i-1][j^(1<<k)][0][0] += dp[i][j][mode][l];
                                else dp[i-1][j^(1<<k)][1][0] += dp[i][j][mode][l];
                            }
                        }
                    }else{
                        if (l){
                            rep(k,0,10){
                                if (k==0) dp[i-1][j][0][1] += dp[i][j][mode][l];
                                else dp[i-1][j^(1<<k)][0][0] += dp[i][j][mode][l];
                            }
                        }else{
                            rep(k,0,10){
                                dp[i-1][j^(1<<k)][0][0] += dp[i][j][mode][l];
                            }
                        }
                    }
                }

            }
        }
    }
    mint ans = dp[0][0][0][0] + dp[0][0][1][0];
    cout << ans.val() << endl;

    return 0;
}