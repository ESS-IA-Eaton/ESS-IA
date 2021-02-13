#include <iostream>
#include "parameters.hpp"
using namespace std;

int hallways(studentBody& students, int day, int rng) {
    srand(rng);
    int people = 0;
    int newHallway = 0;
    for (int i=0; i<::studentNumber; i++) {
        if ((students.studentList[i][3] == day || students.studentList[i][3] == 0 || (day == 1 && students.studentList[i][3] == 5) || (day == 2 && students.studentList[i][3] == 5) || (day == 3 && students.studentList[i][3] == 6) || (day == 4 && students.studentList[i][3] == 6)) && students.studentList[i][5] > 0 && students.studentList[i][5] < ::infectiousPeriod-::exposedPeriod) {
            people++;
        }
    }
    for (int i=0; i<::studentNumber; i++) {
        if (students.studentList[i][4] == 0 && (students.studentList[i][3] == day || students.studentList[i][3] == 0 || (day == 1 && students.studentList[i][3] == 5) || (day == 2 && students.studentList[i][3] == 5) || (day == 3 && students.studentList[i][3] == 6) || (day == 4 && students.studentList[i][3] == 6))) {
            rng = rand() % 10000;
            if (rng < ::hallwayRate*1000*people*::beta/::studentNumber) {
                students.studentList[i][4] = 1;
                students.studentList[i][5] = ::infectiousPeriod;
                newHallway++;
            }
        }
    }
    return newHallway;
}