#pragma once

#include "ofMain.h"


class CAdata{
public:
	
	
	virtual void setup(...){};
	virtual void update(){};
	virtual vector<int>* get(){};
	virtual void set(...){};
	
	
	vector<int>	currentGrid, nextGrid, rules;
	ofPoint		dim;
	unsigned int numcells, numbit, rule;
	bool		countSelf;

	
	 void setRules() {
//		 cout << " rule bin: ";
		for (int i = 0; i < numbit; i++) {
			rules[i] =  (int) ofRandom(2);//>1?true:false;
//			cout << " " << ofToString(rules[i]);
		}
//		 cout << endl;

		 setCenter1();
		 
		 unsigned int num = 0;
		 for (int i = 0; i < numbit; i++) {
			 if (rules[i] == 1)
				 num |= (1 << i);
		 }

		 rule = num;
		 
		 
	}
	
	 void setRule(int rule) {
		setRules(rule);
	}
	
	 void setRules(int rule) {
		 this->rule = rule;
		 int num = rule;
		
		for (int i = 0; i < rules.size(); i++) {
			int rem = num % 2;
			num = num / 2;
			rules[i] = rem;//>0?true:false;
		}
	}
	
	 int getRule() {
		 return rule;
	}
	
	
	
	virtual void setCenter1() {

	}
	
	void setNumBits(int nbits) {
			numbit = nbits;// 10 * 3;		 
			rules.assign(nbits, true);
			setRules();
			setCenter1();
	}
	
	

};