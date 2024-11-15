#include<bits/stdc++.h>
#define PI 3.141592653589793
using namespace std;

class Shape{
private:

public: 
    virtual void whoAmI(){}
};

class TwoDimensionShape : public Shape {
private:

public:
     void whoAmI() { cout << "I AM A TWO DIMENSIONAL SHAPE" << endl;}
};

class ThreeDimensionShape : public Shape {
private:

public:
      void whoAmI() { cout << "I AM A THREE DIMENSIONAL SHAPE" << endl;}
};

class Square : public TwoDimensionShape {
private: 
    int side;
public:
    Square(int s): side(s) {}
    int area() {return side * side;}
    int perimeter() {return 4 * side; }
    void whoAmI() { cout << "I AM SQUARE. I AM A TWO DIMENSIONAL SHAPE" << endl;}
};

class Rectangle : public TwoDimensionShape {
private:
    int length;
    int breadth;
public:
    Rectangle (int l , int b): length(l), breadth(b) {}
    int area() {return length * breadth; }
    int perimeter() { return 2 * (length + breadth); }
    void whoAmI() { cout << "I AM RECTANGLE. I AM A TWO DIMENSIONAL SHAPE" << endl;}

};

class Cube : public ThreeDimensionShape {
private:
    int side;
public:
    Cube(int s) : side(s) {}
    int surface_Area () { return 6 * (side * side);}
    int volume () { return side * side * side; }
    virtual void whoAmI() { cout << "I AM CUBE. I AM A THREE DIMENSIONAL SHAPE" << endl;}
};


class Sphere : public ThreeDimensionShape {
private:
    double radius;
public:
    Sphere(double s) : radius(s) {}
    double surface_Area () { return 4 * PI * (radius * radius);}
    double volume () { return ((4.0/3.0) * PI * (radius * radius * radius)); }
    virtual void whoAmI() { cout << "I AM SPHERE. I AM A THREE DIMENSIONAL SHAPE" << endl;}
};

int main(){
    Square s1(5);
    cout << "Square Area: " << s1.area() << endl;
    cout << "Square Perimeter: " << s1.perimeter() << endl;
    s1.whoAmI();

    Rectangle rectangle(4, 6);
    cout << "Rectangle Area: " << rectangle.area() << endl;
    cout << "Rectangle Perimeter: " << rectangle.perimeter() << endl;
    rectangle.whoAmI();

    Cube cube(3);
    cout << "Cube Surface Area: " << cube.surface_Area() << endl;
    cout << "Cube Volume: " << cube.volume() << endl;
    cube.whoAmI();

    Sphere sphere(4.5);
    cout << "Sphere Surface Area: " << sphere.surface_Area() << endl;
    cout << "Sphere Volume: " << sphere.volume() << endl;
    sphere.whoAmI();

    return 0;
}