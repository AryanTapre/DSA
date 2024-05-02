#include<string.h>
#include<iostream>
using namespace std;
 
void reverse(char data[]) {
	int size = strlen(data);
	int i = 0, j = size - 1;
	
	while(i < j) {
		if(data[i] == data[j] || i == j) {
			i++;
			j--;
			continue;
		}
		swap(data[i], data[j]);
		i++;
		j--;
	}
}

int main() {
 
	char data[1000];
	cout<<"enter data:"<<endl;
	cin.getline(data,1000);
	reverse(data);

	cout<<endl<<"reverse is:"<<data<<endl;

return 0;
}