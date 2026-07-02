#ifndef FARMER_H
#define FARMER_H
#include<iostream>
#include<string>
using namespace std;

class Farmer{
   private:
    string name;
    string state;
    string district;
    string season;
    string soilType;
    int rainfall;
    int temperature;
    double landArea;
    double soilPH;
    double humidity;
    double soilMoisture;
    string waterAvailability;

    public:
     void getDetails();
     void displayDetails();
     void setSoilPH(double ph);
     void setHumidity(double humidity);
     void setSoilMoisture(double moisture);
     void setWaterAvailability(string water);

    double getSoilPH();
    string getState();
    string getDistrict();
    string getSoilType();
    string getSeason();
    int getRainfall();
    int getTemperature();
    double getLandArea();
    double getHumidity();
    double getSoilMoisture();
    string getWaterAvailability();

};

#endif