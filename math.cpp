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