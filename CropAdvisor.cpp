#include "CropAdvisor.h"
#include <algorithm>
#include <cctype>

bool compareRecommendation(Recommendation a, Recommendation b)
{
    if(a.score != b.score)
        return a.score > b.score;

    return a.crop.getYieldPerAcre() > b.crop.getYieldPerAcre();
}

string toLowerCase(string str)
{
    for(int i = 0; i < str.length(); i++)
    {
        str[i] = tolower(str[i]);
    }

    return str;
}

// Helper function to add a crop
void CropAdvisor::addCrop(string name,
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
                          vector<string> fertilizers)
{
    Crop crop;

    crop.setCropName(name);

    // Add States
    for(int i = 0; i < states.size(); i++)
    {
        crop.addState(states[i]);
    }

    // Add Soil Types
    for(int i = 0; i < soilTypes.size(); i++)
    {
        crop.addSoilType(soilTypes[i]);
    }

    // Set Crop Details
    crop.setRainfall(minRain, maxRain);
    crop.setTemperature(minTemp, maxTemp);
    crop.setPH(minPH, maxPH);
    crop.setHumidity(minHumidity,maxHumidity);
    crop.setMoisture(minMoisture,maxMoisture);
    crop.setWaterRequirement(waterRequirement);
    crop.setSeason(season);
    crop.setYield(yield);
    crop.setIrrigationMethod(irrigation);

    // Add Fertilizers
    for(int i = 0; i < fertilizers.size(); i++)
    {
        crop.addFertilizer(fertilizers[i]);
    }

    // Store Crop
    crops.push_back(crop);
}

// Load all crops
void CropAdvisor::loadCropDatabase()
{
addCrop(
    "Cotton",
    {"Andhra Pradesh","Telangana","Maharashtra","Gujarat"},
    {"Black","Loamy"},
    600,900,
    20,35,
    6.0,7.5,
    50,70,
    40,60,
    "Medium",
    "Kharif",
    18,
    "Drip",
    {"Urea","DAP","Potash"}
);

addCrop(
    "Rice",
    {"Andhra Pradesh","Punjab","West Bengal","Odisha"},
    {"Clay","Loamy"},
    1000,2000,
    20,35,
    5.5,6.5,
    70,90,
    80,100,
    "High",
    "Kharif",
    35,
    "Flood",
    {"Urea","DAP","NPK"}
);

addCrop(
    "Wheat",
    {"Punjab","Haryana","Uttar Pradesh","Madhya Pradesh"},
    {"Loamy","Clay"},
    500,800,
    10,25,
    6,7.5,
    40,60,
    35,55,
    "Medium",
    "Rabi",
    22,
    "Sprinkler",
    {"Urea","DAP","Potash"}
);

addCrop(
    "Maize",
    {"Andhra Pradesh","Telangana","Karnataka","Bihar"},
    {"Loamy","Black"},
    500,800,
    18,32,
    5.8,7,
    50,70,
    45,65,
    "Medium",
    "Kharif",
    28,
    "Sprinkler",
    {"Urea","DAP","Zinc Sulphate"}
);

addCrop(
    "Groundnut",
    {"Andhra Pradesh","Telangana","Gujarat","Tamil Nadu"},
    {"Red","Sandy"},
    500,700,
    20,30,
    6.0,6.8,
    50,65,
    35,55,
    "Low",
    "Kharif",
    15,
    "Drip",
    {"Gypsum","DAP","Urea"}
);

addCrop(
    "Sugarcane",
    {"Uttar Pradesh","Maharashtra","Karnataka","Tamil Nadu"},
    {"Loamy","Black"},
    1000,1500,
    20,38,
    6.5,7.5,
    70,90,
    70,90,
    "High",
    "Annual",
    400,
    "Drip",
    {"Urea","Potash","DAP"}
);

addCrop(
    "Soybean",
    {"Madhya Pradesh","Maharashtra","Rajasthan"},
    {"Black","Loamy"},
    600,1000,
    20,30,
    6.0,7.0,
    55,75,
    45,65,
    "Medium",
    "Kharif",
    12,
    "Sprinkler",
    {"Rhizobium","DAP","Potash"}
);

addCrop(
    "Ragi",
    {"Karnataka","Tamil Nadu","Andhra Pradesh"},
    {"Red","Loamy"},
    500,900,
    18,28,
    5.5,7.0,
    50,70,
    35,55,
    "Low",
    "Kharif",
    12,
    "Sprinkler",
    {"Urea","DAP"}
);

addCrop(
    "Bajra",
    {"Rajasthan","Gujarat","Haryana"},
    {"Sandy","Loamy"},
    300,600,
    25,35,
    5.5,7.5,
    35,55,
    25,45,
    "Low",
    "Kharif",
    10,
    "Sprinkler",
    {"Urea","DAP"}
);

addCrop(
    "Jowar",
    {"Maharashtra","Karnataka","Telangana"},
    {"Black","Red"},
    400,700,
    25,35,
    5.8,7.5,
    40,60,
    30,50,
    "Low",
    "Kharif",
    14,
    "Sprinkler",
    {"Urea","DAP"}
);

addCrop(
    "Chickpea",
    {"Madhya Pradesh","Rajasthan","Uttar Pradesh"},
    {"Loamy","Clay"},
    400,700,
    15,25,
    6.0,7.5,
    35,55,
    25,45,
    "Low",
    "Rabi",
    11,
    "Drip",
    {"Rhizobium","DAP"}
);

addCrop(
    "Mustard",
    {"Rajasthan","Haryana","Punjab"},
    {"Loamy","Sandy"},
    300,500,
    10,25,
    6.0,7.5,
    40,60,
    30,50,
    "Low",
    "Rabi",
    9,
    "Sprinkler",
    {"Urea","Sulphur"}
);

addCrop(
    "Tur",
    {"Maharashtra","Karnataka","Telangana"},
    {"Black","Red"},
    600,1000,
    20,35,
    6.0,7.5,
    50,70,
    35,55,
    "Medium",
    "Kharif",
    8,
    "Drip",
    {"Rhizobium","DAP"}
);

addCrop(
    "Green Gram",
    {"Rajasthan","Andhra Pradesh","Karnataka"},
    {"Sandy","Loamy"},
    400,700,
    25,35,
    6.2,7.2,
    50,70,
    35,55,
    "Medium",
    "Zaid",
    7,
    "Sprinkler",
    {"Rhizobium","DAP"}
);

addCrop(
    "Black Gram",
    {"Andhra Pradesh","Tamil Nadu","Madhya Pradesh"},
    {"Black","Loamy"},
    600,800,
    25,35,
    6.0,7.5,
    50,70,
    35,55,
    "Medium",
    "Kharif",
    8,
    "Sprinkler",
    {"Rhizobium","DAP"}
);

addCrop(
    "Tomato",
    {"Karnataka","Andhra Pradesh","Maharashtra"},
    {"Loamy","Sandy"},
    600,1000,
    18,30,
    6.0,6.8,
    60,80,
    60,75,
    "Medium",
    "Year-round",
    120,
    "Drip",
    {"NPK","Urea"}
);

addCrop(
    "Potato",
    {"Uttar Pradesh","Punjab","West Bengal"},
    {"Loamy"},
    500,700,
    15,25,
    5.2,6.5,
    60,80,
    60,80,
    "Medium",
    "Rabi",
    80,
    "Sprinkler",
    {"Potash","Urea"}
);

addCrop(
    "Onion",
    {"Maharashtra","Karnataka","Gujarat"},
    {"Loamy","Sandy"},
    500,800,
    15,30,
    6.0,7.0,
    50,70,
    50,70,
    "Medium",
    "Rabi",
    100,
    "Drip",
    {"Urea","Potash"}
);

addCrop(
    "Chilli",
    {"Andhra Pradesh","Telangana","Karnataka"},
    {"Black","Red"},
    600,1000,
    20,30,
    6.0,7.0,
    60,80,
    50,70,
    "Medium",
    "Kharif",
    20,
    "Drip",
    {"Potash","Urea"}
);

addCrop(
    "Watermelon",
    {"Andhra Pradesh","Telangana","Karnataka","Maharashtra","Tamil Nadu"},
    {"Sandy","Sandy Loam","Loamy"},
    400,800,
    22,35,
    6.0,6.8,
    45,60,
    35,50,
    "Low",
    "Zaid",
    120,
    "Drip",
    {"Urea","DAP","Potash"}
);
}

void CropAdvisor::recommendCrop(Farmer farmer)
{
    string state = toLowerCase(farmer.getState());
    string soil = toLowerCase(farmer.getSoilType());
    int rainfall = farmer.getRainfall();
    int temperature = farmer.getTemperature();
    double soilPH = farmer.getSoilPH();
    double humidity=farmer.getHumidity();
    double moisture=farmer.getSoilMoisture();
    string water=toLowerCase(farmer.getWaterAvailability());
    string season = toLowerCase(farmer.getSeason());
    double landArea = farmer.getLandArea();

    vector<Recommendation> recommendations;

        for(int i=0;i<crops.size();i++)
    {
        int score = 0;
        vector<string> reasons;

        vector<string> cropStates = crops[i].getStates();

        for(int j=0;j<cropStates.size();j++)
        {
            if(state == toLowerCase(cropStates[j]))
            {
                score += 20;
                reasons.push_back("Suitable for your state");
                break;
            }
        }

        vector<string> cropSoils = crops[i].getSoilTypes();

        for(int j=0;j<cropSoils.size();j++)
        {
            if(soil == toLowerCase(cropSoils[j]))
            {
                score += 25;
                reasons.push_back("Suitable soil type");
                break;
            }
        }

        int minRain = crops[i].getMinRainfall();
        int maxRain = crops[i].getMaxRainfall();

        if(rainfall >= minRain && rainfall <= maxRain)
        {
            score += 20;
            reasons.push_back("Ideal rainfall");
        }
        else if(rainfall >= minRain - 100 &&
            rainfall <= maxRain + 100)
        {
       score += 10;
        reasons.push_back("Rainfall is close to ideal");
        }

        int minTemp = crops[i].getMinTemperature();
        int maxTemp = crops[i].getMaxTemperature();

        if(temperature >= minTemp &&
        temperature <= maxTemp)
        {
            score += 15;
            reasons.push_back("Ideal temperature");
        }
        else if(temperature >= minTemp - 3 &&
            temperature <= maxTemp + 3)
        {
            score += 8;
            reasons.push_back("Temperature is acceptable");
        }

        double minPH = crops[i].getMinPH();
        double maxPH = crops[i].getMaxPH();

        if(soilPH >= minPH && soilPH <= maxPH)
        {
            score += 15;
            reasons.push_back("Ideal soil pH");
        }   
        else if(soilPH >= minPH - 0.5 &&
            soilPH <= maxPH + 0.5)
        {   
        score += 8;
        reasons.push_back("Acceptable soil pH");
        }

        double minHumidity = crops[i].getMinHumidity();
        double maxHumidity = crops[i].getMaxHumidity();

        double minMoisture = crops[i].getMinMoisture();
        double maxMoisture = crops[i].getMaxMoisture();

        if(humidity>=minHumidity && humidity<=maxHumidity)
        {
        score+=10;
        reasons.push_back("Ideal humidity");
        }

         if(moisture>=minMoisture && moisture<=maxMoisture)
        {
            score+=10;
            reasons.push_back("Ideal soil moisture");
        }

        if(water== toLowerCase(crops[i].getWaterRequirement()))
        {
            score+=10;
            reasons.push_back("Suitable water availability");
        }
        if(season == toLowerCase(crops[i].getSeason()))
        {
            score += 20;
            reasons.push_back("Best season for cultivation");
        }

       Recommendation temp;

        temp.crop = crops[i];
        temp.score = score;
        temp.reasons = reasons;

        recommendations.push_back(temp);
    }
        sort(recommendations.begin(),
            recommendations.end(),
            compareRecommendation);
     displayRecommendation(recommendations, landArea);
    }

void CropAdvisor::displayRecommendation(
    vector<Recommendation> recommendations,
    double landArea)
{
    cout << "\n==============================\n";
    cout << " AGRISMART RECOMMENDATIONS\n";
    cout << "==============================\n";

    for(int i = 0;
        i < 3 && i < recommendations.size();
        i++)
    {
        cout << "\nRecommendation "
             << i + 1
             << endl;

        cout << "Crop : "
             << recommendations[i].crop.getCropName()
             << endl;

        cout << "Compatibility : "
             << (recommendations[i].score * 100)/145
             << "%"
             << endl;

        cout << "\nReason for Recommendation:\n";

        for(int j = 0;
            j < recommendations[i].reasons.size();
            j++)
        {
            cout << "- "
                 << recommendations[i].reasons[j]
                 << endl;
        }

        cout << "Yield : "
             << recommendations[i].crop.getYieldPerAcre()
             << " Quintals/Acre"
             << endl;

        double expectedProduction =
            landArea *
            recommendations[i].crop.getYieldPerAcre();

        cout << "Land Area : "
             << landArea
             << " Acres"
             << endl;

        cout << "Expected Production : "
             << expectedProduction
             << " Quintals"
             << endl;

        cout << "Season : "
             << recommendations[i].crop.getSeason()
             << endl;

        cout << "Irrigation : "
             << recommendations[i].crop.getIrrigationMethod()
             << endl;

        cout << "Fertilizers : ";

        vector<string> fertilizers =
            recommendations[i].crop.getFertilizers();

        for(int j = 0;
            j < fertilizers.size();
            j++)
        {
            cout << fertilizers[j];

            if(j != fertilizers.size() - 1)
                cout << ", ";
        }

        cout << "\nWater Requirement : "
            << recommendations[i].crop.getWaterRequirement()
            << endl;

        cout << "\n";
    }
}

   void CropAdvisor::displayAllCrops()
{
    cout << "\n=====================================\n";
    cout << "         ALL AVAILABLE CROPS\n";
    cout << "=====================================\n";

    for(int i = 0; i < crops.size(); i++)
    {
        cout << "\nCrop " << i + 1 << endl;
        cout << "--------------------------" << endl;

        crops[i].displayCrop();

        cout << endl;
    }
}


void CropAdvisor::searchCrop(string cropName)
{
    cropName = toLowerCase(cropName);

    for(int i = 0; i < crops.size(); i++)
    {
        if(toLowerCase(crops[i].getCropName()) == cropName)
        {
            cout << "\nCrop Found\n";
            cout << "=====================\n";

            crops[i].displayCrop();

            return;
        }
    }

    cout << "\nCrop Not Found!\n";
}
    