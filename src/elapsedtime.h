#ifndef ELAPSEDTIME_H
#define ELAPSEDTIME_H

#include <fstream>
#include <ctime>
#include <iomanip>
#include <iostream>

inline void begintime(clock_t &time) {
    if (time != 0)
    {
        std::cout << std::fixed;
        std::cout << std::setprecision(9);
        time = clock();
    }
}

inline void elapsedtimeFile(std::ofstream &timefile, clock_t begin_time) {
    if (begin_time != 0) {

        double elapsedtime = (double(clock() - begin_time) / CLOCKS_PER_SEC);
        std::cout << "elapsed time: " << elapsedtime * 1000000 << " microseconds" << std::endl;

        if (timefile.is_open() == true)
            timefile << elapsedtime << '\n';
    }
}

#endif