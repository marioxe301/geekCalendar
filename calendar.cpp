#include <vector>
#include <string>
#include <ctime>
#include <iostream>

#include "calendar.h"
#include "colors.h"

void put_month(std::vector<std::string> &format,int month){
    std::string months[] = {"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
    std::string actual_month = months[month];
    int inital_pos = format[2].find("*");

    format[2].replace(inital_pos,3,actual_month);
}
void put_year(std::vector<std::string>&format,int year){
    int inital_pos = format[0].find("*");
    format[0].replace(inital_pos,4,std::to_string(year));
}
void put_days(std::vector<std::string>&format,int start,int end){
    // 39 es el tamaño del formato
    int size_of_row = 6;
    int index = 4;
    int day = 1; 
    int initial_index = (start == 0) ? 0 :(start * size_of_row); // a este se le va sumar el size_of_row en cada iteracion
    // si el tamaño es mayor a 39 se reinicia a 0 el initial index y se le suma al index + 1
    for(day; day<=end;day++){
        if(initial_index<39){
            if(day<10){
                format[index].replace(initial_index,3," "+std::to_string(day)+" ");
            }else{
                format[index].replace(initial_index,3,std::to_string(day)+" ");
            }

            initial_index+=size_of_row;
        }else{
            index++;
            initial_index = 0;
            if(day<10){
                format[index].replace(initial_index,3," "+std::to_string(day)+" ");
            }else{
                format[index].replace(initial_index,3,std::to_string(day)+" ");
            }
            initial_index+=size_of_row;
        }
    }
}

void Calendar::init_template(){
    //inicializa el tamplate 
    format.push_back("============= YEAR  **** ==============");
    format.push_back("                                       ");
    format.push_back("- - - - - - - - - *** - - - - - - - - -");
    format.push_back("SUN - MON - TUE - WED - THU - FRI - SAT");
    format.push_back("- -   - -   - -   - -   - -   - -   - -");
    format.push_back("- -   - -   - -   - -   - -   - -   - -");
    format.push_back("- -   - -   - -   - -   - -   - -   - -");
    format.push_back("- -   - -   - -   - -   - -   - -   - -");
    format.push_back("- -   - -   - -   - -   - -   - -   - -");
    format.push_back("- -   - -   - -   - -   - -   - -   - -");
}

int get_number_of_days(int year,int month){
    switch(month){
        case 0: return 31;
        case 1: return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) ? 29:28;
        case 2: return 31;
        case 3: return 30;
        case 4: return 31;
        case 5: return 30;
        case 6: return 31;
        case 7: return 31;
        case 8: return 30;
        case 9: return 31;
        case 10: return 30;
        case 11: return 31;
        default: return -1;
    }
}

int get_initial_day(int month, int year){
    int day=1;
	int y = year - (14-month)/12;
	int m = month +12 * ((14-month) / 12) -2;
	return (day + y + y / 4 - y / 100 + y / 400 + (31 * m / 12)) % 7;
}

void Calendar::init_variables(){
    time_t now = time(0);
    tm *ltm = localtime(&now);

    year = 1900 + ltm->tm_year;
    month = ltm->tm_mon;
    day = ltm->tm_mday;

    initial_day = get_initial_day(month+1,year);
    number_of_days = get_number_of_days(year,month);
}

Calendar::Calendar(){
    init_template();
    init_variables();
    put_month(format,month);
    put_year(format,year);
    put_days(format,initial_day,number_of_days);
}

void Calendar::print_calendar(){
    for(int i = 0; i< format.size();i++){
        size_t found = format[i].find(std::to_string(day));
        if(found!=std::string::npos){
            for(int j= 0;j<format[i].size();j++){
                if(j == found){
                    std::cout<< BOLDRED<<format[i][j]<<RESET;
                    std::cout<< BOLDRED<<format[i][j+1]<<RESET;
                    j+=2;
                }
                std::cout<< BOLDWHITE<<format[i][j]<<RESET;
            }
            std::cout<<std::endl;
        }else{
            if(i==0){
               std::cout<<BOLDYELLOW<<format[i]<<RESET<<std::endl; 
            }else if(i==2){
                std::cout<<BOLDYELLOW<<format[i]<<RESET<<std::endl;
            }else if(i==3){
                std::cout<<BLUE<<format[i]<<RESET<<std::endl;
            }else{
                std::cout<< BOLDWHITE<<format[i]<<RESET<<std::endl;
            }
        }
    }
}

Calendar::Calendar(int m,int y){
    init_template();
    year = y;
    month = m;
    initial_day = get_initial_day(month+1,year);
    number_of_days = get_number_of_days(year,month);
    day = -1;
    put_month(format,month);
    put_year(format,year);
    put_days(format,initial_day,number_of_days);
}