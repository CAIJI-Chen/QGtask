#include<stdio.h>
#include<time.h>
#define MAX 1000000



void catalog();                                                             //Ŀ¼
void insertsort(int r[], int a);                                            //��������
void quick_sort(int r[], int begin, int end);                               //��������
void Merge(int r[], int r1[], int startIndex, int midIndex, int endIndex);//һ�ι鲢
void MergeSort(int r[], int r1[], int startIndex, int endIndex);          //�鲢����
void radixSort(int* a, int size);                                             //��������
void CountSort(int* a, int len);
void data(int a1[],int a2[],int a3[]);
void _100();