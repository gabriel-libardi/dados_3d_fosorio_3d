#ifndef __POINT_3D_HXX__
#define __POINT_3D_HXX__

#include "point_3d.hpp"


template <char point_type> istream& operator>>(istream& input, Point<point_type>& point) {

    input >> point.coordinates.x >> point.coordinates.y >> point.coordinates.z;
    input >> point.color.red >> point.color.green >> point.color.blue;
    input >> point.ID;

    return input;
}


template <char point_type> ostream& operator<<(ostream& output, Point<point_type>& point) {
    
    printf("%0.5f, %0.5f, %0.5f, %d, %d, %d, %d\n", 
           point.coordinates.x, point.coordinates.y, point.coordinates.z,
           point.color.red, point.color.green, point.color.blue,
           point.ID);
    
    return output;
}


template <char point_type> bool operator==(Point<point_type>& point_1, Point<point_type>& point_2) {
    return ((point_1.coordinates.x == point_2.coordinates.x) && 
            (point_1.coordinates.y == point_2.coordinates.y) &&
            (point_1.coordinates.z == point_2.coordinates.z));
}


template <char point_type> bool operator==(Point<point_type>& point_1, Point_3D& point_2) {
    return ((point_1.coordinates.x == point_2.x) && 
            (point_1.coordinates.y == point_2.y) &&
            (point_1.coordinates.z == point_2.z));
}


template <char point_type> bool operator==(Point<point_type>& point, int ID) {
    return (point.ID == ID);
}


template <char point_type> bool operator!=(Point<point_type>& point_1, Point<point_type>& point_2) {
    return !(point_1 == point_2);
}


template <char point_type> bool operator!=(Point<point_type>& point_1, Point_3D& point_2) {
    return !(point_1 == point_2);
}


template <char point_type> bool operator!=(Point<point_type>& point, int ID) {
    return (point.ID != ID);
}


template <char point_type> bool operator<(Point<point_type>& point_1, Point<point_type>& point_2) {
    if (point_type == 'X') {
        return ((point_1.coordinates.x < point_2.coordinates.x) || 
                (point_1.coordinates.x == point_2.coordinates.x && point_1.coordinates.y < point_2.coordinates.y) ||
                (point_1.coordinates.y == point_2.coordinates.y && point_1.coordinates.z < point_2.coordinates.z));

    } else if (point_type == 'Y') {
        return ((point_1.coordinates.y < point_2.coordinates.y) || 
                (point_1.coordinates.y == point_2.coordinates.y && point_1.coordinates.x < point_2.coordinates.x) ||
                (point_1.coordinates.x == point_2.coordinates.x && point_1.coordinates.z < point_2.coordinates.z));

    } else {
        return ((point_1.coordinates.z < point_2.coordinates.z) || 
                (point_1.coordinates.z == point_2.coordinates.z && point_1.coordinates.x < point_2.coordinates.x) ||
                (point_1.coordinates.x == point_2.coordinates.x && point_1.coordinates.y < point_2.coordinates.y));
    }
}


template <char point_type> bool operator<(Point<point_type>& point_1, Point_3D& point_2) {
    if (point_type == 'X') {
        return ((point_1.coordinates.x < point_2.x) || 
                (point_1.coordinates.x == point_2.x && point_1.coordinates.y < point_2.y) ||
                (point_1.coordinates.y == point_2.y && point_1.coordinates.z < point_2.z));

    } else if (point_type == 'Y') {
        return ((point_1.coordinates.y < point_2.y) || 
                (point_1.coordinates.y == point_2.y && point_1.coordinates.x < point_2.x) ||
                (point_1.coordinates.x == point_2.x && point_1.coordinates.z < point_2.z));

    } else {
        return ((point_1.coordinates.z < point_2.z) || 
                (point_1.coordinates.z == point_2.z && point_1.coordinates.x < point_2.x) ||
                (point_1.coordinates.x == point_2.x && point_1.coordinates.y < point_2.y));
    }
}


template <char point_type> bool operator>(Point<point_type>& point_1, Point<point_type>& point_2) {
    return (!(point_1 < point_2) && (point_1 != point_2));
}


template <char point_type> bool operator>(Point<point_type>& point_1, Point_3D& point_2) {
    return (!(point_1 < point_2) && (point_1 != point_2));
}


template <char point_type> bool operator<=(Point<point_type>& point_1, Point<point_type>& point_2) {
    return ((point_1 < point_2) || (point_1 == point_2));
}


template <char point_type> bool operator<=(Point<point_type>& point_1, Point_3D& point_2) {
    return ((point_1 < point_2) || (point_1 == point_2));
}


template <char point_type> bool operator>=(Point<point_type>& point_1, Point<point_type>& point_2) {
    return ((point_1 > point_2) || (point_1 == point_2));
}


template <char point_type> bool operator>=(Point<point_type>& point_1, Point_3D& point_2) {
    return ((point_1 > point_2) || (point_1 == point_2));
}


#endif
