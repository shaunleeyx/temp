//
// Created by Shaun Lee on 2020-04-22.
//

/**
 * Author:Shaun Lee
 * Platform:CLion
 * Class Overview:This class is a helps the robot to move
 *
 * Class Invariant:
 * Constructor takes in a number which then declares the direction of where the actuator moves 0 = north,1 = south, 2 = east, 3 = west
 * column and row var is the size of the maze
 * isPoweredUp returns the state of the actuator(on/off)
 *
 * Interface Invariant:
 * column and row var has to always be 11
 * state of actuator is always true
 **/



public class actuator
{
	private const int column = 11;
	private const int row = 11;
	private bool state;
	private int Direction;
	/*
	  *Precondition:row and column int from robot
	  *Postcondition: changes the value for row and column
	  */
	public void MoveForward(ref int rCoord, ref int cCoord)
	{
		switch (Direction)
		{
			case 0:
				rCoord -= 1;
				break;
				//South
			case 1:
				rCoord += 1;
				break;
				//East
			case 2:
				cCoord += 1;
				break;
				//West
			case 3:
				cCoord -= 1;
				break;
			default:
				break;
		}
	}

	/*
	 *Precondition:state is intialized
	 *Postcondition:returns state
	 */
	public bool isPoweredUp()
	{
		return state;
	}

	/*
	 *Precondition: int from 0 to 4
	 *Postcondition: changes int direction of actuator
	 */
	public actuator(int dir)
	{
	Direction = dir; //dir: 0 = north, 1 = south, 2 = east, 3 = west
	state = true;
	}
}
/*Implementation invariant:
 * MoveForward changes the row coordinate and the column coordinate from the robot through reference
 * Direction of actuator is assigned throguh the constructor of actuator's argument
 * actuator is always true no matter what
 * isPoweredUp returns the state of the object for actuator
 */