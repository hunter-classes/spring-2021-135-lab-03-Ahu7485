#include "reverseorder.h"

void reverse_order(std::string date1, std::string date2){
    std::ifstream data ("Current_Reservoir_Levels.tsv");
    //for first line
    std::string title;
    getline(data, title);
    //initializing
    std::string date;
    double useless;
    double w_elevation;
    bool check = false;
    std::vector <double> elevations;
    std::vector <std::string> dates;
    //loop
    while(data >> date >> useless >> useless >> useless >> w_elevation){
        data.ignore(INT_MAX, '\n');
        if (date1 == date){
            check = true;
        }else if (date2 == date){
            elevations.push_back(w_elevation);
            dates.push_back(date);
            check = false;
        }
        if (check){
            elevations.push_back(w_elevation);
            dates.push_back(date);
        }
    }
    for (int i = dates.size()-1; i >= 0 ; i--){
    std::cout << dates.at(i) << ": " << elevations.at(i) << " ft\n";
    }
    data.close();

}