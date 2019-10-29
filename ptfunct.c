#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>



typedef struct object {
struct object *next;
void (*display)(struct object *object);
}t_obj;

struct rectangle {
struct object *next;
void (*display)(struct object *pt);
int left, top, width, height;
};
struct circle {
struct object *next;
void (*display)(struct object *pt);
int radius;
};
struct triangle {
struct object *next;
void (*display)(struct object *pt);
int x1, y1, x2, y2, x3, y3;
};

struct circle *createCircle(int radius);
struct rectangle *createRectangle(int left, int top, int width, int height);
struct triangle *createTriangle(int x1, int y1, int x2, int y2, int x3, int y3);

void displayTriangle(struct object *pt);
void displayCircle(struct object *pt);
void displayRectangle(struct object *pt);

void addObject(struct object *pt, struct object *start);
void displayList();


int main (void){

<<<<<<< Updated upstream
=======
	struct object *start = (t_obj*)createCircle(4);
	//start->display((t_obj*)start);
	start->next = NULL;
	struct object *second = (t_obj*)createCircle(7);
	struct object *sd = (t_obj*)createCircle(1);
	struct object *sf = (t_obj*)createCircle(2);
	struct object *sg = (t_obj*)createCircle(5);
	//second->display((t_obj*)second);
	start->next = second;

	addObject(sd, start);
	addObject(sf, start);
	addObject(sg, start);
>>>>>>> Stashed changes

	t_obj *test;
	test = (t_obj*)malloc(sizeof(t_obj));

//	test->display = displayTriangle;

	struct object *testCircle = (t_obj*)createCircle(4);
	testCircle->display((t_obj*)testCircle);

	struct object *testRectangle = (t_obj*)createRectangle(2,4,6,8);
	testRectangle->display((t_obj*)testRectangle);

	struct object *testTriangle = (t_obj*)createTriangle(2,4,6,6,4,2);
	testTriangle->display((t_obj*)testTriangle);

	return 0;
}

struct circle *createCircle(int radius){

	struct circle *newCircle = (struct circle*)malloc(sizeof(struct circle));

	newCircle->display = displayCircle;
	newCircle->radius = radius;

	return newCircle;
}

struct rectangle *createRectangle(int left, int top, int width, int height){

		struct rectangle *newRectangle = (struct rectangle*)malloc(sizeof(struct rectangle));

		newRectangle->display = displayRectangle;
		newRectangle->left = left;
		newRectangle->top = top;
		newRectangle->width = width;
		newRectangle->height = height;

		return newRectangle;
}

struct triangle *createTriangle(int x1, int x2, int x3, int y1, int y2, int y3){

	struct triangle *newTriangle = (struct triangle*)malloc(sizeof(struct triangle));

	newTriangle->display = displayTriangle;
	newTriangle->x1 = x1;
	newTriangle->x2 = x2;
	newTriangle->x3 = x3;
	newTriangle->y1 = y1;
	newTriangle->y2 = y2;
	newTriangle->y3 = y3;

	return newTriangle;
}

void displayCircle(struct object *pt){
 	struct circle *disp = (struct circle*)pt;
	printf ("this is a circle which has a radius of: %d \n", disp->radius);
}

<<<<<<< Updated upstream
void displayRectangle(struct object *pt){
	struct rectangle *disp = (struct rectangle*)pt;
	printf ("this is a rectangle with the following parameters : left=%d, top=%d, width=%d, height=%d\n", disp->left, disp->top, disp->width, disp->height);

}


void displayTriangle(struct object *pt){
 	struct triangle *disp = (struct triangle*)pt;
	printf ("this is a triangle with the following parameters : x1=%d, x2=%d, x3=%d, y1=%d, y2=%d, y3=%d \n", disp->x1, disp->x2, disp->x3, disp->y1, disp->y2, disp->y3);
}
=======
void addObject(struct object *pt, struct object *start){
	struct object *nextObject = start;
	while (nextObject->next != NULL){
		nextObject = nextObject->next;
	}
	nextObject->display((t_obj*)nextObject);

	nextObject->next = pt;

}

>>>>>>> Stashed changes
