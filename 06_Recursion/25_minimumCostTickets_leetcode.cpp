// leetcode 983

#include<iostream>
#include<algorithm>
using namespace std;

int getPassExpiry(int dayOfJourney, int passValidDays) {
    return (dayOfJourney + passValidDays) - 1;
}

int mincostTicketsRE(vector<int>& days, vector<int>& costs, int i) {
        if(i >= days.size()) return 0;

        // 1 day pass taken..
        int ans1 = costs[0] + mincostTicketsRE(days, costs, i+1);

        // 7 days pass Taken..
        int passExpiryDay = getPassExpiry(days[i], 7);
        int j = i;
        while(j< days.size() && days[j] <= passExpiryDay) {j++;}
        int ans7 = costs[1] + mincostTicketsRE(days, costs,j);

        // 30 days pass taken
        passExpiryDay = getPassExpiry(days[i], 30);
        j = i;
        while(j< days.size() && days[j] <= passExpiryDay) {j++;}
        int ans30 = costs[2] + mincostTicketsRE(days, costs,j);     

        return min(ans1, min(ans7, ans30));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) { 
        return mincostTicketsRE(days,costs,0);
    }

int main() {

return 0;
}