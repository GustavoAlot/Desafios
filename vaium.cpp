#include <iostream>
#include <string>

using namespace std;

int main() {
    while (true) {
        string num1, num2;
        cin >> num1 >> num2;

        if (num1 == "0" && num2 == "0") {
            break;
        }

        int carregado = 0; 

        
        for (int i = num1.length() - 1, j = num2.length() - 1; i >= 0 || j >= 0; i--, j--) {
            int digit1 = 0;
            int digit2 = 0;

            if (i >= 0) {
                digit1 = num1[i] - '0'; //pega o valor em numero
            }
            if (j >= 0) {
                digit2 = num2[j] - '0';
            }

            int sum = digit1 + digit2;

            if (sum >= 10) {
                carregado++;
            } 
        }

        if (carregado == 0) {
            cout << "No carry operation." << endl;
        } else if (carregado == 1) {
            cout << "1 carry operation." << endl;
        } else {
            cout << carregado << " carry operations." << endl;
        }
    }

    return 0;
}
