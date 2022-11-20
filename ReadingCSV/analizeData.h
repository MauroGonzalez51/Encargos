#include <bits/stdc++.h>

// ! All the info about the analisis functions goes to the logFile

/**
 * TODO:
 *      * Buscar la moda, y media (promedio) *
 *      * Mediana *
 * 
 * 
 * 
 * 
 * 
*/

void writeLog(const std::string folderPath, const std::string message);

void findMode(std::vector <float> &dataVector, const std::string folderPath) {
    int maxRepetitions = 0;
    float maxRepetitionsNumber;
    for (auto &value : dataVector) {
        int localRepetitions = 0;
        for (auto &iteration : dataVector) 
            if (value == iteration) localRepetitions++;
        
        if (localRepetitions > maxRepetitions) {
            maxRepetitions = localRepetitions;
            maxRepetitionsNumber = value;
        }
    }

    writeLog(folderPath, "Mode: " + std::to_string(maxRepetitionsNumber) + "| " + std::to_string(maxRepetitions) + " time(s)");
}



void analizeDataMain(std::vector <float> &dataVector, const std::string folderPath) {
    // const std::string categoriesFolderPath = folderPath + "categoryFiles/";
    writeLog(folderPath, "Finding the Mode ...");
    findMode(dataVector, folderPath);
}