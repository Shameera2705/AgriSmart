#ifndef CROPADVISOR_H
#define CROPADVISOR_H

#include <iostream>
#include <vector>

#include "Crop.h"
#include "Farmer.h"

using namespace std;

struct Recommendation
{
    Crop crop;
    int score;
    vector<string> reasons;
};

class CropAdvisor
{
private:
    vector<Crop> crops;

    
    void addCrop(string name,
                 vector<string> states,
                 vector<string> soilTypes,
                 int minRain,
                 int maxRain,
                 int minTemp,
                 int maxTemp,
                 double minPH,
                 double maxPH,
                 double minHumidity,
                 double maxHumidity,
                 double minMoisture,
                 double maxMoisture,
                 string waterRequirement,
                 string season,
                 double yield,
                 string irrigation,
                 vector<string> fertilizers);
    void displayRecommendation(vector<Recommendation> recommendations,
                               double landArea);

public:

    void loadCropDatabase();

    void recommendCrop(Farmer farmer);
    void displayAllCrops();
    void searchCrop(string cropName); 
};

#endif