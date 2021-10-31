#include <iostream>
#include <fstream>
#include <iomanip>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
#include <cstdlib>
#include <cmath>

#include "iShapes.h"

//Function Prototyes
vector<string> parseString(string);

int main()
{
    cout << "Programmer: Kristina Fout\n";
    cout << "Programmer ID: 1866884\n";
    cout << "file: " << __FILE__ << "\n\n";

    ifstream fin;
    ofstream fout;
    string line;

    fin.open("Shapes.input.txt");
    fout.open("Shapes.output.txt");
    
    vector<void*> myBag; //Create an empty bag
    vector<char> myBagType; //It's companion Array

    while (!fin.eof())
    {
        getline(fin, line);
        int shape;
        vector<string> tokens = parseString(line);
        if (tokens.size() == 0)
            continue;
        if (tokens.at(0) == "SQUARE")
        {
            shape = 1;
            Square* s = new Square(tokens);
            myBag.push_back(s);
            myBagType.push_back('S');
        }

        else if (tokens.at(0) == "RECTANGLE")
        {
            Rectangle* r = new Rectangle(tokens);
            shape = 2;
            myBag.push_back(r);
            myBagType.push_back('R');
        }

        else if (tokens.at(0) == "TRIANGLE")
        {
            Triangle* t = new Triangle(tokens);
            shape = 3;
            myBag.push_back(t);
            myBagType.push_back('T');
        }
        else if (tokens.at(0) == "CUBE")
        {
            tokens.resize(4, "0");
            Cube* c = new Cube(tokens);
            shape = 4;
            myBag.push_back(c);
            myBagType.push_back('C');
        }

        else if (tokens.at(0) == "CIRCLE")
        {
            tokens.resize(3, "0");
            Circle* e = new Circle(tokens);
            shape = 5;
            myBag.push_back(e);
            myBagType.push_back('E');
        }

        else if (tokens.at(0) == "CYLINDER")
        {
            Cylinder* y = new Cylinder(tokens);
            shape = 6;
            myBag.push_back(y);
            myBagType.push_back('Y');
        }

        else if (tokens.at(0) == "BOX")
        {
            Box* b = new Box(tokens);
            shape = 7;
            myBag.push_back(b);
            myBagType.push_back('B');
        }

        else if (tokens.at(0) == "PRISM")
        {
            tokens.resize(4, "0");
            shape = 8;
            Prism* pr = new Prism(tokens);
            myBag.push_back(pr);
            myBagType.push_back('P');
        }

        else if (tokens.at(0) == "EOF")
        {
            shape = 9;
            continue;
        }

        else
        {
            cout << tokens.at(0) << " invalid object" << endl;
        }

        for (int i = 0; i <= tokens.size(); i++)
        {
            for (int j = i + 1; j < tokens.size(); j++)
            if (tokens[j] < tokens[i])
                swap(tokens[i], tokens[j]);
        }
    }
        fin.close();

    for (unsigned int i = 0; i < myBag.size(); i++)
    {
        if (myBagType[i] == 'S')
        {
            Square* pSquare = reinterpret_cast<Square*>(myBag[i]);
            Square& rSquare = *pSquare;

            pSquare->output(cout);
    }

        else if (myBagType[i] == 'R')
        {
            Rectangle* pRectangle = reinterpret_cast<Rectangle*>(myBag[i]);
            Rectangle& rRectangle = *pRectangle;
            pRectangle->output(cout);
        }

        else if (myBagType[i] == 'T')
        {
            Triangle* pTriangle = reinterpret_cast<Triangle*>(myBag[i]);
            Triangle& rTriangle = *pTriangle;
            pTriangle->output(cout);
        }

        else if (myBagType[i] == 'C')
        {
            Cube* pCube = reinterpret_cast<Cube*>(myBag[i]);
            Cube& rCube = *pCube;
            pCube->output(cout);
        }

        else if (myBagType[i] == 'E')
        {
            Circle* pCircle = reinterpret_cast<Circle*>(myBag[i]);
            Circle& rCircle = *pCircle;
            pCircle->output(cout);
        }

        else if (myBagType[i] == 'Y')
        {
            Cylinder* pCylinder = reinterpret_cast<Cylinder*>(myBag[i]);
            Cylinder& rCylinder = *pCylinder;
            pCylinder->output(cout);
        }

        else if (myBagType[i] == 'B')
        {
            Box* pBox = reinterpret_cast<Box*>(myBag[i]);
            Box& rBox = *pBox;
            pBox->output(cout);
        }

        else if (myBagType[i] == 'P')
        {
            Prism* pPrism = reinterpret_cast<Prism*>(myBag[i]);
            Prism& rPrism = *pPrism;
            pPrism->output(cout);
        }
    }

    for (unsigned int i = 0; i < myBag.size(); i++)
    {
        if (myBagType[i] == 'S')
        {
            Square* pSquare = reinterpret_cast<Square*>(myBag[i]);
            Square& rSquare = *pSquare;
            pSquare->output(fout);
        }

        else if (myBagType[i] == 'R')
        {
            Rectangle* pRectangle = reinterpret_cast<Rectangle*>(myBag[i]);
            Rectangle& rRectangle = *pRectangle;
            pRectangle->output(fout);
        }

        else if (myBagType[i] == 'T')
        {
            Triangle* pTriangle = reinterpret_cast<Triangle*>(myBag[i]);
            Triangle& rTriangle = *pTriangle;
            pTriangle->output(fout);
        }

        else if (myBagType[i] == 'C')
        {
            Cube* pCube = reinterpret_cast<Cube*>(myBag[i]);
            Cube& rCube = *pCube;
            pCube->output(fout);
        }

        else if (myBagType[i] == 'E')
        {
            Circle* pCircle = reinterpret_cast<Circle*>(myBag[i]);
            Circle& rCircle = *pCircle;
            pCircle->output(fout);
        }

        else if (myBagType[i] == 'Y')
        {
            Cylinder* pCylinder = reinterpret_cast<Cylinder*>(myBag[i]);
            Cylinder& rCylinder = *pCylinder;
            pCylinder->output(fout);
        }

        else if (myBagType[i] == 'B')
        {
            Box* pBox = reinterpret_cast<Box*>(myBag[i]);
            Box& rBox = *pBox;
            pBox->output(fout);
        }

        else if (myBagType[i] == 'P')
        {
            Prism* pPrism = reinterpret_cast<Prism*>(myBag[i]);
            Prism& rPrism = *pPrism;
            pPrism->output(fout);
        }
    }

    fout.close();

    for (unsigned int i = 0; i < myBag.size(); i++)
    {
        if (myBagType[i] == 'S')
        {
            Square* s = reinterpret_cast<Square*>(myBag[i]);
            delete s; // deallocate
        }

        else if (myBagType[i] == 'R')
        {
            Rectangle* r = reinterpret_cast<Rectangle*>(myBag[i]);
            delete r;
        }

        else if (myBagType[i] == 'T')
        {
            Triangle* t = reinterpret_cast<Triangle*>(myBag[i]);
            delete t;
        }

        else if (myBagType[i] == 'C')
        {
            Cube* c = reinterpret_cast<Cube*>(myBag[i]);
            delete c;
        }

        else if (myBagType[i] == 'I')
        {
            Circle* e = reinterpret_cast<Circle*>(myBag[i]);
            delete e;
        }

        else if (myBagType[i] == 'Y')
        {
            Cylinder* y = reinterpret_cast<Cylinder*>(myBag[i]);
            delete y;
        }

        else if (myBagType[i] == 'B')
        {
            Box* b = reinterpret_cast<Box*>(myBag[i]);
            delete b;
        }

        else if (myBagType[i] == 'P')
        {
            Prism* p = reinterpret_cast<Prism*>(myBag[i]);
            delete p;
        }

    }

    //system("PAUSE");

    return 0;
}

vector<string> parseString(string str)
{
    stringstream s(str);
    istream_iterator<string> begin(s), end;

    return vector<string>(begin, end);

}
