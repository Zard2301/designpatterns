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

    virtual void registerObserver( std::shared_ptr<Observer> po ) = 0;
    virtual void removeObserver( std::shared_ptr<Observer> po ) = 0;
    virtual void notifyObserver() = 0;
};

class WeatherData: public Subject {
public:
    WeatherData();
    ~WeatherData();

    void registerObserver( std::shared_ptr<Observer> po ) override;
    void removeObserver( std::shared_ptr<Observer> po ) override;
    void notifyObserver() override;

    float getTemperature();
    float getPressure();
    float getHumidity();
    void measurementChanged();
    void setMeasurement(float temperature, float humidity, float pressure);

private:
    //std::list<std::shared_ptr<Observer>> observers;
    std::list<std::weak_ptr<Observer>> observers; //to address memory leaks caused by circular references in shared_ptr
    float temperature;
    float pressure;
    float humidity;
};

class Temperature: public Observer, public Display {
public:
    Temperature(std::shared_ptr<WeatherData> pw);
    ~Temperature();

    void update() override;
    void display() override;
private:
    float oTemperature;
    std::shared_ptr<WeatherData> pweatherData;
};

class Pressure: public Observer, public Display {
public:
    Pressure(std::shared_ptr<WeatherData> pw);
    ~Pressure();

    void update() override;
    void display() override;
private:
    float oPressure;
    std::shared_ptr<WeatherData> pweatherData;
};

class Humidity: public Observer, public Display {
public:
    Humidity(std::shared_ptr<WeatherData> pw);
    ~Humidity();

    void update() override;
    void display() override;
private:
    float oHumidity;
    std::shared_ptr<WeatherData> pweatherData;
};

class currentConditionsDisplay: public Observer, public Display {
public:
    currentConditionsDisplay(std::shared_ptr<WeatherData> pw);
    ~currentConditionsDisplay();

    void update() override;
    void display() override;

private:
    float temperature;
    //float pressure; currentConditionsDisplay don't need pressure
    float humidity;
    std::shared_ptr<WeatherData> pweatherData;
};

class statisticsDisplay: public Observer, public Display{
public:
    statisticsDisplay(std::shared_ptr<WeatherData> pw);
    ~statisticsDisplay();

    void update();
    void display();

private:
    float temperature;
    std::shared_ptr<WeatherData> pweatherData;
};

class forecastDisplay: public Observer, public Display{
public:
    forecastDisplay(std::shared_ptr<WeatherData> pw);
    ~forecastDisplay();

    void update();
    void display();

private:
    float pressure;
    std::shared_ptr<WeatherData> pweatherData;
};

class heatIndexDisplay: public Observer, public Display {
public:
    heatIndexDisplay(std::shared_ptr<WeatherData> pw);
    ~heatIndexDisplay();
    void update();
    void display();
private:
    float computeHeatIndex(float t, float rh);
    float temperature;
    float humidity;
    float heatindex;
    std::shared_ptr<WeatherData> pweatherData;
};

#endif //_WEATHERDATA_H_