#include <iostream>
#include <vector>
#include <limits>
#include <unordered_map>

using namespace std;

int maxPoints(vector<vector<int>>& points) {
    int n = points.size();
    if (n <= 1) return n;
    
    int ans = 0;
    unordered_map<double, int> slopeMap;
    
    for (int i = 0; i < n; i++) {
        slopeMap.clear();
        int duplicate = 0, maxCount = 0;
        
        for (int j = i + 1; j < n; j++) {
            int y = points[j][1] - points[i][1];
            int x = points[j][0] - points[i][0];
            
            double slope;
            if (x == 0) {
                slope = numeric_limits<double>::infinity();
            } else {
                slope = (double)y / x;
            }

            slopeMap[slope]++;
            maxCount = max(maxCount, slopeMap[slope]);
        }
        
        ans = max(ans, maxCount);
    }
    
    return ans + 1;
}

// Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).
double myPow(double x, int n) {
    long long N = n;
    if (N < 0) {
        x = 1 / x;
        N = -N;
    }
    
    double result = 1.0;
    while (N) {
        if (N % 2 == 1) {
            result *= x;
        }
        x *= x;
        N /= 2;
    }
    return result;
}