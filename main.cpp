#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;
struct Arrow{
	char input;
	char output;
	char direction;
	int nextState;
	void printArrow(){
		cout << input << " -> " << output 
				<< "|" << direction << endl;
		cout << "Next state: " << nextState  << endl;
	}
};
struct  State{
	int state, numArrow;
	string type = "Quit";
	struct Arrow* arrowOut[1000]; 
	void addArrow(char in, char out, char dir, int next){
		arrowOut[numArrow] = {new Arrow()};
		arrowOut[numArrow] -> input  = in;
		arrowOut[numArrow] -> output= out;
		arrowOut[numArrow] -> direction= dir;
		arrowOut[numArrow] -> nextState = next;
		++numArrow;
	}
	void printState(){
		cout << "State: " << state <<"		" << type << endl;
		if(numArrow == 0) cout << "No next state yet" << endl;
		else{
			for(int i = 0; i < numArrow; ++i){
				cout << (arrowOut[i] -> input) << " -> " << (arrowOut[i] -> output) 
					<< "|" << (arrowOut[i] -> direction) << endl;
				cout << "Next state: " << (arrowOut[i] -> nextState)  << endl;
			}
		}
	}
	Arrow* searchArrow(char in){
		for(int i = 0; i < numArrow; ++i){
			if(arrowOut[i] -> input == in) return arrowOut[i];
		}
		return new Arrow();
	}
};



int main (int argc, char*argv[]){
	State* list[1001];
	State* start = new State();
       	State* accept = new State();
	State* reject = new State();;
	State* temp;
	for(int i = 0; i < 1001; ++i){
		temp = new State();
		list[i] = {temp};
		list[i]->state = i;
	}
	string file, cmd, t, str;
	char in, out, dir;
	int indList, current, next;

	ifstream myfile (argv[1]);
	if(myfile.is_open()){
		while(!myfile.eof()){
			myfile >> cmd;
			if(cmd == "state"){
				++indList;
				myfile >> current;
				myfile >> t;
				list[current] -> type = t;
				if(t == "start") start = list[current];
				if(t == "accept") accept = list[current];
				if(t == "reject") reject = list[current];
			}
			if(cmd == "transition"){
				myfile >> current;
				myfile >> in;
				myfile >> next;
				myfile >> out;
				myfile >> dir;
				list[current] ->addArrow(in, out, dir, next);	
			}
		}
	}	
	myfile.close();
	str = argv[2];
	cout << str << endl;
	int limit = stoi(argv[3]);/*
	cin >> str;
	cin >> limit;
	cin >> limit;*/
	int indStr = str.length();
	int i, j, k;
	State* currentState = new State();
	Arrow* matchArrow = new Arrow();
	currentState = start;
	for(i = 0; i < 10; i++) list[i] -> printState();
	k = 0;
	i = 0;
	while((k < indStr) && (currentState != accept) && (currentState != reject) && (i < limit)){
		++i;
		cout << (currentState -> state) << " -> ";
		matchArrow = currentState -> searchArrow(str[k]);
		str[k] = matchArrow -> output;
		if(matchArrow -> direction == 'L') --k;
		if(matchArrow -> direction == 'R') ++k;
		currentState = list[matchArrow -> nextState];
	}
	cout << (currentState -> state) << "	" << (currentState -> type) << endl;
}
