#include "convolution.h"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;




vector<double> convolution(vector<double> v1, vector<double> v2, string strCase){

    vector<double> v3;
    // v1 size = 3;
    // v2 size = 7;
    // v2 is stationary while v1 moves across it
    int t = 0;
    double sum = 0;

    // Slide v1 accross v2.
    // multiple positions down then sum each part
    for ( int i = 0; i <= v2.size(); i++) {
        for ( int n = v1.size()-1; n >= 0; n--){
            if (i-t >= 0){
                sum += v1[n] * v2[i-t];
            }
            t+=1;
        }
        v3.push_back(sum);
        t = 0;
        sum = 0;
    }

    // Duplicated for loop outside of nested forloop but limiting the max size
    // Duplicated to save operation time in nested forloop to check if (i > v2.size()) {i--}
    for ( int n = v1.size()-1; n >= 0; n--){
            sum += v1[n] * v2[v2.size()-1];
    }
    v3.push_back(sum);
    sum = 0;

    // Return trimmed vectors according to option selected
    if (strCase == "all"){
        // If "all" is passed or nothing is passed return all
        return v3;
    } else if (strCase == "same"){
        // keep vector length the same as the v2, to do this I remove one from each end
        v3.erase(v3.begin());
        v3.erase(v3.end()-1);
        return v3;
    } else if (strCase == "valid"){
        // Keep the vector results where all of v1 was in v2, to do this I remove v1 size from the begining and end of v3.
        v3.erase(v3.begin(), v3.begin()+v1.size());
        v3.erase(v3.end()-v1.size(), v3.end());
        return v3;
    } else {
        return vector<double>();
    }
}

vector<double> convolution(vector<double> v1, vector<double> v2){
    return convolution(v1,v2, "all");
}