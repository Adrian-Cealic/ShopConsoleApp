#pragma once
#ifndef CUPON_H
#define CUPON_H

#include <iostream>
#include <map>
#include <string>
#include <cctype> 
#include <algorithm> 

using namespace std;

// Converts a string to uppercase
string toUpperCase(const string& str) {
    string upperStr = str;
    transform(upperStr.begin(), upperStr.end(), upperStr.begin(), ::toupper);
    return upperStr;
}

// Map for promo codes
map<string, float> promoCodes{
    {"SUMMER10", 0.10f},
    {"WELCOME15", 0.15f},
    {"DISCOUNT20", 0.20f},
    {"FREESHIP", 0.20f},
    {"VIP25", 0.25f}
};

#endif
