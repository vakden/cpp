#pragma once
#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

template<class TInfo>
class TDeque
{
protected:
	struct TDItem
	{
		TInfo info;
		TDItem *next;
		TDItem *prev;
		TDItem() :next(NULL), prev(NULL) {};
	};
	TDItem *front, *rear;
	int size;
	void erase();
	void clone(const TDeque&);
	void deleteItem(TDItem*);
	void* ptrByIndex(unsigned) const;
public:
	TDeque();
	TDeque(const TDeque&);
	virtual ~TDeque();
	void insFront(TInfo);
	void insRear(TInfo);
	bool delFront(TInfo &);
	bool delRear(TInfo &);
	const TDeque& operator=(const TDeque &);
	const TInfo& getByIndex(unsigned) const;
	void setByIndex(TInfo, unsigned);
	void browse(void work(TInfo&));
	void browse(void work(TInfo)) const;
};

template<class TInfo>//идет перезапись tmp
void TDeque<TInfo>::erase()
{
	TInfo tmp;
	while (delRear(tmp));
	size = 0;
}
template<class TInfo>
void TDeque<TInfo>::clone(const TDeque&c)
{
	TDItem* tmp = c.front;
	for (int i = 0; i < c.size; i++, tmp = tmp->next)
		insRear(tmp->info);
	size = c.size;
}
template<class TInfo>
void TDeque<TInfo>::deleteItem(TDItem* c)
{
	(c->next)->prev = c->prev;
	(c->prev)->next = c->next;
	delete c;
	size--;
}
template<>
void TDeque<char*>::deleteItem(TDItem* c)
{
	(c->next)->prev = c->prev;
	(c->prev)->next = c->next;
	delete[] c;
	delete c;
	size--;
}
template<class TInfo>
void* TDeque<TInfo>::ptrByIndex(unsigned n) const
{
	if (size == 0)
		throw "Deque is empty!";
	if (n < 0 || n >= (unsigned)size)
		return NULL;
	TDItem* tmp = front;
	for (unsigned i = 0; i < n; i++)
		tmp = tmp->next;
	return tmp;
}
template<class TInfo>
TDeque<TInfo>::TDeque() : front(NULL), rear(NULL), size(0)
{}
template<class TInfo>
TDeque<TInfo>::TDeque(const TDeque&c) : front(NULL), rear(NULL), size(0)
{
	clone(c);
}
template<class TInfo>
TDeque<TInfo>::~TDeque()
{
	erase();
}
template<class TInfo>
void TDeque<TInfo>::insFront(TInfo c)
{
	TDItem *tmp = new TDItem;
	tmp->info = c;
	if (size == 0)
		front = rear = tmp;
	else
	{
		tmp->next = front;//элементу новому указываем на первый элемент
		front->prev = tmp;//обратно связываем
		front = tmp;//делаем голову новым элементом
	}
	size++;
}
template<>
void TDeque<char*>::insFront(char* c)
{
	TDItem *tmp = new TDItem;
	tmp->info = new char[strlen(c) + 1];
	strcpy(tmp->info, c);
	if (size == 0)
		front = rear = tmp;
	else
	{
		tmp->next = front;
		front->prev = tmp;
		front = tmp;
	}
	size++;
}
template<class TInfo>
void TDeque<TInfo>::insRear(TInfo c)
{
	TDItem *tmp = new TDItem;
	tmp->info = c;
	if (size == 0)
		front = rear = tmp;
	else
	{
		tmp->prev = rear;
		rear->next = tmp;
		rear = tmp;
	}
	size++;
}
template<>
void TDeque<char*>::insRear(char* c)
{
	TDItem *tmp = new TDItem;
	tmp->info = new char[strlen(c) + 1];
	strcpy(tmp->info, c);
	if (size == 0)
		front = rear = tmp;
	else
	{
		tmp->prev = rear;
		rear->next = tmp;
		rear = tmp;
	}
	size++;
}
template<class TInfo>
bool TDeque<TInfo>::delFront(TInfo &c)
{
	if (size == 0)
		return false;
	TDItem *tmp = front;//в тмп сохранили голову
	front = front->next;//сдвинули голову впереди
	if (front != NULL)//если не один элемент в очереди
	{
		front->prev = NULL;//убрали связь с предыдущим
	}
	c = tmp->info;//чтобы показать, что именно удалили
	delete tmp;
	size--;
	return true;
}
template<>
bool TDeque<char*>::delFront(char* &c)
{
	if (size == 0)
		return false;
	TDItem *tmp = front;
	front = front->next;
	if (front != NULL)
	{
		front->prev = NULL;
	}
	if (c != NULL)
		delete[] c;
	c = new char[strlen(tmp->info) + 1];
	strcpy(c, tmp->info);
	delete[] tmp->info;
	delete tmp;
	size--;
	return true;
}
template<class TInfo>
bool TDeque<TInfo>::delRear(TInfo &c)
{
	if (size == 0)
		return false;
	TDItem *tmp = rear;
	rear = rear->prev;
	if (rear != NULL)
	{
		rear->next = NULL;
	}
	c = tmp->info;
	delete tmp;
	size--;
	return true;
}
template<>
bool TDeque<char*>::delRear(char* &c)
{
	if (size == 0)
		return false;
	TDItem *tmp = rear;
	rear = rear->prev;
	if (rear != NULL)
	{
		rear->next = NULL;
	}
	/*if (c != NULL)
	delete[] c;*/
	c = new char[strlen(tmp->info) + 1];
	strcpy(c, tmp->info);
	delete[] tmp->info;
	delete tmp;
	size--;
	return true;
}
template<class TInfo>
const TDeque<TInfo>& TDeque<TInfo>::operator=(const TDeque &c)
{
	if (this == &c)
		return *this;
	erase();
	clone(c);
	return *this;
}
template<class TInfo>
const TInfo& TDeque<TInfo>::getByIndex(unsigned n) const
{
	if (size == 0)	throw "Deque is empty!\n";
	if (n < 0 || n >= (unsigned)size)
		throw "Error: wrong N!\n";
	TDItem *tmp = (TDItem*)ptrByIndex(n);
	return tmp->info;
}
template<class TInfo>
void TDeque<TInfo>::setByIndex(TInfo i, unsigned n)
{
	if (size == 0)	throw "Deque is empty!\n";
	if (n < 0 || n >= (unsigned)size)
		throw "Error: wrong N!\n";
	TDItem *tmp = (TDItem*)ptrByIndex(n);
	tmp->info = i;
}
template<>
void TDeque<char*>::setByIndex(char* i, unsigned n)
{
	if (size == 0)	throw "Deque is empty!\n";
	if (n < 0 || n >= (unsigned)size)
		throw "Error: wrong N!\n";
	TDItem *tmp = (TDItem*)ptrByIndex(n);
	delete[] tmp->info;
	tmp->info = new char[strlen(i) + 1];
	strcpy(tmp->info, i);
}
template<class TInfo>
void TDeque<TInfo>::browse(void work(TInfo&))
{
	if (size == 0)
		throw "Deque is empty!\n";
	TDItem* tmp = front;
	for (int i = 0; i < size; i++, tmp = tmp->next)
		work(tmp->info);
}
template<class TInfo>
void TDeque<TInfo>::browse(void work(TInfo)) const
{
	if (size == 0)
		throw "Deque is empty!\n";
	TDItem* tmp = front;
	for (int i = 0; i < size; i++, tmp = tmp->next)
		work(tmp->info);
}
