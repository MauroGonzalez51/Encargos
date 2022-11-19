// ! THIS IS THE MAIN FILE 

#include <bits/stdc++.h>
#include "dynamicSorting.h"

const std::string folderPath = "ReadingCSV/files/";

int main(void) {
    std::vector <float> values = {1.3, 1.7, 2, 5, 3.8, 4.6, 3.9};
    categorizePeople(values, folderPath);


    return EXIT_SUCCESS;
}