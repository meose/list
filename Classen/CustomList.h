#pragma once
#include "Pointer.h"
class CustomList
{
public:
	Pointer* CList;

	// Temp Variables
	Pointer* TMP0;
	Pointer* TMP1;
	Pointer** TMP2;
	bool flag;

	int *legth;
	int Len();
	CustomList();
	~CustomList();
	void Output();
	int Append(const int &);
	int InsertBefore(const int &);
	int Insert(const int &, const int &);
	int Delete(const int &);
	int Free();
private:
	int InsertDelInception(char, const int &);
	int InsertDelEnd(char, const int &);
};