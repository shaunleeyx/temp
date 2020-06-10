/**
 * Author:Shaun Lee
 * Platform:VSCode
 * Class Overview:This class has all the functionality of robot plus up down left right
 *
 * Class Invariant: 
 * don't go out of bounds in the grid
 * Forward() moves the position of the robot north
 * Back() move the position of the robot south
 * Left() moves the position of the robot left 
 * Right() moves the position of the robot right
 * moves moves the robot forward depending on the direction of the robot
 *
 * Interface Invariant:   
 * robot cannot go through walls
 * rCoord and cCoord cannot go below 0 
 * using the direction function changes the direction of the robot
 * 
 **/
using System;
public class TranRobot : robot,iTran
{
    public TranRobot(string str) : base(str)
    {
        
    }
    /**
     *PreCondition: existing 2 ints
     *PostCondition: changing state of ints
     **/
    public override void Forward()
    {
        if (upSensor.isValid(rCoord,cCoord,grid))
        {
            nAct.MoveForward(ref rCoord, ref cCoord);
        }
        orientationState = orientation.Up;
    }
    /**
     *PreCondition: existing 2 ints
     *PostCondition: changing state of ints
     **/
    public override void Left()
    {
        if (leftSensor.isValid(rCoord,cCoord,grid))
        {
            wAct.MoveForward(ref rCoord, ref cCoord);
        }
        orientationState = orientation.Left;
    }
    /**
     *PreCondition: existing 2 ints
     *PostCondition: changing state of ints
     **/
    public override void Right()
    {
        if (rightSensor.isValid(rCoord,cCoord,grid))
        {
            eAct.MoveForward(ref rCoord, ref cCoord);
        }
        orientationState = orientation.Right;
    }
    /**
     *PreCondition: existing 2 ints
     *PostCondition: changing state of ints
     **/
    public override void Back()
    {
        if (downSensor.isValid(rCoord,cCoord,grid))
        {
            sAct.MoveForward(ref rCoord, ref cCoord);
        }    
        orientationState = orientation.Down;
    }

    /**
     *PreCondition: none
     *PostCondition: changing state of ints
     **/
    public override void Move()
    { 
        switch (orientationState)
		{
			case orientation.Up:
				while (upSensor.isValid(rCoord,cCoord,grid))
				{
					nAct.MoveForward(ref rCoord, ref cCoord);
				}
				break;
			case orientation.Down: 
				while (downSensor.isValid(rCoord,cCoord,grid))
				{
					sAct.MoveForward(ref rCoord, ref cCoord);
				}
				break;
			case orientation.Right:
				while (rightSensor.isValid(rCoord,cCoord,grid))
				{
					eAct.MoveForward(ref rCoord, ref cCoord);
				}
				break;
			case orientation.Left:
				while (leftSensor.isValid(rCoord,cCoord,grid))
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
     *PostCondition: changing state of coord
     **/
    public override void MoveOne()
    {
        switch (orientationState)
		{
			case orientation.Up:
				if (upSensor.isValid(rCoord,cCoord,grid))
				{
					nAct.MoveForward(ref rCoord, ref cCoord);
				}
				break;
			case orientation.Down:
				if (downSensor.isValid(rCoord,cCoord,grid))
				{
					sAct.MoveForward(ref rCoord, ref cCoord);
				}
				break;
			case orientation.Right:
				if (rightSensor.isValid(rCoord,cCoord,grid))
				{
					eAct.MoveForward(ref rCoord, ref cCoord);
				}
				break;
			case orientation.Left:
				if (leftSensor.isValid(rCoord,cCoord,grid))
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
 * Constructor argument passes the arguments to the robot
 * moving a direction changes the direction of the robot
 * rCoord and cCoord are changed through references passed in
 * override parent's move() with transrobot()
 * directional functions uses directional actuator with directional sensors
 */