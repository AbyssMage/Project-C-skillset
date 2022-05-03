#include<bits/stdc++.h>
using namespace std;

const unordered_map<string,int>instruction_list = 
{
    {"add",3},
    {"sub",3},
    {"mul",3},
    {"div",3},
    {"mod",3},
    {"addi",3},
    {"subi",3},
    {"la",2},
    {"li",2},
    {"ecall",0},
    {"loop:",0}
};
 //key: opcode, value: # of operands

regex digit("[+-]?[0-9]+");
regex register_regex("[a-z]{1}[0-9]{1,2}");