#include "app.h"

//matrix pool
std::map<std::string, Matrix*> matrixPool;

void processAdd()
{
    std::string name;
    int rows, cols;

    std::cin >> name >> rows >> cols;
    
    int **matrix = new int*[rows];

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];

        for (int j = 0; j < cols; j++)
        {
            std::cin >> matrix[i][j];
        }
    }

    if (matrixPool[name])
    {
        std::cout << "matrix " << name << " already exists\n";
    
    } else {

        Matrix* m = new Matrix(rows, cols, matrix);

        matrixPool[name] = m;

        std::cout << "matrix " << name << " added:\n";
        std::cout << matrixPool[name]->ToString();
    }
}

void processRemove()
{
    std::string name;
    std::cin >> name;

    if (!matrixPool[name])
    {
        std::cout << "matrix " << name << " does not exist\n";
    } else {
        delete matrixPool[name];
        matrixPool.erase(name);
        std::cout << "removed matrix " << name << "\n";
    }
}

void processRename()
{
    std::string name, newName;
    std::cin >> name >> newName;

    if (!matrixPool[name])
    {
        std::cout << "matrix " << name << " does not exist\n";
    } else {
        if (matrixPool[newName]) {
            std::cout << "matrix " << newName << " already exists\n";
        } else {
            matrixPool[newName] = matrixPool[name];
            matrixPool.erase(name);
            std::cout << "renamed matrix " << name << " to " << newName << "\n";
        }
    }   
}

void processPrint()
{
    std::string name;
    std::cin >> name;

    if (!matrixPool[name])
    {
        std::cout << "matrix " << name << " does not exist\n";
    } else {
        std::cout << matrixPool[name]->ToString();
    }
}

void processList()
{
    std::map<std::string, Matrix*>::iterator it;

    if (matrixPool.size() == 0) 
    {
        std::cout << "no matrices to list\n";
    } 
    else 
    {
        for (it=matrixPool.begin(); it != matrixPool.end(); it++)
        {
            std::cout << "matrix " << it->first << ":\n";
            std::cout << it->second->ToString();
        }
    }    
}

void processIsSquare()
{
    std::string name;
    std::cin >> name;

    if (!matrixPool[name])
    {
        std::cout << "matrix " << name << " does not exist\n";
    } else {
        std::string res = matrixPool[name]->IsSquare() ? "true" : "false";
        std::cout << res << "\n";
    } 
}

void processIsIdentity()
{
    std::string name;
    std::cin >> name;

    if (!matrixPool[name])
    {
        std::cout << "matrix " << name << " does not exist\n";
    } else {
        std::string res = matrixPool[name]->IsIdentity() ? "true" : "false";
        std::cout << res << "\n";
    }
}

void processIsScalar()
{
    std::string name;
    std::cin >> name;

    if (!matrixPool[name])
    {
        std::cout << "matrix " << name << " does not exist\n";
    } else {
        std::string res = matrixPool[name]->IsScalar() ? "true" : "false";
        std::cout << res << "\n";
    }
}

void processIsNull()
{
    std::string name;
    std::cin >> name;

    if (!matrixPool[name])
    {
        std::cout << "matrix " << name << " does not exist\n";
    } else {
        std::string res = matrixPool[name]->IsNull() ? "true" : "false";
        std::cout << res << "\n";
    }
}

void processIsRow()
{
    std::string name;
    std::cin >> name;

    if (!matrixPool[name])
    {
        std::cout << "matrix " << name << " does not exist\n";
    } else {
        std::string res = matrixPool[name]->IsRow() ? "true" : "false";
        std::cout << res << "\n";
    }
}

void processIsCol()
{
    std::string name;
    std::cin >> name;

    if (!matrixPool[name])
    {
        std::cout << "matrix " << name << " does not exist\n";
    } else {
        std::string res = matrixPool[name]->IsColumn() ? "true" : "false";
        std::cout << res << "\n";
    }
}

void processIsSymmetric()
{
    std::string name;
    std::cin >> name;

    if (!matrixPool[name])
    {
        std::cout << "matrix " << name << " does not exist\n";
    } else {
        std::string res = matrixPool[name]->IsSymmetric() ? "true" : "false";
        std::cout << res << "\n";
    }
}

void processIsSkewSymmetric()
{
    std::string name;
    std::cin >> name;

    if (!matrixPool[name])
    {
        std::cout << "matrix " << name << " does not exist\n";
    } else {
        std::string res = matrixPool[name]->IsSkewSymmetric() ? "true" : "false";
        std::cout << res << "\n";
    }
}

void processScale()
{
    std::string name;
    float scalar;
    std::cin >> name >> scalar;

    if (!matrixPool[name])
    {
        std::cout << "matrix " << name << " does not exist\n";
    } else {
        matrixPool[name]->Scale(scalar);
        std::cout << "matrix " << name << " scaled:\n";
        std::cout << matrixPool[name]->ToString();
    } 
}

void processSum()
{
    std::string matrixA, matrixB;
    std::cin >> matrixA >> matrixB;

    if (!matrixPool[matrixA])
    {
        std::cout << "matrix " << matrixA << " does not exist\n";
    } else {
        
        if (!matrixPool[matrixB])
        {
            std::cout << "matrix " << matrixB << " does not exist\n";
        } else {
            if (matrixPool[matrixA]->GetRows() != matrixPool[matrixB]->GetRows() ||
                matrixPool[matrixA]->GetCols() != matrixPool[matrixB]->GetCols()
            )
            {
                std::cout << "cannot sum matrices of diferent dimensions\n";
            } else {

                Matrix* m = Matrix::Sum(matrixPool[matrixA], matrixPool[matrixB]);
                matrixPool["(" + matrixA + "+" + matrixB + ")"] = m;
                std::cout << "matrix (" << matrixA + "+" + matrixB << "):\n";
                std::cout << m->ToString();
            }
        }
    } 
}

void processSubtract()
{
    std::string matrixA, matrixB;
    std::cin >> matrixA >> matrixB;

    if (!matrixPool[matrixA])
    {
        std::cout << "matrix " << matrixA << " does not exist\n";
    } else {
        
        if (!matrixPool[matrixB])
        {
            std::cout << "matrix " << matrixB << " does not exist\n";
        } else {
            if (matrixPool[matrixA]->GetRows() != matrixPool[matrixB]->GetRows() ||
                matrixPool[matrixA]->GetCols() != matrixPool[matrixB]->GetCols()
            )
            {
                std::cout << "cannot subtract matrices of diferent dimensions\n";
            } else {

                Matrix* m = Matrix::Subtract(matrixPool[matrixA], matrixPool[matrixB]);
                matrixPool["(" + matrixA + "-" + matrixB + ")"] = m;
                std::cout << "matrix (" << matrixA + "-" + matrixB << "):\n";
                std::cout << m->ToString();
            }
        }
    } 
}