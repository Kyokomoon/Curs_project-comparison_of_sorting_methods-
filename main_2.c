#include "header.h"
int* create_mass(int n,int choice ){ //Создание и заполение массива
	srand(time(NULL));//для рандома чисел
	int i;
	int* mass = (int *)malloc(n*sizeof(int));//выделение памяти для массива из n элементов
	if(choice==1 || choice < 1 || choice > 3){//рандомное заполение
		if(choice < 1 || choice > 2) printf("\n\x1b[31mERROR: \x1b[3;31m unknown way, the array will be filled from the random\x1b[0m");//обработка ошибки когда выбрана неизвестная команда
		for(i=0;i<n;i++){//заполнение массива
			mass[i] =  (rand()%1000)-500;//рандомные числа в диапазоне от -500 до 500
		}
	}
	else if(choice==2){ //ручной ввод
		for(i=0;i<n;i++){//заполнение массива
			printf("\nEnter element(integer number) \x1b[4;33m№%d\x1b[0m: ",i);
			scanf("%d", &mass[i]);//считывание элемента
		}
	}
	return mass;//возвращние массива
}
struct ret* create_file(){//Создание массива из файла
        struct ret  *rezult = (struct ret*)malloc(sizeof(struct ret));//выделение памяти для структуры
	int* mass;
	char str[50];//Имя файла
	int n, i,s;
	printf("\n\x1b[33mATTENTION: \x1b[3;33menter the correct file name, along with the extension .txt\x1b[0m");
	printf("\nenter filename : ");
        scanf("%s", str);//Считываем имя файла
        fflush(stdin); // очищаем поток ввода

	FILE *myfile = fopen(str, "r"); //открываем файл
        fscanf(myfile,"%d",&n); //Считываем количество элементов в файле
       	mass = (int *)malloc(n*sizeof(int));//создаем массив из n элементов
		for(i=0;i<n;i++){
                	fscanf(myfile,"%d", &s);//берем по одному элементу из файла
                        mass[i]=s;
                }
        fclose(myfile);//закрываем файл
	rezult->new_mass = mass;//массив
	rezult->per=n;//количество элементов
        rezult->razb=0;//ненужное значение
	return rezult;//возвращаем  структуру
}
void print_mass(int* mass, int n){//вывод массива
	printf("\nmass=[");
	for(int i=0;i<n;i++){//вывод элементов
		printf("%d ", mass[i]);
		}
	printf("]");
}
int* mas(int n, int* mass){//пересоздание массива для тестирования сортировок
	int i;
	int* mass_2;
	mass_2 = (int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++){//переназначение элементов
		mass_2[i]=mass[i];
	}
	return mass_2;//возвращение  массива
}
void test(){//тестирование всех сортировок на  трудоемкость
	struct ret *rez;
	int* mass;
	int i,n, min=99999,max=-99999, elem;
	for(n=100;n<501;n=n+100){//Цикл для определения количества элементов от 100 до 500 с шагом 100
		printf("\nN= %d", n);//выводим количество элементов
		min=99999;//для  заполнения массива  по убыванию
		max=-99999;//для заполнения массива по возрастанию
		mass = (int *)malloc(n*sizeof(int));//создание массива из n элементов
		for(i=0;i<n;i=i){//заполнение массива
			elem = (rand()%10000)-5000;//рандомнно в диапазоне от -5000 до 5000 
			if(elem <= min){//заполнение массива по убыванию
				mass[i] = elem;
				min = elem;
				i++;
			}
		}
		//вызов каждого варианта сортировок и вывод трудоемкости
		printf("\n-----------\nПо убыванию\n-----------");
		rez=ProstSort(n,mas(n,mass));
		printf("\nТрудоемкость(Простой выбор)-%d", rez->per + rez->razb);
		rez=ShelSort(n,mas(n,mass));
		printf("\nТрудоемкость(Шелл)-%d", rez->per + rez->razb);
		rez=InsertionSort(n,mas(n,mass));
		printf("\nТрудоемкость(Бинарное включение)-%d", rez->per + rez->razb);
    		rez=shekerSort(n,mas(n,mass));
		printf("\nТрудоемкость(Шейкерная)-%d", rez->per + rez->razb);
		for(i=0;i<n;i++){//заполнение массива рандомно
			mass[i]=(rand()%10000)-5000;

		}
		//вызов каждого варианта сортировок и вывод трудоемкости
		printf("\n--------\nРандомно\n--------");
 		rez=ProstSort(n, mas(n,mass));
              	printf("\nТрудоемкость(Простой выбор)-%d", rez->per + rez->razb);
		rez=ShelSort(n,mas(n,mass));
              	printf("\nТрудоемкость(Шелл)-%d", rez->per + rez->razb);
              	rez=InsertionSort(n,mas(n,mass));
              	printf("\nТрудоемкость(Бинарное включение)-%d", rez->per + rez->razb);
              	rez=shekerSort(n,mas(n,mass));
              	printf("\nТрудоемкость(Шейкерная)-%d", rez->per + rez->razb);
		for(i=0;i<n;i=i){//заполнение массива по возрастанию
                      elem = (rand()%10000)-5000;
			if(elem >= max){
                                mass[i] = elem;
                                max = elem;
                                i++;
                        }
              	}
		//вызов каждого варианта сортировок и вывод трудоемкости
		printf("\n--------------\nПо возрастанию\n--------------");
		rez=ProstSort(n, mas(n,mass));
              	printf("\nТрудоемкость(Простой выбор)-%d", rez->per + rez->razb);
		rez=ShelSort(n,mas(n,mass));
              	printf("\nТрудоемкость(Шелл)-%d", rez->per+rez->razb);
              	rez=InsertionSort(n,mas(n,mass));
              	printf("\nТрудоемкость(Бинарное включение)-%d", rez->per+rez->razb);
              	rez=shekerSort(n,mas(n,mass));
              	printf("\nТрудоемкость(Шейкерная)-%d", rez->per+ rez->razb);
	}
	free(mass);//освобождение памяти
}
