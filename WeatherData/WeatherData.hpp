/**********************************************************
* File Name: WeatherData.hpp
* Created by: Zard 2025/03/25
* Description: Test code of Head First Design Patterns
* Modified:
*     1:
**********************************************************/

#ifndef _A_WEATHERDATA_H_
#define _A_WEATHERDATA_H_

#include <list>
#include <memory>

class Observer {
public:
    virtual ~Observer();

    virtual void update() = 0;
};

class Display {
public:
    virtual ~Display();

    virtual void display() = 0;
};

class Subject {
public:
    virtual ~Subject();

    virtual void registerObserver( std::unique_ptr<Observer> po ) = 0;
    virtual void removeObserver( std::unique_ptr<Observer> po ) = 0;
    virtual void notifyObserver() = 0;
};

class WeatherData: public Subject {
public:
    WeatherData();
    ~WeatherData();

    void registerObserver( std::unique_ptr<Observer> po ) override;
    void removeObserver( std::unique_ptr<Observer> po ) override;
    void notifyObserver() override;

    float getTemperature();
    float getPressure();
    float getHummidity();
    void measurementChanged();
    void setMeasurement(float temperature, float pressure, float hummidity);

private:
    std::list<std::unique_ptr<Observer>> observers;
    float temperature;
    float pressure;
    float hummidity;
};

class Temperature: public Observer, public Display {
public:
    Temperature(std::shared_ptr<WeatherData> pw);
    ~Temperature();

    void update();
    void display();
private:
    float oTemperature;
    std::shared_ptr<WeatherData> pweatherData;
};

class Pressure: public Observer, public Display {
public:
    Pressure(std::shared_ptr<WeatherData> pw);
    ~Pressure();

    void update();
    void display();
private:
    float oPressure;
    std::shared_ptr<WeatherData> pweatherData;
};

class Hummidity: public Observer, public Display {
public:
    Hummidity(std::shared_ptr<WeatherData> pw);
    ~Hummidity();

    void update();
    void display();
private:
    float oHummidity;
    std::shared_ptr<WeatherData> pweatherData;
};

#endif //_WEATHERDATA_H_