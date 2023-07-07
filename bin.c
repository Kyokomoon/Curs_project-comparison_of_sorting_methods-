#include "header.h"
struct ret*  InsertionSort(int n, int* mass)//сортировка бинарным включением
{
	struct ret  *rezult = (struct ret*)malloc(sizeof(struct ret));//выделение памяти для структуры
        rezult->new_mass=mass;//массив

	int nE, pos, pere = 0, sr = 0;
 
    	for (int i = 1; i < n; i++)
    	{
        	nE = mass[i];
        	pos = i - 1;
        	while(pos >= 0 && mass[pos] > nE)
        	{
            		mass[pos+1] = mass[pos];
            		pos = pos - 1;
            		sr++;
        	}
        	mass[pos+1] = nE;
        	if (mass[pos + 1] = nE)
        	{
            		pere += 1;
        	}
    	}
	rezult->per=pere;//количество перестановок
        rezult->razb=sr;//количество сравнений
        return rezult;//возврат структуры
}


