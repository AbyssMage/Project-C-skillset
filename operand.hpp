#include<bits/stdc++.h>
using namespace std;

template <typename T> class Operand
{
    protected:
        string type; //register or immediate
        T value;
    
    public:
        Operand(string type = "", T value = 0)
        {
            this->type = type;
            this->value = value;
        }
    
        string get_type()
        {
            return type;
        }
    
        T get_value()
        {
            return value;
        }

};

class OperandFactory
{
    public:
        OperandFactory() {}
        Operand<string> getOperand(string operand, string type = "register")
        {
            return Operand<string>(type,operand);
        }
        Operand<int> getOperand(int operand)
        {
            return Operand<int>("immediate",operand);
        }
};