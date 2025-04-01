/**********************************************************
* File Name: main.cpp
* Created by: Zard 2025/03/25
* Description: Test code of Head First Design Patterns
* Modified:
*     1:
**********************************************************/

#include "WeatherData.hpp"

int main ()
{
    //std::shared_ptr<WeatherData> pw = std::make_shared<WeatherData>();
    std::shared_ptr<WeatherData> pw(new WeatherData());
    std::shared_ptr<currentConditionsDisplay> pc(new currentConditionsDisplay(pw));
    std::shared_ptr<statisticsDisplay> ps(new statisticsDisplay(pw));
    std::shared_ptr<forecastDisplay> pf(new forecastDisplay(pw));
    std::shared_ptr<heatIndexDisplay> ph(new heatIndexDisplay(pw));

    pw->registerObserver(pc);//Is there a memory leak? -> use weak_ptr to address memory leaks caused by circular references in shared_ptr
    pw->registerObserver(ps);
    pw->registerObserver(pf);
    pw->registerObserver(ph);

    pw->setMeasurement(80.0f, 65.0f, 30.4f);
    pw->setMeasurement(82.0f, 70.0f, 29.2f);
    pw->setMeasurement(78.0f, 90.0f, 29.2f);

    // pw->removeObserver(pc);//test remove func

    // pw->setMeasurement(79.0f, 91.6f, 30.4f);

    return 0;
}