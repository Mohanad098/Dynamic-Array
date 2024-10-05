#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <initializer_list>


class Students
{
private:
    /* A vector considered of a pair, first one is the student name and second one is his grade*/
    std::vector<std::pair<std::string,int>> array;
    /*A descending order sort to print out the students in order of their grades*/
    void sortStudents()
    {
        std::sort(array.begin(), array.end(), [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {return a.second > b.second;});
    }
public:
    /*Empty default constructor*/
    Students(){}
    /*An initializer list constructor if the user wanted to put all the students in one go*/
    Students(std::initializer_list<std::pair<std::string,int>> other)
    {
        for(const auto& pair:other)
        {
            /*The grade has to be positive and below 100*/
            if(pair.second<0 || pair.second>100)
            {
                throw std::runtime_error("invalid grade entered for " + pair.first);
            }
        }
        array = other;
    }
    /*For memory conservation in case the user knows the number of students beforehand*/
    void NumberOfStudents(int n)
    {
        array.reserve(n);
    }
    /*To insert a student*/
    void insertElement(std::string name, int grade)
    {
        /*The grade has to be positive and below 100*/
        if(grade<0||grade>100)
        {
            throw std::runtime_error("invalid grade entered");
        }
        else
        {
            array.push_back({name,grade});
        }
        
    }
    /*To insert all the students*/
    void insertArray(std::vector<std::pair<std::string,int>> other)
    {
        for(const auto& pair:other)
        {
            if(pair.second<0 || pair.second>100)
            {
                throw std::runtime_error("invalid grade entered for " + pair.first);
            }
        }
        array = other;
    }
    /*Assignment operator*/
    Students operator=(const Students& other)
    {
        this->array = other.array;
        return *this;
    }
    /*If user entered a student by mistake or wants to delete him*/
    void deleteElement(std::string searchName)
    {
        // Use std::find_if to find the pair with the given name
        auto it = std::find_if(array.begin(), array.end(), [&searchName](const std::pair<std::string, int>& element) {
            return element.first == searchName;
        });
        if (it == array.end())
        {
            throw std::runtime_error("Name not found to be deleted");
        }
        array.erase(it);
    }
    /*To replace a student in the vector*/
    void replaceElement(std::string searchName, std::string newName, int newGrade)
    {
        // Use std::find_if to find the pair with the given name
        auto it = std::find_if(array.begin(), array.end(), [&searchName](const std::pair<std::string, int>& element) {
            return element.first == searchName;
        });
        // If the element is found, update the name and number, else throw an exception
        if (it == array.end())
        {
            throw std::runtime_error("Name not found to be replaced");
        }        
        else
        {
            it->first = newName;
            it->second = newGrade;
        }
    }
    /*To print all students in descending order*/
    void PrintElements()
    {
        sortStudents();
        for(const auto& pair:array)
        {
            std::cout << pair.first << ": " << pair.second << std::endl;
        }
    }
};

/*Test Case 1
-inserting elements one by one
-printing the elements and checking if printed in order
*/
void TestCase1()
{
    Students students;
    students.insertElement("Ahmed",50);
    students.insertElement("Ali",60);
    students.insertElement("Sandy",40);
    students.insertElement("Bob",80);
    students.insertElement("Marley",20);

    students.PrintElements();    
}

/*Test Case 2
-inserting elements as initializer list in constructor
-Using the = Assignment operator
-Inserting elements using a vector
-Checking if the students changed
*/
void TestCase2()
{
    Students students = {{"John", 95}, {"Ahmed", 85}, {"Alice", 90}};
    Students students2;
    students2 = students;
    students2.PrintElements();

    std::vector<std::pair<std::string,int>> vect={{"Bob",80},{"Omar",85},{"Ali",70},{"Mohab",90}};
    students2.insertArray(vect);
    students2.PrintElements();
    
}

/*Test Case 3
-inserting elements as initializer list in constructor
-deleting an element in the vector
-inserting an element in the vector
-replacing an element in the vector
-Printing the vector to check on changes
*/
void TestCase3()
{
    Students students = {{"John", 95}, {"Ahmed", 85}, {"Alice", 90}};
    students.deleteElement("Ahmed");
    students.insertElement("Mohamed",60);
    students.replaceElement("John","John",80);
    students.PrintElements();
}
int main()
{
    std::cout<<"Test Case 1\n";
    TestCase1();
    std::cout<<"\nTest Case 2\n";
    TestCase2();
    std::cout<<"\nTest Case 3\n";
    TestCase3();
}

