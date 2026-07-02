#include "Crop.h"
void Crop::setCropName(string name)
{
    cropName = name;
}

void Crop::addState(string state)
{
    states.push_back(state);
}

void Crop::addSoilType(string soil)
{
    soilTypes.push_back(soil);
}

void Crop::setRainfall(int minRain, int maxRain)
{
    minRainfall = minRain;
    maxRainfall = maxRain;
}

void Crop::setTemperature(int minTemp, int maxTemp)
{
    minTemperature = minTemp;
    maxTemperature = maxTemp;
}

void Crop::setPH(double min, double max)
{
    minPH = min;
    maxPH = max;
}

void Crop::setHumidity(double min,double max)
{
    minHumidity=min;
    maxHumidity=max;
}

void Crop::setMoisture(double min,double max)
{
    minMoisture=min;
    maxMoisture=max;
}

void Crop::setWaterRequirement(string water)
{
    waterRequirement=water;
}

void Crop::setYield(double yield)
{
    yieldPerAcre = yield;
}

void Crop::setIrrigationMethod(string method)
{
    irrigationMethod = method;
}

void Crop::setSeason(string seasonName)
{
    season = seasonName;
}

void Crop::addFertilizer(string fertilizer)
{
    fertilizers.push_back(fertilizer);
}


void Crop::displayCrop()
{
    cout << "\nCrop Name          : " << cropName << endl;

        cout << "Suitable States   : ";

    for(int i = 0; i < states.size(); i++)
    {
        cout << states[i];

        if(i != states.size()-1)
            cout << ", ";
    }

    cout << endl;

    cout << "Suitable Soil Types : ";

    for(int i = 0; i < soilTypes.size(); i++)
    {
        cout << soilTypes[i];

        if(i != soilTypes.size()-1)
            cout << ", ";
    }

    cout << endl;

    cout << "Rainfall Range     : "
         << minRainfall << " - "
         << maxRainfall << " mm" << endl;

    cout << "Temperature Range  : "
         << minTemperature << " - "
         << maxTemperature << " °C" << endl;

    cout << "Soil pH           : "
         << minPH << " - "
         << maxPH << endl;
        
    cout << "Humidity Range     : "
         << minHumidity << " - "
         << maxHumidity << " %" << endl;

     cout << "Soil Moisture      : "
         << minMoisture << " - "
         << maxMoisture << " %" << endl;

    cout << "Water Requirement  : "
         << waterRequirement << endl;
                
    cout << "Yield Per Acre     : "
         << yieldPerAcre << " Quintals" << endl;

    cout << "Irrigation Method  : "
         << irrigationMethod << endl;

    cout << "Season            : " << season << endl;

    cout << "Recommended Fertilizers : ";

    for(int i = 0; i < fertilizers.size(); i++)
    {
        cout << fertilizers[i];

        if(i != fertilizers.size() - 1)
             cout << ", ";
    }

    cout << endl;

}

string Crop::getCropName() const
{
    return cropName;
}

vector<string> Crop::getStates()
{
    return states;
}

vector<string> Crop::getSoilTypes()
{
    return soilTypes;
}

int Crop::getMinRainfall()
{
    return minRainfall;
}

int Crop::getMaxRainfall()
{
    return maxRainfall;
}

int Crop::getMinTemperature()
{
    return minTemperature;
}

int Crop::getMaxTemperature()
{
    return maxTemperature;
}

double Crop::getMinPH()
{
    return minPH;
}

double Crop::getMaxPH()
{
    return maxPH;
}

double Crop::getMinHumidity()
{
    return minHumidity;
}

double Crop::getMaxHumidity()
{
    return maxHumidity;
}

double Crop::getMinMoisture()
{
    return minMoisture;
}

double Crop::getMaxMoisture()
{
    return maxMoisture;
}

string Crop::getWaterRequirement()
{
    return waterRequirement;
}

double Crop::getYieldPerAcre()
{
    return yieldPerAcre;
}

string Crop::getIrrigationMethod()
{
    return irrigationMethod;
}

string Crop::getSeason()
{
    return season;
}

vector<string> Crop::getFertilizers()
{
    return fertilizers;
}