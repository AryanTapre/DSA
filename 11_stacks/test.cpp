#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

    double canCollide(int &i, vector<vector<int>> &cars) {
        double time = -1;

        cout<<cars[i].at(1)<<endl;
        cout<<cars[i+1].at(1)<<endl;

        if(cars[i].at(1) >= cars[i+1].at(1)) {
            double d = cars[i+1].at(0) - cars[i].at(0);
            double speed = cars[i].at(1) - cars[i+1].at(1);
            time = d / speed;
            return time;
        }
        return time;
    }

    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        vector<double> ans;
        ans.push_back(-1);
        if(cars.size() == 1) {
            cout<<"inside if"<<endl;
            return ans;
        }

        cout<<"here"<<cars.size()<<endl;


        for(int i=cars.size()-2; i>=0; --i) {
               cout<<"return time is: "<<time<<endl;
            double time = canCollide(i,cars);
         
            if(time != -1){
                ans.push_back(time);
            }else {
                ans.push_back(time);
            }
        }
        return ans;
    }

int main() {

    vector<vector<int>> v = {{3,4},{5,4},{6,3},{9,1}};

   vector<double> ans = getCollisionTimes(v);

   for(auto i : ans) cout<<i<<" ";

   cout<<endl;

    double time = 2/0;
    cout<<"yes "<<time<<endl;


return 0;
}
