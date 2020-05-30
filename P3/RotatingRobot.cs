/**
 * Author:Shaun Lee
 * Platform:VSCode
 * Class Overview: rotating robot derives from robot which has all the functionality of robot plus new move and moveonce and a rotation function
 *
 * Class Invariant:  
 * uses the orientationstate from robot
 * move() moves the robot forward depending on the direction of the robot until sensors hit the wall
 * moveone() moves the robot forward by one depending on the direction 
 * rotate() rotates the robot clockwise north,east,south,west
 *  
 *
 * Interface Invariant:   
 * the robot starts facing up by default and then rotating clockwise just like a clock
 * orientationstate has to be set on a valid state
 * orientation default direction is set to north
 **/
using System;
public class RotatingRobot : robot
{ 
    public RotatingRobot(string str,double drainRate) : base(str,drainRate)
    {
    }
    /**
     *PreCondition: existing orientationstate set to a direction
     *PostCondition: rotates the orientationstate up,right,down,left
     **/
    public void Rotate()
    {
        switch(orientationState)
        {
            case orientation.Up: 
                orientationState = orientation.Right;
                break;
            case orientation.Right: 
                orientationState = orientation.Down;
                break;
            case orientation.Down: 
                orientationState = orientation.Left;
                break;
            case orientation.Left: 
                orientationState = orientation.Up;
                break;
            default:
                break; 
        }
    }
    /**
     *PreCondition: none
     *PostCondition: moves the robot to the direction its facing
     **/
    public override void Move()
    { 
        switch (orientationState)
		{
			case orientation.Up:
				while (upSensor.isValid(rCoord,cCoord))
				{
					nAct.MoveForward(ref rCoord, ref cCoord);
				}
				break;
			case orientation.Down: 
				while (downSensor.isValid(rCoord,cCoord))
				{
					sAct.MoveForward(ref rCoord, ref cCoord);
				}
				break;
			case orientation.Right:
				while (rightSensor.isValid(rCoord,cCoord))
				{
					eAct.MoveForward(ref rCoord, ref cCoord);
				}
				break;
			case orientation.Left:
				while (leftSensor.isValid(rCoord,cCoord))
				{
					wAct.MoveForward(ref rCoord, ref cCoord);
				}
				break;
			default:
				break;
		}

    }

    /**
     *PreCondition: none
     *PostCondition: moves the robot in the direction once
     **/

    public override void MoveOne()
    {
		switch (orientationState)
		{
			case orientation.Up:
				if (upSensor.isValid(rCoord,cCoord))
				{
					nAct.MoveForward(ref rCoord, ref cCoord);
				}
				break;
			case orientation.Down:
				if (downSensor.isValid(rCoord,cCoord))
				{
					sAct.MoveForward(ref rCoord, ref cCoord);
				}
				break;
			case orientation.Right:
				if (rightSensor.isValid(rCoord,cCoord))
				{
					eAct.MoveForward(ref rCoord, ref cCoord);
				}
				break;
			case orientation.Left:
				if (leftSensor.isValid(rCoord,cCoord))
				{
					wAct.MoveForward(ref rCoord, ref cCoord);
				}
				break;
			default:
				break;
		}

    }

}
/*Implementation invariant:
 * the direction of the robot is set to north by default
 * move moves the robot forward until it hits a wall 
 * move once moves the robot forward once
 * orientation state rotate uses switch case statement for rotating the robot through the state of enums
 * the argument of the constructor passes into the robot constructor
 */