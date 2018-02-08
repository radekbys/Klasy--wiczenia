#include "Airport_list.h"



void Airport_list::add(Airport & a)
{
	head = list_add(a,head);
}

element* Airport_list::list_add(Airport & a, element * head)
{
	if (head != nullptr)
	{
		head->next = list_add(a, head->next);
		return head;
	}
	else
	{
		head = new element;
		head->port = a;
		head->next = nullptr;
		return head;
	}
}

element* Airport_list::remove_last(element * head)
{
	if (head == nullptr)
	{
		return head;
	}
	else if (head->next == nullptr)
	{
		delete head;
		head = nullptr;
	}
	else
	{
		head->next = remove_last( head->next);
	}
	return head;
}



Airport_list::Airport_list()
{
	head = nullptr;
}

Airport_list::~Airport_list()
{
	while (head)
	{
		head = remove_last(head);
	}
}

