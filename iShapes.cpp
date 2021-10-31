#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#include <cmath>
#include "iShapes.h"

const double PI = 3.14159;

ostream& roundingTwo(ostream& out)
{
    out.setf(ios::fixed);
    out.precision(2); // 2 decima;

    return out;
}

ostream& roundingOff(ostream& out)
{
    out.unsetf(ios::fixed);
    out.precision(6);

    return out;
}

void checkShape(vector<string>& lineWords, vector<const Shape*>& shapesBag, vector<string>& shapesTypeBag)
{
    string validShapes[] = {"SQUARE", "RECTANGLE", "CIRCLE", "TRIANGLE", "CUBE", "BOX", "CYLINDER", "PRISM"};
    bool valShape = false;
    for(auto& i : validShapes)
    {
        if(lineWords.at(0) == i)
        {
          valShape = true;
        }
    }
    cout.flush();
    if(valShape == true)
    {
        calcShape(lineWords, shapesBag, shapesTypeBag);
    }
    else
    {
        if(lineWords.at(0)!="EOF")
        {
            cout << lineWords.at(0) << " invalid shape" << endl;
        }
    }
}

void calcShape(vector<string>& lineWords, vector<const Shape*>& shapesBag, vector<string>& shapesTypeBag)
{
    string shapeType = lineWords.at(0);
    
    if (shapeType == "SQUARE")
    {
        const Square* const s = new Square(lineWords);
        shapesBag.push_back(s);
        shapesTypeBag.push_back("SQUARE");
    }
    else if (shapeType=="RECTANGLE")
    {
        const Rectangle* const r = new Rectangle(lineWords);
        shapesBag.push_back(r);
        shapesTypeBag.push_back("RECTANGLE");
    }
    else if (shapeType == "CIRCLE")
    {
        const Circle* const c = new Circle(lineWords);
        shapesBag.push_back(c);
        shapesTypeBag.push_back("CIRCLE");
    }
    else if (shapeType == "TRIANGLE")
    {
        const Triangle* const t = new Triangle(lineWords);
        shapesBag.push_back(t);
        shapesTypeBag.push_back("TRIANGLE");
    }
    else if (shapeType == "CUBE")
    {
        const Cube* const c = new Cube(lineWords);
        shapesBag.push_back(c);
        shapesTypeBag.push_back("CUBE");
    }
    else if (shapeType == "BOX")
    {
        const Box* const b = new Box(lineWords);
        shapesBag.push_back(b);
        shapesTypeBag.push_back("BOX");
    }
    else if (shapeType == "CYLINDER")
    {
        const Cylinder* const c = new Cylinder(lineWords);
        shapesBag.push_back(c);
        shapesTypeBag.push_back("CYLINDER");
    }
    else if (shapeType == "PRISM")
    {
        const Prism* const p = new Prism(lineWords);
        shapesBag.push_back(p);
        shapesTypeBag.push_back("PRISM");
    }
    else
    {

      }
}

Square& Square::operator = (const Square& copyThis)
{
    Square& host = *this;
    if (this!= &copyThis)
    {
        const_cast<double&>(host.side) = copyThis.side;
    }

    return host;
}

Rectangle& Rectangle::operator = (const Rectangle& copyThis)
{
    Rectangle& host = *this;
    
    if (this != &copyThis)
    {
        const_cast<double&>(host.length) = copyThis.length;

        const_cast<double&>(host.width) = copyThis.width;
    }
    return host;
}

Triangle& Triangle::operator = (const Triangle& copyThis)
{
    Triangle& host = *this;
    if (this != &copyThis)
    {
        const_cast<double&>(host.side) = copyThis.side;
    }
    
    return host;
}

Circle& Circle::operator = (const Circle& copyThis)
{
    Circle& host = *this;
    if (this != &copyThis)
    {
        const_cast<double&>(host.radius) = copyThis.radius;
    }
    
    return host;
}

Cube& Cube::operator = (const Cube& copyThis)
{
    Cube& host = *this;

    if (this != &copyThis)
    {
        const_cast<double&>(host.side) = copyThis.side;
    }

    return host;
}

Prism& Prism::operator = (const Prism& copyThis)
{
    Prism& host = *this;

    if (this != &copyThis)
    {
        const_cast<double&>(host.side) = copyThis.side;
        const_cast<double&>(host.height) = copyThis.height;
    }

    return host;

}

Cylinder& Cylinder::operator = (const Cylinder& copyThis)
{
    Cylinder& host = *this;
    
    if (this != &copyThis)
    {
        const_cast<double&>(host.radius) = copyThis.radius;
        const_cast<double&>(host.height) = copyThis.height;
    }
    
    return host;
}

Box& Box::operator = (const Box& copyThis)
{
    Box& host = *this;

    if (this != &copyThis)
    {
        const_cast<double&>(host.length) = copyThis.length;
        const_cast<double&>(host.width) = copyThis.width;
        const_cast<double&>(host.height) = copyThis.height;
    }
    return host;
}

void Square::output(ostream& os) const
{
    const double area = side * side;
    const double perim = side * 4.0;
      os << "SQUARE side= " << side;
      os << roundingTwo << " area= " << area << " perimeter= " << perim << endl;
      os << roundingOff;
}

void Rectangle::output(ostream& os) const
{
    const double area = length * width;
    const double perim = (2.0 * length) + (2.0 * width);
      os << "RECTANGLE length= " << length << " width= " << width;
      os << roundingTwo << " area= " << area << " perimeter= " << perim << endl;
      os << roundingOff;
}

void Triangle::output(ostream& os) const
{
    const double area = (pow(3.0, 0.5) / 4.0) * pow(side, 2.0);
    const double perim = side * 3.0;
      os << "TRIANGLE side= " << side;
      os << roundingTwo << " area= " << area << " perimeter= " << perim << endl;
      os << roundingOff;
}

void Cube::output(ostream& os) const
{
    const double surfaceArea = 6.0 * pow(side, 2.0);
    const double volume = pow(side, 3.0);
      os << "CUBE side= " << side;
      os << roundingTwo << " surface area= " << surfaceArea << " volume= " << volume << endl;
      os << roundingOff;
}

void Circle::output(ostream& os) const
{
    const double area = PI * radius * radius;
    const double perim = 2 * PI * radius;
      os << "CIRCLE radius= " << radius;
      os << roundingTwo << " area= " << area << " perimeter= " << perim << endl;
      os << roundingOff;
}

void Cylinder::output(ostream& os) const
{
    const double surfaceArea = (2.0 * (PI * pow(radius, 2.0))) + (2.0 * PI * radius * height);
    const double volume = PI * pow(radius, 2.0) * height;
      os << "CYLINDER radius= " << radius << " height= " << height;
      os << roundingTwo << " surface area= " << surfaceArea << " volume= " << volume << endl;
      os << roundingOff;
}

void Box::output(ostream& os) const
{
    const double surfaceArea = 2.0 * ((length * width) + (length * height) + (width * height));
    const double volume = length * width * height;
      os << "BOX length= " << length << " width= " << width << " height= " << height;
      os << roundingTwo << " surface area= " << surfaceArea << " volume= " << volume << endl;
      os << roundingOff;
}

void Prism::output(ostream& os) const
{
    const double surfaceArea = (2.0 * ((pow(3.0, 0.5) / 4.0) * pow(side, 2.0))) + (3.0 * (side * height));
    const double volume = ((pow(3.0, 0.5) / 4.0) * pow(side, 2.0)) * height;
      os << "PRISM side= " << side << " height= " << height;
      os << roundingTwo << " surface area= " << surfaceArea << " volume= " << volume << endl;
      os << roundingOff;
}

Square::Square(const vector<string>& lineWords): side(lineWords.size() >= 2 ? atof(lineWords.at(1).c_str()) : 0)
{
    
}

Rectangle::Rectangle(const vector<string>& lineWords) : length(lineWords.size() >= 2 ? atof(lineWords.at(1).c_str()) : 0), width(lineWords.size() >= 3 ? atof(lineWords.at(2).c_str()) : 0)
{
    
}

Circle::Circle(const vector<string>& lineWords) : radius(lineWords.size() >= 2 ? atof(lineWords.at(1).c_str()) : 0)
{
}

Triangle::Triangle(const vector<string>& lineWords): side(lineWords.size() >= 2 ? atof(lineWords.at(1).c_str()) : 0)
{
    
}
