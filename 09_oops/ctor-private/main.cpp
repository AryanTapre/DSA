#include<iostream>
using namespace std;

class Box {
    private:
        int width;
        Box(int _width) : width(_width) {}
    public:
        void getWidth() {
            cout<<this->width<<endl;
        }

    friend class BoxFactory;
};

class BoxFactory {
    private:
        int boxCount = 0;

    public:
        Box getBox(const int _width) {
            this->boxCount+=1;
            return  Box(_width);
        }

        void getBoxCount() {
            cout<<"box count is:"<<this->boxCount<<endl;
        }

};



int main() {

    BoxFactory* boxFactory = new BoxFactory();
    Box box1 = boxFactory->getBox(10);
    Box box2 = boxFactory->getBox(11);
    Box box3 = boxFactory->getBox(12);
    Box box4 = boxFactory->getBox(13);
    
    boxFactory->getBoxCount();
    box1.getWidth();

return 0;
}