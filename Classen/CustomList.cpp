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

int CustomList::InsertDelEnd(char operation, const int &numb = 0) {
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

void CustomList::Append(const int &numb)
{
	CustomList::InsertDelEnd('+', numb);
}

void CustomList::InsertBefore(const int &numb)
{
	CustomList::InsertDelInception('+', numb);
}


int CustomList::Len()
{
	this->TMP1 = this->CList;
	this->legth = new int;
	(*(this->legth)) = 0;

	while (1)
	{
		(*(this->legth))++;
		if (!TMP1->next)
		{
			return *(this->legth);
		}
		TMP1 = TMP1->next;
	}

}

void CustomList::Insert(const int &num, const int &pos) {
	if (pos == 0) {
		CustomList::InsertBefore(num);
	}
	else if (pos == CustomList::Len()) {
		CustomList::Append(num);
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
	}
	else {
		std::cout << "Error operation\n";
	}
}

void CustomList::Delete(const int &pos) {
	if (pos == 0) {
		CustomList::InsertDelInception('-');
	}
	else if (pos == CustomList::Len()) {
		CustomList::InsertDelEnd('-');
	}
	else if (pos > 0 && pos < CustomList::Len()) {
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
	}
	else {
		std::cout << "Error operation\n";
	}
}

void CustomList::Free()
{
	if (this->CList == 0) return;
	this->TMP0 = CList;
	this->TMP1 = NULL;

	while (TMP0)
	{
		TMP1 = TMP0;
		TMP0 = TMP0->next;
		delete TMP1;
	}
	CList = NULL;
}

CustomList::~CustomList()
{
	CustomList::Free();
	delete this->CList;
	delete this->TMP0;
}