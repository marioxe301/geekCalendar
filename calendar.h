#ifndef CALENDAR_H
#define CALENDAR_H

class Calendar{
private:
    int year;
    int month;
    int initial_day;
    int day;
    int number_of_days; 
    std::vector<std::string>format;
public:
    Calendar(int month,int year);
    Calendar();
    
    void init_template();
    void init_variables();
    void print_calendar();
};

void put_month(std::vector<std::string>&format,int month);
void put_year(std::vector<std::string>&format,int year);
void put_days(std::vector<std::string>&format,int start,int end);

int get_number_of_days(int year,int month);
int get_initial_day(int month, int year);

#endif