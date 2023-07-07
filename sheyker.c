#include "header.h"
struct ret* shekerSort(int count, int* mass)//Шейкерная перестановка
{
	struct ret  *rezult = (struct ret*)malloc(sizeof(struct ret));//выделение памяти для структуры
        rezult->new_mass=mass;//массив
int left = 0, right = count-1;
int flag = 1, per = 0;
while ((left < right) && flag > 0)
{

for (int i = left; i<right; i++)
{
if (mass[i]>mass[i + 1])
{
int t = mass[i];
mass[i] = mass[i + 1];
mass[i + 1] = t;
flag = flag+1;
per = per + 1;
}
}
right--;
for (int i = right; i>left; i--)
{
if (mass[i - 1]>mass[i])
{
int t = mass[i];
mass[i] = mass[i - 1];
mass[i - 1] = t;
flag = flag+1;
per = per + 1;
}
}
left++;
}
	rezult->per=(flag-1);//количество перестановок
        rezult->razb=per;//количество сравнений
        return rezult;//возврат структуры
}
