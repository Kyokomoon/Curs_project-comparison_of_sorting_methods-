#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct  ret {//структура дял вывода результатов сортировки
	int per, razb;
	int* new_mass;
};
//объявление всех функций
int* create_mass(int n, int choice);
void print_mass(int* mass, int n);
struct ret*  ProstSort(int n, int* mass);
struct ret*  ShelSort(int n, int* mass);
struct ret*  InsertionSort(int n, int* mass);
struct ret* shekerSort(int count, int* mass);
void test();
int* mas(int n, int* mass);
struct ret*  create_file();
