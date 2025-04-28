#include <iostream>
#include <vector>

using std::vector;

class ArrayList {
private:
    static const int MAX_SIZE = 100;
    int items[MAX_SIZE];
    int length;
    bool (*compareFunc)(int, int) = &ascendingCompare;
protected:
    void buildMaxOrMinHeap();
    void heapify(int length, int i);
public:
    ArrayList() : length(0) {}
    ArrayList(int item) : length(1) { items[0] = item; }
    ArrayList(vector<int> numbers) : length(numbers.size()) { for (int i = 0; i < numbers.size(); i++) items[i] = numbers[i]; }
    bool isEmpty() const { return length == 0; }
    bool isFull() const { return length == MAX_SIZE; }
    void add(int item);
    int indexOf(int item) const;
    void remove(int item);
    static bool ascendingCompare(int a, int b);
    static bool descendingCompare(int a, int b);
    void heapsort(bool isAscending);
    void printList() const;
    int size() const { return length; }
};