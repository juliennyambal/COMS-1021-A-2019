#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstddef>
#include <iostream>
#include "tests.h"

using namespace std;

class Link{
public:
    TestFixture t; // Ignore this, it is for testing

    int value;
    Link* next;

    Link(int v) : value(v), next(nullptr){}
    ~Link(){}
};

class LinkedList
{
public:
    Link* head;
    Link* tail;

    LinkedList();

    void push_front(int value);
    void push_back(int value);
    void pop_front();
    void pop_back();

    void remove_at_index(int idx);
    void insert_at_index(int idx, int value);

    void reverse();
};

LinkedList *list_union(LinkedList &l1, LinkedList &l2);

#endif // LINKEDLIST_H
