//Nome: João Pedro de Paula Oliveira do Amaral / Nicolas de Barros
//TIA: 32049390 / 32070837
#include "StaticDeque.h"
#include <iostream>

using namespace std;

void organizadeque(StaticDeque& deque, int num_pre)	//Ordena as preferencias da fila
{
	for (int j = 0; j < num_pre; j++)
	{
		int temp_remove = RemoveBack(deque);
		InsertFront(deque, temp_remove);
	}
}

int main()
{
	setlocale(LC_ALL, "pt-BR");
	StaticDeque deque = Create();
	int opcao = 0;
	int tmp;
	int num_senha = 1;
	bool continuar = true;
	int num_pre = 0;
	int num_nor = 0;

	//MENU 
	while (continuar)
	{
		cout << "\n------------------------------------";
		cout << "\n***	BANCO	***";
		cout << "\n1-) Entrar na fila preferencial";
		cout << "\n2-) Entrar na fila normal";
		cout << "\n3-) Realizar os atendimentos";
		cout << "\n4-) Sair ";
		cout << "\n------------------------------------\n";

		cout << "Digite a opcao de cadastro : ";
		cin >> opcao;

		if (opcao == 1)
		{
			cout << "\nSua senha é : " << num_senha << "\n";
			InsertBack(deque, num_senha);
			++num_senha, ++num_pre;
		}

		else if (opcao == 2)
		{
			cout << "\nSua senha é : " << num_senha << "\n";
			InsertFront(deque, num_senha);
			++num_senha, ++num_nor;
		}

		else if (opcao == 3)
		{
			organizadeque(deque, num_pre);

			cout << "\n***	Atendimentos por tipo e ordem de preferencia	***\n";

			int i = 1;

			while (!IsEmpty(deque))
			{
				if (num_pre > 0)	//Printar os PREFERENCIAIS 
				{
					tmp = Front(deque);
					RemoveFront(deque);
					cout << i << "-) Tipo : 1 Senha : " << tmp << "\n";
					--num_pre; //Decrementa o contador dos elem preferenciais 
				}

				else if ((num_pre == 0) && (num_nor > 0))	//Printar os NORMAIS 
				{
					tmp = Back(deque);
					RemoveBack(deque);
					cout << i << "-) Tipo : 2 Senha : " << tmp << "\n";
					--num_nor;	//Decrementa o contador dos elem normais
				}

				++i; //Pra printar o numero de ordem no console
			}
		}

		else if (opcao == 4)
		{
			continuar = false;
		}

		else
		{
			cout << "Digite a opção válida !!! ";
		}
	}
}