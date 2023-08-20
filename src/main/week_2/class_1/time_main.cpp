#include <iostream>
#include "time.h"

int main(){
    Time t1(59, 59, 23);
    t1.print();
    
    t1.nextSecond();
    t1.print();

    t1.setHour(12);
    t1.setMinute(30);
    t1.setSecond(15);

    std::cout << "Hour: " << t1.getHour() << "\n";
    std::cout << "Minute: " << t1.getMinute() << "\n";
    std::cout << "Second: " << t1.getSecond() << "\n";

    t1.print();

    std::cout << "\nPrinting t2\n";
    Time t2(12);
    t2.print();

    return 0;
}