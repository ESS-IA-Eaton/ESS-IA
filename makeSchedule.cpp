#include <iostream>
#include "parameters.hpp"
using namespace std;

struct teacherBody teacherSchedule(int rng) {
    struct teacherBody teachers;
    int p1 = ::classNumber;
    int p2 = ::classNumber;
    int p3 = ::classNumber;
    srand(rng);
    while (p1 > 0) {
        rng = rand() % ::teacherNumber;
        if (teachers.teacherList[rng][0] == 0) {
            teachers.teacherList[rng][0] = 1;
            p1--;
        }
    }
    while (p2 > 0) {
        rng = rand() % ::teacherNumber;
        if (teachers.teacherList[rng][1] == 0) {
            teachers.teacherList[rng][1] = 1;
            p2--;
        }
    }
    while (p3 > 0) {
        rng = rand() % ::teacherNumber;
        if (teachers.teacherList[rng][2] == 0) {
            teachers.teacherList[rng][2] = 1;
            p3--;
        }
    }
    return teachers;
}

struct studentBody studentSchedule(teacherBody& teachers, int cohorts, int rng) {
    struct studentBody students;
    int slots;
    int teacher;
    int student;
    int rngTeacher;
    int sizeRng;
    int size;
    switch (cohorts) {
        case 1:
            size = 30;
            break;
        case 2:
            size = 15;
            for (int i=0; i<::studentNumber/2; i++) {
                students.studentList[i][3] = 5;
            }
            for (int i=::studentNumber/2; i<::studentNumber; i++) {
                students.studentList[i][3] = 6;
            }
            break;
        case 4:
            size = 8;
            for (int i=0; i<::studentNumber/4; i++) {
                students.studentList[i][3] = 1;
            }
            for (int i=::studentNumber/4; i<::studentNumber/2; i++) {
                students.studentList[i][3] = 2;
            }
            for (int i=::studentNumber/2; i<3*::studentNumber/4; i++) {
                students.studentList[i][3] = 3;
            }
            for (int i=3*::studentNumber/4; i<::studentNumber; i++) {
                students.studentList[i][3] = 4;
            }
            break;
    }
    srand(rng);
     // divided into individual cohorts -> individual periods
    for (int i=0; i<cohorts; i++) {
        for (int j=0; j<3; j++) {
            slots = ::classNumber*30/cohorts;
            teacher = 0;
            student = 0;
            while (slots > 0) {
                rng = (rand() % (::studentNumber/cohorts)) + (::studentNumber/cohorts)*i;
                sizeRng = rand() % 3;
                if (students.studentList[rng][j] == 0) {
                    if (teacher == ::teacherNumber) {
                        rngTeacher = rand() % ::teacherNumber;
                        if (teachers.teacherList[rngTeacher][j] != 0) {
                            teachers.teacherList[rngTeacher][j]++;
                            slots--;
                            students.studentList[rng][j] = rngTeacher+1;
                        }
                    } else if (student == size || teachers.teacherList[teacher][j] == 0 || (size == 8 && student == size-1 && sizeRng > 0)) {
                        teacher++;
                        student = 0;
                    } else {
                        teachers.teacherList[teacher][j]++;
                        student++;
                        slots--;
                        students.studentList[rng][j] = teacher+1;
                    }
                }
            }
        }
    }
    return students;
}