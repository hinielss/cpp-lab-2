#include <iostream>
#include <fstream>
#include <random>
#include <math.h>
#include "logic.h"

using namespace std;

void writeDataForTestsToFile()
{
    ofstream file;
    file.open("tests.txt");
    if (file.is_open())
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dist(-15000, 15000);

        for (int i = 0; i < 1000; i++)
        {
            int r = dist(gen);
            double res = round(getResult(r)*1000000)/1000000;
            file << r << " " << res << endl;
        }
    }
    file.close(); 
    cout << "File has been written" << std::endl;
}


int main()
{
    writeDataForTestsToFile();
    int y;
    cout << "Enter y: ";
    cin >> y;
    double res = getResult(y);
    cout << "Result: " << res << "\n";
}
