#include <iostream>
#include "taskFunctions.h"
#include "sortFunctions.h"
#include "listFunctions.h"
#include "stackFunctions.h"
using namespace std;

void fillingArray(int* array, unsigned lenght) // ������� ����� ������������� �������� ������ �������
{
	for (int i = 0; i < lenght; i++)
	{
		std::cin >> array[i];
	}
	system("cls"); // ������� ���� ������� ��� ���������� �����������
}

int getMinrun(unsigned lenght) // ������� ���������� minrun
{
	int r = 0;	// ������ 1 ���� ����� ��������� ����� ����� ���� �� 1 ���������
	while (lenght >= 64)
	{
		r |= lenght & 1;
		lenght >>= 1;
	}
	return lenght + r;
}

void timSort(int* array, unsigned lenght)
{
	List OurList = List();
	Stack OurStack;
	int minrun = getMinrun(lenght);
	creatingRuns(array, lenght, minrun, OurList, OurStack);
	box* listBeggining = OurList.addressGetter();
	while (listBeggining != nullptr && lenght>64)
	{
		int lenght = 1;
		listBeggining = OurList.addressGetter();
		box* checkingLenght = OurList.addressGetter();;
		box* secondElement = nullptr;
		box* thirdElement = nullptr;
		while (checkingLenght->Adr != nullptr) // ���������� ���������� ������� ����� ��� ������� �������
		{
			checkingLenght = checkingLenght->Adr;
			lenght++;
			if (lenght == 3)
				break;
		}
		bool isLenghtChanged = false;
		if (lenght >= 2)
		{
			secondElement = listBeggining->Adr;
			if (listBeggining->SecondInf >= secondElement->SecondInf)
			{
				mergeSort(array, listBeggining->FirstInf, secondElement->FirstInf, listBeggining->SecondInf, secondElement->SecondInf);
				secondElement->SecondInf = secondElement->SecondInf + listBeggining->SecondInf;
				if (secondElement->FirstInf > listBeggining->FirstInf)
					secondElement->FirstInf = listBeggining->FirstInf;
				OurStack.pop(OurList);
				lenght--;
				isLenghtChanged = true;
			}
			if (lenght == 3)
			{
				thirdElement = secondElement->Adr;
				if (thirdElement->SecondInf <= (listBeggining->SecondInf + secondElement->SecondInf))
				{
					if (listBeggining->SecondInf <= thirdElement->SecondInf)
					{
						mergeSort(array, listBeggining->FirstInf, secondElement->FirstInf, listBeggining->SecondInf, secondElement->SecondInf);
						secondElement->SecondInf = secondElement->SecondInf + listBeggining->SecondInf;
						if (secondElement->FirstInf > listBeggining->FirstInf)
							secondElement->FirstInf = listBeggining->FirstInf;
						OurStack.pop(OurList);
					}
					else
					{
						mergeSort(array, thirdElement->FirstInf, secondElement->FirstInf, thirdElement->SecondInf, secondElement->SecondInf);
						secondElement->SecondInf = secondElement->SecondInf + thirdElement->SecondInf;
						if (secondElement->FirstInf > thirdElement->FirstInf)
							secondElement->FirstInf = thirdElement->FirstInf;
						OurStack.popForIndex(OurList, 3);
					}
				}
			}
			if (lenght == 2 && isLenghtChanged==false)
			{
				mergeSort(array, listBeggining->FirstInf, secondElement->FirstInf, listBeggining->SecondInf, secondElement->SecondInf);
				OurStack.pop(OurList);
				OurStack.pop(OurList);
				lenght--;
			}
			if (lenght == 1)
				 listBeggining = nullptr;
		}
	}
}