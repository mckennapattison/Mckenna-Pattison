#include"main.h"
#include"chassis.h"

void chassisSet (int left, int right) {
    motorSet (2, left); //front left wheel// 
    motorSet (3, left); //back left wheel//
    motorSet (4, right); // back right wheel//
    motorSet (5, right); //front right// 
    printf("right speed %d left speed %d \n", right, left);
}