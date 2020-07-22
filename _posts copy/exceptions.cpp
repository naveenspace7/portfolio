#include <iostream>
#include <string>
#include <exception>

using namespace std;

class myexception: exception
{
public:
    myexception() = default;
    ~myexception() = default;

    virtual const char* what() const noexcept override
    {
        return "Exception went wrong in ";
    }

};



int main()
{
    try
    {
        throw myexception();
    }
    catch(const myexception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

