// ! Testing an UwU way to categorize things
#include <bits/stdc++.h>

const std::string folderPath = "ReadingCSV/files/";

std::vector <float> breakpoints = {1, 1.5, 2, 2.5, 3, 3.5, 4.5, 5};

// * By this way the ideal is that firstly the breakpoints are created, then the arrays for storing people 
// * of the categories are created later


// !Important:
    // ? To access all the files, remmember that all of them are named as the breakpoints

void categorizePeople(std::vector <float> dataVector) {
    const std::string categoriesFolderPath = folderPath + "categoryFiles/";

    // ! Loop to iterates from the end to the beginning of the array given
    for (auto valueManager = dataVector.rbegin(); valueManager != dataVector.rend(); valueManager++) {
        
        // ! Check with the value given if it fits in any category -> Looping again
        for (int breakpointManager = 0; breakpointManager < breakpoints.size(); breakpointManager++) {
            
            // ! For every iteration it opens a file name as the breakpoint is checking at the moment
            std::ofstream categoryFile (categoriesFolderPath + std::to_string(breakpoints.at(breakpointManager)) + ".txt", std::ios::app);

            // ! The value is a pointer so for accesing the value, it's necesary the "*"
            if (*valueManager <= breakpoints.at(breakpointManager)) {
                
                // * Write it into the file -> with the "," for upcoming values 
                categoryFile << *valueManager << ",";
                break;
            }

            categoryFile.close();
        }
    }
}


int main(void) {
    std::vector <float> values = {1, 2, 3.3, 2.4, 5, 2.7, 1.3};

    categorizePeople(values);

    return EXIT_SUCCESS;
}