#include <iostream>
#include "makeSchedule.cpp"
#include "outsideInfection.cpp"
#include "classroomInfection.cpp"
#include "hallwayInfection.cpp"
using namespace std;

struct fullReport week(studentBody& students, teacherBody& teachers, fullReport& report, int week, int rng) {
    srand(rng);
    int rngTeachersOutside;
    int rngStudentsOutside;
    int rngTeachersInside;
    int rngStudentsInside;
    int rngHallways;
    // monday
    rngTeachersOutside = rand();
    rngStudentsOutside = rand();
    report.report[week][0][0] = teachersOutside(teachers, rngTeachersOutside)+
                                studentsOutside(students, teachers, rngStudentsOutside);
    // tuesday
    rngTeachersInside = rand();
    rngStudentsInside = rand();
    rngHallways = rand();
    rngTeachersOutside = rand();
    rngStudentsOutside = rand();
    report.report[week][1][0] = teachersOutside(teachers, rngTeachersOutside)+
                                studentsOutside(students, teachers, rngStudentsOutside);
    report.report[week][1][1] = teachersInside(teachers, 1, rngTeachersInside)+
                                studentsInside(students, teachers, 1, rngStudentsInside)+
                                hallways(students, 1, rngHallways);
    // wednesday
    rngTeachersInside = rand();
    rngStudentsInside = rand();
    rngHallways = rand();
    rngTeachersOutside = rand();
    rngStudentsOutside = rand();
    report.report[week][2][0] = teachersOutside(teachers, rngTeachersOutside)+
                                studentsOutside(students, teachers, rngStudentsOutside);
    report.report[week][2][1] = teachersInside(teachers, 2, rngTeachersInside)+
                                studentsInside(students, teachers, 2, rngStudentsInside)+
                                hallways(students, 2, rngHallways);
    // thursday
    rngTeachersInside = rand();
    rngStudentsInside = rand();
    rngHallways = rand();
    rngTeachersOutside = rand();
    rngStudentsOutside = rand();
    report.report[week][3][0] = teachersOutside(teachers, rngTeachersOutside)+
                                studentsOutside(students, teachers, rngStudentsOutside);
    report.report[week][3][1] = teachersInside(teachers, 3, rngTeachersInside)+
                                studentsInside(students, teachers, 3, rngStudentsInside)+
                                hallways(students, 3, rngHallways);
    // friday
    rngTeachersInside = rand();
    rngStudentsInside = rand();
    rngHallways = rand();
    rngTeachersOutside = rand();
    rngStudentsOutside = rand();
    report.report[week][4][0] = teachersOutside(teachers, rngTeachersOutside)+
                                studentsOutside(students, teachers, rngStudentsOutside);
    report.report[week][4][1] = teachersInside(teachers, 4, rngTeachersInside)+
                                studentsInside(students, teachers, 4, rngStudentsInside)+
                                hallways(students, 4, rngHallways);
    // saturday
    rngTeachersOutside = rand();
    rngStudentsOutside = rand();
    report.report[week][5][0] = teachersOutside(teachers, rngTeachersOutside)+
                                studentsOutside(students, teachers, rngStudentsOutside);
    // sunday
    rngTeachersOutside = rand();
    rngStudentsOutside = rand();
    report.report[week][6][0] = teachersOutside(teachers, rngTeachersOutside)+
                                studentsOutside(students, teachers, rngStudentsOutside);
    return report;
}