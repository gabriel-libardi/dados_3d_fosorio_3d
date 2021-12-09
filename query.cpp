#include <iostream>
#include "linked_list.hpp"
#include "linked_list.hxx"
#include "point_3d.hpp"
#include "point_3d.hxx"
#include "query.hpp"
using namespace std;


void query_tot(LinkedList<Point<'X'>>& list_x) {
    size_t size = list_x.size;
    printf("LX:%lu LI:%lu LF:%lu\n", list_x.nodes, size, size*(size + 1)/2);
}


void query_pz(LinkedList<Point<'Z'>>& list_z) {
    Point_3D point = list_z[0].coordinates;
    printf("%0.5f %0.5f %0.5f TOTAL:1\n", point.x, point.y, point.z);
}


void query_pi(LinkedList<Point<'I'>>& list_i) {
    Point<'I'> smallest_z = (*(list_i.head))->data;

    for (Node<Point<'I'>> *current = *(list_i.head); current != NULL; current = current->next_node_ptr) {
        if (current->data < smallest_z) {
            smallest_z = current->data;
        }
    }
    
    Point_3D point = smallest_z.coordinates;
    printf("%0.5f %0.5f %0.5f TOTAL:%lu\n", point.x, point.y, point.z, list_i.size);
}


void query_id(LinkedList<Point<'X'>>& list_x) {
    int requested_id;
    cin >> requested_id;

    for (Node<Point<'X'>> *current = *(list_x.head); current != NULL; current = current->next_node_ptr) {
        if (current->data == requested_id) {
            cout << current->data;
        }
    }
}


void query_cut(LinkedList<Point<'X'>>& list_x) {
    /*Executes the "CUT" query.*/
    Point_3D minimum;
    Point_3D maximum;

    cin >> minimum.x >> minimum.y >> minimum.z;
    cin >> maximum.x >> maximum.y >> maximum.z;

    for (Node<Point<'X'>> *current = *(list_x.head); current != NULL; current = current->next_node_ptr) {
        if (current->data >= minimum && current->data <= maximum) {
            cout << current->data;
        }
    }
}
