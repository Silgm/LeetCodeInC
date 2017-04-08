/*Some Macro tool and basic head file like stdio.h stdlib.h etc. in toolbox.h*/
#include "toolbox.h"

/*question_test_choose*/
#include "question_choose.h"
/************************************************************************/
/* 
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.
Grid cells are connected horizontally/vertically (not diagonally). 
The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). 
The island doesn't have "lakes" (water inside that isn't connected to the water around the island). 
One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. 
Determine the perimeter of the island.

Example:

[[0,1,0,0],
[1,1,1,0],
[0,1,0,0],
[1,1,0,0]]

Answer: 16

*/
/************************************************************************/
#ifndef Q463_ISLAND_PERIMETER

/*以下函数由于由于leetcode支持变长数组,因此通过*/
/*

int islandPerimeter(int** grid, int gridRowSize, int gridColSize) {
	int indexI, indexJ;
	int perimeter = 0;
	for (indexI = 0; indexI < gridRowSize; indexI++) {
	for (indexJ = 0; indexJ < gridColSize; indexJ++) {
		if (grid[indexI][indexJ]) {
			perimeter += 4;
			if (indexI && grid[indexI - 1][indexJ]) {
				perimeter--;
			}
			if (indexI < gridRowSize - 1 && grid[indexI + 1][indexJ]) {
				perimeter--;
			}
			if (indexJ && grid[indexI][indexJ - 1]) {
				perimeter--;
			}
			if (indexJ < gridColSize - 1 && grid[indexI][indexJ + 1]) {
				perimeter--;
			}
		}
	}
	return perimeter;
}

return perimeter;
}
*/
/*以下函数由于vs不支持C99变长数组而无法通过, 但在VS环境下可用*/
int islandPerimeter(int** grid, int gridRowSize, int gridColSize) {
	int indexI, indexJ;
	int *map = (int *)grid;
	int perimeter = 0;
	for (indexI = 0; indexI < gridRowSize; indexI++) {
		for (indexJ = 0; indexJ < gridColSize; indexJ++) {
			if (*(map + indexI*gridColSize + indexJ)) {
				perimeter += 4;
				if (indexI && *(map + (indexI - 1)*gridColSize + indexJ)) {
					perimeter--;
				}
				if (indexI < gridRowSize - 1 && *(map + (indexI + 1)*gridColSize + indexJ)) {
					perimeter--;
				}
				if (indexJ && *(map + (indexI)*gridColSize + indexJ - 1)) {
					perimeter--;
				}
				if (indexJ < gridColSize - 1 && *(map + (indexI)*gridColSize + indexJ + 1)) {
					perimeter--;
				}
			}
		}
	}
	return perimeter;
}

void test(int **InputMap, int row, int col) {
	int indexI, indexJ;
	int *map = (int *)InputMap;
	for (indexI = 0; indexI < row; indexI++) {
		for (indexJ = 0; indexJ < col; indexJ++) {
			*(map + indexI*col + indexJ) = 1;
		}
	}
}

int main() {
	int indexI, indexJ;
	int map[4][3] = {
		{ 1,0,0 },
		{ 1,0,0 },
		{ 1,0,0 },
		{ 1,0,0 }
	};

	
	
	for (indexI = 0; indexI < 4; indexI++) {
		for (indexJ = 0; indexJ < 3; indexJ++) {
			printf("%d,", map[indexI][indexJ]);
		}
		printf("\n");
	}
	printf("%d\n", islandPerimeter((int **)map, 4, 3));
	return  EXIT_SUCCESS;
}

#endif // !Q463_ISLAND_PERIMETER




