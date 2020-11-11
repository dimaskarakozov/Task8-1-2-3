// Task 8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void puzir (int *mas,int n)
{
    int kolperest = 0, kolif=0;
    for (int i = 0; i < n-1; i++) {

        for (int j = 0; j < n-1; j++) {
        
            kolif = kolif + 1;
            if (mas[j] > mas[j + 1]) {
                mas[j] = mas[j] + mas[j + 1];
                mas[j + 1] = mas[j] - mas[j + 1];
                mas[j] = mas[j] - mas[j + 1];
                kolperest = kolperest + 1;
            }

        }

    }
    printf("\nКол-во перестановок: %d",kolperest);
    printf("\nКол-во сравнений: %d", kolif);



}




void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}


int partition(int array[], int low, int high, int* nswap, int* nif) {

 
    int pivot = array[high];
    int i = (low - 1);


    for (int j = low; j < high; j++) {
        *nif = *nif + 1;
        if (array[j] <= pivot) {
            i++;
            *nswap = *nswap + 1;
            swap(&array[i], &array[j]);
        }
    }
    *nswap = *nswap + 1;
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSort(int array[], int low, int high,int  *nswap,int *nif) {
    if (low < high) {
        *nif = *nif + 1;
        int pi = partition(array, low, high,&*nswap,&* nif);

   
        quickSort(array, low, pi - 1, &*nswap, &*nif);

        quickSort(array, pi + 1, high, &*nswap, &*nif);
    }

}


void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d  ", array[i]);
    }
    printf("\n");
}




void insertionSort(int mas[], int n)
{
    int nswap=0,nif=0;
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = mas[i];
        j = i - 1;

        while (j >= 0 && mas[j] > key) {
            nswap++;
            mas[j + 1] = mas[j];
            j = j - 1;
        }
        mas[j + 1] = key;
    }

    printf("Кол-во перестановок равно кол-во сравнений и равно: %d \n", nswap);

}



int main()
{
    setlocale(LC_ALL, "Russian");

    int *mas, n,q=-1;

    while (q != 0) {
        printf("\n\n\n\n0)Выход\n1)Пузырек\n2)Быстрая сортировка(Quick sort)\n3)Сортировка вставкам(Insertion sort)");
        printf("\nВведите число ");
        scanf_s("%d", &q);
        switch (q) {
        case 1: {
          
            printf("Введите кол-во эллементов в массиве: ");
            scanf_s("%d", &n);

            mas = (int*)malloc(n * sizeof(int));
            printf("Введите эллеметнты массива: ");
            for (int i = 0; i < n; i++)
            {
                scanf_s("%d", &mas[i]);
            }
           
            puzir(mas, n);
            printf("\nСам массив отсортированный пузырьком: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", mas[i]);
            }
            break;
                }
        case 2: {
        
            printf("Введите кол-во эллементов в массиве: ");
            scanf_s("%d", &n);

            mas = (int*)malloc(n * sizeof(int));
            printf("Введите эллеметнты массива: ");
            for (int i = 0; i < n; i++)
            {
                scanf_s("%d", &mas[i]);
            }
            int nswap = 0, nif = 0;
            quickSort(mas, 0, n - 1, &nswap, &nif);

            printf("Кол-во перестановок: %d", nswap);
            printf("Кол-во сравнений: %d", nif);
            printf("   Массив: \n");
            printArray(mas, n);
            break;
        }
        case 3: {  
            printf("Введите кол-во эллементов в массиве: ");
            scanf_s("%d", &n);

            mas = (int*)malloc(n * sizeof(int));
            printf("Введите эллеметнты массива: ");
            for (int i = 0; i < n; i++)
            {
                scanf_s("%d", &mas[i]);
            }
            insertionSort(mas, n);
            printArray(mas, n);
            break;
        }
        }

    }


   






    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
