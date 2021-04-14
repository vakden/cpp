#include "queue.h"
using namespace std;

Queue::Queue(const Queue &q)
{
	Clone(q);
}
Queue::~Queue()
{
	Erase();
}
Queue & Queue::operator=(const Queue &q)
{
	if (this == &q)
	{
		Erase();
		Clone(q);
	}
	return *this;
}

void LQueue::Erase()
{
	while (Pop());
	size = 0;
	rear = NULL;
	front = NULL;
}
void LQueue::Clone(const Queue &q)
{
	QItem *tmp = dynamic_cast<const LQueue&>(q).front;
	for (unsigned i = 0; i < dynamic_cast<const LQueue&>(q).size; i++)
	{
		Push(tmp->info);
		tmp = tmp->next;
	}
}
LQueue::LQueue(const LQueue &q)
{
	Clone(q);
}
void LQueue::Push(InfoType info)
{
	QItem* tmp = new QItem(info);
	if (size > 0)
		rear->next = tmp;
	else
		front = tmp;
	rear = tmp;
	size++;
}
bool LQueue::Pop()
{
	if (size == 0)
		return false;
	QItem *tmp = front;
	front = front->next;
	delete tmp;
	size--;
	if (size == 0)
		rear = NULL;
	return true;
}
InfoType LQueue::GetFirst() const
{
	if (IsEmpty())
		throw QException("Impossible to execute GetFirst: queue is empty");
	return front->info;
}
bool LQueue::IsEmpty() const
{
	return (size == 0);
}
unsigned LQueue::GetSize() const
{
	return size;
}
InfoType & LQueue::operator[](unsigned k)
{
	return (InfoType&)GetByIndex(k);
}
const InfoType & LQueue::GetByIndex(unsigned k) const
{
	if ((k < 0) || (k >= size))
		throw QException("Impossible to execute operator[]: invalid index");
	QItem *tmp = front;
	for (unsigned i = 0; i < k; i++)
		tmp = tmp->next;
	return tmp->info;
}
void LQueue::Browse(void ItemWork(InfoType info)) const
{
	QItem *tmp = front;
	for (unsigned i = 0; i < size; i++) {
		ItemWork(tmp->info);
		tmp = tmp->next;
	}
}
void LQueue::Browse(void ItemWork(InfoType& info))
{
	QItem *tmp = front;
	for (unsigned i = 0; i < size; i++) {
		ItemWork(tmp->info);
		tmp = tmp->next;
	}
}

void AQueue::Erase()
{
	delete Arr;
	first = last = capacity = 0;
}
void AQueue::Clone(const Queue &q)
{
	capacity = dynamic_cast<const AQueue&>(q).capacity;
	first = dynamic_cast<const AQueue&>(q).first;
	last = dynamic_cast<const AQueue&>(q).last;
	Arr = new InfoType[capacity];
	for (unsigned i = 0; i < capacity; i++)
		Arr[i] = dynamic_cast<const AQueue&>(q).Arr[i];
}
AQueue::AQueue(int cpty) :first(0), last(0)
{
	capacity = cpty;
	Arr = new InfoType[capacity];
}
AQueue::AQueue(const AQueue &q)
{
	Clone(q);
}
void AQueue::Push(InfoType info)
{
	if (IsFull())
		throw QException("Impossible to push element: AQueue is full");
	Arr[last++] = info;
	if (last > capacity)
		last = 0;
}
bool AQueue::Pop()
{
	if (IsEmpty())
		return false;
	first++;
	return true;
}
InfoType AQueue::GetFirst() const
{
	if (IsEmpty())
		throw QException("Impossible to execute GetFirst(): AQeue is empty");
	return Arr[first];
}
bool AQueue::IsFull() const
{
	if ((last == capacity && first == 0) || last + 1 == first)
		return true;
	return false;
}
bool AQueue::IsEmpty() const
{
	if (first == last)
		return true;
	return false;
}
unsigned AQueue::GetSize() const
{
	return capacity;
}
InfoType & AQueue::operator[](unsigned k)
{
	return (InfoType&)GetByIndex(k);
}
const InfoType & AQueue::GetByIndex(unsigned k) const
{
	if (k<0 || k >= capacity)
		throw QException("Impossible to execute operator[]: invalid index");
	return Arr[k];
}
void AQueue::Browse(void ItemWork(InfoType info)) const
{

	for (unsigned i = first; i != last; i++)
	{
		ItemWork(Arr[i]);
		if (i >= capacity)
			i = -1;
	}
}
void AQueue::Browse(void ItemWork(InfoType &info))
{
	for (unsigned i = first; i != last; i++)
	{
		if (i > capacity)
			i = 0;
		ItemWork(Arr[i]);
	}
}
//AQueue& AQueue::operator = (const AQueue&q)
//{
//	
//		if (this != &q)
//		{
//			Erase();
//			Clone(q);
//		}
//		return *this;
//	
//}
//LQueue& LQueue::operator = (const LQueue&q)
//{
//
//	if (this != &q)
//	{
//		Erase();
//		Clone(q);
//	}
//	return *this;
//
//}
//LQueue::~LQueue()
//{
//	Erase();
//}
//AQueue::~AQueue()
//{
//	Erase();
//}