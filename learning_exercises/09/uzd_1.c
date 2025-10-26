#include <stdio.h>
#include <math.h>

typedef struct Point{
	double x;
	double y;
} Point;

Point createPoint(double x, double y){
	Point p = {x, y};
	return p;
}

void printPoint(Point p){
	printf("( %.1f , %.1f )\n", p.x, p.y);
	return;
}

double getDistance(Point a, Point b){
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main(){
	double x, y, distance;
	
	x = 2;
	y = -3;
	Point p1 = createPoint(x, y);
	printPoint(p1);
	
	x = -4;
	y = 5;
	Point p2 = createPoint(x, y);
	printPoint(p2);
	
	distance = getDistance(p1, p2);	
	printf ("\nAtstumas: %f", distance);
	
	
	return 0;
}