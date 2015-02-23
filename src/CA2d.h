/*
	 ofxCellularAutomata - André Sier 2009
	 cellular automata in 1,2,3 dimensions
	 
	 licensed under lgpl 2.1+
	 
	 s373.net/x
 */

#pragma once

#include "CAdata.h"


class CA2d : public CAdata {
public:
	
	
	CA2d(){
		CAdata();
	}
	~CA2d(){}
	
	void setup(int rx, int ry) {
		dim.x = rx;
		dim.y = ry;
		
		numcells = dim.x * dim.y;
		currentGrid.assign( numcells, 0 );
		nextGrid.assign( numcells, 0 );
		
		setNumBits(512);

		setCenter1();
		cout << this << " CA2d init: " + ofToString(dim.x) + " " + ofToString(dim.y) + " " +ofToString(numcells) + "\n";
	}
		
	
	void set(int locx, int locy, int val) {		
		currentGrid[(int)(locx+locy*dim.x)] = val;
	}
	
	vector<int>* get() {
		return &currentGrid;
	}
	
	void setCenter1() {
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
				
	}
	
	void setNextGrid(int x, int y, float val) {
		nextGrid[x+y*dim.x] = val;
	}
	
	inline int countCells(int x, int y) {
		
		int count = 0;

		if(classic){
			count += getCell2D(x,y-1);		//n
			count += getCell2D(x+1,y-1);	//ne
			count += getCell2D(x+1,y);		//e
			count += getCell2D(x+1,y+1);	//se
			count += getCell2D(x,y+1);		//s
			count += getCell2D(x-1,y+1);	//sw
			count += getCell2D(x-1,y);		//w
			count += getCell2D(x-1,y-1);	//nw
			if(countself)count += getCell2D(x,y);
		} else {
			for(int i=0; i<9; i++){
				int lx = i%3;
				int ly = i/3;
				if(getCell2D(x+lx-1,y+ly-1)==1){
					count |= (1<<i);
				}
				
			}
		}
		return count;
	}
	
	
	inline int getCell2D(int locx, int locy) {
		return currentGrid[(int) (locx + locy * dim.x)];
	}
	
};