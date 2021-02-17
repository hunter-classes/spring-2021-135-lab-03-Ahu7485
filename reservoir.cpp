// add your code
#include "reservoir.h"

double get_east_storage(std::string date){
    std::string dates, data;
    double avg = 0;
    std::ifstream inFile;
    inFile.open("Current_Reservoir_Levels.tsv");
    //checks to see if file is opened
    if (!inFile) {
        std::cout << "Unable to open file datafile.txt";
        exit(1);
    }
    //looks at data to find date and return number
    while(inFile >> dates >> data){
        inFile.ignore(INT_MAX, '\n');
        if (dates == date){
            std::cout << dates << " ";
            std::stringstream convert(data);
            convert >> avg;
            return avg;
            break;
        }
    }
    inFile.close();
    return 0;
}

double get_min_east(){
    std::ifstream data ("Current_Reservoir_Levels.tsv");
    //reads the first line
    std::string title;
    getline(data, title);
    //variables
    std::string dates;
    double estorage;
    double smallest = 1000.0;
    while (data >> dates >> estorage){
        data.ignore(INT_MAX, '\n');
        if (estorage < smallest){
            smallest = estorage;
        }
    }
    return smallest;
}

double get_max_east(){
    std::ifstream data ("Current_Reservoir_Levels.tsv");
    //reads the first line
    std::string title;
    getline(data, title);
    //variables
    std::string dates;
    double estorage;
    double largest = 0.0;
    while (data >> dates >> estorage){
        data.ignore(INT_MAX, '\n');
        if (estorage > largest){
            largest = estorage;
        }
    }
    return largest;
}

std::string compare_basins(std::string date){
    std::ifstream data ("Current_Reservoir_Levels.tsv");
    std::string title;
    getline(data, title);
    std::string dates;
    double useless;
    double east;
    double west;
    std::string result;
    while(data >> dates >> useless >> east >> useless >> west){
        data.ignore(INT_MAX, '\n');
        if (date == dates){
            if (east > west){
                result = "East";
            }else if (west > east){
                result = "West";
            }else {
                result = "Equal";
            }
        }
    }
    return date + " " + result;
}