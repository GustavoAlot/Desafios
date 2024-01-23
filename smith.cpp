#include <iostream>
#include <vector>

using namespace std;

int somaNum(int num) {
    int soma = 0;
    while (num > 0) {
        soma += num % 10;
        num /= 10;
    }
    return soma;
}

int main() {
    int entradas;
    cin >> entradas;
    
    while (entradas--) {
        int n;
        cin >> n;
        
        n++; 
        
        while (true) {
            int num = n;
            int soma_digitos_n = 0;

            while (num > 0) {
                soma_digitos_n += num % 10;
                num /= 10;
            }

            // Encontre os fatores primos de n
            num = n;
            vector<int> prime_factors_n;

            for (int i = 2; i * i <= num; i++) {
                while (num % i == 0) {
                    prime_factors_n.push_back(i);
                    num /= i;
                }
            }

            if (num > 1) {
                prime_factors_n.push_back(num);
            }

            // Calcule a soma dos dígitos dos fatores primos
            int somaDigitosPrimos = 0;

            for (int factor : prime_factors_n) {
                somaDigitosPrimos += somaNum(factor);
            }

            if (soma_digitos_n == somaDigitosPrimos) {
                cout << n << endl;
                break;
            }
            
            n++;
        }
    }
    
    return 0;
}
