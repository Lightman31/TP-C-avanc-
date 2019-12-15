#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

/**************************************************************

	this function teaches us how to use pointers on functions to
	create different objects who have the same basic elements.

 **************************************************************/


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

struct object *createCircle(int radius);
struct object *createRectangle(int left, int top, int width, int height);
struct object *createTriangle(int x1, int y1, int x2, int y2, int x3, int y3);

void displayTriangle(struct object *pt);
void displayCircle(struct object *pt);
void displayRectangle(struct object *pt);

void addObject(struct object *pt, struct object *start);
void displayList(struct object *start);


int main (void){

	struct object *start = createCircle(4);
	start->next = NULL;

	addObject(createCircle(7), start);
	addObject(createCircle(1), start);
	addObject(createCircle(2), start);
	addObject(createRectangle(2,4,6,8), start);
	addObject(createTriangle(2,4,6,6,4,2), start);
	addObject(createCircle(5), start);

	displayList(start);

	return 0;
}


void displayList(struct object *start){ // function that displays the list of objects that begins with object start.

	struct object *nextObject = start;
	nextObject->display((t_obj*)nextObject);
	while (nextObject->next != NULL){
		nextObject = nextObject->next;
		nextObject->display((t_obj*)nextObject);
	}
}


void addObject(struct object *pt, struct object *start){ // function that adds the pointed struct object pt to the list of objects begining with the object start.

	struct object *nextObject = start;
	while (nextObject->next != NULL){
		nextObject = nextObject->next;
	}
	nextObject->next = pt;
	pt->next = NULL;
}



struct object *createCircle(int radius){ // function that returns an object which is casted as a circle to access circle parameters. 

	struct circle *newCircle = (struct circle*)malloc(sizeof(struct circle));

	newCircle->display = displayCircle;
	newCircle->radius = radius;

	return (t_obj*)newCircle;
}

struct object *createRectangle(int left, int top, int width, int height){ // function that returns an object which is casted as a rectangle to access rectangle parameters. 

	struct rectangle *newRectangle = (struct rectangle*)malloc(sizeof(struct rectangle));

	newRectangle->display = displayRectangle;
	newRectangle->left = left;
	newRectangle->top = top;
	newRectangle->width = width;
	newRectangle->height = height;

	return (t_obj*)newRectangle;
}

struct object *createTriangle(int x1, int x2, int x3, int y1, int y2, int y3){ // function that returns an object which is casted as a triangle to access triangle parameters. 

struct triangle *newTriangle = (struct triangle*)malloc(sizeof(struct triangle));

	newTriangle->display = displayTriangle;
	newTriangle->x1 = x1;
	newTriangle->x2 = x2;
	newTriangle->x3 = x3;
	newTriangle->y1 = y1;
	newTriangle->y2 = y2;
	newTriangle->y3 = y3;

	return (t_obj*)newTriangle;
}

void displayCircle(struct object *pt){ // function that displays parameters of a circle.
	struct circle *disp = (struct circle*)pt;
	printf ("this is a circle which has a radius of: %d \n", disp->radius);
}

void displayRectangle(struct object *pt){ // function that displays parameters of a rectangle.
	struct rectangle *disp = (struct rectangle*)pt;
	printf ("this is a rectangle with the following parameters : left=%d, top=%d, width=%d, height=%d\n", disp->left, disp->top, disp->width, disp->height);
}

void displayTriangle(struct object *pt){ // function that displays parameters of a triangle.
	struct triangle *disp = (struct triangle*)pt;
	printf ("this is a triangle with the following parameters : x1=%d, x2=%d, x3=%d, y1=%d, y2=%d, y3=%d \n", disp->x1, disp->x2, disp->x3, disp->y1, disp->y2, disp->y3);
}



