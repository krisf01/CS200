// Programmer: Kristina Fout
// Programmer ID: 1866884

#include "pch.h"

#include "iostream"
#include "fstream"
#include <string>
#include <vector>

using namespace std;

#include <cmath>
#include "pFinal.h"

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

void checkShape(vector<string>& lineWords, vector<const Shape*>& shapesBag)
{
    string validShapes[] = { "SQUARE", "RECTANGLE", "CIRCLE", "TRIANGLE", "ROOT", "POWER" };
    bool valShape = false;
    for (auto& i : validShapes)
    {
        if (lineWords.at(0) == i)
        {
            valShape = true;
        }
    }
    cout.flush();
    if (valShape == true)
    {
        calcShape(lineWords, shapesBag);
    }
    else
    {
        if (lineWords.at(0) != "EOF")
        {
            cout << lineWords.at(0) << " invalid shape" << endl;
        }
    }
}

void calcShape(vector<string>& lineWords, vector<const Shape*>& shapesBag)
{
    string shapeType = lineWords.at(0);

    if (shapeType == "SQUARE")
    {
        const comsc::Square* const s = new comsc::Square(lineWords);
        shapesBag.push_back(s);
    }
    else if (shapeType == "RECTANGLE")
    {
        const comsc::Rectangle* const r = new comsc::Rectangle(lineWords);
        shapesBag.push_back(r);
    }
    else if (shapeType == "CIRCLE")
    {
        const comsc::Circle* const c = new comsc::Circle(lineWords);
        shapesBag.push_back(c);
    }
    else if (shapeType == "TRIANGLE")
    {
        const comsc::Triangle* const t = new comsc::Triangle(lineWords);
        shapesBag.push_back(t);
    }
    else if (shapeType == "ROOT")
    {
        const comsc::Root* const t = new comsc::Root(lineWords);
        shapesBag.push_back(t);
    }
    else if (shapeType == "POWER")
    {
        const comsc::Power* const t = new comsc::Power(lineWords);
        shapesBag.push_back(t);
    }
    else
    {

    }
}

comsc::Square& comsc::Square::operator = (const comsc::Square& copyThis)
{
    comsc::Square& host = *this;

    if (this != &copyThis)
    {
        const_cast<double&>(host.length2) = copyThis.length2;

        const_cast<double&>(host.width2) = copyThis.width2;
    }
    return host;
}

comsc::Rectangle& comsc::Rectangle::operator = (const comsc::Rectangle& copyThis)
{
    comsc::Rectangle& host = *this;

    if (this != &copyThis)
    {
        const_cast<double&>(host.length1) = copyThis.length1;

        const_cast<double&>(host.width1) = copyThis.width1;
    }
    return host;
}

comsc::Triangle& comsc::Triangle::operator = (const comsc::Triangle& copyThis)
{
    comsc::Triangle& host = *this;

    if (this != &copyThis)
    {
        const_cast<double&>(host.length4) = copyThis.length4;

        const_cast<double&>(host.width4) = copyThis.width4;
    }
    return host;
}

comsc::Circle& comsc::Circle::operator = (const comsc::Circle& copyThis)
{
    comsc::Circle& host = *this;

    if (this != &copyThis)
    {
        const_cast<double&>(host.length3) = copyThis.length3;

        const_cast<double&>(host.width3) = copyThis.width3;
    }
    return host;
}

comsc::Root& comsc::Root::operator = (const comsc::Root& copyThis)
{
    comsc::Root& host = *this;

    if (this != &copyThis)
    {
        const_cast<double&>(host.length5) = copyThis.length5;

        const_cast<double&>(host.width5) = copyThis.width5;
    }
    return host;
}

comsc::Power& comsc::Power::operator = (const comsc::Power& copyThis)
{
    comsc::Power& host = *this;

    if (this != &copyThis)
    {
        const_cast<double&>(host.length6) = copyThis.length6;

        const_cast<double&>(host.width6) = copyThis.width6;
    }
    return host;
}

void comsc::Square::output(ostream& os) const
{
    const double area = length2 * width2;
    os << "CALCULATING... " << length2 << " * " << width2;
    os << roundingTwo << " ANSWER= " << area << endl;
    os << roundingOff;
}

void comsc::Rectangle::output(ostream& os) const
{
    const double area = length1 / width1;
    os << "CALCULATING... " << length1 << " / " << width1;
    os << roundingTwo << " ANSWER= " << area << endl;
    os << roundingOff;
}

void comsc::Triangle::output(ostream& os) const
{
    const double area = length4 + width4;
    os << "CALCULATING... " << length4 << " + " << width4;
    os << roundingTwo << " ANSWER= " << area << endl;
    os << roundingOff;
}

void comsc::Circle::output(ostream& os) const
{
    const double area = length3 - width3;
    os << "CALCULATING... " << length3 << " - " << width3;
    os << roundingTwo << " ANSWER= " << area << endl;
    os << roundingOff;
}

void comsc::Root::output(ostream& os) const
{
    const double area1 = sqrt(length5);
    const double area2 = sqrt(width5);
    os << "CALCULATING... ";
    os << roundingTwo << " ANSWER= " << area1 << " and " << area2 << endl;
    os << roundingOff;
}

void comsc::Power::output(ostream& os) const
{
    const double area = pow(length6, width6);
    os << "CALCULATING... " << length6 << " to the " << width6;
    os << roundingTwo << " ANSWER= " << area << endl;
    os << roundingOff;
}

comsc::Square::Square(const vector<string>& lineWords) : length2(lineWords.size() >= 2 ? atof(lineWords.at(1).c_str()) : 0), width2(lineWords.size() >= 3 ? atof(lineWords.at(2).c_str()) : 0)
{

}

comsc::Rectangle::Rectangle(const vector<string>& lineWords) : length1(lineWords.size() >= 2 ? atof(lineWords.at(1).c_str()) : 0), width1(lineWords.size() >= 3 ? atof(lineWords.at(2).c_str()) : 0)
{

}

comsc::Circle::Circle(const vector<string>& lineWords) : length3(lineWords.size() >= 2 ? atof(lineWords.at(1).c_str()) : 0), width3(lineWords.size() >= 3 ? atof(lineWords.at(2).c_str()) : 0)
{

}

comsc::Triangle::Triangle(const vector<string>& lineWords) : length4(lineWords.size() >= 2 ? atof(lineWords.at(1).c_str()) : 0), width4              (lineWords.size() >= 3 ? atof(lineWords.at(2).c_str()) : 0)
{

}

comsc::Root::Root(const vector<string>& lineWords) : length5(lineWords.size() >= 2 ? atof(lineWords.at(1).c_str()) : 0), width5(lineWords.size() >= 3 ? atof(lineWords.at(2).c_str()) : 0)
{

}

comsc::Power::Power(const vector<string>& lineWords) : length6(lineWords.size() >= 2 ? atof(lineWords.at(1).c_str()) : 0), width6(lineWords.size() >= 3 ? atof(lineWords.at(2).c_str()) : 0)
{

}

ostream& operator<<(ostream& out, const Shape& s)
{
    s.output(out);
    return out;
}
