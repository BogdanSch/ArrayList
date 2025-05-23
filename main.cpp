#include <iostream>
#include <limits.h>
#include "ArrayList.h"

using std::cout;
using std::cin;

int main() {
    ArrayList myList({ 1, 1000, 2, 999, 3, 998, 4, 997, 0, -100, -5, INT_MAX, -INT_MAX, -200});
    myList.printList();

    int choice;
    std::cout << "Enter 1 for ascending, 0 for descending: ";
    cin >> choice;

    bool isAscending = (choice == 1);

    std::cout << "Sorting in " << (isAscending ? "ascending" : "descending") << " order:\n";
    myList.heapsort(isAscending);

    myList.printList();
    
    std::cout << "Building max heap:\n";
	vector<int> numbers = { 20, 1, 30, 9, 56, 66, 109 };
    ArrayList* myList2 = ArrayList::buildHeap(numbers);
    myList2->printList();

    return 0;
}
