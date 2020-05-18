#include <ctime>
#include <vector>
#include <string>
#include <iostream>
#include "calendar.h"
#include "colors.h"
using namespace std;

int main(int argc, char**argv){
    if(argc==1){
        // si no hay parametro solo se imprime el calendario del mes actual
        Calendar *cl = new Calendar();
        cl->print_calendar();
        delete cl;
    }else if(argc == 3){
        try{
            if(atoi(argv[1])>=12){
                cout<<BOLDYELLOW<<"Month out of bounds [0-11]"<<RESET<<endl;
            }else{
                Calendar *cl = new Calendar(atoi(argv[1]),atoi(argv[2]));
                cl->print_calendar();
                delete cl;
            }   
        }
        catch(const exception &e)
        {
            cout<<BOLDRED << e.what() << RESET<<endl;
        }
    }else{
        cout<< BOLDRED << "Invalid Argument number"<<RESET<<endl;
    }
    return 0;
}

//pramp.com
//www.leetcode.com
//cscareerquestions.reddit.com