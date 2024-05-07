#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

string K;
int D;
using mint = modint1000000007;
mint dp[10010][110][2];

int main()
{
    cin >> K;
    cin >> D;
    int l = K.size();
    
    dp[0][0][1] = 1;
    for (int i=0; i<l; i++) for (int j=0; j<D; j++) for (int m=0; m<2; m++){
        if (dp[i][j][m] == 0) continue;
        if (m){
            int _max = K[i]-'0';
            for (int k=0; k<=_max; k++){
                if (k == _max){
                    dp[i+1][(j+k)%D][1] += dp[i][j][m];
                }else{
                    dp[i+1][(j+k)%D][0] += dp[i][j][m];
                }
            }
        }else{
            for (int k=0; k<10; k++){
                dp[i+1][(j+k)%D][0] += dp[i][j][m];
            }
        }
    }

    mint ans = dp[l][0][0] + dp[l][0][1] - 1;
    cout << ans.val() << endl;

    return 0;
}