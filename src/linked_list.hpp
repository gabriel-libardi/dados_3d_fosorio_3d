#ifndef __LINKED_LIST_HPP__
#define __LINKED_LIST_HPP__

#include <iostream>
using namespace std;


template <class Type> struct Node {
    Type data;
    Node<Type> *next_node_ptr;
};


template <class Type> class LinkedList;
template <class Type> ostream& operator<<(ostream& os, LinkedList<Type>& list);
template <class Type> istream& operator>>(istream& in, LinkedList<Type>& list);


template <class Type> class LinkedList {

  friend ostream& operator<<<Type>(ostream& os, LinkedList<Type>& list);
  friend istream& operator>><Type>(istream& in, LinkedList<Type>& list);

  private:

    Node<Type> *get_tail();
    static Node<Type> *new_node(Type& data);
    bool is_this_an_integer_list();

    LinkedList<Type> *operator/(size_t divisor);
    void ord_insert(Node<Type> **list_to_insert, size_t list_size);
  
  public:
    Node<Type> **head;
    size_t size;
    size_t nodes;

    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList<Type>& list);
    LinkedList<Type>& operator=(const LinkedList<Type>& list_to_assign);

    void operator+(Type& head_node_data);
    void push(Type& tail_node_data);
    Type operator[](size_t index);

    void reverse();
    void ord_insert(const LinkedList<Type>& list_to_insert);
    void merge_sort();

    void ordered_read(string input_stream);
    void unordered_read_init(string input_stream);
    void unordered_read_end(string input_stream);
};


#include "linked_list.hxx"
#endif
