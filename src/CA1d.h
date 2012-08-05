/*
 *  CA1d.h
 *  example-ca1d
 *
 *  Created by andré sier on 20120803.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once

#include "CAdata.h"


class CA1d : public CAdata {
public:
	
	void setup(int rx) {
		dim.x = rx;
		
		numcells = dim.x;
		currentGrid.assign( numcells, 0 );
		nextGrid.assign( numcells, 0 );

		setNumBits(4);
		setCenter1();
		countSelf = true;
		
		cout << "CA1d init: " + ofToString(dim.x) + " " + ofToString(numcells) + "\n";
	}
	
	void set(int locx, int val) {

		currentGrid[locx] = val;
	}
	
	vector<int>* get() {
		return &currentGrid;
	}
	
	void setCenter1() {
		currentGrid[(int) (dim.x * 0.5)] = 1;
	}
	
	void update() {
		
		for (int x = 1; x < dim.x - 1; x++) {
			int count = countCells(x);
			setNextGrid(x, rules[count]);		
//			cout << "i "<< x << " count " << count << " " << rules[count] << endl;			
		}
		
		
		int temp;
		for(int i=0; i<dim.x; i++){
			temp =  currentGrid[i] ;
			currentGrid[i] = nextGrid[i];
			nextGrid[i] = temp;
		}

		
//		int[] temp = currentGrid;
//		currentGrid = nextGrid;
//		nextGrid = temp;
	}
	
	void setNextGrid(int x, float val) {
			nextGrid[x] = val;
	}
	
	int countCells(int x) {
		if(countSelf){
			return currentGrid[x - 1] + currentGrid[x + 1] + currentGrid[x];		
		} else {
			return currentGrid[x - 1] + currentGrid[x + 1] ;			
		}
		
		return 0;
	}
	

};