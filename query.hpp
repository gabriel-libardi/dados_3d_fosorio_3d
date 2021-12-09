#ifndef __QUERY_HPP__
#define __QUERY_HPP__


#include <iostream>
#include "linked_list.hpp"
#include "linked_list.hxx"
#include "point_3d.hpp"
#include "point_3d.hxx"
using namespace std;


void query_tot(LinkedList<Point<'X'>>& list_x);
void query_pz(LinkedList<Point<'Z'>>& list_z);
void query_pi(LinkedList<Point<'I'>>& list_i);
void query_id(LinkedList<Point<'X'>>& list_x);
void query_cut(LinkedList<Point<'X'>>& list_x);

#endif
