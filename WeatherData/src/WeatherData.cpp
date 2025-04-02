/**********************************************************
* File Name: WeatherData.cpp
* Created by: Zard 2025/03/25
* Description: Test code of Head First Design Patterns
* Modified:
*     1:
**********************************************************/

#include <iostream>
#include <numeric>
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
    humidity = 0.0;
}

WeatherData::~WeatherData() {
    std::cout << "Run WeatherData Destructor" << std::endl;
}

void WeatherData::registerObserver( std::shared_ptr<Observer> po ) {
    observers.push_back(po);
}

void WeatherData::removeObserver( std::shared_ptr<Observer> po ) {
    //observers.remove(po);
    observers.remove_if([&po](std::weak_ptr<Observer> o){
        return (o.lock() == po);});// optimize lambda
}

void WeatherData::notifyObserver() {
    // for(const auto& it : observers)
    //     it->update();
    for(auto it = observers.begin(); it != observers.end();) {
        if(auto obs = it->lock()) {
            obs->update();
            ++it;
        }
        else {
            std::cout << "notifyObserver: erase invalid iterator" << std::endl;
            it = observers.erase(it);
        }
    }
}

void WeatherData::measurementChanged() {
    notifyObserver();
}

void WeatherData::setMeasurement(float temperature, float humidity, float pressure) {
    this->temperature = temperature;
    this->humidity = humidity;
    this->pressure = pressure;
    measurementChanged();
}

float WeatherData::getTemperature() {
    return temperature;
}

float WeatherData::getPressure() {
    return pressure;
}

float WeatherData::getHumidity() {
    return humidity;
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

Humidity::Humidity(std::shared_ptr<WeatherData> pw) {
    oHumidity = 0;
    pweatherData = pw;
}

Humidity::~Humidity() {
    pweatherData = NULL;
}

void Humidity::update() {
    oHumidity = pweatherData->getHumidity();
};

void Humidity::display() {}

currentConditionsDisplay::currentConditionsDisplay(std::shared_ptr<WeatherData> pw) {
    this->pweatherData = pw;
}

currentConditionsDisplay::~currentConditionsDisplay() {
    pweatherData = NULL;
    std::cout << "Run currentConditionsDisplay Destructor" << std::endl;
}

void currentConditionsDisplay::update() {
    this->temperature = pweatherData->getTemperature();
    //this->pressure = pweatherData->getPressure();
    this->humidity = pweatherData->getHumidity();

    display();
}

void currentConditionsDisplay::display() {
    std::cout << "Current conditions temperature: " << temperature << "F degrees and : " \
    << humidity << "% humidity"<< std::endl;
}

statisticsDisplay::statisticsDisplay(std::shared_ptr<WeatherData> pw) {
    this->pweatherData = pw;
    this->temp_avg = -999.0;
    this->temp_max = -999.0;
    this->temp_min = -999.0;
}

statisticsDisplay::~statisticsDisplay() {
    this->pweatherData = NULL;
    std::cout << "Run statisticsDisplay Destructor" << std::endl;
}

void statisticsDisplay::update() {
    this->temp_vec.push_back(pweatherData->getTemperature());
    this->temp_avg = std::accumulate(this->temp_vec.begin(), this->temp_vec.end(), 0) / temp_vec.size(); //use accumulate get avg
    if (this->temp_max < this->temp_vec.back())
        this->temp_max = this->temp_vec.back();
    if (this->temp_min > this->temp_vec.back() || this->temp_min < -990.0)
        this->temp_min = this->temp_vec.back();
    this->display();
}

void statisticsDisplay::display() {
    std::cout << "Avg/Max/Min temperature = " << this->temp_avg << "/"  \
    << this->temp_max << "/" << this->temp_min <<std::endl;
}

forecastDisplay::forecastDisplay(std::shared_ptr<WeatherData> pw) {
    this->currentPressure = 29.92f;
    this->pweatherData = pw;
}

forecastDisplay::~forecastDisplay() {
    this->pweatherData = NULL;
    std::cout << "Run forecastDisplay Destructor" << std::endl;
}

void forecastDisplay::update() {
    this->lastPressure = this->currentPressure;
    this->currentPressure = pweatherData->getPressure();
    
    this->display();
}

void forecastDisplay::display() {
    if (this->currentPressure > this->lastPressure)
        std::cout << "Forecast: Improving weather on the way!" << std::endl;
    else if (this->currentPressure == this->lastPressure)
        std::cout << "Forecast: More of the same" << std::endl;
    else
        std::cout << "Forecast: Watch out for cooler, rainy weather" << std::endl;
}

heatIndexDisplay::heatIndexDisplay(std::shared_ptr<WeatherData> pw) {
    pweatherData = pw;
}

heatIndexDisplay::~heatIndexDisplay() {
    pweatherData = NULL;
    std::cout << "Run heatIndexDisplay Destructor" << std::endl;
}

void heatIndexDisplay::update() {
    this->temperature = pweatherData->getTemperature();
    this->humidity = pweatherData->getHumidity();
    this->heatindex = computeHeatIndex(temperature, humidity);

    display();
}

void heatIndexDisplay::display() {
    std::cout << "Heat index is " << heatindex << std::endl;
}

float heatIndexDisplay::computeHeatIndex(float t, float rh) {
    float index = (float)((16.923 + (0.185212 * t) + (5.37941 * rh) - (0.100254 * t * rh) + 
		(0.00941695 * (t * t)) + (0.00728898 * (rh * rh)) + 
		(0.000345372 * (t * t * rh)) - (0.000814971 * (t * rh * rh)) + 
		(0.0000102102 * (t * t * rh * rh)) - (0.000038646 * (t * t * t)) + (0.0000291583 * 
		(rh * rh * rh)) + (0.00000142721 * (t * t * t * rh)) + 
		(0.000000197483 * (t * rh * rh * rh)) - (0.0000000218429 * (t * t * t * rh * rh)) + 
		0.000000000843296 * (t * t * rh * rh * rh)) - 
		(0.0000000000481975 * (t * t * t * rh * rh * rh)));
	return index;
}
