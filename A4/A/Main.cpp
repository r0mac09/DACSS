#include <cstdio>

#include "StudentDaoImpl.hpp"

// Implementing requierements from 
// http://staff.cs.upt.ro/~ioana/arhit-engl/2017/t4a.html
// according to
// https://www.tutorialspoint.com/design_pattern/data_access_object_pattern.htm

int main(void) {
    StudentDaoImpl *dao = new StudentDaoImpl();

    for(unsigned day = 1; day <= 31; day++) {
        printf("DAY %u:\n", day);
        dao->guessLuck(day);
    }

    delete dao;

    return 0;
}