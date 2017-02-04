#pragma once
#include <iostream>
#include "CustomList.h"

CustomList::CustomList()
{
	this->CList = NULL;
	this->TMP2 = &CList;
	*TMP2 = new Pointer;

	Object a[1] = { 0 };

	this->TMP1 = *TMP2;
	(*TMP2)->item = a[0];
	(*TMP2)->next = NULL;
	flag = true;
}

void CustomList::Output() {
	this->TMP1 = this->CList;

	while (this->TMP1)
	{
		std::cout << this->TMP1->item.key << " -> ";
		this->TMP1 = this->TMP1->next;
	}
	std::cout << "NULL\n";
}

int CustomList::InsertDelInception(char operation, const int &numb = 0) {
	try {
		if (!flag) throw "-- Traceback (most recent call last):\n	File '/Classen/CustomList.cpp', line 51, in <InsertDelInception-module>:\n	The list-object is not exists \n";
		this->TMP0 = new Pointer;
		this->TMP1 = this->CList;
		if (operation == '+') {
			this->TMP0->item.key = numb;
			this->TMP0->next = this->CList;
			this->CList = this->TMP0;
			return 0;
		}
		else if (operation == '-')
		{
			CList = TMP1->next;
			delete TMP1;
			return 0;
		}
		else {
			return 1;
		}
	}
	catch (char * a) {
		std::cout << a;
		return 1;
	}
}

int CustomList::InsertDelEnd(char operation, const int &numb = 0) {
	try{
		if(!flag) throw "-- Traceback (most recent call last):\n	File '/Classen/CustomList.cpp', line 94, in <InsertDelEnd-module>:\n	The list-object is not exists \n";

		this->TMP0 = this->CList;
		this->TMP1 = new Pointer;
		if (operation == '+') {
			this->TMP1->item.key = numb;
			this->TMP1->next = NULL;
			while (1)
			{
				if (!this->TMP0->next)
				{
					this->TMP0->next = this->TMP1;
					break;
				}
				this->TMP0 = this->TMP0->next;
			}
		}
		else if (operation == '-')
		{
			this->TMP1 = TMP0->next;
			while (TMP1)
			{
				if (!this->TMP1->next)
				{
					this->TMP0->next = this->TMP1->next;
					delete TMP1;
					return 1;
				}
				TMP0 = TMP1;
				TMP1 = TMP1->next;
			}
		}
		else {
			return 1;
		}
	}
	catch(char * a) {
		std::cout << a;
		return 1;
	}
}

int CustomList::Append(const int &numb)
{
	return CustomList::InsertDelEnd('+', numb);
}

int CustomList::InsertBefore(const int &numb)
{
	return CustomList::InsertDelInception('+', numb);
}


int CustomList::Len()
{
	try {
		if (!flag) throw "-- Traceback (most recent call last):\n	File '/Classen/CustomList.cpp', line 129, in <Len-module>:\n	The list-object is not exists \n";
		
		this->TMP1 = this->CList;
		this->legth = new int;
		(*(this->legth)) = 0;

		while (1)
		{
			(*(this->legth))++;
			if (!TMP1 || !TMP1->next)
			{
				return *(this->legth);
			}
			TMP1 = TMP1->next;
		}
	}
	catch (char * a) {
		std::cout << a;
	}
}

int CustomList::Insert(const int &num, const int &pos) {
	try {
		if (!flag) throw "-- Traceback (most recent call last):\n	File '/Classen/CustomList.cpp', line 168, in <Insert-module>:\n	The list-object is not exists \n";
		
		if (pos == 0) {
			return CustomList::InsertBefore(num);
		}
		else if (pos == CustomList::Len()) {
			return CustomList::Append(num);
		}
		else if (pos > 0 && pos < CustomList::Len()) {
			this->TMP0 = this->CList;
			this->TMP1 = new Pointer;
			this->TMP1->item.key = num;
			this->TMP1->next = NULL;

			int curp = 0;

			while (1)
			{
				if (pos - 1 == curp)
				{
					this->TMP1->next = this->TMP0->next;
					this->TMP0->next = this->TMP1;
					break;
				}
				curp++;
				this->TMP0 = this->TMP0->next;
			}

			return 0;
		}
		else {
			throw "-- Traceback (most recent call last):\n	File '/Classen/CustomList.cpp', line 168, in <Insert-module>:\n	Incorrect second argument \n";
		}
	}
	catch (char * a) {
		std::cout << a;
		return 1;
	}
}

int CustomList::Delete(const int &pos) {
	try {
		if (!flag) throw "-- Traceback (most recent call last):\n	File '/Classen/CustomList.cpp', line 206, in <Delete-module>:\n	The list-object is not exists \n";
		
		if (pos == 0 && pos < CustomList::Len() - 1) {
			return CustomList::InsertDelInception('-');
		}
		else if (pos == CustomList::Len() - 1 && pos != 0) {
			return CustomList::InsertDelEnd('-');
		}
		else if (pos > 0 && pos < CustomList::Len() - 1) {
			this->TMP0 = this->CList;
			this->TMP1 = TMP0->next;

			int curp = 0;

			while (1)
			{
				if (pos - 1 == curp)
				{
					this->TMP0->next = this->TMP1->next;
					delete TMP1;
					break;
				}
				curp++;
				this->TMP0 = this->TMP1;
				TMP1 = TMP1->next;
			}
			return 0;
		}
		else {
			throw "-- Traceback (most recent call last):\n	File '/Classen/CustomList.cpp', line 206, in <Delete-module>:\n	Incorrect second argument \n";
		}
	}
	catch (char * a) {
		std::cout << a;
		return 1;
	}
}

int CustomList::Free()
{
	try {
		if (!flag) throw "-- Traceback (most recent call last):\n	File '/Classen/CustomList.cpp', line 229, in <Free-module>:\n	The list-object is not exists \n";
		
		if (this->CList == 0) return 1;
		this->TMP0 = CList;
		this->TMP1 = NULL;

		while (TMP0)
		{
			TMP1 = TMP0;
			TMP0 = TMP0->next;
			delete TMP1;
		}
		CList = NULL;
		this->flag = false;
		return 0;
	}
	catch (char * a) {
		std::cout << a;
		return 1;
	}
}

CustomList::~CustomList()
{
	CustomList::Free();
	delete this->CList;
	delete this->TMP0;
}