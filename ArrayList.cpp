#include "ArrayList.h"
#include <functional>

using std::cout; 
using std::endl;
using std::swap;

void ArrayList::add(int item)
{
    if (isFull()) 
    {
        cout << "Cannot add item. List is full.\n";
        return;
    }
    items[++length] = item;
}

int ArrayList::indexOf(int item) const
{
    int index = -1;
    for (int i = 1; i <= length; i++) 
    {
        if (items[i] == item) 
        {
            index = i;
            break;
        }
    }
    return index;
}

void ArrayList::remove(int item)
{
    if (isEmpty()) 
    {
        cout << "Cannot remove item. List is empty.\n";
        return;
    }

    int index = indexOf(item);

    if (index == -1) 
    {
        cout << "Item not found.\n";
        return;
    }

    for (int i = index; i <= length; i++)
    {
        items[i] = items[i + 1];
    }
    length--;
}

bool ArrayList::ascendingCompare(int a, int b)
{
	return a > b;
}

bool ArrayList::descendingCompare(int a, int b)
{
    return a < b;
}

void ArrayList::heapsort(bool isAscending)
{
	if (isEmpty())
    {
		cout << "Cannot sort. List is empty.\n";
		return;
	}

	compareFunc = isAscending ? &ascendingCompare : &descendingCompare;

	buildMaxOrMinHeap();

	for (int i = length; i >= 2; i--)
    {
		swap(items[1], items[i]);
		heapify(i - 1, 1);
	}
}

ArrayList* ArrayList::buildHeap(vector<int>& numbers)
{
    ArrayList* tempList = new ArrayList(numbers);
    //tempList.compareFunc = &ascendingCompare;
    tempList->buildMaxOrMinHeap();

	return tempList;
}

void ArrayList::buildMaxOrMinHeap()
{
	if (isEmpty())
    {
		cout << "Cannot build heap. List is empty.\n";
		return;
	}

	for (int i = length / 2; i >= 1; i--)
    {
		heapify(length, i);
	}
}

void ArrayList::heapify(int heapLength, int i)
{
	if (isEmpty())
	{
		cout << "Cannot heapify. List is empty.\n";
		return;
	}

	int leftIndex = 2 * i;
	int rightIndex = leftIndex + 1;
    int index = i;

    if (leftIndex <= heapLength && compareFunc(items[leftIndex], items[index]))
        index = leftIndex;
    if (rightIndex <= heapLength && compareFunc(items[rightIndex], items[index]))
        index = rightIndex;

    if (index != i)
    {
        swap(items[i], items[index]);
        heapify(heapLength, index);
    }
}

void ArrayList::printList() const
{
    if (isEmpty())
    {
        cout << "List is empty.\n";
        return;
    }

    cout << "List items: ";
    for (int i = 1; i <= length; ++i)
    {
        cout << items[i] << " ";
    }
    cout << endl;
}
