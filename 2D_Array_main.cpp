#include "2D_Array.hpp"

int main()
{
    DynamicMatrix d(3,3);
    int nums[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    try
    {
        d.AssignAllValues(&nums[0][0],3,3);
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << "Caught Exception: " <<e.what() << '\n';
    }
    
    std::cout<<d<<std::endl;
    
}