#include "header.h"
struct ret*  ShelSort(int n, int* mass){//Сортировка методом шелла
	struct ret  *rezult = (struct ret*)malloc(sizeof(struct ret));//выделение памяти для структуры
	rezult->new_mass=mass;//массив
    	int i, j, pos, tmp, pere = 0, sr = 0;
        for (pos = n / 2; pos > 0; pos = pos / 2){
                for (i = pos; i < n; i++){
                        tmp = mass[i];
                        pere++;
                        for (j = i; j >= pos; j -= pos){
                        if (tmp < mass[j - pos]){
                                mass[j] = mass[j - pos];
                                sr++;
                        }
                        else {
                                break;
                        }
                }
                mass[j] = tmp;
                }
        }

        rezult->per=pere;//количество перестановок
        rezult->razb=sr;//количесвто сравнений
        return rezult;//возврат структуры

}

