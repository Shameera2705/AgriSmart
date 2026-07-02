#ifndef CROP_H
#define CROP_H
#include<iostream>
#include<vector>
using namespace std;

class Crop{

    private:
      string cropName;
      vector<string> states;
      vector<string> soilTypes;
      int minRainfall;
      int maxRainfall;
      int minTemperature;
      int maxTemperature;
      double minPH;
      double maxPH;
      double minHumidity;
      double maxHumidity;
      double minMoisture;
      double maxMoisture;
      string waterRequirement;
      double yieldPerAcre;
      string irrigationMethod;
      string season;
      vector<string> fertilizers;
      

    public:
        void setCropName(string name);
        void addState(string state);
        void addSoilType(string soil);
        void setRainfall(int minRain, int maxRain);
        void setTemperature(int minTemp, int maxTemp);
        void setPH(double min, double max);
        void setHumidity(double min,double max);
        void setMoisture(double min,double max);
        void setWaterRequirement(string water);
        void setYield(double yield);
        void setIrrigationMethod(string method);
        void setSeason(string seasonName);
        void addFertilizer(string fertilizer);


        void displayCrop();

    string getCropName() const;
    vector<string> getStates();
    vector<string> getSoilTypes();
    int getMinRainfall();
    int getMaxRainfall();
    int getMinTemperature();
    int getMaxTemperature();
    double getMinPH();
    double getMaxPH();
    double getMinHumidity();
    double getMaxHumidity();
    double getMinMoisture();
    double getMaxMoisture();
    string getWaterRequirement();
    double getYieldPerAcre();
    string getIrrigationMethod();
    string getSeason();
    vector<string> getFertilizers();
    
};

#endif