#include <iostream>
#include "./src/box.cpp" // Included cpp for templates to work.

using std::cin;
using std::cout;

void testCount();
void testRange();
void testRemoveAll();
void testAppend();
void testConcat();
void testMap();
void testReverse();
void testDuplicates();
void testRemoveDuplicates();
void testIsSorted();
void testPalindrome();

int main() {
    // testCount();
    // testRange();
    // testRemoveAll();
    // testAppend();
    // testConcat();
    // testMap();
    // testReverse();
    // testDuplicates();
    // testRemoveDuplicates();
    // testIsSorted();
    testPalindrome();
    
    return 0;
}

void testCount() {
    Box<int> *b = new Box<int>(5,
                    new Box<int>(5,
                      new Box<int>(4, nullptr)));

    std::cout << count(b, 4) << std::endl;
}

void testRange() {
    Box<int> *b = range(5, 10);
    print(b);
}

void testRemoveAll() {
    Box<int> *b = new Box<int>(5,
                    new Box<int>(8,
                      new Box<int>(5,
                        new Box<int>(8,
                          new Box<int>(5, nullptr)))));
    print(b);
    removeAll(b, 5);
    print(b);
}

void testAppend() {
    Box<int> *l1 = range(1, 3);
    Box<int> *l2 = range(5, 7);
    print(l1);
    print(l2);
    append(l1, l2);
    print(l1);
    print(l2);
}

void testConcat() {
    Box<int> *l1 = range(1, 3);
    Box<int> *l2 = range(5, 7);
    print(l1);
    print(l2);
    print(concat(l1, l2));
    print(l1);
    print(l2);
}

void testMap() {
    Box<int> *l1 = range(1, 3);
    int (*square)(int x) = [](int x) -> int { return x * x; };
    print(map(square, l1));
}

void testReverse() {
    Box<int> *l = range(1, 3);
    print(reverse(l));
}

void testDuplicates() {
    Box<int> *l1 = new Box<int>(1, range(1, 3));
    Box<int> *l2 = range(1, 3);
    print(l1);
    std::cout << "Duplicates: " << (duplicates(l1) ? "true" : "false") << std::endl;
    print(l2);
    std::cout << "Duplicates: " << (duplicates(l2) ? "true" : "false") << std::endl;
}

void testRemoveDuplicates() {
    Box<int> *l = new Box<int>(1, range(1, 3));
    print(l);
    removeDuplicates(l);
    print(l);
}

void testIsSorted() {
    Box<int> *l = range(1, 5);
    Box<int> *rev = reverse(l);
    Box<int> *no = new Box<int>(1, new Box<int>(1, nullptr));
    print(l);
    std::cout << "Is sorted: " << (isSorted(l) ? "true" : "false") << std::endl;
    print(rev);
    std::cout << "Is sorted: " << (isSorted(rev) ? "true" : "false") << std::endl;
    print(no);
    std::cout << "Is sorted: " << (isSorted(no) ? "true" : "false") << std::endl;
}

void testPalindrome() {
    Box<int> *l1 = range(1, 3);
    Box<int> *l2 = new Box<int>(1, new Box<int>(2, new Box<int>(1, nullptr)));

    print(l1);
    std::cout << "Is palindrome: " << (palindrome(l1) ? "true" : "false") << std::endl;
    print(l2);
    std::cout << "Is palindrome: " << (palindrome(l2) ? "true" : "false") << std::endl;
}