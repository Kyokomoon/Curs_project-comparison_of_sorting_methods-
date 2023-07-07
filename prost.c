#include "header.h"
struct ret*  ProstSort(int n, int* mass){//Сортирока простым выбором
	struct ret  *rezult = (struct ret*)malloc(sizeof(struct ret));//выделение памяти для структуры
	rezult->new_mass=mass;//массив
	int min,j,tmp, pere = 0, razb = 0;
	for (int i = 0; i < n; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
		razb +=1;
		if (mass[min] > mass[j]){
			 min = j;
		}
		}
		tmp = mass[min];
		mass[min] = mass[i];
		mass[i] = tmp;
		pere += 1 ;
	}
	rezult->per=pere;//количесвто перстановок
	rezult->razb=razb;//количество сравнений 
	return rezult;//возврат структуры
}
