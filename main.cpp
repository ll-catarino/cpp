#include <iostream>
#include <string>
#include "app.h"

const std::string PROMPT = "> ";

//command defining constants
const std::string EXIT = "exit";
const std::string ADD = "add";
const std::string REMOVE = "remove";
const std::string RENAME= "rename";
const std::string PRINT = "print";
const std::string LIST = "list";
const std::string IS_SQUARE = "square?";
const std::string IS_IDENTITY = "identity?";
const std::string IS_SCALAR = "scalar?";
const std::string IS_NULL = "null?";
const std::string IS_ROW = "row?";
const std::string IS_COL = "column?";
const std::string IS_SYMMETRIC = "symmetric?";
const std::string IS_SKEW_SYMMETRIC = "skewsymmetric?";
const std::string SCALE = "scale";
const std::string SUM = "sum";
const std::string SUBTRACT = "subtract";


int main() {
    
    while (true)
    {
        std::string command;

        std::cout << PROMPT;
        std::cin >> command;

        if (command == EXIT) 
        {
            std::cout << "goodbye!\n";
            return 0;
        }

        if (command == ADD)
        {
            processAdd();
            continue;
        }

        if (command == REMOVE)
        {
            processRemove();
            continue;
        }
        if (command == RENAME)
        {
            processRename();
            continue;
        }

        if (command == PRINT)
        {
            processPrint();
            continue;
        }
        if (command == LIST)
        {
            processList();
            continue;
        } 
        if (command == IS_SQUARE)
        {
            processIsSquare();
            continue;
        } 
        if (command == IS_IDENTITY)
        {
            processIsIdentity();
            continue;
        }
        if (command == IS_SCALAR)
        {
            processIsScalar();
            continue;
        }
        if (command == IS_NULL)
        {
            processIsNull();
            continue;
        }
        if (command == IS_ROW)
        {
            processIsRow();
            continue;
        }
        if (command == IS_COL)
        {
            processIsCol();
            continue;
        }
        if (command == IS_SYMMETRIC)
        {
            processIsSymmetric();
            continue;
        }
        if (command == IS_SKEW_SYMMETRIC)
        {
            processIsSkewSymmetric();
            continue;
        } 
        if (command == SCALE)
        {
            processScale();
            continue;
        } 
        if (command == SUM)
        {
            processSum();
            continue;
        }
        if (command == SUBTRACT)
        {
            processSubtract();
            continue;
        }
        std::cout << "command not found\n";
    }
}



