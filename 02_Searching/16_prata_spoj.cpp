// PRATA SPOJ
// spoj.com/problems/PRATA
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
 
bool canCook(int prata, vector<int> ranks, int time) { // time complexity : O(N*prata)
 
    int currrentPrata = 1;
    int prataCooked = 0;
    int timeSum = 0;

    for(int i=0; i<ranks.size(); i++) {
        while(currrentPrata <= prata) {
            timeSum += currrentPrata*ranks[i];

            if(timeSum <= time) {
                prataCooked++;
                if(prataCooked == prata) {
                    return true;
                }
            }
            else {
                timeSum = 0;
                currrentPrata = 1;
                break;
            }
            currrentPrata++;
        }
    }
    return false;
}


int maxTimeToCook(int prata, vector<int> ranks) { // time complexity :  O(N)
    int highestRank = *max_element(ranks.begin(), ranks.end()); // O(N)
    return highestRank * (prata * (prata + 1)) / 2;
}

int cookPrata(int prata, vector<int> &ranks) {
    int start = 0;
    int end = maxTimeToCook(prata,ranks); // time complexity : O(N)
    int time = -1;
    int mid;

    while(start <= end) { // Log x => Maximum time taken to cook prata's
        mid = start + (end-start)/2;
        if(canCook(prata,ranks,mid)) {
            time = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }                           // FIXME: Total time complexity => O(N) + O(Log x * N*prata)
                                    //                                 O(N) + O(log XNP)
                                    //                                 O(log XNP) times

                                    //        Total space complexity => O(1)
    }
    return time;
}

int main() {
 
    int T;
    cin>>T;

    while(T--) {
        int np,nc;
        cin>>np>>nc;
        vector<int> ranks;

        while(nc--) {
            int R;
            cin>>R;
            ranks.push_back(R);
        }
        cout<<cookPrata(np,ranks)<<endl;
    }


    // vector<int> ranks = {1,1,1,1,1,1,1,1};
    // int prata = 8;

    // cout<<cookPrata(prata,ranks);

return 0;
}