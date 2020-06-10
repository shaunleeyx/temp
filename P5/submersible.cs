/**
 * Author:Shaun Lee
 * Platform:VSCode
 * Class Overview:This class inherits from both submersible and robot with its descendants and the functionality of both of them
 *
 * Class Invariant:
 *                 arrayofgrid contains strings of the name of the gridfile with the format "GridN.txt" i.example: Grid1.txt Grid2.txt ..etc
 *                 numberofGrid is the highest number gridfile you see in the directory assuming everything is consecutive till the N number of gridfiles
 *                 level is the current level the robot is at.!-- it starts at the top and the digging to the bottom
 *                 contains one sensor and one actuator for sensing if the bottom grid is a wall or a open space
 *                 the sensor and actuator can do its function for the higher grid or the lower grid
 *                 sensor will have a random drainRate from 0 to 20
 *                 You cannot dig below the grid level and above the highest floor
 *                 
 *                  
 * 
 *
 * Interface Invariant:
 *                       field: 
 *                                  verticalactuator - actuator that can move the robot to the floor above or below
 *                                  verticalsensor - sensor that can sense the floor above or below
 *                                  arrayofgrid - an array of the list of gridnames which have to be properly formatted "Grid1.txt"
 *                                  level - current level that the robot is in default is 0 which is the highest floor *                                  *                                  *                                  
 *                                  
 *                       Constructor:
 *                                  numberofGrid - the highest number of grid file so if the highest number is Grid4.txt number should be 4
 *                       Function:
 *                                  dive - given the arguments row and column it will return the 2darray of the grid below if the coordinate is not where a wall is supposed to be
 *                                  climb - given the arguments row and column it will return the 2darray of the grid above if the coordinate is not where a wall is supposed to be
 *                                  getDepth - return the current level the robot is in
 *                                 
 *                                  
 *                                  
 **/
using System;
public class submersible : isubmersible {
    private actuator verticalActuator;
    private sensor verticalSensor;
    private string[] arrayofgrid;
    private int level;
    private int numberofGrid;

    /*
     *PreCondition: int
     *PostCondition: sets the field arrayofgrid to that one and also intializes the arrayofgrid to strings of the gridfile name i.e Grid0.txt Grid1.txt
     */
    public submersible (int numberofGrid) {
        this.numberofGrid = numberofGrid;
        Random random = new Random ();
        double rand = random.Next (1, 20);
        verticalActuator = new actuator (4);
        verticalSensor = new sensor (rand, 4);
        level = 0; //higher is deeper
        arrayofgrid = new string[numberofGrid];
        for (int i = 0; i <= numberofGrid; i++) {
            arrayofgrid[i] = "Grid" + i + ".txt";
        }
    }
     /*
      *PreCondition: row and column integers
      *PostCondition: it returns a 2d array of the next grid depending if there is a wall
      */

    public int[, ] dive (int rCoord, int cCoord) {
        if (++level > numberofGrid) return readfile (arrayofgrid[level]);
        int[, ] belowgrid = readfile (arrayofgrid[++level]);
        if (verticalSensor.isValid (rCoord, cCoord, belowgrid)) {
            level = verticalActuator.MoveDown (level);
        }

        return belowgrid;
    }
     /*
      *PreCondition: row and column integers
      *PostCondition: it returns a 2d array of the previous grid depending if there is a wall
      */
    public int[, ] climb (int rCoord, int cCoord) {
        if (--level < 0) return readfile (arrayofgrid[level]);
        int[, ] abovegrid = readfile (arrayofgrid[--level]);
        if (verticalSensor.isValid (rCoord, cCoord, abovegrid)) {
            level = verticalActuator.MoveUp (level);
        }
        return abovegrid;
    }

     /*
      *PreCondition: string
      *PostCondition: returns 2d array of grid file mapped
      */
    private int[, ] readfile (string filename) {
        const int SIZE = 11;
        int[, ] grid = new int[SIZE, SIZE];
        int count = 0;
        string text = System.IO.File.ReadAllText (filename);
        string ss = text.Replace ("\n", " ");
        ss = string.Join (" ", ss.Split (new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries));
        string[] arr = ss.Split (' ');
        for (int r = 0; r <= 10; r++) {
            for (int c = 0; c <= 10; c++) {
                grid[r, c] = Int32.Parse (arr[count]);;
                count++;
            }
        }

        return grid;
    }

     /*
      *PreCondition:none 
      *PostCondition: returns level integer
      */
    public int getDepth () {
        return level;
    }

}
/*Implementation invariant:
 *                          climb() returns a 2darray of the bottom grid if its a valid spot for row and column to be in
 *                          level cannot go below 0 or above numberofGrid
 *                          level defaults to 0 which is the highest 
 *                          readfile takes in the gridfile as input and returns a 2darray with the gridfile properly mapped to it
 *                          climb() and dive() both return 2d arrays of the appropriate grid level
 *                          made readfile private to have encapsulation. don't know why client would need that
 *                          
 *                          
 *                          
 *                          
 *                          
 */