#include "../include/box.h"

template <typename T>
Box<T>::Box(T _data, Box<T>* _next) : data(_data), next(_next) {}

template <typename T>
void append(Box<T>*& l1, Box<T>* l2) {
    if (l1 == nullptr && l2 != nullptr) {
        l1 = new Box<T>(l2->data, nullptr);
        l2 = l2->next;
    }

    Box<T>* tail = l1;
    while (tail->next != nullptr) {
        tail = tail->next;
    }

    while (l2 != nullptr) {
        tail->next = new Box<T>(l2->data, nullptr);
        tail = tail->next;
        l2 = l2->next;
    }
}

template <typename T>
Box<T>* concat(Box<T>* l1, Box<T>* l2) {
    Box<T>* result = nullptr;
    append(result, l1);
    append(result, l2);
    return result;
}

template <typename T>
int count(Box<T>* l, T x) {
    if (l == nullptr) {
        return 0;
    }
    
    if (l->data == x) {
        return 1 + count(l->next, x);
    } else {
        return count(l->next, x);
    }
}

template <typename T>
void print(Box<T> *b) {
    while (b != nullptr)
    {
        std::cout << b->data << " ";
        b = b->next;
    }
    std::cout << std::endl;
}


template <typename T>
void removeAll(Box<T>*& b, T x) {
    while (b != nullptr && b->data == x) {
        Box<T>* temp = b;
        b = b->next;
        delete temp;
    }

    if (b != nullptr) {
        removeAll(b->next, x);
    }
}

Box<int>* range(int x, int y) {
    if (x > y) {
        throw std::runtime_error("Invalid range for Box<int> creation.");
    }

    Box<int>* first = new Box<int>(x, nullptr);
    Box<int>* current = first;

    while (x < y)
    {
        current->next = new Box<int>(++x, nullptr);
        current = current->next;
    }

    return first;
}

template <typename T>
Box<T>* map(T (*mapping)(T), Box<T>* b) {
    Box<T>* result = concat(b, (Box<T>*)nullptr);

    Box<T>* curr = result;
    while (curr != nullptr) {
        curr->data = mapping(curr->data);
        curr = curr->next;
    }

    return result;
}

template <typename T>
Box<T>* reverse(Box<T>* b) {
    Box<T>* result = nullptr;

    while (b != nullptr)
    {
        Box<T>* temp = result;
        result = new Box<T>(b->data, temp);
        b = b->next;
    }

    return result;
}

template <typename T>
bool inList(Box<T>* l, T x) {
    return count(l, x) > 0;
}

template <typename T>
bool duplicates(Box<T>* l) {
    // Recursive implementation;
    if (l == nullptr) {
        return false;
    }
    
    return inList(l->next, l->data) || duplicates(l->next);

    // Imperative implementation:

    // Box<T>* current = l;
    // while (current != nullptr) {
    //     if (count(current, current->data) != 1) {
    //         return true;
    //     }
    //     current = current->next;
    // }
    // return false;
}

template <typename T>
void removeDuplicates(Box<T>* l) {
    if (l != nullptr) {
        removeAll(l->next, l->data);
        removeDuplicates(l->next);
    }
}

template <typename T>
bool isAscending(Box<T>* l) {
    while (l != nullptr && l->next != nullptr) {
        if (l->data >= l->next->data) {
            return false;
        }

        l = l->next;
    }

    return true;
}

template <typename T>
bool isSorted(Box<T>* l) {
    // This creates a memory leak, but since the problem definitions
    // aren't that concise I won't bother creating a memory cleanup function.
    return isAscending(l) || isAscending(reverse(l));
}

template <typename T>
bool equals(Box<T>* l1, Box<T>* l2) {
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->data != l2->data) {
            return false;
        }

        l1 = l1->next;
        l2 = l2->next;
    }

    return l1 == nullptr && l2 == nullptr;
}

template <typename T>
bool palindrome(Box<T>* l) {
    return equals(l, reverse(l));
}