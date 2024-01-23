#include<iostream>
#include<vector>

enum {
	CIMA = 0,
	ESQUERDA = 1,
	DIREITA = 2,
	BAIXO = 3	
};

using namespace std;

int main()
{
	while(true)
	{
		size_t tempo;
		cin >> tempo;
		if(cin.eof()) break;

		if(tempo == 1) cout << "1 1" << endl;
		else if(tempo == 2) cout << "1 2" << endl;
		else if(tempo == 3) cout << "2 2" << endl;
		else if(tempo == 4) cout << "2 1" << endl;
		else if(tempo == 5) cout << "3 1" << endl;
		else
		{
			size_t t = 5;

			size_t x = 3;
			size_t y = 1;
			size_t passo = 2;
			size_t direcao = CIMA;
			while(t != tempo)
			{
				if(t + passo > tempo)
				{
					// Mover para a posição final
					size_t novoPasso = tempo - t;
					
					if(direcao == CIMA)
					{
						y += novoPasso;
						t += novoPasso;
					}
					else if(direcao == ESQUERDA)
					{
						x -= novoPasso;
						t += novoPasso;
					}
					else if(direcao == DIREITA)
					{
						x += novoPasso;
						t += novoPasso;
					}
					else if(direcao == BAIXO)
					{
						y -= novoPasso;
						t += novoPasso;
					}
					
				}
				else
				{
					// Mover um passo inteiro

                    
					if(direcao == CIMA)
					{
						y += passo;
						t += passo;
						if(t == tempo) break;
						else
						{
							direcao = ESQUERDA;
						}
					}
					else if(direcao == ESQUERDA)
					{
						x -= passo;
						t += passo;
						if(t == tempo) break;
						else
						{
							y++;
							t++;
							direcao = DIREITA;
							passo++;
						}
					}
					else if(direcao == DIREITA)
					{
						x += passo;
						t += passo;
						if(t == tempo) break;
						else
						{
							direcao = BAIXO;
						}
					}
					else if(direcao == BAIXO)
					{
						y -= passo;
						t += passo;
						if(t == tempo) break;
						else
						{
							x++;
							t++;
							direcao = CIMA;
							passo++;
						}
					}
				}
			}
			
			cout << x << " " << y << endl;
			
		}
	}
}
