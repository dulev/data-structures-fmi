#ifndef BOX_H
#define BOX_H

template <typename T>
struct Box {
    Box *next;
    T data;

    Box(T _data, Box* _next);
};

template <typename T>
void append(Box<T>*& l1, Box<T>* l2);

template <typename T>
Box<T>* concat(Box<T>* l1, Box<T>* l2);

template <typename T>
Box<T>* map(T (*mapping)(T), Box<T>* b);

template <typename T>
Box<T>* reverse(Box<T>* b);

template <typename T>
int count(Box<T>* l, T x);

template <typename T>
void print(const Box<T>* b);

template <typename T>
void removeAll(Box<T>*& b, T x);

Box<int>* range(int x, int y);

#endif