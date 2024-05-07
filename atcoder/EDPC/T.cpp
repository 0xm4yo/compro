#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int N;
string S;
using mint = modint1000000007;
mint dp[3010][3010];
mint cum[3010][3010];

int main()
{
    cin >> N;
    cin >> S;

    dp[0][0] = 1;
    for (int i=1; i<N; i++) {
        for (int j=0; j<N+1; j++){
            cum[i-1][j+1] = cum[i-1][j] + dp[i-1][j];
        }
        if (S[i-1] == '<'){
            for (int j=0; j<i+1; j++) dp[i][j] += cum[i-1][j];
        }else{
            for (int j=0; j<N+1; j++) dp[i][j] += cum[i-1][i+1] - cum[i-1][j];
        }
    }

    mint ans = 0;
    for (int j=0; j<N+1; j++){
        ans += dp[N-1][j];
    }
    cout << ans.val() << endl;
    
    return 0;
}