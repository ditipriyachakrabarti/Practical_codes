#include <iostream>
#include <cmath>
using namespace std;
double AREA(double r) {
    return 3.14159 * r * r;
}
double AREA(double l, double w) {
    return l * w;
}
double AREA(double a, double b, double c) {
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}
int main() {
    double r, l, w, a, b, c;
    cout << "Enter radius of the circle: ";
    cin >> r;
    cout << "Enter length and breadth of the rectangle: ";
    cin >> l >> w;
    cout << "Enter three lengths of the triangle's sides: ";
    cin >> a >> b >> c;
    cout << "Area of circle: " << AREA(r) << endl;
    cout << "Area of rectangle: " << AREA(l, w) << endl;
    cout << "Area of triangle: " << AREA(a, b, c) << endl;
    return 0;
}