#include <iostream>
#include <fstream>
#include <random>
#include <time.h>
#include <chrono>
#include "iteration.cpp"
#include "makeCSV.cpp"
using namespace std; 

typedef std::mt19937 rng_type;
std::uniform_int_distribution<rng_type::result_type> rangeMain(0, 1000000);
rng_type rngMain;

int main() {
    auto start = chrono::high_resolution_clock::now();
    ::rngMain.seed(time(0));
    rng_type::result_type randomMain;
    struct fullReport report;
    ofstream file;
    file.open("data/cohort" + to_string(::cohortNumber) + "ExternalInfection.txt", std::ios::trunc);
    file.close();
    file.open("data/cohort" + to_string(::cohortNumber) + "InternalInfection.txt", std::ios::trunc);
    file.close();
    file.open("data/cohort" + to_string(::cohortNumber) + "TotalInfection.txt", std::ios::trunc);
    file.close();
    file.open("data/cohort" + to_string(::cohortNumber) + "TotalInternalInfection.txt", std::ios::trunc);
    file.close();
    for (int i=0; i<::iterations; i++) {
        randomMain = rangeMain(rngMain);
        iteration(report, randomMain);
        makeCSV(report);
        report = fullReport();
    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << duration.count()/1000 << " milliseconds" << endl; 
    return 0;
}
