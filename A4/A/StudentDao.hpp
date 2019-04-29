#ifndef STUDENT_DAO_HPP
#define STUDENT_DAO_HPP

#include "Student.hpp"

class StudentDao
{
public:
    StudentDao() {}
    virtual ~StudentDao() {}
    virtual void guessLuck(unsigned) = 0;
};

#endif