#include "Farmer.h"

void Farmer::getDetails(){

cout<<"Enter Farmer Name: ";
getline(cin,name);

cout<<"Enter State: ";
getline(cin,state);

cout<<"Enter District: ";
getline(cin,district);

cout<<"Enter Soil Type: ";
getline(cin,soilType);

cout<<"Enter Rainfall (mm): ";
cin>>rainfall;

cout<<"Enter Temperature (°C): ";
cin>>temperature;

cout << "Enter Soil pH (0-14): ";
cin >> soilPH;

cout << "Enter Humidity (%): ";
cin >> humidity;

cout << "Enter Soil Moisture (%): ";
cin >> soilMoisture;

cin.ignore();

cout << "Water Availability (Low/Medium/High): ";
getline(cin, waterAvailability);

cout<<"Enter Season (Kharif/Rabi/Zaid): ";
getline(cin,season);

cout<<"Enter Land Area (Acres): ";
cin>>landArea;

}

void Farmer::displayDetails(){

    cout << "\nFarmer's Name : " << name << endl;
    cout << "State          : " << state << endl;
    cout << "Land Area      : " << landArea << "Acres" << endl;

}

void Farmer::setSoilPH(double ph)
{
    soilPH = ph;
}

void Farmer::setHumidity(double hum)
{
    humidity = hum;
}

void Farmer::setSoilMoisture(double moisture)
{
    soilMoisture = moisture;
}

void Farmer::setWaterAvailability(string water)
{
    waterAvailability = water;
}

string Farmer::getState(){

    return state;

}

string Farmer::getSoilType()
{
    return soilType;
}

int Farmer::getRainfall()
{
    return rainfall;
}

int Farmer::getTemperature()
{
    return temperature;
}

double Farmer::getSoilPH()
{
    return soilPH;
}

double Farmer::getHumidity()
{
    return humidity;
}

double Farmer::getSoilMoisture()
{
    return soilMoisture;
}

string Farmer::getWaterAvailability()
{
    return waterAvailability;
}

string Farmer::getSeason()
{
    return season;
}

double Farmer::getLandArea(){

    return landArea;

}