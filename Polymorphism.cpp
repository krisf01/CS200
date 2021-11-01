class Prism : public Triangle
{
   public:
   Prism(const vector<string>& tokens): Triangle(tokens), height (tokens.size() > 2 ? atof(tokens[2].c_str()) : 0) {};
   virtual void outputPrismCalculation(ostream&) const;
   virtual ~Prism() {};
};
