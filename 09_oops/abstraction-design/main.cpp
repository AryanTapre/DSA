#include<iostream>
#include "animal.h"
using namespace std;

void birdDoesSometing (Bird* &bird) {
    bird->eat();
    bird->speak();
    bird->fly();
}


int main() {

    Bird* bird = new Sparrow();
    birdDoesSometing(bird);

return 0;
}