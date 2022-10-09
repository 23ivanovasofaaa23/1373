#pragma once
#include <iostream>

class DynArray
{
private:
	int size;
	double* data;

public:
	DynArray();
	DynArray(int elemAmount);
	~DynArray();

	int find(double value); //����� ������ �� ��������

	void add(int index, double value); //�������� �������

	void remove(int index); // ������� ������� �� ������ �� �������

	double& operator[](const int index);
};
