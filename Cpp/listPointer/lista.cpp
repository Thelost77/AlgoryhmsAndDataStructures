typedef int elementtype;
struct celltype
{
    celltype(const elementtype &element) : element(element), next(nullptr) {}

    elementtype element;
    celltype *next;
};
typedef celltype *position;

#include <iostream>
#include <climits>
class Lista
{
protected:
    position listHead; // wskaźnik do głowy listy
public:
    Lista()
    {
        celltype *c = new celltype(INT_MIN);
        listHead = c;
    };
    ~Lista()
    {
        while (listHead->next != NULL)
        {
            position tmp = listHead->next;
            listHead->next = tmp->next;
            delete tmp;
        }
        delete listHead;
    };
    void Insert(elementtype x, position p)
    {
        position next = p->next;
        celltype *c = new celltype(x);
        c->next = next;
        p->next = c;
    };
    void Delete(position p)
    {
        position temp = p->next;
        if (temp)
            p->next = temp->next;
        delete temp;
    };
    elementtype Retrieve(position p)
    {
        if (p->next != nullptr)
            return p->next->element;

        return INT_MIN;
    };
    position Locate(elementtype x)
    {
        position i = First();
        while (i->next->element != x)
            i = i->next;
        return i;
    };
    position First()
    {
        return listHead;
    };
    position Next(position p)
    {
        return p->next;
    };
    position Previous(position p)
    {
        position i = First();
        while (i->next != p)
            i = i->next;
        return i;
    };
    position END()
    {
        position i = listHead;
        while (i->next != nullptr)
            i = i->next;
        return i;
    };
    void Print()
    {
        position i = First();
        while (i != END())
        {
            std::cout << Retrieve(i) << " ";
            i = i->next;
        }
        std::cout << std::endl;
    }

    void Duplicate()
    {
        position i = First();
        while (i != END())
        {
            elementtype currentElement = Retrieve(i);
            i = Next(i);
            Insert(currentElement, First());
        }
    }

    void Purge()
    {
        position i = First();
        while (i != END())
        {
            elementtype currentElement = Retrieve(i);
            position elementLastIndex = LocateNextIndex(currentElement, i);
            if (elementLastIndex != i && elementLastIndex != END())
            {
                Delete(i);
                continue;
            }
            i = Next(i);
        }
    }

    position LocateNextIndex(elementtype x, position p)
    {
        for (position i = p->next; i != END(); i = i->next)
        {
            if (x == Retrieve(i))
                return i;
        }
        return END();
    }
};
    

int Top(List list) {
    return list.Retrieve(list.First());
}

void Pop(List list) {
    list.Delete(list.First());
}

void Push(List list, elementtype element) {
    list.Insert(element, list.First());
}

#include <iostream>
int main()
{
    Lista list{};

    list.Insert(5, list.First());
    std::cout << list.Retrieve(list.First()) << std::endl;

    list.Insert(2, list.First());
    std::cout << list.Retrieve(list.First()) << std::endl;
    std::cout << list.Retrieve(list.Next(list.First())) << std::endl;

    list.Insert(1, list.Next(list.First()));
    list.Print();

    list.Insert(100, list.END());
    list.Print();

    list.Delete(list.Previous(list.Locate(100)));
    list.Print();

    list.Duplicate();
    list.Print();

    list.Duplicate();
    list.Print();

    list.Purge();
    list.Print();

    return 0;
}