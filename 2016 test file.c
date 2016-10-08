#pragma config(Motor,  port2,           RightBack,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           RightFront,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           RightY,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           LeftY,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           RightTop,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           LeftTop,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           LeftBack,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           LeftFront,     tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int joyThresh = 10; // This variable controls the size of the deadzone for the joysticks

#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(115)

#include "Vex_Competition_Includes.c"


/**
*
* DriveControl moves the drive based upon the inputs from the parameters
* @param leftPower int -128 to 127
* @param rightPower int -128 to 127
*
*/

void driveControl (int leftPower, int rightPower)
{
	motor[LeftBack] = leftPower;
	motor[LeftFront] = leftPower;
	motor[RightBack] = rightPower;
	motor[RightFront] = rightPower;
}

void armControl (){
	int power = 0;
	if(vexRT[Btn6D]){
		power = -128;
	}
	else if(vexRT[Btn6U]){
		power = 127;
	}

	motor[RightY] = power;
	motor[LeftY] = power;
	motor[RightTop] = power;
	motor[LeftTop] = power;
}

void resetMotors(){
    motor[LeftBack] = 0;
    motor[LeftFront] = 0;
    motor[RightBack] = 0;
    motor[RightFront] = 0;
    motor[RightY] = 0;
    motor[LeftY] = 0;
    motor[RightTop] = 0;
    motor[LeftTop] = 0;
}

/**
*
* mapJoyInt takes the TVexJoysticks input value and a threshold value and returns an integer
* @param TVexJoysticks is a created variable that accepts joystick channels
* @param threshold is an int -128 to 127
*
*/

int mapJoyInt (TVexJoysticks input)
{
	if (abs(vexRT[input]) > joyThresh)
	{
		return vexRT[input];
	}
	return 0;
}

//Divider for readability

void pre_auton()
{

}

//Divider for readability

task autonomous()
{
    resetMotors();
    driveControl(127,127);
    wait1MSec(500);
    resetMotors();
}

//Divider for readability

task usercontrol()
{
    while (true)
	{
		driveControl(mapJoyInt(Ch3),mapJoyInt(Ch2));
		armControl();
        
        
	}
}
