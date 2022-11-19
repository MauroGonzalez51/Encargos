// ! THIS IS THE MAIN FILE 

#include <bits/stdc++.h>
#include "dynamicSorting.h"
#include "readingFile.h"
#include "createBreakpoints.h"
#include <chrono>

const std::string folderPath = "ReadingCSV/files/";
std::ofstream logFile (folderPath + "logFile.txt", std::ios::app);

void writeLog(const std::string logMsg) {
    logFile << "[INFO] " << logMsg << std::endl;
}

// TODO: 
//   - Create the breakpoints :>

struct {
    std::vector <float> dataVector;
    std::vector <std::string> dataVectorParseString;
    std::vector <float> breakpoints;
} dataArrays;

void categoriesMain() {
    (readingFile(dataArrays.dataVector, dataArrays.dataVectorParseString, folderPath)) ?
        writeLog("Finished reading the file") : writeLog("Error during reading the file");
    dataArrays.dataVectorParseString.clear();

    createBreakpoints(dataArrays.dataVector, dataArrays.breakpoints);
    categorizePeople(dataArrays.dataVector, dataArrays.breakpoints, folderPath);
}

int main(void) {
    categoriesMain();

    return EXIT_SUCCESS;
}