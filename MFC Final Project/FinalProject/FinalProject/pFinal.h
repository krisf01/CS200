// Programmer: Kristina Fout
// Programmer ID: 1866884

#ifndef pFinal_H
#define pFinal_H

#include <string>
#include <vector>
using namespace std;

#include <cstdlib>

struct Shape {
	virtual void output(ostream&) const = 0;
	virtual ~Shape() {}
};

namespace comsc
{
	struct Rectangle : public Shape {
		Rectangle(const vector<string>&);
		void output(ostream&) const;
		Rectangle& operator=(const Rectangle&);

	protected:
		const double length1;
		const double width1;
	};

	struct Square : public Shape {
		Square(const vector<string>&);
		void output(ostream&) const;
		Square& operator=(const Square&);

	protected:
		const double length2;
		const double width2;
	};

	struct Circle : public Shape {
		Circle(const vector<string>&);
		void output(ostream&) const;
		Circle& operator=(const Circle&);

	protected:
		const double length3;
		const double width3;
	};

	struct Triangle : public Shape {
		Triangle(const vector<string>&);
		void output(ostream&) const;
		Triangle& operator=(const Triangle&);

	protected:
		const double length4;
		const double width4;
	};

	struct Root : public Shape {
		Root(const vector<string>&);
		void output(ostream&) const;
		Root& operator=(const Root&);

	protected:
		const double length5;
		const double width5;
	};

	struct Power : public Shape {
		Power(const vector<string>&);
		void output(ostream&) const;
		Power& operator=(const Power&);

	protected:
		const double length6;
		const double width6;
	};
}

void checkShape(vector<string>&, vector<const Shape*>&);
void calcShape(vector<string>&, vector<const Shape*>&);
ostream& operator<<(ostream&, const Shape&);

#endif /* pFinal_h */
