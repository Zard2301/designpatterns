/**********************************************************
* File Name: WeatherData.hpp
* Created by: Zard 2025/03/25
* Description: Test code of Head First Design Patterns
* Modified:
*     1:
**********************************************************/

#ifndef _A_WEATHERDATA_H_
#define _A_WEATHERDATA_H_

#include <memory>

class Subject {
    virtual ~Subject();

    virtual void registerObserver() = 0;
    virtual void removeObserver() = 0;
    virtual void notifyObserver() = 0;
};

class Observer {
    virtual ~Observer();

    virtual update() = 0;
};

class Display {
    virtual ~Display();

    virtual display() = 0;
};

class WeatherData: public Subject {};

#endif //_WEATHERDATA_H_