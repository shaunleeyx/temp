//
// Created by Shaun Lee on 2020-04-22.
//

/**
 * Author:Shaun Lee
 * Platform:CLion
 * Class Overview:This class is the robot that can move around the maze
 *
 * Class Invariant:
 *                     for first arg in move() inputting a 0 = north, 1 = south, 2 = right, 3 = left
 *                     Robot is always turned on
 *                     rCoord and cCoord is the row,column coordinates for the robot's position
 *                     able to be copied
 *                     isPowered returns the state of object (on/off)
 *                     getRow and getColumn returns the coordinates for rCoord and cCoord
 *                     size of the maze has to be always 11x11
 *                     robot cannot get outside the maze
 *
 * Interface Invariant:
 *                     robot has 4 actuator for each direction
 *                     takes in a file through 1st argument in param
 *                     2nd argument is drainRate for the battery for the Sensor
 *                     if drainRate < 0 it will default to 1 if higher than 100 it will default to 1
 *                     Recharge recharges the battery for the sensor
 *                     inputting more than 4 will make hte function do nothing
 **/

using System;
public class robot 
{
	private actuator nAct; 
	private actuator sAct;
	private actuator eAct;
	private actuator wAct;
	private int rCoord;
	private int cCoord;
	private sensor sObj;
	private int count;
	private int[,] grid;
	const int SIZE = 11;
	private bool state;
	/*
	 *Precondition:string and double
	 *Postcondition:filename is str and 2d array copies the file,double sets the drainRate for the battery for the sensor
	 */
	public robot(string str, double drainRate)
	{
		grid = new int[SIZE, SIZE];
		count = 0;
		sObj = new sensor(drainRate);
		nAct = new actuator(0);
		sAct = new actuator(1);
		eAct = new actuator(2);
		wAct = new actuator(3);
		rCoord = 5;
		cCoord = 5;
		state = true;
		string text = System.IO.File.ReadAllText(str);
		string ss = text.Replace("\n", " ");
		ss = string.Join( " ", ss.Split( new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries ));
		string[] arr = ss.Split(' ');
		for (int r = 0; r <= 10; r++)
		{
			for (int c = 0; c <= 10; c++)
			{
				grid[r,c] = Int32.Parse(arr[count]);;
				count++;
			}
		}
	}

	/*
	 *Precondition: int
	 *Postcondition:returns true or false
	 */
	public bool isValid(int num)
	{
		return sObj.isValid(num);
	}

	public int getColumn()
	{
		return cCoord;
	}
	
	public int getRow()
	{
		return rCoord;
	}
	/*
	 *Precondition:int from 0 to 4
	 *Postcondition: moves the robot in direction depending on dir until a wall is in front
	 */
	public void Move(int Dir)
	{
		int sensed;
		switch (Dir)
		{
			case 0:
				sensed = grid[rCoord - 1,cCoord];
				while (sObj.isValid(sensed))
				{
					nAct.MoveForward(ref rCoord, ref cCoord);
					sensed = grid[rCoord - 1,cCoord];
				}
				break;
			case 1:
				sensed = grid[rCoord + 1,cCoord];
				while (sObj.isValid(sensed))
				{
					sAct.MoveForward(ref rCoord, ref cCoord);
					sensed = grid[rCoord + 1,cCoord];
				}
				break;
			case 2:
				sensed = grid[rCoord,cCoord + 1];
				while (sObj.isValid(sensed))
				{
					eAct.MoveForward(ref rCoord, ref cCoord);
					sensed = grid[rCoord,cCoord + 1];
				}
				break;
			case 3:
				sensed = grid[rCoord,cCoord - 1];
				while (sObj.isValid(sensed))
				{
					wAct.MoveForward(ref rCoord, ref cCoord);
					sensed = grid[rCoord,cCoord - 1];
				}
				break;
			default:
				return;
		}
	}

	/*
	 *Precondition: int from 0 to 4
	 *Postcondition:moves the robot once
	 */
	public void MoveOne(int Dir)
	{
		int sensed;
		switch (Dir)
		{
			case 0:
				sensed = grid[rCoord - 1,cCoord];
				if (sObj.isValid(sensed))
				{
					nAct.MoveForward(ref rCoord, ref cCoord);
				}
				break;
			case 1:
				sensed = grid[rCoord + 1,cCoord];
				if (sObj.isValid(sensed))
				{
					sAct.MoveForward(ref rCoord, ref cCoord);
				}
				break;
			case 2:
				sensed = grid[rCoord,cCoord + 1];
				if (sObj.isValid(sensed))
				{
					eAct.MoveForward(ref rCoord, ref cCoord);
				}
				break;
			case 3:
				sensed = grid[rCoord,cCoord - 1];
				if (sObj.isValid(sensed))
				{
					wAct.MoveForward(ref rCoord, ref cCoord);
				}
				break;
			default:
				break;
		}
	}

	/*
	 *Precondition: state is set to something
	 *Postcondition: returns the state of object
	 */
	public bool isPowered()
	{
		return state;
	}

	/*
	 *Precondition: none
	 *Postcondition:recharges the battery of the sensor to 100
	 */
	//only moves if it has 1

	public void Recharge()
	{
		sObj.Recharge();
	}

}

//C++ TO C# CONVERTER TODO TASK: 'rvalue references' have no equivalent in C#:
/*Implementation invariant:
 * echos sensor's isvalid
 * echos actuator's moveforward() in move and moveone
 * copies the file to a 2d array and row and column coordinates are the same
 * move semantics uses swap for both = and the default move constructor
 * MoveOne uses sensor and detects for walls make sure the robot doesn't overlap with the wall
 * Move does the same thing but uses a while loop that invokes moveForward from the actuator until theres a wall in front
 */
