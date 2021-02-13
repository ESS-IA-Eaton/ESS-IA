#ifndef PARAMETERS_HPP
#define PARAMETERS_HPP

// INDEPENDENT VARIABLE
const int cohortNumber = 4;

// school stats
const int iterations = 10000;
const int weekNumber = 17;
const int teacherNumber = 90;
const int studentNumber = 2200;
const int classNumber = 70;
const int hallwayNumber = 20;
const int beta = studentNumber/hallwayNumber/cohortNumber/9;

// covid stats
const int infectionRatio1 = 3856;
const int infectionRatio2 = 10000;
const int exposedPeriod = 2;
const int symptomPeriod = 4;
const int infectiousPeriod = 14;
const double asymptomaticRate = 0.4;
const double classroomRate = 0.026;
const double hallwayRate = 0.128;

// struct declaration
struct teacherBody {
    // each teacher as [P1, P2, P3, empty, S, I, T1, T2, T3, W1, W2, W3, Th1, Th2, Th3, F1, F2, F3]
    // P1, P2, P3 as 0 or 1 where 0 means no class and means class
    // empty to align teacher and student S and I index
    // S as 0 or 1 where 0 means susceptible and 1 means not susceptible
    // I as 0 or # where 0 means not infectious and # means days left
    // T1~F3 as # of infectious people in class correspondent to day and period
    int teacherList[::teacherNumber][18] = {0};
};
struct studentBody {
    // each student as [P1, P2, P3, day, S, I]
    // P1, P2, P3 as # where 0 means off and number is teacher+1
    // day as # where 0 is TWThF, 1 as T, 2 as W, 3 as Th, 4 as F, 5 as TW, and 6 as ThF
    // S as 0 or 1 where 0 means susceptible and 1 means not susceptible
    // I as 0 or # where 0 means not infectious and # means days left
    int studentList[::studentNumber][6] = {0};
};
struct fullReport {
    // each week as [W1, W2, W3...]
    // week as [[Mon, 0], [Tue, Cls], [Wed, Cls], [Thu, Cls], [Fri, Cls], [Sat, 0], [Sun, 0]]
    int report[::weekNumber][7][2] = {0};
};

#endif // PARAMETERS_HPP