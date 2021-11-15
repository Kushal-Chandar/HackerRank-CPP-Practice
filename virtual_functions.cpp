#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int pId = 0;
int sId = 0;
class Person
{
protected:
    int age;
    string name;

public:
    virtual void putdata() = 0;
    virtual void getdata() = 0;
    //pure virtual function as there is definition according to the question
};

class Professor : public Person
{
private:
    int publications;
    int cur_id = ++pId;

public:
    void putdata();
    void getdata();
};

class Student : public Person
{
private:
    int marks[6];
    int cur_id = ++sId;

public:
    void putdata();
    void getdata();
};

//Definations of class professor
void Professor::getdata()
{
    cin >> name >> age >> publications;
}
void Professor::putdata()
{
    cout << name << ' ' << age << ' ' << publications << ' ' << cur_id << '\n';
}

//Definations of class Student
void Student::getdata()
{
    cin >> name >> age;
    for (int i = 0; i < 6; i++)
    {
        cin >> marks[i];
    }
}
void Student::putdata()
{
    cout << name << ' ' << age << ' ';
    int sum = 0;
    for (int i = 0; i < 6; i++)
    {
        sum += marks[i];
    }
    cout << sum << ' ' << cur_id << '\n';
}

int main()
{

    int n, val;
    cin >> n; //The number of objects that is going to be created.
    Person *per[n];

    for (int i = 0; i < n; i++)
    {

        cin >> val;
        if (val == 1)
        {
            // If val is 1 current object is of type Professor
            per[i] = new Professor;
        }
        else
            per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.
    }

    for (int i = 0; i < n; i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;
}
