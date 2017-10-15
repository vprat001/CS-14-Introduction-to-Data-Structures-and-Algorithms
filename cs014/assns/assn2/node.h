#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;
template<class T>
class Node {
    T data;
    Node<T> *next;
    Node(T data) : data(data), next(0) {}
};
#endif
