#pragma once

#include "CAdata.h"


class CA3d : public CAdata {
public:
	int dxdy;
	
	void setup(int rx, int ry, int rz) {
		dim.x = rx;
		dim.y = ry;
		dim.z = rz;
		numcells = dim.x * dim.y * dim.z;
		dxdy = dim.x * dim.y;
		currentGrid.assign( numcells, 0 );
		nextGrid.assign( numcells, 0 );
		
		setNumBits(27);
		setCenter1();
		countSelf = true;
		cout << "CA3d init: " + ofToString(dim.x) +
		" " + ofToString(dim.y) + " " + ofToString(dim.z) + " "  +ofToString(numcells) + "\n";
	}
	
	void set(int locx, int locy, int locz, int val) {		
		currentGrid[(int)(locx+locy*dim.x+locz*dxdy)] = val;
	}
	
	vector<int>* get() {
		return &currentGrid;
	}
	
	void setCenter1() {
		currentGrid[(int) (dim.x * 0.5 + dim.y * 0.5 * dim.x + dim.z * 0.5 * dim.x
						   * dim.y)] = 1;
		
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
		
		
		//		int[] temp = currentGrid;
		//		currentGrid = nextGrid;
		//		nextGrid = temp;
	}
	
	void setNextGrid(int x, int y,int z, float val) {
		nextGrid[x+y*dim.x+z*dxdy] = val;
	}
	
	int countCells(int x, int y, int z) {
		int count = getCell3D(x, y - 1, z - 1) + // north
		getCell3D(x + 1, y - 1, z - 1) + // northeast
		getCell3D(x + 1, y, z - 1) + // east
		getCell3D(x + 1, y + 1, z - 1) + // southeast
		getCell3D(x, y + 1, z - 1) + // south
		getCell3D(x - 1, y + 1, z - 1) + // southwest
		getCell3D(x - 1, y, z - 1) + // west
		getCell3D(x - 1, y - 1, z - 1) + // northwest
		
		getCell3D(x, y - 1, z + 1) + // north
		getCell3D(x + 1, y - 1, z + 1) + // northeast
		getCell3D(x + 1, y, z + 1) + // east
		getCell3D(x + 1, y + 1, z + 1) + // southeast
		getCell3D(x, y + 1, z + 1) + // south
		getCell3D(x - 1, y + 1, z + 1) + // southwest
		getCell3D(x - 1, y, z + 1) + // west
		getCell3D(x - 1, y - 1, z + 1) ;

		
		if(countSelf){
			count +=
				getCell3D(x, y - 1, z) + // north
				getCell3D(x + 1, y - 1, z) + // northeast
				getCell3D(x + 1, y, z) + // east
				getCell3D(x + 1, y + 1, z) + // southeast
				getCell3D(x, y + 1, z) + // south
				getCell3D(x - 1, y + 1, z) + // southwest
				getCell3D(x - 1, y, z) + // west
				getCell3D(x - 1, y - 1, z);
			
			count += getCell3D(x,y,z) + getCell3D(x,y,z-1) + getCell3D(x,y,z+1);
			
		}
		
		
		return count;
	}
	
	
	int getCell3D(int locx, int locy, int locz) {
		return currentGrid[(int) (locx + locy * dim.x + locz * dxdy)];
	}
	
};