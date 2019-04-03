//
//  main.cpp
//  Zajecia5
//
//  Created by Marcin Jurczyk on 26/03/2019.
//  Copyright © 2019 Marcin Jurczyk. All rights reserved.
//
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

// integral function
inline double f(double x){
    return (x*x*x)+2;
}

// p - lower band
// k - upper band
// n - precision
double integrateRectangle(double p, double k, unsigned int n){
    
    double result = 0;
    double dx = (k - p) / n;
    double x = p + dx;
    for (int i = 0; i < n; i++) {
        result += f(x);
        x += dx;
    }
    result = result * dx;
    
    return result;
}

double integrateTrapeze(double p, double k, unsigned int n){
    
    double result = 0;
    double dx = (k - p) / n;
    double x = p;
    for (unsigned int i = 0; i < n; i++) {
        result += ((f(x) + f(x + dx)) / 2 * dx);
        x += dx;
    }
    
    return result;
}

int main()
{
    
    double tabR[5], tabT[5];
    
    tabR[0] = integrateRectangle(1, 4, 1);
    tabR[1] = integrateRectangle(1, 4, 3);
    tabR[2] = integrateRectangle(1, 4, 10);
    tabR[3] = integrateRectangle(1, 4, 50);
    tabR[4] = integrateRectangle(1, 4, 200);
    
    tabT[0] = integrateTrapeze(1, 4, 1);
    tabT[1] = integrateTrapeze(1, 4, 3);
    tabT[2] = integrateTrapeze(1, 4, 10);
    tabT[3] = integrateTrapeze(1, 4, 50);
    tabT[4] = integrateTrapeze(1, 4, 200);
    
    cout << "N\t\t\t1\t\t\t3\t\t\t10\t\t\t50\t\t\t200\n";
    
    cout << "Rectangle\t";
    for (int i = 0; i < 5; i++)
    {
        cout << fixed;
        cout << setprecision(2);
        cout << tabR[i] << "\t\t";
    }
    
    cout << endl << "Trapeze\t\t";
    for (int i = 0; i < 5; i++)
    {
        cout << fixed;
        cout << setprecision(2);
        cout << tabT[i] << "\t\t";
    }
    
    // Save results to excel
    fstream plik;
    plik.open("tabela.xls", ios::out);
    if (plik.good() == true)
    {
        plik << "Rectangle" << "\t" << "Trpeze" << endl;
        for (int i = 0; i < 5; i++)
        {
            plik << fixed;
            plik << setprecision(2);
            plik << tabR[i];
            plik << "\t" << tabT[i] << endl;
        }
        
    }
    plik.close();
    
    cout << endl;

    return 0;
}
