#include <iostream>
#include "Farmer.h"
#include "CropAdvisor.h"

using namespace std;

int main()
{
    CropAdvisor advisor;
    advisor.loadCropDatabase();

    int choice;

    do
    {
        cout << "\n=====================================\n";
        cout << "         AGRISMART SYSTEM\n";
        cout << "=====================================\n";
        cout << "1. Recommend Crop\n";
        cout << "2. View All Crops\n";
        cout << "3. Search Crop\n";
        cout << "4. Exit\n";
        cout << "Enter your choice : ";
        cin >> choice;

        cin.ignore();
        switch(choice)
        {
            case 1:
            {
                Farmer farmer;
                farmer.getDetails();
                advisor.recommendCrop(farmer);
                break;
            }

            case 2:
            {
                advisor.displayAllCrops();
                break;
            }

            case 3:
            {
                string cropName;
                cin.ignore();

                cout << "Enter Crop Name : ";
                getline(cin, cropName);

                advisor.searchCrop(cropName);
                break;
            }

            case 4:
            {
                cout << "\nThank you for using AgriSmart!\n";
                break;
            }

            default:
            {
                cout << "\nInvalid Choice!\n";
            }
        }

    }while(choice != 4);

    return 0;
}