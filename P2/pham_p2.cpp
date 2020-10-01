#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;
struct Gate{
	string name;
	int m;
	char dir;
};

int main( int argc, char* argv[]){
	Gate* gate[8];
	for(int i = 0; i < 8; ++i){
		gate[i] = new Gate();
	}
	string input, side;
	Gate* current = new Gate();	
	cout << "Enter your input here (or 'Q' to quit): ";
	cin >> side;	
	while(side != "Q"){
		cin >> input;
		int count = input.length();
		int index ;
		cout << side;
		for(int i = 0; i < count ; ++i){
			for(int j = 0; j < 4 ; ++j){
				gate[j] -> dir = side[j];
			}
			current = gate[0];
			if(input[i] == '0'){
				if(current == gate[0]){
					char temp = current -> dir;
					if(temp == 'L'){
						gate[0] -> dir = 'R';
						current = gate[1];
					}
					else if(temp == 'R'){
						gate[0] -> dir = 'C';
						current = gate[3];
					}
					else if(temp = 'C'){
						gate[0] -> dir = 'L';
						current = gate[2];
					}	
				}

			}
			else if(input[i] == '1'){
				if(current == gate[0]){
					char temp = current -> dir;
					if(temp == 'L'){
						gate[0] -> dir = 'C';
						current = gate[1];
					}
					else if(temp == 'R'){
						gate[0] -> dir = 'L';
						current = gate[3];
					}
					else if(temp = 'C'){
						gate[0] -> dir = 'R';
						current = gate[2];
					}
				}	

			}		
			if(current == gate[1]){
				char temp = current -> dir;
				if(temp == 'L'){
					gate[1] -> dir = 'R';
					current = gate[4];
				}
				if(temp == 'R'){
					gate[1] -> dir = 'L';
					current = gate[5];
				}
			}
			if(current == gate[2]){
				char temp = current -> dir;
				if(temp == 'L'){
					gate[2] -> dir = 'R';
					current = gate[5];
				}
				if(temp == 'R'){
					gate[2] -> dir = 'L';
					current = gate[6];
				}
			}
			if(current == gate[3]){
				char temp = current -> dir;
				if(temp == 'L'){
					gate[3] -> dir = 'R';
					current = gate[6];
				}
				if(temp == 'R'){
					gate[3] -> dir = 'L';
					current = gate[7];
				}
			}
			for(int k = 0; k < 4; ++k){
				side[k] = gate[k] -> dir;
			}
			cout << " -> " << side;

		}
		cout << '\t';
		if(current == gate[4]) cout << 'B';
		else if(current == gate[5]) cout << 'C';
		else if(current == gate[6]) cout << 'D';
		else if(current == gate[7]) cout << 'E';
		cout << endl;	
		cout << "Enter your input here (or 'Q' to quit): ";
		cin >> side;	
	}
	return 0;
}
