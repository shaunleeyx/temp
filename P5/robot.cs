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
public class robot : irobot
{
	protected orientation orientationState;
    protected enum orientation
        {
            Up,
            Down,
            Left,
            Right
        }
	protected actuator nAct; 
	protected actuator sAct;
	protected actuator eAct;
	protected actuator wAct;
	protected int rCoord;
	protected int cCoord;
	protected sensor upSensor;
	protected sensor downSensor;
	protected sensor rightSensor;
	protected sensor leftSensor;

	private int count;
	private String filename;
	protected int[,] grid;
	private const int SIZE = 11;
	private const int maxDrain = 20;
	private const int minDrain = 0;
	private bool state; 
	/*
	 *Precondition:string and double
	 *Postcondition:filename is str and 2d array copies the file,double sets the drainRate for the battery for the sensor
	 */
	public robot(string str)
	{ 
		Random random = new Random();
		double drainRate = random.Next(minDrain,maxDrain);
		if (str == null) throw new ArgumentNullException("invalid file");
        orientationState = orientation.Up; 
		filename = str;
		grid = new int[SIZE, SIZE];
		count = 0;
		upSensor = new sensor(drainRate,0);
		downSensor = new sensor(drainRate,1);
		rightSensor = new sensor(drainRate,2);
		leftSensor = new sensor(drainRate,3);
		nAct = new actuator(0);
		sAct = new actuator(1);
		eAct = new actuator(2);
		wAct = new actuator(3);
		rCoord = 5;
		cCoord = 5;
		state = true;
		string text = System.IO.File.ReadAllText(filename);
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
	public bool isValid()
	{
		
		return (upSensor.isValid(rCoord,cCoord,grid) && downSensor.isValid(rCoord,cCoord,grid) && rightSensor.isValid(rCoord,cCoord,grid) && leftSensor.isValid(rCoord,cCoord,grid));
	}
	//TODO document this

	public int getColumn()
	{
		return cCoord;
	}

	
	public int getRow()
	{
		return rCoord;
	}
	/*
	 *Precondition: None
	 *Postcondition: keeps moving robot up 
	 */

	public virtual void Move()
	{
		while(upSensor.isValid(rCoord,cCoord,grid))
		{
			nAct.MoveForward(ref rCoord, ref cCoord);
		}
	}

	/*
	 *Precondition:None 
	 *Postcondition:moves the robot up once
	 */
	public virtual void MoveOne()
	{
		if(upSensor.isValid(rCoord,cCoord,grid))
		{
			nAct.MoveForward(ref rCoord, ref cCoord);
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
		upSensor.Recharge();
		downSensor.Recharge();
		rightSensor.Recharge();
		leftSensor.Recharge(); 
	}

	public void setGrid(int[,] input)
	{
		grid = input;
	}

	public virtual void Forward()
	{

	}
	public virtual void Left()
	{

	}
	public virtual void Right()
	{

	}
	public virtual void Back()
	{

	}
	public virtual void Rotate()
	{

	}
}

//
/*Implementation invariant:
 * echos sensor's isvalid
 * echos actuator's moveforward() in move and moveone
 * copies the file to a 2d array and row and column coordinates are the same
 * move semantics uses swap for both = and the default move constructor
 * MoveOne uses sensor and detects for walls make sure the robot doesn't overlap with the wall
 * Move does the same thing but uses a while loop that invokes moveForward from the actuator until theres a wall in front
 * changed the boundaries of the grid to a variable so it removes the hardcoding
 * Made the protected variables like the sensor and actuator accessible to rotatingRobot
 * changed move() and moveone() to only go up because parent robot shouldn't beable to rotate or move sideways
 * every robot has 4 sensors for each direction
 * made a field called filename that encapsulates the string of the filename being passed into the param of constructor via constructor injection
 * throws exception if argument is null for constructor
 * initialized enum for direction in robot
 * changed the way 2darr gets processed from the file b/c c#
 * had to implement virtual methods for the functions of the derived classes for polymorphism to work
 * virtual functions are NOP
 * used property injection for grid 
 */
