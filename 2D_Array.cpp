#include "2D_Array.hpp"

DynamicMatrix::DynamicMatrix()
{
    array = nullptr;
}

DynamicMatrix::DynamicMatrix(int row,int col):row(row),col(col),array(new int*[row])
{
    for(int i=0;i<row;i++)
    {
        array[i] = new int[col];
    }
}

inline int DynamicMatrix::GetRow() const
{
    return row;
}

inline int DynamicMatrix::GetCol() const
{
    return col;
}

inline int** DynamicMatrix::GetArray() const
{
    return array;
}

DynamicMatrix::DynamicMatrix(const DynamicMatrix& other)
{
    /* Free allocated memory*/
    for(int i=0;i<row;i++)
    {
        delete []array[i];
    }
    delete []array;
    /* Deep copy (new allocatiion,copy values) */
    row = other.row;
    col = other.col;
    array = new int*[row];
    for(int i=0;i<row;i++)
    {
        array[i] = new int[col];
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            array[i][j]=other.array[i][j];
        }
    }
}


DynamicMatrix& DynamicMatrix::operator=(const DynamicMatrix& other)
{
    /* Self check */
    if(this == &other)   return *this;
    else
    {
        /* Free allocated memory*/
        for(int i=0;i<row;i++)
        {
            delete []array[i];
        }
        delete []array;
        /* Deep copy (new allocatiion,copy values) */
        row = other.row;
        col = other.col;
        array = new int*[row];
        for(int i=0;i<row;i++)
        {
            array[i] = new int[col];
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                array[i][j]=other.array[i][j];
            }
        }
        /* Return object */
        return *this;
    }
}

void DynamicMatrix::AssignAllValues(int *array,int row,int col)
{
    if(row!=this->row || col!=this->col)
    {
        throw std::runtime_error("Array size is not the same");
    }
    else
    {
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                this->array[i][j]=array[i*col+j];
            }
        }  
    }      
}

void DynamicMatrix::AssignSpecificValue(int value,int row,int col)
{
    if(row<0 || row>this->row)
    {
        throw std::runtime_error("This row is not available");
    }
    else if(col<0 || col>this->col)
    {
        throw std::runtime_error("This coloumn is not available");
    }
    else
    {
        array[row][col]=value;
    }
}

void DynamicMatrix::PrintSpecificElement(int row,int col)
{
    if(row<0 || row>this->row)
    {
        throw std::runtime_error("This row is not available");
    }
    else if(col<0 || col>this->col)
    {
        throw std::runtime_error("This coloumn is not available");
    }
    else
    {
        std::cout<<"Element in row "<<row<<" and coloumn "<<col<<" = "<<array[row][col]<<std::endl;
    }
}

DynamicMatrix::~DynamicMatrix()
{
    /* Free allocated memory*/
    for(int i=0;i<row;i++)
    {
        delete []array[i];
    }
    delete []array;
}

std::ostream& operator<<(std::ostream& out,const DynamicMatrix& d)
{
    for(int i=0;i<d.GetRow();i++)
    {
        for(int j=0;j<d.GetCol();j++)
        {
            out<<d.GetArray()[i][j]<<" ";
        }
        out<<'\n';
    }
    return out;
}