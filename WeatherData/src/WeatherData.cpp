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
    temperature = 0.0;
    pressure = 0.0;
    hummidity = 0.0;
}

WeatherData::~WeatherData() {
    /* Do nothing */
}

void WeatherData::registerObserver( std::shared_ptr<Observer> po ) {
    observers.push_back(po);
}

void WeatherData::removeObserver( std::shared_ptr<Observer> po ) {
    observers.remove(po);
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

currentConditionsDisplay::currentConditionsDisplay(std::shared_ptr<WeatherData> pw) {
    this->pweatherData = pw;
}

currentConditionsDisplay::~currentConditionsDisplay() {
    pweatherData = NULL;
}

void currentConditionsDisplay::update() {
    this->temperature = pweatherData->getTemperature();
    this->pressure = pweatherData->getPressure();
    this->hummidity = pweatherData->getHummidity();

    display();
}

void currentConditionsDisplay::display() {
    std::cout << "Current conditions temperature: " << temperature << "F degrees and pressure: " \
    << pressure << "kPa and hummidity: " << hummidity << "% hummidity"<< std::endl;
}