// ! THIS IS THE MAIN FILE 

#include <bits/stdc++.h>
#include "dynamicSorting.h"
#include "readingFile.h"

const std::string folderPath = "ReadingCSV/files/";

// TODO: 
//   - Read all data and show it UwU
//   - Create a main function for the categories

struct {
    std::vector <float> dataVector;
    std::vector <std::string> dataVectorParseString;
} dataArrays;

int main(void) {
    readingFile(dataArrays.dataVector, dataArrays.dataVectorParseString, folderPath);
    std::cout << dataArrays.dataVector.size() << std::endl;

    return EXIT_SUCCESS;
}