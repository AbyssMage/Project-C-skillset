#include <bits/stdc++.h>

using namespace std;


class Opcode
{
protected:
    string name;
    int number_of_operands;

public:
    Opcode(string name = "", int number_of_operands = -1)
    {
        this->name = name;
        this->number_of_operands = number_of_operands;
    }

    string get_name()
    {
        return name;
    }

    int get_number_of_operands()
    {
        return number_of_operands;
    }
};

class Add : public Opcode
{
public:
    Add(string name = "add", int number_of_operands = 3) : Opcode(name, number_of_operands) {}
};

class Addi : public Opcode
{
public:
    Addi(string name = "addi", int number_of_operands = 3) : Opcode(name, number_of_operands) {}
};

class Sub : public Opcode
{
public:
    Sub(string name = "sub", int number_of_operands = 3) : Opcode(name, number_of_operands) {}
};

class Subi : public Opcode
{
public:
    Subi(string name = "subi", int number_of_operands = 3) : Opcode(name, number_of_operands) {}
};

class La : public Opcode
{
public:
    La(string name = "la", int number_of_operands = 2) : Opcode(name, number_of_operands) {}
};

class Li : public Opcode
{
public:
    Li(string name = "li", int number_of_operands = 2) : Opcode(name, number_of_operands) {}
};

class Ecall : public Opcode
{
public:
    Ecall(string name = "ecall", int number_of_operands = 0) : Opcode(name, number_of_operands) {}
};

class OpcodeFactory
{
public:
    OpcodeFactory() {}
    Opcode getOpcode(string opcode)
    {

        if (opcode == "add")
        {
            return Add();
        }
        else if (opcode == "addi")
        {
            return Addi();
        }
        else if (opcode == "sub")
        {
            return Sub();
        }
        else if (opcode == "subi")
        {
            return Subi();
        }
        else if (opcode == "la")
        {
            return La();
        }
        else if (opcode == "li")
        {
            return Li();
        }
        else if (opcode == "ecall")
        {
            return Ecall();
        }
        else
        {
            return Opcode();
        }
    }
};