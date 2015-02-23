/*
	 ofxCellularAutomata - André Sier 2009
	 cellular automata in 1,2,3 dimensions
	 
	 licensed under lgpl 2.1+
	 
	 s373.net/x
 */

#pragma once

#include "CAdata.h"


class CA3d : public CAdata {
public:
	int dxdy;
	
	CA3d(){
		CAdata();
	}
	~CA3d(){}
	
	void setup(int rx, int ry, int rz) {
		dim.x = rx;
		dim.y = ry;
		dim.z = rz;
		numcells = dim.x * dim.y * dim.z;
		dxdy = dim.x * dim.y;
		currentGrid.assign( numcells, 0 );
		nextGrid.assign( numcells, 0 );
		
		setNumBits(134217728);
		
		setCenter1();
		cout << this << " CA3d init: " + ofToString(dim.x) +
		" " + ofToString(dim.y) + " " + ofToString(dim.z) + " "  +ofToString(numcells) + "\n";
	}
	
	
	void set(int locx, int locy, int locz, int val) {		
		currentGrid[(int)(locx+locy*dim.x+locz*dxdy)] = val;
	}
	
	vector<int>* get() {
		return &currentGrid;
	}
	
	void setCenter1() {
		currentGrid[(int) (dim.x * 0.5 + dim.y * 0.5 * dim.x +
						   dim.z * 0.5 * dim.x * dim.y)] = 1;
	}
	
	void update() {
		
		for (int x = 1; x < dim.x - 1; x++) {
			for (int y = 1; y < dim.y - 1; y++) {				
				for (int z = 1; z < dim.z - 1; z++) {
					int count = countCells(x, y, z);
					setNextGrid(x, y,z, rules[count]);
				}
			}
		}		
		
		
		int temp;
		for(int i=0; i<numcells; i++){
			temp =  currentGrid[i] ;
			currentGrid[i] = nextGrid[i];
			nextGrid[i] = temp;
		}
		
	}
	
	void setNextGrid(int x, int y,int z, float val) {
		nextGrid[x+y*dim.x+z*dxdy] = val;
	}
	
	inline int countCells(int x, int y, int z) {
		
		int count = 0;
		
		if(classic){
			count += getCell3D(x,y-1,z-1);		//n
			count += getCell3D(x+1,y-1,z-1);	//ne
			count += getCell3D(x+1,y,z-1);		//e
			count += getCell3D(x+1,y+1,z-1);	//se
			count += getCell3D(x,y+1,z-1);		//s
			count += getCell3D(x-1,y+1,z-1);	//sw
			count += getCell3D(x-1,y,z-1);		//w
			count += getCell3D(x-1,y-1,z-1);	//nw
			count += getCell3D(x,y-1,z);		//n
			count += getCell3D(x+1,y-1,z);		//ne
			count += getCell3D(x+1,y,z);		//e
			count += getCell3D(x+1,y+1,z);		//se
			count += getCell3D(x,y+1,z);		//s
			count += getCell3D(x-1,y+1,z);		//sw
			count += getCell3D(x-1,y,z);		//w
			count += getCell3D(x-1,y-1,z);		//nw
			count += getCell3D(x,y-1,z+1);		//n
			count += getCell3D(x+1,y-1,z+1);	//ne
			count += getCell3D(x+1,y,z+1);		//e
			count += getCell3D(x+1,y+1,z+1);	//se
			count += getCell3D(x,y+1,z+1);		//s
			count += getCell3D(x-1,y+1,z+1);	//sw
			count += getCell3D(x-1,y,z+1);		//w
			count += getCell3D(x-1,y-1,z+1);	//nw
			count += getCell3D(x,y,z+1);		//nw
			count += getCell3D(x,y,z-1);		//nw
			if(countself)count += getCell3D(x,y,z);

		} else {
				
			for(int i=0; i<27; i++){
				int lx = i%3;
				int ly = i/3;
				int lz = i/9;
				if(getCell3D(x+lx-1,y+ly-1, z+lz-1)==1){
					count |= (1<<i);
				}
			}
			
		}
		return count;
	}
	
	
	inline int getCell3D(int locx, int locy, int locz) {
		return currentGrid[(int) (locx + locy * dim.x + locz * dxdy)];
	}
	
};