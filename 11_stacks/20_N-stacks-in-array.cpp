// implement N stacks in Single Array...

#include<iostream>
using namespace std;

/*
    PUSH - Algo
index = free-spot
if(index ==-1) return
free-spot = next[index]
next[index] = top[k-1]
top[k-1] = index
main[top[k-1]] = data

*/

/**         
    POP - Algo
index= top[k-1]
if(index == -1) return
data = main[top[k-1]]
top[k-1] = next[index]
next[index] = index+1
free-spot = index
 * 
 */


class NStacks {
    private:
        int n,k;
        int *main, *top, *next;
        int freespot;

    public:
        NStacks(int _n, int _k) : n(_n), k(_k) {
            main = new int[this->n];
            top = new int[this->k];
            next = new int[this->n];
            this->freespot = 0;

            for(int i=0; i<this->k; ++i) {
                this->top[i] = -1;
            }

            for(int i=0; i<this->n; ++i) {
                this->next[i] = i + 1;
            }
            this->next[n-1] = -1;
        }

        bool push(int data, int k) {
            int index = this->freespot;
            if(index  == -1) return false;

            this->freespot = this->next[index];
            this->next[index] = this->top[k-1];
            this->top[k-1] = index;
            this->main[this->top[k-1]] = data;

            return true;
        }

        int pop(int k) {
            int index = this->top[k-1];
            if(index == -1) return -1;

            int poppedElement = this->main[this->top[k-1]];
            this->top[k-1] = this->next[index];
            this->next[index] = index + 1;
            this->freespot = index;
            
            return poppedElement;
        }
};

int main() {

    NStacks * st = new NStacks(9,4);

    cout<<"pushed : "<<st->push(10,1)<<endl;
    cout<<"pushed : "<<st->push(11,1)<<endl;
    cout<<"pushed : "<<st->push(12,1)<<endl;
    cout<<"pushed : "<<st->push(13,1)<<endl;
    cout<<"pushed : "<<st->push(14,1)<<endl;
    cout<<"pushed : "<<st->push(15,1)<<endl;
    cout<<"pushed : "<<st->push(16,1)<<endl;
    cout<<"pushed : "<<st->push(17,1)<<endl;
    cout<<"pushed : "<<st->push(18,1)<<endl;

    cout<<"pushed : "<<st->push(18,1)<<endl;

    cout<<"pop: "<<st->pop(1)<<endl;
    cout<<"pop: "<<st->pop(1)<<endl;
    cout<<"pop: "<<st->pop(1)<<endl;
    cout<<"pop: "<<st->pop(1)<<endl;
    cout<<"pop: "<<st->pop(1)<<endl;
    cout<<"pop: "<<st->pop(1)<<endl;
    cout<<"pop: "<<st->pop(1)<<endl;
    cout<<"pop: "<<st->pop(1)<<endl;
    
    cout<<"pop: "<<st->pop(1)<<endl;

    cout<<"pop: "<<st->pop(1)<<endl;

    


return 0;
}