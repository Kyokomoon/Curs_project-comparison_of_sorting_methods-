#include <stdio.h>//библеотека для вывода\ввода
#include <stdlib.h>//библеотека для функций с выделением памяти
#include <time.h>//библеотека  для рандома
#include "header.h"//заголовочный файл
void menu(){//функция для отрисовки  меню
	printf("\x1b[0;34m---------------------------------------------------------------------------------------------------------------------");
	printf("\n\x1b[0;35m█████████████████████████████████████████████████████████████████████████████████████████████████████████████████████");
	printf("\n█     ██     ██ ██   █     ██ ████    ███      █████       ███    ██████ ███ ██       ██     ██     ██ ██ ███ ██    █");
	printf("\n█ ██████ ███ ██   ██████ ████████ ████ ██ ████████████████ ██ ████ █████  █  ████████ ██ ██████ █████████ ███ ██ ████");
	printf("\n█     ██ ███ ██ ████████ ████ ███ ████ ██ ██   █████       ██ ████ █████ █ █ ██       ██     ██     ██ ██ ███ ██    █");
	printf("\n█████ ██ ███ ██ ████████ ████ ███ ████ ██ ████ █████ █████ ██ ████ █████ ███ ██ █████ ██████ ██████ ██ ███ █ ███ ████");
	printf("\n█     ██     ██ ████████ ████ ███ ████ ██      █████       ██ ████ █████ ███ ██       ██     ██     ██ ████ ████    █");
	printf("\n█████████████████████████████████████████████████████████████████████████████████████████████████████████████████████");
	printf("\n \x1b[0;34m---------------------------------------------------------------------------------------------------------------------\x1b[0;37m");
	printf("\n \x1b[0;30;47m0\x1b[0m-\x1b[4;33m          Exit\x1b[0m  \x1b[0;30;47m1\x1b[0m-\x1b[4;33mCreate massive\x1b[0m  \x1b[0;30;47m2\x1b[0m-\x1b[4;33m Print massive\x1b[0;37m\x1b[0m  ");
	printf("\x1b[0;30;47m3\x1b[0m-\x1b[4;33m  Sort massive\x1b[0m  \x1b[0;30;47m4\x1b[0m-\x1b[4;33m Clear console\x1b[0m  ");
}
int main(){//главная функция
	int n, command=1,choice_sort,choice_create, chek=0;// n-количество элементов, command-команда,choice_sort-выбор сортировки,choice_create-выбор создания массива, chek-проверка создания массива
        int* mass; //объявление массива
	struct ret *rez;//объявление структуры
	char str[10];
	menu();//прорисовка меню
	while(command!=0){//бесконечный цикл пока не введем команду 0 
		printf("\nEnter command: ");
        	scanf("%d", &command);//выбор команды
		if(command==1){//Создание массива
			printf("Fill in random(\x1b[0;30;47m1\x1b[0m), or using the keyboard(\x1b[0;30;47m2\x1b[0m), or take from file(\x1b[0;30;47m3\x1b[0m)");
			scanf("%d", &choice_create);//вариант создания массива
			if(choice_create != 3){
				printf("\nEnter the number of array elements:  ");
                        	scanf("%d", &n);//количесвто элементов
				mass =create_mass(n, choice_create); //возврат заполненного массива
				chek=1;//массив создан
	                        print_mass(mass, n);//вывод массива

			}
			else{
				rez = create_file(); //возврат заполненного массива
				mass = rez->new_mass;
				n = rez->per;
				chek=1;//массив создан
	                        print_mass(mass, n);//вывод массива

			}
		}
		else if(command==2){//вывод массива
			if(chek == 0){//Исключение ошибки отсутсвия массива
                                printf("\n\x1b[31mERROR: \x1b[3;31mArray not specified\x1b[0m");
                                continue;//возврат к началу
                        }
			print_mass(mass, n);//вывод массива
		}
		else if(command==3){//сортировка массива
			if(chek == 0){//Исключение ошибки отсутствия массива
				printf("\n\x1b[31mERROR: \x1b[3;31mArray not specified\x1b[0m");
				continue;//возврат к началу
			}
			printf("\nChoose a sorting method\n\x1b[0;30;47m1)\x1b[0m\x1b[4;33m     easy choice\n\x1b[0;30;47m2)\x1b[0m\x1b[4;33m    shell method");
			printf("\n\x1b[0;30;47m3)\x1b[0m\x1b[4;33mbinary inclusion\n\x1b[0;30;47m4)\x1b[0m\x1b[4;33m     shaker sort\x1b[0m\n\x1b[0;30;47m5)\x1b[0m\x1b[4;33m      testingAll\x1b[0m\n");
			printf("Enter your choice: ");
			scanf("%d", &choice_sort);//Выбор сортировки
			if (choice_sort==1){//сорттировка простым выбором
				rez = ProstSort(n, mass);//возвращаем количество перестановок и разбиений
				printf("перестановок-%d, сравнений-%d", rez->per, rez->razb);
				print_mass(mass, n);//вывод массива
			}
			else if(choice_sort==2){//сортировка методом шелла
				rez = ShelSort(n, mass);//возвращаем количество перестановок и разбиений
				printf("перестановок-%d, сравнений-%d", rez->per, rez->razb);
				print_mass(mass, n);//вывод массива
			}
			else if(choice_sort==3){//сортировка бинарным включением
				rez = InsertionSort(n, mass);//возвращаем количество перестановок и разбиений
                              	printf("перестановок-%d, сравнений-%d", rez->per, rez->razb);
				print_mass(mass, n);//вывод массива
			}
			else if(choice_sort==4){//шейкерная сортировка
                              	rez = shekerSort(n, mass);//возвращаем количество перестановок и разбиений
                              	printf("перестановок-%d, сравнений-%d", rez->per, rez->razb);
				print_mass(mass, n);//вывод массива
                        }
			else if(choice_sort==5) {//Тестироание всех методов сортировки
				test();
			}
			else if(choice_sort<1|| choice_sort>5){//обработка ошибки когда введена неизвестная команда
				printf("\n\x1b[31mERROR: \x1b[3;31mNon-existent sort method -> a easy choice sort will be performed\x1b[0m");
				rez = ProstSort(n, mass);
                                printf("перестановок-%d, разбиений-%d", rez->per, rez->razb);
			}
		}
		else if(command==4){//очистка консоли
			system("clear");
			menu();//отрисовка меню
		}
		else if(command != 0) printf("\n\x1b[31mERROR: \x1b[3;31mcommand not found\x1b[0m");//обработка ошибки когда введена неизвестная команда

	}

}
