#include <iostream>
#include "parameters.hpp"
using namespace std;

int teachersOutside(teacherBody& teachers, int rng) {
    srand(rng);
    int rng2;
    int newOutside = 0;
    for (int i=0; i<::teacherNumber; i++) {
        rng = rand() % ::infectionRatio2;
        rng2 = rand() % 10000;
        if (rng < ::infectionRatio1 && rng2 <= 1 && teachers.teacherList[i][4] == 0) {
            teachers.teacherList[i][4] = 1;
            teachers.teacherList[i][5] = ::infectiousPeriod;
            newOutside++;
        }
        if (teachers.teacherList[i][5] > 0) {
            teachers.teacherList[i][5]--;
            if (teachers.teacherList[i][5] == ::infectiousPeriod-::exposedPeriod) {
                // add to rate after becoming infectious
                teachers.teacherList[i][6]++;
                teachers.teacherList[i][7]++;
                teachers.teacherList[i][8]++;
                teachers.teacherList[i][9]++;
                teachers.teacherList[i][10]++;
                teachers.teacherList[i][11]++;
                teachers.teacherList[i][12]++;
                teachers.teacherList[i][13]++;
                teachers.teacherList[i][14]++;
                teachers.teacherList[i][15]++;
                teachers.teacherList[i][16]++;
                teachers.teacherList[i][17]++;
            } else if (teachers.teacherList[i][5] == ::infectiousPeriod-::symptomPeriod) {
                // remove from rate after being sent home
                // teachers live alone
                if (rng2 > ::asymptomaticRate*1000) {
                    teachers.teacherList[i][6]--;
                    teachers.teacherList[i][7]--;
                    teachers.teacherList[i][8]--;
                    teachers.teacherList[i][9]--;
                    teachers.teacherList[i][10]--;
                    teachers.teacherList[i][11]--;
                    teachers.teacherList[i][12]--;
                    teachers.teacherList[i][13]--;
                    teachers.teacherList[i][14]--;
                    teachers.teacherList[i][15]--;
                    teachers.teacherList[i][16]--;
                    teachers.teacherList[i][17]--;
                    teachers.teacherList[i][5] = -1;
                }
            } else if (teachers.teacherList[i][5] == 0) {
                //remove from rate after becoming uninfectious
                teachers.teacherList[i][6]--;
                teachers.teacherList[i][7]--;
                teachers.teacherList[i][8]--;
                teachers.teacherList[i][9]--;
                teachers.teacherList[i][10]--;
                teachers.teacherList[i][11]--;
                teachers.teacherList[i][12]--;
                teachers.teacherList[i][13]--;
                teachers.teacherList[i][14]--;
                teachers.teacherList[i][15]--;
                teachers.teacherList[i][16]--;
                teachers.teacherList[i][17]--;
            }
        }
    }
    return newOutside;
}

int studentsOutside(studentBody& students, teacherBody& teachers, int rng) {
    srand(rng);
    int rng2;
    int newOutside = 0;
    for (int i=0; i<::studentNumber; i++) {
        rng = rand() % ::infectionRatio2;
        rng2 = rand() % 10000;
        if (rng < ::infectionRatio1 && rng2 <= 1 && students.studentList[i][4] == 0) {
            students.studentList[i][4] = 1;
            students.studentList[i][5] = ::infectiousPeriod;
            newOutside++;
        }
        if (students.studentList[i][5] > 0) {
            students.studentList[i][5]--;
            if (students.studentList[i][5] == ::infectiousPeriod-::exposedPeriod) {
                // add to rate after becoming infectious
                if (students.studentList[i][3] == 0 || students.studentList[i][3] == 1 ||students.studentList[i][3] == 5) {
                    teachers.teacherList[students.studentList[i][0]-1][6]++;
                    teachers.teacherList[students.studentList[i][1]-1][7]++;
                    teachers.teacherList[students.studentList[i][2]-1][8]++;
                }
                if (students.studentList[i][3] == 0 || students.studentList[i][3] == 2 ||students.studentList[i][3] == 5) {
                    teachers.teacherList[students.studentList[i][0]-1][9]++;
                    teachers.teacherList[students.studentList[i][1]-1][10]++;
                    teachers.teacherList[students.studentList[i][2]-1][11]++;
                }
                if (students.studentList[i][3] == 0 || students.studentList[i][3] == 3 ||students.studentList[i][3] == 6) {
                    teachers.teacherList[students.studentList[i][0]-1][12]++;
                    teachers.teacherList[students.studentList[i][1]-1][13]++;
                    teachers.teacherList[students.studentList[i][2]-1][14]++;
                }
                if (students.studentList[i][3] == 0 || students.studentList[i][3] == 4 ||students.studentList[i][3] == 6) {
                    teachers.teacherList[students.studentList[i][0]-1][15]++;
                    teachers.teacherList[students.studentList[i][1]-1][16]++;
                    teachers.teacherList[students.studentList[i][2]-1][17]++;
                }
            } else if (students.studentList[i][5] == ::infectiousPeriod-::symptomPeriod) {
                // remove from rate after being sent home
                // students live with two parents
                if (rng2 > ::asymptomaticRate*::asymptomaticRate*::asymptomaticRate*1000) {
                    if (students.studentList[i][3] == 0 || students.studentList[i][3] == 1 ||students.studentList[i][3] == 5) {
                        teachers.teacherList[students.studentList[i][0]-1][6]--;
                        teachers.teacherList[students.studentList[i][1]-1][7]--;
                        teachers.teacherList[students.studentList[i][2]-1][8]--;
                    }
                    if (students.studentList[i][3] == 0 || students.studentList[i][3] == 2 ||students.studentList[i][3] == 5) {
                        teachers.teacherList[students.studentList[i][0]-1][9]--;
                        teachers.teacherList[students.studentList[i][1]-1][10]--;
                        teachers.teacherList[students.studentList[i][2]-1][11]--;
                    }
                    if (students.studentList[i][3] == 0 || students.studentList[i][3] == 3 ||students.studentList[i][3] == 6) {
                        teachers.teacherList[students.studentList[i][0]-1][12]--;
                        teachers.teacherList[students.studentList[i][1]-1][13]--;
                        teachers.teacherList[students.studentList[i][2]-1][14]--;
                    }
                    if (students.studentList[i][3] == 0 || students.studentList[i][3] == 4 ||students.studentList[i][3] == 6) {
                        teachers.teacherList[students.studentList[i][0]-1][15]--;
                        teachers.teacherList[students.studentList[i][1]-1][16]--;
                        teachers.teacherList[students.studentList[i][2]-1][17]--;
                    }
                    students.studentList[i][5] = -1;
                }
            } else if (students.studentList[i][5] == 0) {
                //remove from rate after becoming uninfectious
                if (students.studentList[i][3] == 0 || students.studentList[i][3] == 1 ||students.studentList[i][3] == 5) {
                    teachers.teacherList[students.studentList[i][0]-1][6]--;
                    teachers.teacherList[students.studentList[i][1]-1][7]--;
                    teachers.teacherList[students.studentList[i][2]-1][8]--;
                }
                if (students.studentList[i][3] == 0 || students.studentList[i][3] == 2 ||students.studentList[i][3] == 5) {
                    teachers.teacherList[students.studentList[i][0]-1][9]--;
                    teachers.teacherList[students.studentList[i][1]-1][10]--;
                    teachers.teacherList[students.studentList[i][2]-1][11]--;
                }
                if (students.studentList[i][3] == 0 || students.studentList[i][3] == 3 ||students.studentList[i][3] == 6) {
                    teachers.teacherList[students.studentList[i][0]-1][12]--;
                    teachers.teacherList[students.studentList[i][1]-1][13]--;
                    teachers.teacherList[students.studentList[i][2]-1][14]--;
                }
                if (students.studentList[i][3] == 0 || students.studentList[i][3] == 4 ||students.studentList[i][3] == 6) {
                    teachers.teacherList[students.studentList[i][0]-1][15]--;
                    teachers.teacherList[students.studentList[i][1]-1][16]--;
                    teachers.teacherList[students.studentList[i][2]-1][17]--;
                }
            }
        }
    }
    return newOutside;
}