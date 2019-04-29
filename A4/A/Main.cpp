#include <cstdio>

#include "StudentDaoImpl.hpp"

// Implementing requierements from 
// http://staff.cs.upt.ro/~ioana/arhit-engl/2017/t4a.html
// according to
// https://www.tutorialspoint.com/design_pattern/data_access_object_pattern.htm

// REQ: Design a Horoscope application, which calculates the horoscope of students.
// The students can be read from different data sources (XML files, SQL database).
// Use the Data Acces Object pattern to decouple between the business logic and the
// data source. The business logic (the horoscope algorithm) predicts if a student
// will have a good day, according to following algorithm: if the number of vowels
// in the student name is a divisor of the current day, then the student will have
// a good day. 

int main(void) {
    StudentDaoImpl *dao = new StudentDaoImpl();

    for(unsigned day = 1; day <= 31; day++) {
        printf("DAY %u:\n", day);
        dao->guessLuck(day);
    }

    delete dao;

    return 0;
}