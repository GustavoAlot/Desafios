#include <bits/stdc++.h>

using namespace std;

int main() {
    typedef struct {
        string placa;
        int dia;
        int hora;
        int km;
        string status;
    } Fotos;

    int numMeses;
    cin >> numMeses;

    string linha;
    getline(cin, linha);

    for (int i = -1; i < numMeses; i++) {
        int numEntradas = 0;
        int precosHora[24];
        Fotos dados[1000];

        while (true) {
            getline(cin, linha);

            if (linha.empty()) {
                break;
            } else {
                istringstream iss(linha);

                if (numEntradas == 0) {
                    iss >> precosHora[0] >> precosHora[1] >> precosHora[2] >> precosHora[3] >> precosHora[4] >> precosHora[5] >> precosHora[6] >> precosHora[7] >> precosHora[8]
                        >> precosHora[9] >> precosHora[10] >> precosHora[11] >> precosHora[12] >> precosHora[13] >> precosHora[14] >> precosHora[15] >> precosHora[16] >> precosHora[17] >> precosHora[18]
                        >> precosHora[19] >> precosHora[20] >> precosHora[21] >> precosHora[22] >> precosHora[23];
                    numEntradas++;
                } else {
                    string auxData;
                    iss >> dados[numEntradas].placa >> auxData >> dados[numEntradas].status >> dados[numEntradas].km;

                    string auxDia, auxHora;
                    auxDia = auxData.substr(3, 2);
                    auxHora = auxData.substr(6, 2);
                    dados[numEntradas].dia = stoi(auxDia);
                    dados[numEntradas].hora = stoi(auxHora);

                    numEntradas++;
                }
            }
        }
       
        for (int j = 0; j < numEntradas; j++) {
            for (int k = 0; k < numEntradas; k++) {
                if (k != 0) {
                    if (dados[k].placa < dados[k - 1].placa) {
                        Fotos dadosAux;
                        dadosAux.dia = dados[k - 1].dia;
                        dadosAux.hora = dados[k - 1].hora;
                        dadosAux.km = dados[k - 1].km;
                        dadosAux.placa = dados[k - 1].placa;
                        dadosAux.status = dados[k - 1].status;
           
                        dados[k - 1].dia = dados[k].dia;
                        dados[k - 1].hora = dados[k].hora;
                        dados[k - 1].km = dados[k].km;
                        dados[k - 1].placa = dados[k].placa;
                        dados[k - 1].status = dados[k].status;
           
                        dados[k].dia = dadosAux.dia;
                        dados[k].hora = dadosAux.hora;
                        dados[k].km = dadosAux.km;
                        dados[k].placa = dadosAux.placa;
                        dados[k].status = dadosAux.status;
                    }
                }
            }
        }

    // --------------------------------------------------------------------------
    // Dia

    for (int j = 0; j < numEntradas; j++) {
      for (int k = 0; k < numEntradas; k++) {
        if (k != 0) {
          if (dados[k].placa == dados[k - 1].placa &&
              dados[k].dia < dados[k - 1].dia) {
            Fotos dadosAux;
            dadosAux.dia = dados[k - 1].dia;
            dadosAux.hora = dados[k - 1].hora;
            dadosAux.km = dados[k - 1].km;
            dadosAux.placa = dados[k - 1].placa;
            dadosAux.status = dados[k - 1].status;

            dados[k - 1].dia = dados[k].dia;
            dados[k - 1].hora = dados[k].hora;
            dados[k - 1].km = dados[k].km;
            dados[k - 1].placa = dados[k].placa;
            dados[k - 1].status = dados[k].status;

            dados[k].dia = dadosAux.dia;
            dados[k].hora = dadosAux.hora;
            dados[k].km = dadosAux.km;
            dados[k].placa = dadosAux.placa;
            dados[k].status = dadosAux.status;
          }
        }
      }
    }

    // --------------------------------------------------------------------------
    // Hora

    for (int j = 0; j < numEntradas; j++) {
      for (int k = 0; k < numEntradas; k++) {
        if (k != 0) {
          if (dados[k].placa == dados[k - 1].placa &&
              dados[k].dia == dados[k - 1].dia &&
              dados[k].hora < dados[k - 1].hora) {
            Fotos dadosAux;
            dadosAux.dia = dados[k - 1].dia;
            dadosAux.hora = dados[k - 1].hora;
            dadosAux.km = dados[k - 1].km;
            dadosAux.placa = dados[k - 1].placa;
            dadosAux.status = dados[k - 1].status;

            dados[k - 1].dia = dados[k].dia;
            dados[k - 1].hora = dados[k].hora;
            dados[k - 1].km = dados[k].km;
            dados[k - 1].placa = dados[k].placa;
            dados[k - 1].status = dados[k].status;

            dados[k].dia = dadosAux.dia;
            dados[k].hora = dadosAux.hora;
            dados[k].km = dadosAux.km;
            dados[k].placa = dadosAux.placa;
            dados[k].status = dadosAux.status;
          }
        }
      }
    }
   
        // for (int j = 0; j < numEntradas+1; j++)
        // {
        //     cout << dados[j].placa <<  " - Dia: " << dados[j].dia << " - Hora: " << dados[j].hora << "\n";
        // }

       
        set<string> placasProcessadas;

        for (int j = 1; j < numEntradas; j++) {
            float taxa = 2.0;
            string placaAtual = dados[j].placa;
            bool placaValida = false;

            // Ve se ja passou por aquela placa
            if (placasProcessadas.find(placaAtual) != placasProcessadas.end()) {
                continue;
            }

            for (int k = 1; k < numEntradas; k++) {
                if (dados[k].status == "enter" && dados[k + 1].status == "exit" && dados[k].placa == placaAtual && k < numEntradas) {
                    if (dados[k].placa == dados[k + 1].placa) {
                        placaValida = true;
                        taxa++;
                        float kmsRodados = abs(dados[k + 1].km - dados[k].km);
                        float taxaRodagem = (kmsRodados * precosHora[dados[k].hora]) / 100;
                        taxa += taxaRodagem;
                    }
                }
            }

            if(placaValida)
                cout << placaAtual << " $" << fixed << setprecision(2) << taxa << "\n";

            // feitico
            placasProcessadas.insert(placaAtual);
        }
        if(i != -1)
            cout << "\n";
       
    }

    return 0;
}