#include<stdio.h>
#include<time.h>
#define MAX 1000000



void catalog();                                                             //目录
void insertsort(int r[], int a);                                            //插入排序
void quick_sort(int r[], int begin, int end);                               //快速排序
void Merge(int r[], int r1[], int startIndex, int midIndex, int endIndex);//一次归并
void MergeSort(int r[], int r1[], int startIndex, int endIndex);          //归并排序
void radixSort(int* a, int size);                                             //基数排序
void CountSort(int* a, int len);
void data(int a1[],int a2[],int a3[]);
void _100();