// ChocolateProblem.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
using namespace std;

int main()
{
    int large = 150; // Bars Available 
    int medium = 120;
    int small = 700;
    double largeSalePrice = 30.05; // Bars Prices
    double mediumSalePrice = 25.99;
    double smallSalePrice = 10.50;
    int bigBarsUsed, mediumBarsUsed{}, smallBarsUsed = 0; // bars Used 
    int largeWeight = 5; // Weights of Bars 
    int mediumWeight = 3;
    int smallWeight = 1;
    int weight1 = 0; // Used weight by Big Bars
    int left1 = 0; // Remaining weight of chocolate after calculating with big bars 
    int weight2 = 0; // Used weight by Medium Bars
    int left2 = 0; // Remaining weight of chocolate after calculating with medium bars
    int weight3 = 0; // Used weight by Small Bars
    int left3 = 0; // Remaining weight of chocolate after calculating with small bars
    int weight = 0;
    float total = 0; // Total Price of  Order
    int remLarge = large; // Remaining Bars
    int remMedium = medium;
    int remSmall = small;
    int rem1 = 0;

    cout << "Please enter how many pounds of chocolate would you like:  " << endl;
    cin >> weight;

    bigBarsUsed = weight / largeWeight; // Calculating Big Bars that can be used
    weight1 = bigBarsUsed * 5; // Calculating the total weight used by big bars 
    left1 = weight - weight1; // Leftover weight

    if (bigBarsUsed < 150)
    {
        remLarge = large - bigBarsUsed; // Remaining Large Bars
    }
    else {
        if (weight1 > 1060) { cout << "Cannot Fulfill Order!"; return 1; }
        else { remLarge = 0; }
    }

    if (remMedium != 0) {
        if (left1 != 0) {
            mediumBarsUsed = left1 / mediumWeight;
            weight2 = mediumBarsUsed * 3;
            left2 = left1 - weight2;
            remMedium = medium - mediumBarsUsed;
            if (mediumBarsUsed > 120) { remMedium = 0; }
        }
    }
    else { return 1; }
    if (remSmall != 0) {
        if (left2 != 0)
        {
            smallBarsUsed = left2 / smallWeight; // Remaining Medium Bars
            weight3 = smallBarsUsed * 1;
            left3 = left2 - weight3;
            remSmall = smallBarsUsed - smallBarsUsed;
            if (smallBarsUsed > 700) {
                cout << "Order cannot be fullfilled for " << left3 << "pounds.";
                return 1;
            }
        }
    }
    else {
        cout << "Out of Small Bars! Cannot Fulfil order. ";
        return 1;
    }



    cout << "Big Bars Used: " << bigBarsUsed << " , " << "Medium Bars Used: " << mediumBarsUsed << " , " << "Small Bars Used: " << smallBarsUsed;
    total = (largeSalePrice * bigBarsUsed) + (mediumSalePrice * mediumBarsUsed) + (smallSalePrice * smallBarsUsed);
    cout << "\n Total Price: " << total << "$";
    cout << "\n Remaining Inventory - Large Bars: " << remLarge << ", Medium Bars: " << remMedium << " , Small Bars: " << remSmall;
    return 0;
}