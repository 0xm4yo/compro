#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int N, K, A[110], dp[100010];

int main()
{
    cin >> N >> K;
    for (int i=0; i<N; i++){
        cin >> A[i];
    }

    for (int i=0; i<K+1; i++){
        dp[i] = 0;
    }

    for (int i=1; i<K+1; i++){
        for (int j=0; j<N; j++){
            if (i-A[j] < 0){
                continue;
            }
            if (dp[i-A[j]] == 0){
                dp[i] = 1;
                break;
            }
        }
    }

    if (dp[K]){
        cout << "First" << endl;
    }else{
        cout << "Second" << endl;
    }

    return 0;
}