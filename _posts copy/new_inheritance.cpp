#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
    string name;
    int age;
public:
    Person(string name, int age): name{name}, age{age}
    {
        cout << "Created a person" << endl;
    }

    virtual void Profession() = 0;

    virtual void Talk(string s) { cout << "I'm a human" << endl; }

    ~Person()
    {
        cout << "Person destructor called" << endl;
    }
};

class Teacher: public Person
{
private:
    string subject, position;
    int experience;
public:
    Teacher(string name, int age, string subject, string position, int experience = 0):
        Person{name, age},
        subject{subject}, position{position}, experience{experience}
    {
        cout << "Created a teacher" << endl;
    }

    ~Teacher()
    {
        cout << "Teacher destructor called" << endl;
    }

    void Profession()
    {
        cout << "I am a teacher, I teach" << endl;
    }

    void Talk(string something) override
    {
        cout << something << endl;
    }

};

int main()
{
    Teacher koen{"koen", 60, "embedded systems", "head", 30};

    koen.Talk("hello world");

}