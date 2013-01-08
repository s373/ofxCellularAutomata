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

	
	 void setRules() {
		for (int i = 0; i < numbit; i++) {
			rules[i] =  (int) ofRandom(2);
		}

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
			rules[i] = rem;
		}
	 }
	
	 int getRule() {
		 return rule;
	 }
	
	void setBinaryRule(vector<int> & binrules) {
		for (int i = 0; i < binrules.size(); i++) {
			rules[i] = binrules[i];
		}
	}
	

	vector<int> & getBinaryRule() {
		return rules;
	}

	string getBinaryRuleString() {
		string r="";
		for (int i = 0; i < rules.size(); i++) {
			r += ofToString(rules[i]);
		}
		return r;
	}
	
	
	
	virtual void setCenter1() {

	}
	
	void setNumBits(int nbits) {
			numbit = nbits;// 10 * 3;		 
			rules.assign(nbits, true);
			setRules();
			setCenter1();
	}
	
	void clear(){
		for(int i=0; i<currentGrid.size();i++){
			currentGrid[i] = nextGrid[i] = 0;
		}
	}
	
	

};