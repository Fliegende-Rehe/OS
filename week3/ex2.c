#include <math.h>

// define a structure Point with 2 real number fields x and y
struct Point {
    double x;
    double y;
};

double distance(struct Point A, struct Point B);

double area(struct Point A, struct Point B, struct Point C);

// write a main function to define A(2.5, 6), B(1, 2.2) and C(10, 6)
// as the vertices of the triangle ABC. Find the distance between A
// and B, then calculate the area of ABC
int main() {
    struct Point A, B, C;
    A.x = 2.5;      A.y = 6;
    B.x = 1;        B.y = 2.2;
    C.x = 10;       C.y = 6;
    double l = distance(A, B);
    double a = area(A, B, C);
    return 0;
}

// provide an implementation of a function distance
// that computes the euclidean distance between two points.
double distance(struct Point A, struct Point B) {
    return sqrt(pow(B.x - A.x, 2)
                + pow(B.y - A.y, 2));
}

// write a function area that will compute the area of the triangle
// whose vertices are A(x1, y1), B(x2, y2), and C(x3, y3)
double area(struct Point A, struct Point B, struct Point C) {
    return ((A.x - C.x) * (B.y - C.y) - (B.x - C.x) * (A.y - C.y)) * 0.5;
}