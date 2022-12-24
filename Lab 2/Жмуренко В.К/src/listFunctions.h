#pragma once
struct box				// ��������� �������� ������������ ������
{
	int FirstInf, SecondInf;
	box* Adr;
};

class List
{
	box* Head;
	unsigned Size;

public:

	// �����������
	List();

	// ������, ���������� � ����������� �������
	void CreateList(unsigned Lenght);	// �������� ������������ ������
	box* addressGetter();	// ��������� ������ ������ �������� ��������
	void dataInserting(int data1, int data2);	// ���� ������ � ������� ������� ������
	void sizeOfList(box* Beg);	// �������, ���������� ������ ������
	void newItem(unsigned Index);	// ���������� ������ �������� � ������
	box* getItem(unsigned Index);	// ��������� ������ ������������� �������� �� �������
	unsigned IndexforData(int data1, int data2); // ��������� ������� �� �������� ������ ��������
	void DeleteItem(unsigned Index);	// ������� ������� �� �������
	bool isListDataNotEmpty();	// �������� ������ �� ������� ������ � ���
	void DeleteList();	// ������� ������ � ����������� ������
};