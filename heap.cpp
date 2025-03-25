#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    int n = profits.size();
    vector<pair<int, int>> projects;
    
    for (int i = 0; i < n; ++i) {
        projects.emplace_back(capital[i], profits[i]);
    }
    
    sort(projects.begin(), projects.end());
    
    priority_queue<int> maxHeap;
    int i = 0;
    
    while (k--) {
        while (i < n && projects[i].first <= w) {
            maxHeap.push(projects[i].second);
            ++i;
        }

        if (maxHeap.empty()) break;

        w += maxHeap.top();
        maxHeap.pop();
    }
    
    return w;
}


class MedianFinder {
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>>minheap;
public:
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
    
       if (maxheap.empty() || num <= maxheap.top()) {
            maxheap.push(num);
        } else {
            minheap.push(num);
        }

        // Rebalance the heaps if necessary to maintain size property
        if (maxheap.size() > minheap.size() + 1) {
            minheap.push(maxheap.top());
            maxheap.pop();
        } else if (minheap.size() > maxheap.size()+1) {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() {
        if ((maxheap.size() + minheap.size()) % 2 == 0) {
            // Even number of elements
            return (maxheap.top() + minheap.top()) / 2.0;
        } else {
            // Odd number of elements
             if(minheap.size()>maxheap.size()){
                return minheap.top();
            }
            else{
                return maxheap.top();
            }
        }
    }
};


int main() {
    vector<int> profits = {1, 2, 3};
    vector<int> capital = {0, 1, 1};
    int k = 2, w = 0;
    
    cout << "Maximized Capital: " << findMaximizedCapital(k, w, profits, capital) << endl;

    MedianFinder mf;
    mf.addNum(2);
    mf.addNum(3);
    cout << "Median: " << mf.findMedian() << endl; // Output: 2.5
    mf.addNum(4);
    cout << "Median: " << mf.findMedian() << endl; // Output: 3
    
    return 0;
}