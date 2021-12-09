#include <iostream>
#include <string>
#include "linked_list.hpp"
#include "linked_list.hxx"
#include "point_3d.hpp"
#include "point_3d.hxx"
#include "query.hpp"
using namespace std;


int main(int argc, char* argv[]) {

    LinkedList<Point<'X'>> list_x;
    LinkedList<Point<'Y'>> list_y;
    LinkedList<Point<'Z'>> list_z;
    LinkedList<Point<'I'>> list_i;
    LinkedList<Point<'F'>> list_f;

    list_x.ordered_read("dados3d.txt");
    list_y.ordered_read("dados3d.txt");
    list_z.ordered_read("dados3d.txt");
    list_i.unordered_read_init("dados3d.txt");
    list_f.unordered_read_end("dados3d.txt");

    string query;
    cin >> query; //Reads the user command;

    if (query == "LX") {
        cout << list_x;
    } else if (query == "LY") {
        cout << list_y;
    } else if (query == "LZ") {
        cout << list_z;
    } else if (query == "LI") {
        cout << list_i;
    } else if (query == "LF") {
        cout << list_f;
    } else if (query == "TOT") {
        query_tot(list_x);
    } else if (query == "PZ") {
        query_pz(list_z);
    } else if (query == "PI") {
        query_pi(list_i);
    } else if (query == "ID") {
        query_id(list_x);
    } else if (query == "CUT") {
        query_cut(list_x);
    } else {
        cout << "Invalid query, the program crashed. Try again if you are not a moron";
    }
}
