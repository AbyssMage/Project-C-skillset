#include <bits/stdc++.h>

#include "instruction.hpp"


using namespace std;

vector<string> validity_check(vector<string> lines)
{
    vector<string> valid_lines;


    for (int i = 0; i < lines.size(); i++)
    {

        int hash_found = lines[i].find('#');
        // cout << hash_found << endl;
        if (hash_found != 0) // first comment
        {
            int length = hash_found == -1 ? lines[i].size() : hash_found;
            string line = lines[i].substr(0, length); // intermediate comment
            // cout << line << endl;
            int first_blank = line.find(' ');
            string opcode = line.substr(0, first_blank);
            //cout << "op " << opcode << endl;
            auto x = instruction_list.find(opcode);

            if (x != instruction_list.end()) // G1
            {
                int number_of_operand = x->second;

                if (first_blank != -1)
                {
                    line = line.substr(first_blank + 1, line.size());
                    line.erase(remove(line.begin(), line.end(), ' '), line.end());
                    //cout << "arg line:" << line << endl;
                    int comma_count = count(line.begin(), line.end(), ',');
                    if (comma_count == number_of_operand - 1)
                    {
                        int c = 0;
                        stringstream ss(line);
                        string s;
                        string operands;
                        while (getline(ss, s, ','))
                        {
                            // cout <<"arg: "<< s << endl;
                            if (s != "")
                            {
                                operands += s + " ";
                                c++;
                            }
                        }
                        if (c == number_of_operand)
                        {
                            //cout << "valid: " << opcode + " " + operands << endl;
                            valid_lines.push_back(opcode + " " + operands);
                        }
                        else
                            cout << "# of operands mismatched " <<line<< endl;
                    }
                    else
                        cout << "# of comma mismatched " <<line<< endl;
                }
                else if (number_of_operand == 0)
                {
                    //cout << "valid: " << lines[i] << endl;
                    valid_lines.push_back(lines[i]);
                }
                else
                    cout << "# of operands mismatched " <<line<< endl;
            }
            else
                cout << "not in instruction list " <<line<< endl;
        }
    }

    return valid_lines;
}

vector<string> validity_check_regex(vector<string> lines)
{
    vector<string> valid_string;

    for (int i = 0; i < lines.size(); i++)
    {
        int hash_found = lines[i].find('#');
        if (hash_found != 0)
        {
            int length = hash_found == -1 ? lines[i].size() : hash_found;
            string line = lines[i].substr(0, length); // intermediate comment
            // cout << line << endl;
            int first_blank = line.find(' ');
            string opcode = line.substr(0, first_blank);
            //cout << "op " << opcode << endl;
            auto x = instruction_list.find(opcode);

            if (x != instruction_list.end())
            {
                int number_of_operand = x->second;
                if (first_blank != -1)
                {
                    line = line.substr(first_blank + 1, line.size());
                    line.erase(remove(line.begin(), line.end(), ' '), line.end());
                    if (number_of_operand != 0)
                    {
                        int repeat = number_of_operand - 1;
                        string reg = "(([a-z][0-9]{1,2}),){" + to_string(repeat) + "}(([a-z][0-9]{1,2})|([+-]?[0-9]+)|([a-z]+))";
                        //regex str_expr2("(([a-z][0-9]),){1}(([a-z][0-9])|([+-]?[0-9]+)|([a-z]+))");
                        regex str_expr(reg);
                        if (regex_match(line, str_expr))
                        {
                            //cout << "match" << endl;
                            stringstream ss(line);
                            string s;
                            string operands;
                            while (getline(ss, s, ','))
                            {
                                // cout <<"arg: "<< s << endl;
                                operands += s + " ";
                            }

                            valid_string.push_back(opcode+" "+operands);
                        }
                        else
                        {
                            cout << "not match " <<opcode<<" "<<line<< endl;
                        }
                    }
                }
                else if(number_of_operand == 0)
                {
                    valid_string.push_back(line);
                }
                else
                {
                    cout << "not match" << endl;
                }
                
                
            }
            else
            {
                cout << "not in instruction list "<<line<< endl;
            }
        }
    }

    return valid_string;
}

int main()
{
    int var = 1;

    //string reg = "((([a-z][0-9]) | ([0-9]+),){" + to_string(var) + "}([a-z][0-9]) | ([0-9]+))";

    /*string reg = "((([a-z][0-9]),){1}(([a-z][0-9])|([0-9])))"; //number and string operand
    regex str_expr(reg);
    regex str_expr2("(([a-z][0-9]),){1}(([a-z][0-9])|([+-]?[0-9]+)|([a-z]+))");
    string str = "a0,hello";
    if (regex_match(str, str_expr2))
    {
        cout << "match" << endl;
    }
    else
    {
        cout << "not match" << endl;
    }*/

    ifstream input;
    input.open("input.txt");
    vector<string> lines;
    while (!input.eof())
    {
        string line;
        getline(input, line); // read line by line
        lines.push_back(line);
    }

    vector<string> valid_strings =  validity_check_regex(lines);

    InstructionBuilder instruction_builder;

    cout << "Valid Strings" << endl;

    for(string line:valid_strings)
    {
        cout<<line<<endl;
        Instruction instruction = instruction_builder.buildInstruction(line);
        instruction.show_instruction();
    }

    
}