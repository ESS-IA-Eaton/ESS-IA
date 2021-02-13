#include <iostream>
#include "week.cpp"

struct fullReport iteration(fullReport& report, int rng) {
    srand(rng);
    struct teacherBody teachers;
    rng = rand();
    teachers = teacherSchedule(rng);
    struct studentBody students;
    rng = rand();
    students = studentSchedule(teachers, ::cohortNumber, rng);
    for (int i=0; i<::weekNumber; i++) {
        rng = rand();
        week(students, teachers, report, i, rng);
    }
    return report;
}