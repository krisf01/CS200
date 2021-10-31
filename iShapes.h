#ifndef iShapes_h
#define iShapes_h

#include <string>
#include <vector>

using namespace std;

#include <cstdlib>


struct Shape{};

struct Square:public Shape
{
    Square (const vector<string>&);
    void output(ostream&) const;
    Square& operator= (const Square&);
    
    protected:
    const double side;
};

struct Cube:public Square
{
    Cube (const vector<string>&p) : Square(p) {}
    void output(ostream&) const;
    Cube& operator= (const Cube&);
};

struct Rectangle:public Shape
{
    Rectangle (const vector<string>&);
    void output(ostream&) const;
    Rectangle& operator= (const Rectangle&);
    
    protected:
    const double length;
    const double width;
};

struct Box:public Rectangle
{
    Box (const vector<string>& p) : Rectangle(p), height(p.size() >= 4 ? atof(p.at(3).c_str()) : 0){}
    void output(ostream&) const;
    Box& operator= (const Box&);
    
    protected:
    const double height;
};

struct Circle:public Shape
{
    Circle (const vector<string>&);
    void output(ostream&) const;
    Circle& operator= (const Circle&);
    
    protected:
    const double radius;
};

struct Cylinder:public Circle
{
    Cylinder (const vector<string>& p) : Circle(p), height(p.size() >= 3 ? atof(p.at(2).c_str()) : 0){}
    void output(ostream&) const;
    Cylinder& operator= (const Cylinder&);
    
    protected:
    const double height;
};

struct Triangle:public Shape
{
    Triangle (const vector<string>&);
    void output(ostream&) const;
    Triangle& operator= (const Triangle&);
    
    protected:
    const double side;
};

struct Prism:public Triangle
{
    Prism (const vector<string>& p) : Triangle(p), height(p.size() >= 3 ? atof(p.at(2).c_str()) : 0){}
    void output(ostream&) const;
    Prism& operator= (const Prism&);
    
    protected:
    const double height;
};

void checkShape (vector<string>&, vector<const Shape*>&, vector<string>&);
void calcShape (vector<string>&, vector<const Shape*>&, vector<string>&);

#endif /* iShapes_h */
