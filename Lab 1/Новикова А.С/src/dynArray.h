#pragma once
#include <iostream>
#include <string>

class DynArray
{
private:
	int size;
	std::string* data;

public:
	DynArray();
	DynArray(int elemAmount);
	~DynArray();

	int find(std::string value); //����� ������ �� ��������

	void add(int index, std::string value); //�������� �������

	void remove(int index); // ������� ������� �� ������ �� �������

	int getSize();

	void pushBack(std::string value);

	std::string& operator[](const int index);
};
