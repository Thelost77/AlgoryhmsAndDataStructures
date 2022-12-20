#include <cstdio>

typedef int elementtype, position;
const int maxlength = 40;
const int minValue = -10000000;
struct List
{
	elementtype elements[maxlength];
	int last;           //indeks ostatniego elementu listy
};

position END(List l)
{ 
	return l.last + 1;
}

position First(List l)
{
	return 0;
}

position Next(position p, List l)
{
	if(p == l.last)
		return END(l);

	if(p < END(l))
		return p+1;
	
	return -1;
}


position Previous(position p,List l) 
{
	if(p - 1 >= First(l))
		return p-1;
	return -1;
}



position Locate(elementtype x, List l) 
{ //zwraca pozycje x w l, gdy nie ma x w l zwraca end(l)
	for (position i = 0; i <= l.last; i++)
	{
		if(x == l.elements[i])
			return i;
	}
	return END(l);
}

position LocateLastIndex(elementtype x, List l) 
{ //zwraca pozycje od końca x w l, gdy nie ma x w l zwraca end(l)
	for (position i = l.last; i >= First(l); i--)
	{
		if(x == l.elements[i])
			return i;
	}
	return END(l);
}

elementtype Retrieve(position p, List l) 
{
	if(p >= 0 && p <= l.last) {
		return l.elements[p];
	}
	return minValue;
}

bool Insert(int x, position p, List &l)
{
	if(p > maxlength - 1 || p < 0)
		return false;
	
	int lastElement = END(l);
	if(lastElement >= maxlength)
		lastElement = l.last;

	for (position i = lastElement; i > p; i--)
	{
		l.elements[i] = l.elements[i - 1];
	}
	l.elements[p] = x;

	l.last = lastElement;

	return true;
}

bool Delete(position p, List &l)
{
	if(p > l.last || p < 0)
		return false;
	
	for (position i = p; i < l.last; i++)
	{
		l.elements[i] = l.elements[i + 1];
	}
	l.last--;
	return true;

}

void print(List l)
{
	position i=First(l);
	while (i!=END(l))
	{
		printf ("  %d,", Retrieve(i,l));
		i=Next(i,l);
	}
	printf("\n");

}

void Purge(List& l)
{
	position i = First(l);
	while(i < END(l)) {
		elementtype currentElement = Retrieve(i, l);
		position elementLastIndex = LocateLastIndex(currentElement, l);
		if(elementLastIndex != i && elementLastIndex != END(l)) {
			Delete(i, l);
			continue;
		}
		i = Next(i, l);
	}
}

// void DuplicateDuplicates(List& l)
// {
// 	position i = First(l);
// 	position end = END(l);
// 	elementtype firstElement = Retrieve(i, l);
// 	position firstElementDuplicateIndex = LocateLastIndex(firstElement, l);
// 	if(firstElementDuplicateIndex != i && firstElementDuplicateIndex != END(l))
// 		Insert(firstElement, END(l), l);
// 	while(i < end) {
// 		elementtype currentElement = Retrieve(i, l);
// 		position elementLastIndex = LocateLastIndex(currentElement, l);
// 		if(elementLastIndex != i && elementLastIndex != END(l))
// 			Insert(currentElement, END(l), l);
// 		i = Next(i, l);
// 	}
// }

void Duplicate(List& l)
{
	position i = First(l);
	position end = END(l);
	while(i < end) {
		elementtype currentElement = Retrieve(i, l);
		Insert(currentElement, END(l), l);
		i = Next(i, l);
	}
}

int main() {
	List l;
	l.last=-1;
	
	Insert(100, First(l), l);
	print(l);

	for (int i=0; i<5;i++)
		Insert(i, First(l), l);

	print (l);

	Insert (20, Previous(END(l), l), l);
	print(l);

	Delete(Locate(20,l),l);
	print(l);

	Insert(50, Next(Locate(0, l), l), l);
	print(l);

	Duplicate(l);
	print(l);

	Duplicate(l);
	print(l);

	Purge(l);
	print(l);
}

