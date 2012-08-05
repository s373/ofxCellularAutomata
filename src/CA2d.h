#pragma once

#include "CAdata.h"


class CA2d : public CAdata {
public:
	
	void setup(int rx, int ry) {
		dim.x = rx;
		dim.y = ry;
		
		numcells = dim.x * dim.y;
		currentGrid.assign( numcells, 0 );
		nextGrid.assign( numcells, 0 );
		
		setNumBits(11);
		setCenter1();
		countSelf = true;
		cout << "CA2d init: " + ofToString(dim.x) + " " + ofToString(dim.y) + " " +ofToString(numcells) + "\n";
	}
	
	void set(int locx, int locy, int val) {		
		currentGrid[(int)(locx+locy*dim.x)] = val;
	}
	
	vector<int>* get() {
		return &currentGrid;
	}
	
	void setCenter1() {
//		currentGrid[(int) (dim.x * 0.5)] = 1;
		currentGrid[(int) (dim.x * 0.5 + dim.y * 0.5 * dim.x)] = 1;

	}
	
	void update() {
		
		for (int x = 1; x < dim.x - 1; x++) {
			for (int y = 1; y < dim.y - 1; y++) {				
				int count = countCells(x, y);
				setNextGrid(x, y, rules[count]);				
			}
		}
		
		
		
		
		int temp;
		for(int i=0; i<numcells; i++){
			temp =  currentGrid[i] ;
			currentGrid[i] = nextGrid[i];
			nextGrid[i] = temp;
		}
		
		
		//		int[] temp = currentGrid;
		//		currentGrid = nextGrid;
		//		nextGrid = temp;
	}
	
	void setNextGrid(int x, int y, float val) {
		nextGrid[x+y*dim.x] = val;
	}
	
	int countCells(int x, int y) {
		int count = getCell2D(x, y - 1) + // north
		getCell2D(x + 1, y - 1) + // northeast
		getCell2D(x + 1, y) + // east
		getCell2D(x + 1, y + 1) + // southeast
		getCell2D(x, y + 1) + // south
		getCell2D(x - 1, y + 1) + // southwest
		getCell2D(x - 1, y) + // west
		getCell2D(x - 1, y - 1); // northwest
		
		if(countSelf){
			count += getCell2D(x,y);
		}
		
		return count;
	}
	
	
	int getCell2D(int locx, int locy) {
		return currentGrid[(int) (locx + locy * dim.x)];
	}
	
};