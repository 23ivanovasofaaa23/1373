#pragma once
#include "listFunctions.h"
#include "stackFunctions.h"

void swapArray(int* array, int lenght, int beggining);// ������� �������������� �������

void insertionSort(int* array, unsigned lenght, unsigned beggining, bool ascendingOrDescending); // ������� ���������� ���������

void mergeSort(int* array, int firstBeggining, int secondBeggining, int firstLenght, int secondLenght); // ������� ���������� ��������

void creatingRuns(int* array, unsigned lenght, int minrun, List& ourList, Stack& ourStack); // ������� ��������� ������� �� ����������