// car fleet
// leetcode 853

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

class Car {
    public:
        int pos;
        int speed;

        Car(int _pos, int _speed): pos(_pos), speed(_speed) {}
};

bool myComp(Car &A, Car &B) {
    return A.pos < B.pos;
}

int carFleet(int target, vector<int> &position, vector<int> &speed) {
    vector<Car> cars;
    for(int i=0; i<position.size(); ++i) {
        Car car(position[i], speed[i]);
        cars.push_back(car);
    }
    
    sort(cars.begin(), cars.end(), myComp);

    stack<float> st;
    for(auto car: cars) {
        float time = (target - car.pos) / ((float)car.speed);
        while(!st.empty() && time >= st.top()) {
            st.pop();
        }
        st.push(time);
    }
    return st.size();
}

int main() {

    int target = 12;
    vector<int> speed = {2,4,1,1,3};
    vector<int> position = {10,8,0,5,3};

    cout<<"car fleet => "<<carFleet(target, position, speed)<<endl;


return 0;
}