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

void displayTriangle(struct triangle *pt);
void displayCircle(struct circle *pt);
void displayRectangle(struct rectangle *pt);

void addObject(struct object *pt);
void displayList();


int main (void){


	t_obj *test;
	test = (t_obj*)malloc(sizeof(t_obj));

//	test->display = displayTriangle;

	struct circle *coucou = createCircle(4);
	coucou->display(coucou);



	return 0;
}

struct circle *createCircle(int radius){

	struct circle *newCircle = (struct circle*)malloc(sizeof(struct circle));

	newCircle->display = displayCircle;
	newCircle->radius = radius;
}

void displayCircle(struct circle *pt){

	printf ("this is a circle \n");
	printf("test %d\n", pt->radius);

}

