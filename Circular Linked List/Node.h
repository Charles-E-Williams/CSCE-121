#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T val;
    Node<T>* next;
    Node() : next(nullptr) {}
    Node(T val) : val(val), next(nullptr) {}
};








#endif