#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countSubsequences(string X, string Z) {
    int m = X.size();
    int n = Z.size();
    
    // Cria uma matriz para armazenar resultados de subproblemas
    vector<vector<long long>> dp(m+1, vector<long long>(n+1, 0));
    
    // Inicializa a primeira coluna com 1, pois uma string vazia é subsequence de qualquer string
    for (int i = 0; i <= m; i++) {
        dp[i][0] = 1;
    }
    
    // Preenche dp[m+1][n+1] de maneira bottom-up
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            // Se os caracteres são iguais, adicione o número de subsequências sem o último caractere mais o número de subsequências até o último caractere
            if (X[i-1] == Z[j-1]) {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            } else {
                // Se não, apenas leva em conta as subsequências até o último caractere de X
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    // O último elemento de dp é o resultado
    return dp[m][n];
}

int main() {
    int testCases;
    cin >> testCases;
    
    while (testCases--) {
        string X, Z;
        cin >> X;
        cin >> Z;
        
        cout << countSubsequences(X, Z) << endl;
    }
    
    return 0;
}