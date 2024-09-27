#ifndef _2DARRAY_
#define _2DARRAY_

#include <iostream>

class DynamicMatrix
{
private:
    int row,col;
    int **array;
public:
    DynamicMatrix();

    DynamicMatrix(int row,int col);

    inline int GetRow() const;

    inline int GetCol() const;

    inline int** GetArray() const;

    DynamicMatrix(const DynamicMatrix& other);

    DynamicMatrix& operator=(const DynamicMatrix& other);

    void AssignAllValues(int *array,int row,int col);

    void AssignSpecificValue(int value,int row,int col);

    void PrintSpecificElement(int row,int col);

    ~DynamicMatrix();
};

std::ostream& operator<<(std::ostream& out,const DynamicMatrix& d);

#endif