#include <bits/stdc++.h>
using namespace std;

int N;
int A[310], C[4];
double dp[310][310][310];
bool flag[310][310][310];

double f(int a, int b, int c){
        if (a == 0 && b == 0 && c == 0){
            return 0.0;
        }
        if (flag[a][b][c]){
            return dp[a][b][c];
        }
        flag[a][b][c] = true;

        double sm = a + b + c;
        double res = N / sm;
        if (a){
            res += f(a-1, b, c) * (double)(a/sm);
        }
        if (b){
            res += f(a+1, b-1, c) * (double)(b/sm);
        }
        if (c){
            res += f(a, b+1, c-1) * (double)(c/sm);
        }
        
        dp[a][b][c] = res;
        return res;
    }

int main()
{
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> A[i];
        C[A[i]]++;
    }

    for (int i=0; i<310; i++){
        for (int j=0; j<310; j++){
            for (int k=0; k<310; k++){
                flag[i][j][k] = false;
            }
        }
    }

    double ans = 0;
    ans = f(C[1], C[2], C[3]);
    cout << std::setprecision(15) << ans << endl;
    return 0;
}