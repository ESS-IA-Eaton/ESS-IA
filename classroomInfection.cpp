#include <iostream>
#include "parameters.hpp"
using namespace std;

int teachersInside(teacherBody& teachers, int day, int rng) {
    srand(rng);
    int newInside = 0;
    for (int i=0; i<::teacherNumber; i++) {
        if (teachers.teacherList[i][4] == 0) {
            rng = rand() % 10000;
            if (rng < ::classroomRate*10000*(teachers.teacherList[i][3+day*3]+teachers.teacherList[i][4+day*3]+teachers.teacherList[i][5+day*3])) {
                teachers.teacherList[i][4] = 1;
                teachers.teacherList[i][5] = ::infectiousPeriod;
                newInside++;
            }
        }
    }
    return newInside;
}

int studentsInside(studentBody& students, teacherBody& teachers, int day, int rng) {
    srand(rng);
    int people;
    int newInside = 0;
    for (int i=0; i<::studentNumber; i++) {
        if (students.studentList[i][4] == 0 && (students.studentList[i][3] == day || students.studentList[i][3] == 0 || (day == 1 && students.studentList[i][3] == 5) || (day == 2 && students.studentList[i][3] == 5) || (day == 3 && students.studentList[i][3] == 6) || (day == 4 && students.studentList[i][3] == 6))) {
            rng = rand() % 10000;
            people = 0;
            if (students.studentList[i][0] > 1) {
                people += teachers.teacherList[students.studentList[i][0]-1][3+day*3];
            }
            if (students.studentList[i][1] > 1) {
                people += teachers.teacherList[students.studentList[i][1]-1][4+day*3];
            }
            if (students.studentList[i][2] > 1) {
                people += teachers.teacherList[students.studentList[i][2]-1][5+day*3];
            }
            if (rng < ::classroomRate*10000*people) {
                students.studentList[i][4] = 1;
                students.studentList[i][5] = ::infectiousPeriod;
                newInside++;
            }
        }
    }
    return newInside;
}