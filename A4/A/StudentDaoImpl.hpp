#ifndef STUDENT_DAO_IMPL_HPP
#define STUDENT_DAO_IMPL_HPP

#include <cctype>
#include <list>
#include <cstring>

#include "pugixml.hpp" //https://github.com/zeux/pugixml
#include "StudentDao.hpp"

class StudentDaoImpl : public StudentDao
{
private:
    std::list<Student> students;
public:
    StudentDaoImpl() {
        pugi::xml_document xml_doc;
        if (!xml_doc.load_file("students.xml")) {
            printf("ERROR : Parse failed\n+---> TERMINATING\n");
            exit(1);
        }

        pugi::xml_node nodes = xml_doc.child("data").child("students");

        for (pugi::xml_node_iterator it = nodes.begin(); it != nodes.end(); ++it)
        {
            for (pugi::xml_attribute_iterator ait = it->attributes_begin(); ait != it->attributes_end(); ++ait)
            {
                students.push_back(Student(ait->value()));
            }
        }
    };

    ~StudentDaoImpl() {};

    void guessLuck(unsigned day) override {
        char name[64], c;
        unsigned vcnt = 0;
        for (std::list<Student>::iterator it = students.begin(); it != students.end(); ++it){
            strncpy(name, it->getName(), 63);
            for (size_t i = 0; i < strlen(name); i++) {
                c = tolower(name[i]);
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') vcnt++;
            }

            if (day % vcnt) printf("\t%s is not so fortunate today.\n", it->getName());
            else printf("\t%s should buy some lotto tickets today!\n", it->getName());
            vcnt = 0;
        }
    }
};

#endif