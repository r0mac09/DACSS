#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>

class Student
{
private:
    std::string name;
public:
    Student(const char* name) { this->name = name; }

    ~Student() {}

    const char* getName(void) const { return name.c_str(); }
};

#endif