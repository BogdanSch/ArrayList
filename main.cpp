#include <iostream>
#include <limits.h>
#include "ArrayList.h"

using std::cout;
using std::cin;

int main() {
    ArrayList myList({ 1, 1000, 2, 999, 3, 998, 4, 997, 0, -100, -5, INT_MAX, -INT_MAX });
    myList.printList();

    int choice;
    std::cout << "Enter 1 for ascending, 0 for descending: ";
    cin >> choice;

    bool isAscending = (choice == 1);

    std::cout << "Sorting in " << (isAscending ? "ascending" : "descending") << " order:\n";
    myList.heapsort(isAscending);

    myList.printList();

    return 0;
}
