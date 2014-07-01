// There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

// You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

// Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

// Note:
// The solution is guaranteed to be unique.

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        assert(n == cost.size());
        
        int start = 0, cur = 0;
        int curGas = 0;
        int curLen = 0;
        while(true) {
            if(curLen == n) return start;
            if(curGas+gas[cur] < cost[cur]) {
                if((cur+1)%n <= start) break;
                start = (cur+1)%n;
                cur = start;
                curGas = 0;
                curLen = 0;
            } else {
                curGas += gas[cur]-cost[cur];
                cur = (cur+1)%n;
                ++curLen;
            }
        }
        return -1;
    }
};
