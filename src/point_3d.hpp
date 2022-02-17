#ifndef __POINT_3D_HPP__
#define __POINT_3D_HPP__

#include <iostream>
using namespace std;


struct Point_3D {
    double x;  //x coordinate
    double y;  //y coordinate
    double z;  //z coordinate
};

struct Color {
    unsigned int red;    //R from the RGB system
    unsigned int green;  //G from the RGB system
    unsigned int blue;   //B from the RGB system
};


template <char point_type> class Point {

  public:
    Point_3D coordinates;
    Color color;
    int ID;
};


template <char point_type> bool operator==(Point<point_type>& point_1, Point<point_type>& point_2);
template <char point_type> bool operator==(Point<point_type>& point_1, Point_3D& point_2);
template <char point_type> bool operator==(Point<point_type>& point, int ID);

template <char point_type> bool operator!=(Point<point_type>& point_1, Point<point_type>& point_2);
template <char point_type> bool operator!=(Point<point_type>& point_1, Point_3D& point_2);
template <char point_type> bool operator!=(Point<point_type>& point, int ID);

template <char point_type> bool operator<(Point<point_type>& point_1, Point<point_type>& point_2);
template <char point_type> bool operator<(Point<point_type>& point_1, Point_3D& point_2);

template <char point_type> bool operator>(Point<point_type>& point_1, Point<point_type>& point_2);
template <char point_type> bool operator>(Point<point_type>& point_1, Point_3D& point_2);

template <char point_type> bool operator<=(Point<point_type>& point_1, Point<point_type>& point_2);
template <char point_type> bool operator<=(Point<point_type>& point_1, Point_3D& point_2);

template <char point_type> bool operator>=(Point<point_type>& point_1, Point<point_type>& point_2);
template <char point_type> bool operator>=(Point<point_type>& point_1, Point_3D& point_2);

template <char point_type> istream& operator>>(istream& input, Point<point_type>& point);
template <char point_type> ostream& operator<<(ostream& output, Point<point_type>& point);


#endif
