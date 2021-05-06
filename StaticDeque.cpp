#include "StaticDeque.h"

StaticDeque Create()
{
	StaticDeque deque = { 0, 0, 0, { 0 } };
	return deque;
}

bool InsertFront(StaticDeque& deque, int elem) 
{
	if (deque.count == Size(deque))		//Verifica se está cheia
		return false;
	int i, temp;
	if (deque.front != 0)		//{0, 0, 1, 2, 3, 4, 5, 6}
	{
		deque.values[deque.front-1] = elem;
		--deque.front;
		++deque.count;		//{0, elem, 1, 2, 3, 4, 5, 6}
	}
	else		//Front se localiza no Values [ 0 ]:
	{
	for (i = 0; i < deque.count; i++) //{1, 2, 3, 0 ,0 ,0 ,0, 0}  
		{
			temp = deque.values[deque.count-i-1];
			deque.values[deque.count -i] = temp;
		}
		deque.values[0] = elem;  //Coloca o elem na primeira posição da Deque
		
		++deque.count;
		++deque.back;
		//{elem, 1, 2, 3, 0 , 0 , 0, 0}
	}
	
	return true;
}

bool InsertBack(StaticDeque& deque, int elem) 
{
	if (deque.count == Size(deque))
		return false;
	if ((deque.back == Size(deque)) && (deque.front != 0))  //Verifica se vai ser necessário deslocar os elem pra esquerda && se tem espaço pra colocar eles dentro
	{	//{0, 0, 1, 2, 3, 4, 5, 6}
		int temp;
		for (int i = 0; i < deque.count; i++)		//Deslocar pra esquerda
		{
			temp = deque.values[deque.front + i];
			deque.values[deque.front+i-1] = temp;
		}
		deque.values[7] = elem; //Insere o elem no ultimo espaço 
		--deque.front;
		++deque.count;
		//{0, 1, 2, 3, 4, 5, 6, elem}
	}
	else
	{//{0, 1, 2, 3, 0, 0, 0, 0}
		deque.values[deque.count + deque.front] = elem;   //Add no fim da fila (depois do último elem)
		++deque.count;
		++deque.back;
	} //{0, 1, 2, 3, elem, 0, 0, 0}
	return true;
}

int RemoveFront(StaticDeque& deque) 
{
	if (IsEmpty(deque)) //Verifica se a Deque está vazia
		return '\0';
	int value = Front(deque); //int que guarda o Fronte pra retornar depois
	deque.values[deque.front] = '\0'; //Zera o Front antigo
	++deque.front;
	
	--deque.count;

	return value;
}

int RemoveBack(StaticDeque& deque) 
{
	if (IsEmpty(deque))	//Verifica de está vazio
	{
		return '\0';
	}

	int temp = deque.values[deque.back - 1]; //int que guarda o back pra retornar depois
	deque.values[deque.back - 1] = '\0';  //Zera o Back antigo
	--deque.count;
	--deque.back;
	return temp;
}

int Front(StaticDeque& deque)
{
	return IsEmpty(deque) ? '\0' : deque.values[deque.front];
}

int Back(StaticDeque& deque)
{
	if (IsEmpty(deque))
	{
		return '\0';
	}

	return deque.values[deque.back - 1];
}

int Size(StaticDeque& deque)
{
	return sizeof(deque.values) / sizeof(deque.values[0]);
}

int Count(StaticDeque& deque)
{
	return deque.count;
}

bool IsEmpty(StaticDeque& deque)
{
	return deque.count == 0;
}

bool Clear(StaticDeque& deque)
{
	while (!IsEmpty(deque))
		RemoveFront(deque);
	deque.back = 0;
	deque.front = 0;
	return IsEmpty(deque);
}