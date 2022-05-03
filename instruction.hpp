#include <bits/stdc++.h>
#include "instruction_list.hpp"
#include "opcode.hpp"
#include "operand.hpp"

using namespace std;

class Instruction
{
protected:
    Opcode opcode;
    vector<Operand<string>> operands;
    //vector<Operand<int>> imm_operands;
    Operand<int> last_operand;

public:

    


    Instruction(Opcode opcode, vector<Operand<string>> operands = {}, Operand<int> last_operand = Operand<int>())
    {
        this->opcode = opcode;
        this->operands = operands;
        this->last_operand = last_operand;
    }


    Opcode get_opcode()
    {
        return opcode;
    }

    vector<Operand<string>> get_operands()
    {
        return operands;
    }

    Operand<int> get_last_operand()
    {
        return last_operand;
    }

    void show_instruction()
    {
        cout <<"opcode: "<< opcode.get_name() << endl;
        for (int i = 0; i < operands.size(); i++)
        {
            cout << operands[i].get_value() << " " << operands[i].get_type() << endl;
        }
        if(last_operand.get_type() == "immediate")
        {
            cout << last_operand.get_value() <<" "<< last_operand.get_type() <<endl;
        }
    }
};

class InstructionBuilder
{
    protected:
        OpcodeFactory opcode_factory;
        OperandFactory operand_factory;
    public:
        InstructionBuilder()
        {
            opcode_factory = OpcodeFactory();
            operand_factory = OperandFactory();
        }

        Instruction buildInstruction(string line)
        {
            stringstream ss(line);
            string opcode_name;
            ss >> opcode_name;
            Opcode opcode = opcode_factory.getOpcode(opcode_name);
            vector<Operand<string>> operands;
            string operand;
            int count = 0;

            if (opcode.get_number_of_operands() == 0)
            {
                return Instruction(opcode);
            }

            while (ss >> operand && count < opcode.get_number_of_operands() - 1)
            {
                
                operands.push_back(operand_factory.getOperand(operand));

                count++;
            }

            ss >> operand;
            //regex r("[+-]?[0-9]+");
            if (regex_match(operand, digit))
            {
                Operand<int> last_operand = operand_factory.getOperand(stoi(operand));
                return Instruction(opcode, operands, last_operand);
            }
            else if(regex_match(operand, register_regex))
            {
                Operand<string> operand_obj = operand_factory.getOperand(operand);
                operands.push_back(operand_obj);
                return Instruction(opcode, operands);
            }
            else
            {
                operands.push_back(operand_factory.getOperand(operand,"variable"));
                return Instruction(opcode, operands);
            }
            
        }
    
};
