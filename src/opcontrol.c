/** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"
#include "chassis.h"
Ultrasonic leftSonar;
Ultrasonic rightSonar;
/* 
/* 
 * Runs the user operator control code. This function will be started in its own task with the
 * default priority and stack size whenever the robot is enabled via the Field Management System
 * or the VEX Competition Switch in the operator control mode. If the robot is disabled or
 * communications is lost, the operator control task will be stopped by the kernel. Re-enabling
 * the robot will restart the task, not resume it from where it left off.
 *
 * If no VEX Competition Switch or Field Management system is plugged in, the VEX Cortex will
 * run the operator control task. Be warned that this will also occur if the VEX Cortex is
 * tethered directly to a computer via the USB A to A cable without any VEX Joystick attached.
 *
 * Code running in this task can take almost any action, as the VEX Joystick is available and
 * the scheduler is operational. However, proper use of delay() or taskDelayUntil() is highly
 * recommended to give other tasks (including system tasks such as updating LCDs) time to run.
 *
 * This task should never exit; it should end with some kind of infinite loop, even if empty.
 */
int joystickGetAnalog (
	unsigned char joystick,
	unsigned char axis

);
//measures how hard you push and what direction you push joystick//
void motorSet(
	unsigned char channel, 
	int speed
);
// sets motor in code with cord and comand speed//
void initialize () {
	rightSonar = ultrasonicInit(2,1);
	leftSonar = ultrasonicInit (4,3);
}
// defines up code ^^//
void operatorControl(){
	int power; 
	int turn; 
	//sensor determines left right position//
	int distanceRight;
	int distanceLeft;
	while (1){
		power = joystickGetAnalog (1,2);
		turn = joystickGetAnalog (3,4);
		chassisSet(power+turn, power-turn);
		//power measures joy push turn measures joy turn//
		//+turn -turn meausres motor turn//
		//joy dig is path following//
		if (joystickGetDigital(1,,8, JOY_RIGHT)) {
			distanceRight = ultrasonicGet (rightSonar);
			distanceLeft = ultrasonicGet (leftSonar);
			// print f if ("the distance to the object is d%"", distance Too Object)//
			//goes full forward or full back if obis in front of bot (direct)//
			if (distanceRight == distanceLeft)  {
				if (distanceRight > 20)  {
					chassisSet(100,100);

				}
			}
		}
	}
}
void operatorControl() {
	while (1) {
		printf("Hello PROS User!\n");
		delay(20);
	}
}
