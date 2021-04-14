#pragma once
#pragma once
#include <iostream>
#include <exception>
#include <algorithm>
using namespace std;
class QException : public exception
{
public:
	QException(const char* message) :exception(message) {};
	QException(const QException& right) : exception(right) {};
};

typedef int InfoType;
class Queue
{
private:
	virtual void Erase(){};
	virtual void Clone(const Queue&){};
public:
	Queue() {};
	Queue(const Queue&);
	virtual ~Queue();
	virtual Queue& operator = (const Queue&);
	virtual void Push(InfoType AInfo) = 0;
	virtual bool Pop() = 0;
	virtual InfoType GetFirst() const = 0;
	virtual bool IsEmpty()const = 0;
	virtual unsigned GetSize() const = 0;
	virtual InfoType& operator [] (unsigned) = 0;
	virtual const InfoType& GetByIndex(unsigned k) const = 0;
	virtual void Browse(void ItemWork(InfoType)) const = 0;
	virtual void Browse(void ItemWork(InfoType&)) = 0;
};

class LQueue : public Queue
{
private:
	struct QItem
	{
		InfoType info = 0;
		QItem* next = NULL;
		QItem(InfoType Ainfo) : info(Ainfo), next(NULL) {}
	};
	QItem *front, *rear;
	unsigned size;
	void Erase();
	void Clone(const Queue&);
public:
	LQueue() : front(NULL), rear(NULL), size(0) {};
	LQueue(const LQueue&);
	virtual void Push(InfoType AInfo);
	virtual bool Pop();
	virtual InfoType GetFirst() const;
	virtual bool IsEmpty()const;
	virtual unsigned GetSize() const;
	virtual InfoType& operator [] (unsigned);
	virtual const InfoType& GetByIndex(unsigned k) const;
	virtual void Browse(void ItemWork(InfoType)) const;
	virtual void Browse(void ItemWork(InfoType&));
	//LQueue& operator = (const LQueue&q);
	~LQueue() {};
};

class AQueue : public Queue
{
private:
	InfoType *Arr;
	unsigned first, last, capacity;
	void Erase();
	void Clone(const Queue&);
public:
	//virtual AQueue& operator = (const AQueue&);
	AQueue(int cpty = 3);
	AQueue(const AQueue&);
	~AQueue() {};
	virtual void Push(InfoType AInfo);
	virtual bool Pop();
	virtual InfoType GetFirst() const;
	virtual bool IsFull()const;
	virtual bool IsEmpty()const;
	virtual unsigned GetSize() const;
	virtual InfoType& operator [] (unsigned);
	virtual const InfoType& GetByIndex(unsigned k) const;
	virtual void Browse(void ItemWork(InfoType)) const;
	virtual void Browse(void ItemWork(InfoType&));
};