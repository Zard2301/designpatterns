/**********************************************************
* File Name: WeatherData.cpp
* Created by: Zard 2025/03/25
* Description: Test code of Head First Design Patterns
* Modified:
*     1:
**********************************************************/

#include <iostream>
#include "WeatherData.hpp"

Observer::~Observer() {
    /* Do nothing */
}

Display::~Display() {
    /* Do nothing */
}

Subject::~Subject() {
    /* Do nothing */
}

WeatherData::WeatherData() {
    float temperature = 0.0;
    float pressure = 0.0;
    float hummidity = 0.0;
}

WeatherData::~WeatherData() {
    /* Do nothing */
}

void WeatherData::registerObserver( std::unique_ptr<Observer> po ) {
    //observers.push_back(po);
}

void WeatherData::removeObserver( std::unique_ptr<Observer> po ) {
    //observers.remove(po);
}

void WeatherData::notifyObserver() {
    for(const auto& it : observers)
        it->update();
}

void WeatherData::measurementChanged() {
    notifyObserver();
}

void WeatherData::setMeasurement(float temperature, float pressure, float hummidity) {
    this->temperature = temperature;
    this->pressure = pressure;
    this->hummidity = hummidity;
    measurementChanged();
}

float WeatherData::getTemperature() {
    return temperature;
}

float WeatherData::getPressure() {
    return pressure;
}

float WeatherData::getHummidity() {
    return hummidity;
}

Temperature::Temperature(std::shared_ptr<WeatherData> pw) {
    oTemperature = 0;
    pweatherData = pw;
}

Temperature::~Temperature() {
    pweatherData = NULL;
}

void Temperature::update() {
    oTemperature = pweatherData->getTemperature();
}; //TODO: need to use this.oTemperature?

void Temperature::display() {}

Pressure::Pressure(std::shared_ptr<WeatherData> pw) {
    oPressure = 0;
    pweatherData = pw;
}

Pressure::~Pressure() {
    pweatherData = NULL;
}

void Pressure::update() {
    oPressure = pweatherData->getPressure();
};

void Pressure::display() {}

Hummidity::Hummidity(std::shared_ptr<WeatherData> pw) {
    oHummidity = 0;
    pweatherData = pw;
}

Hummidity::~Hummidity() {
    pweatherData = NULL;
}

void Hummidity::update() {
    oHummidity = pweatherData->getHummidity();
};

void Hummidity::display() {}
