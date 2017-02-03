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
	
	int *legth;
	int Len();
	CustomList();
	~CustomList();
	void Output();
	void Append(const int &);
	void InsertBefore(const int &);
	void Insert(const int &, const int &);
	void Delete(const int &);
private:
	int InsertDelInception(char, const int &);
	int InsertDelEnd(char, const int &);
	void Free();
};