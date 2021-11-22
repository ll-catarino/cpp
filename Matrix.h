#include <string>

class Matrix {
private:
    int** matrix;
    int rows;
    int cols;

public:
    Matrix(int rows, int cols, int** matrix);
    
    int GetRows();

    int GetCols();

    int GetElement(int row, int col);

    void SetElement(int row, int col, int element);

    int** ToArray();

    bool IsSquare();

    bool IsIdentity();

    bool IsScalar();

    bool IsNull();

    bool IsRow();

    bool IsColumn();

    bool IsSymmetric();

    bool IsSkewSymmetric();

    void Scale(float scalar);

    static Matrix* Sum(Matrix* a, Matrix* b);

    static Matrix* Subtract(Matrix* a, Matrix* b);

    int GetLongestElement();

    std::string ToString();

    ~Matrix();
};