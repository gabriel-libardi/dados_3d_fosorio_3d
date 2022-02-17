#ifndef __LINKED_LIST_HXX__
#define __LINKED_LIST_HXX__

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include <string>
#include "linked_list.hpp"
using namespace std;


template <class Type> LinkedList<Type>::LinkedList() {
    this->size = 0;
    this->nodes = 0;
    this->head = (Node<Type> **)malloc(sizeof(Node<Type> *));
    *(this->head) = NULL;
}


template <class Type> LinkedList<Type>::~LinkedList() {
    /*This method frees all the memory allocated in the heap for a LinkedList object.*/
    for (Node<Type> *current_node = *(this->head); current_node != NULL;) {
        Node<Type> *next_node = current_node->next_node_ptr;
        free(current_node);
        current_node = next_node;
    }

    free(this->head);
}


template <class Type> LinkedList<Type>::LinkedList(const LinkedList<Type>& list) {
    this->size = list.size;
    this->head = (Node<Type> **)malloc(sizeof(Node<Type> *));

    Node<Type> *list_tail = *head;

    for (Node<Type> *current_node = *(list.head); current_node != NULL; current_node = current_node->next_node_ptr) {
        Node<Type> *new_node = this->new_node(current_node->data);

        if (list_tail != NULL) {
            list_tail->next_node_ptr = new_node;
        } else {
            *(this->head) = new_node;
        }

        list_tail = new_node;  
    }
}


template <class Type> LinkedList<Type>& LinkedList<Type>::operator=(const LinkedList<Type>& list_to_assign) {
    for (Node<Type> *current_node = *(this->head); current_node != NULL;) {
        Node<Type> *next_node = current_node->next_node_ptr;
        free(current_node);
        current_node = next_node;
    }

    this->size = list_to_assign.size;
    *(this->head) = NULL;
    Node<Type> *list_tail = *head; //This is used to append elements at the tail of *this.

    for (Node<Type> *cursor = *(list_to_assign.head); cursor != NULL; cursor = cursor->next_node_ptr) {
        Node<Type> *new_node = this->new_node(cursor->data);

        if (list_tail != NULL) {
            list_tail->next_node_ptr = new_node;
        } else {
            *(this->head) = new_node;
        }

        list_tail = new_node;    
    }

    return *this;
}


template <class Type> Node<Type> *LinkedList<Type>::new_node(Type& data) {
    /*This function creates a node and returns a pointer to it.*/
    Node<Type> *new_node = (Node<Type> *)malloc(sizeof(Node<Type>));
    new_node->data = data;
    new_node->next_node_ptr = NULL;

    return new_node;
}


template <class Type> void LinkedList<Type>::operator+(Type& head_node_data) {
    /*This method adds a node in the head of the list*/
    Node<Type> *new_node = this->new_node(head_node_data);
    new_node->next_node_ptr = *(this->head);
    *(this->head) = new_node;
    this->size++;
}


template <class Type> Node<Type> *LinkedList<Type>::get_tail() {
    /*This method returns the pointer for the tail of the list.*/
    Node<Type> *current_node = *(this->head);
    while (current_node != NULL && current_node->next_node_ptr != NULL) {
        current_node = current_node->next_node_ptr;
    }

    return current_node;
}


template <class Type> Type LinkedList<Type>::operator[](size_t index) {
    Node<Type> *current_node = *(this->head);

    for (size_t node_index = 0; node_index < index; node_index++) {
        current_node = current_node->next_node_ptr;
    }

    return current_node->data;
}


template <class Type> LinkedList<Type> *LinkedList<Type>::operator/(size_t divisor) {
    LinkedList<Type> *list_fragments = new LinkedList<Type>[divisor*sizeof(LinkedList<Type>)];
    Node<Type> *current_node = *(this->head);
    
    for (size_t fragment = 0; fragment < divisor; fragment++) {
        *((list_fragments[fragment]).head) = current_node;
        (list_fragments[fragment]).size = (this->size)/divisor + (this->size%divisor)*(fragment == divisor - 1);

        for (size_t index = 0; index < (this->size)/divisor - 1; index++) {
            current_node = current_node->next_node_ptr;
        }

        Node<Type> *next_node = current_node->next_node_ptr;
        current_node->next_node_ptr = (fragment != divisor - 1) ? NULL : current_node->next_node_ptr;
        current_node = next_node;
    }
    this->size /= divisor;
    
    return list_fragments;
}


template <class Type> void LinkedList<Type>::push(Type& tail_node_data) {
    /*This method adds a node at the tail of the list.*/
    Node<Type> *new_node = this->new_node(tail_node_data);
    this->size++;

    Node<Type> *list_tail = this->get_tail();
    if (list_tail != NULL) {
        list_tail->next_node_ptr = new_node;
    } else {
        *(this->head) = new_node;
    }
}


template <class Type> ostream& operator<<(ostream& output, LinkedList<Type>& list) {
    Node<Type> *current_node = *(list.head);

    while (current_node != NULL) {
        output << current_node->data;
        current_node = current_node->next_node_ptr;
    }

    return output;
}


template <class Type> istream& operator>>(istream& input, LinkedList<Type>& list) {
    for (Type new_element; true; list.size++) {
        input >> new_element;

        if (new_element == -1) {
            break;
        } else {
            list + new_element;
        }
    } 

    return input;
}


template <class Type> void LinkedList<Type>::ordered_read(string input_stream) {
    /*Reads a list from the input_stream and sorts it with insertion sort.*/
    ifstream input;
    input.open(input_stream);

    while (true) {
        Type new_element;
        input >> new_element;

        if (new_element == -1) {
            break;
        } else {
            Node<Type> *new_node = this->new_node(new_element);
            this->ord_insert(&new_node, 1);
        }
    }
}


template <class Type> void LinkedList<Type>::unordered_read_init(string input_stream) {
    /*Reads a list from the input stream and inserts each element in the head of the list.*/
    ifstream input;
    input.open(input_stream);

    while (true) {
        Type new_element;
        input >> new_element;

        if (new_element == -1) {
            break;
        } else {
            *this + new_element;
        }
    }
}


template <class Type> void LinkedList<Type>::unordered_read_end(string input_stream) {
    /*Reads a list from the input stream and inserts each element in the head of the list.*/
    ifstream input;
    input.open(input_stream);

    while (true) {
        Type new_element;
        input >> new_element;

        if (new_element == -1) {
            break;
        } else {
            this->push(new_element);
        }
    }
}


template <class Type> void LinkedList<Type>::reverse() {
    /*Returns a copy of *this with its elements in reverse order.*/
    Node<Type> *previous_node = NULL;
    Node<Type> *current_node = *(this->head);

    while (current_node != NULL) {
        Node<Type> *next_node = current_node->next_node_ptr;
        current_node->next_node_ptr = previous_node; //Reverses the order of the list.

        previous_node = current_node;
        current_node = next_node;
    }

    *(this->head) = previous_node; //Sets the head of the list as its old tail.
}


template <class Type> void LinkedList<Type>::ord_insert(const LinkedList<Type>& list_to_insert) {
    /*Performs an ordered insertion of list_to_insert in *this. */
    if (*(this->head) != NULL) {
        Node<Type> *insert = *(list_to_insert.head);
        Node<Type> *current_node = *(this->head);
        Node<Type> *previous_node = NULL;

        while (current_node != NULL) {
            while (insert != NULL && insert->data <= current_node->data) {

                Node<Type> *new_node = this->new_node(insert->data);
                new_node->next_node_ptr = current_node;

                if (previous_node != NULL) {
                    previous_node->next_node_ptr = new_node;
                } else {
                    *(this->head) = new_node;
                }
                previous_node = new_node;
                insert = insert->next_node_ptr;
            }
            previous_node = current_node;
            current_node = current_node->next_node_ptr;
        }

        while (insert != NULL) { //Insert remaining elements at the end of the list.
            previous_node->next_node_ptr = this->new_node(insert->data); //Append to the tail.
            previous_node = previous_node->next_node_ptr;
            insert = insert->next_node_ptr;
        }
        this->size += list_to_insert.size; //Correct the size of the list.
    } else {
        *this = list_to_insert; //*this is an empty list, so we make a deep copy of list_to_insert.
    }
}


template <class Type> void LinkedList<Type>::ord_insert(Node<Type> **list_to_insert, size_t list_size) {
    /*Performs an ordered insertion of list_to_insert in *this. */
    if (*(this->head) != NULL) {
        Node<Type> *insert = *list_to_insert;
        Node<Type> *current_node = *(this->head);
        Node<Type> *previous_node = NULL;

        while (current_node != NULL) {
            while (insert != NULL && insert->data <= current_node->data) {

                if (previous_node != NULL) {
                    previous_node->next_node_ptr = insert;
                } else {
                    *(this->head) = insert;
                }
                Node<Type> *next_node_to_insert = insert->next_node_ptr;
                insert->next_node_ptr = current_node;

                previous_node = insert;
                insert = next_node_to_insert;
            }
            previous_node = current_node;
            current_node = current_node->next_node_ptr;
            this->nodes++;
        }
        previous_node->next_node_ptr = insert;

    } else {
        *(this->head) = *list_to_insert; //*this is an empty list, so we make a copy of list_to_insert.
    }

    this->size += list_size;
    *list_to_insert = NULL;
}


template <class Type> void LinkedList<Type>::merge_sort() {
    if (this->size > 2) {
        LinkedList<Type> *list_halves = (*this)/2;
        
        list_halves[0].merge_sort();
        list_halves[1].merge_sort();

        list_halves[0].ord_insert(list_halves[1].head, list_halves[1].size);

        *(this->head) = *(list_halves[0].head);
        this->size = list_halves[0].size;
        *(list_halves[0].head) = NULL;
        
    } else if (this->size == 2) {
        Type first_num = (*(this->head))->data;
        Type second_num = ((*(this->head))->next_node_ptr)->data;

        (*(this->head))->data = (first_num < second_num) ? first_num : second_num;
        ((*(this->head))->next_node_ptr)->data = (first_num < second_num) ? second_num : first_num;
    }
}


#endif
