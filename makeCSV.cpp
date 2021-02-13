#include <iostream>
#include <fstream>
#include <string>
#include "parameters.hpp"

int inputData(std::string fileName, int Mon, int Tue, int Wed, int Thu, int Fri, int Sat, int Sun, std::string end) {
    std::ofstream file;
    file.open(fileName, std::ios_base::app);
    file << Mon << "," << Tue << "," << Wed << "," << Thu << "," << Fri << "," << Sat << "," << Sun << end;
    file.close();
    return 0;
}

int externalCSV(fullReport report) {
    std::string fileName = "cohort" + std::to_string(::cohortNumber) + "ExternalInfection.txt";
    for (int i=0; i<::weekNumber-1; i++) {
        inputData(fileName, report.report[i][0][0], report.report[i][1][0], report.report[i][2][0], report.report[i][3][0], report.report[i][4][0], report.report[i][5][0], report.report[i][6][0], ",");
    }
    inputData(fileName, report.report[::weekNumber-1][0][0], report.report[::weekNumber-1][1][0], report.report[::weekNumber-1][2][0], report.report[::weekNumber-1][3][0], report.report[::weekNumber-1][4][0], report.report[::weekNumber-1][5][0], report.report[::weekNumber-1][6][0], "\n");
    return 0;
}

int internalCSV(fullReport report) {
    std::string fileName = "cohort" + std::to_string(::cohortNumber) + "InternalInfection.txt";
    for (int i=0; i<::weekNumber-1; i++) {
        inputData(fileName, report.report[i][0][1], report.report[i][1][1], report.report[i][2][1], report.report[i][3][1], report.report[i][4][1], report.report[i][5][1], report.report[i][6][1], ",");
    }
    inputData(fileName, report.report[::weekNumber-1][0][1], report.report[::weekNumber-1][1][1], report.report[::weekNumber-1][2][1], report.report[::weekNumber-1][3][1], report.report[::weekNumber-1][4][1], report.report[::weekNumber-1][5][1], report.report[::weekNumber-1][6][1], "\n");
    return 0;
}

int totalCSV(fullReport report) {
    int Mon = 0;
    int Tue = 0;
    int Wed = 0;
    int Thu = 0;
    int Fri = 0;
    int Sat = 0;
    int Sun = 0;
    std::string fileName = "cohort" + std::to_string(::cohortNumber) + "TotalInfection.txt";
    for (int i=0; i<::weekNumber-1; i++) {
        Mon = Sun + report.report[i][0][0] + report.report[i][0][1];
        Tue = Mon + report.report[i][1][0] + report.report[i][1][1];
        Wed = Tue + report.report[i][2][0] + report.report[i][2][1];
        Thu = Wed + report.report[i][3][0] + report.report[i][3][1];
        Fri = Thu + report.report[i][4][0] + report.report[i][4][1];
        Sat = Fri + report.report[i][5][0] + report.report[i][5][1];
        Sun = Sat + report.report[i][6][0] + report.report[i][6][1];
        inputData(fileName, Mon, Tue, Wed, Thu, Fri, Sat, Sun, ",");
    }
    Mon = Sun + report.report[::weekNumber-1][0][0] + report.report[::weekNumber-1][0][1];
    Tue = Mon + report.report[::weekNumber-1][1][0] + report.report[::weekNumber-1][1][1];
    Wed = Tue + report.report[::weekNumber-1][2][0] + report.report[::weekNumber-1][2][1];
    Thu = Wed + report.report[::weekNumber-1][3][0] + report.report[::weekNumber-1][3][1];
    Fri = Thu + report.report[::weekNumber-1][4][0] + report.report[::weekNumber-1][4][1];
    Sat = Fri + report.report[::weekNumber-1][5][0] + report.report[::weekNumber-1][5][1];
    Sun = Sat + report.report[::weekNumber-1][6][0] + report.report[::weekNumber-1][6][1];
    inputData(fileName, Mon, Tue, Wed, Thu, Fri, Sat, Sun, "\n");
    return 0;
}

int totalInternalCSV(fullReport report) {
    int Mon = 0;
    int Tue = 0;
    int Wed = 0;
    int Thu = 0;
    int Fri = 0;
    int Sat = 0;
    int Sun = 0;
    std::string fileName = "cohort" + std::to_string(::cohortNumber) + "TotalInternalInfection.txt";
    for (int i=0; i<::weekNumber-1; i++) {
        Mon = Sun + report.report[i][0][1];
        Tue = Mon + report.report[i][1][1];
        Wed = Tue + report.report[i][2][1];
        Thu = Wed + report.report[i][3][1];
        Fri = Thu + report.report[i][4][1];
        Sat = Fri + report.report[i][5][1];
        Sun = Sat + report.report[i][6][1];
        inputData(fileName, Mon, Tue, Wed, Thu, Fri, Sat, Sun, ",");
    }
    Mon = Sun + report.report[::weekNumber-1][0][1];
    Tue = Mon + report.report[::weekNumber-1][1][1];
    Wed = Tue + report.report[::weekNumber-1][2][1];
    Thu = Wed + report.report[::weekNumber-1][3][1];
    Fri = Thu + report.report[::weekNumber-1][4][1];
    Sat = Fri + report.report[::weekNumber-1][5][1];
    Sun = Sat + report.report[::weekNumber-1][6][1];
    inputData(fileName, Mon, Tue, Wed, Thu, Fri, Sat, Sun, "\n");
    return 0;
}

int makeCSV(fullReport report) {
    /* layed out as: 
        D1  D2  D3
    I1  __, __, __,
    I2  __, __, __,
    I3  __, __, __,
    with D as day and I as iteration */
    externalCSV(report);
    internalCSV(report);
    totalCSV(report);
    totalInternalCSV(report);
    return 0;
}