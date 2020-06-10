/**
 * Author:Shaun Lee
 * Platform:VSCode
 * Class Overview:This class inherits from both submersible and robot with its descendants and the functionality of both of them.!-- 
 *                
 * Class Invariant:
 *                 robotnum in the constructor uses polymorphism on the robotobj.!--
 *                 if robotnum is 0 then robot object becomes a robot  
 *                 if robotnum is 1 then robot object is a Rotating robot
 *                 if robotnum is 2 then robot object is a TransBot
 *                 Robot will dive into the next grid file if it hits a wall
 *                 This will work for any movement function for any robot
 *                 getColumn and getRow gets the value of the column and row
 *                 Robot will use dive if it hits a wall and if its at the most bottom floor it will climb 
 *                 
 * Interface Invariant:
 *                            Fields: 
 *                                    robot object named robotobj
 *                                    submersible object named subobj
 *                                    rCoord keeps track of the row coordinate
 *                                    cCoord keeps track of the column coordinate
 *                                    numberofGrids is the number of grid files                             
 * 
 *                       Constructor: robotnum changes the robot to any kind of robot base and derived
 *                                    file is the filename of the grid
 *                                    the grid files have to be Grid1.txt Grid2.txt .. GridN.txt
 *                                    numberofGrids the number of how many grid files you have so if u have
 * 
 *                         Functions:
 *                                    Move() invokes the appropriate move depending on the type of robot
 *                                    MoveOne() invokes the appropriate moveone depending on the type of robot
 *                                    Recharge() recharges battery of the sensors 
 *                                    Forward() moves robot up
 *                                    Back() moves robot down 
 *                                    Left() moves robot left
 *                                    Right() moves robot right
 *                       
 * 
 **/
using System;
public class SubRobot : irobot, isubmersible,irotate,iTran{
     private robot robotObj;
     private submersible subObj;
     private int rCoord;
     private int cCoord;
     private int numberofGrids;

     public SubRobot(int robotnum,string file,int numberofGrids){
          this.numberofGrids = numberofGrids;
          if(robotnum == 0){
               robotObj = new robot(file);
          }
          else if(robotnum == 1){
               robotObj = new RotatingRobot(file);
          }
          else{
               robotObj = new TranRobot(file);
          }
          subObj = new submersible(numberofGrids);
          rCoord = robotObj.getRow();
          cCoord = robotObj.getColumn();

     }
     /*
      *PreCondition:none
      *PostCondition: returns int of robot's column value
      */
     public int getColumn(){
          return robotObj.getColumn();
     } 

     /*
      *PreCondition:
      *PostCondition: returns int of robot's row value
      */
     public int getRow(){
          return robotObj.getRow();
     } 
     /*
      *PreCondition:none
      *PostCondition: uses move() the robot depending on the type of robot robotObj is
      */
     public void Move()
     {
          robotObj.Move();
          Check(); 
     }
     /*
      *PreCondition:none
      *PostCondition: uses moveone() the robot depending on the type of robot robotObj is
      */
     public void MoveOne()
     {
          robotObj.MoveOne();
          Check();
     }
     /*
      *PreCondition:none
      *PostCondition: recharges the battery of robot
      */
     public void Recharge()
     {
          robotObj.Recharge();
     } 

     /*
      *PreCondition:none
      *PostCondition: moves column of robot up by 1
      */
     public void Forward()
     {
          robotObj.Forward();
          Check();
     }

     /*
      *PreCondition:none
      *PostCondition: moves row of robot down by 1
      */
     public void Left()
     {
          robotObj.Left();
          Check();
     }

     /*
      *PreCondition:
      *PostCondition: moves row of robot up by 1
      */
     public void Right()
     {
          robotObj.Right();
          Check();
     }

     /*
      *PreCondition:none
      *PostCondition: moves column of robot down by 1
      */
     public void Back()
     {
          robotObj.Back();
          Check();
     }

     /*
      *PreCondition:none
      *PostCondition: rotates orientation of robot
      */
     public void Rotate()
     {
          robotObj.Rotate();
     }

     /*
      *PreCondition:none
      *PostCondition: checks if coordinates of robot are the same and then move robot to next grid if there isn't wall else previous grid
      */
     private void Check() //Checks if the robot hits a wall and then dives into next grid
     {
          if(robotObj.getColumn() == cCoord && robotObj.getRow() == rCoord && subObj.getDepth() < numberofGrids){ 
               robotObj.setGrid(subObj.dive(robotObj.getRow(),robotObj.getColumn()));
          } 
          if(robotObj.getColumn() == cCoord && robotObj.getRow() == rCoord && subObj.getDepth() >= numberofGrids){ 
               robotObj.setGrid(subObj.climb(robotObj.getRow(),robotObj.getColumn()));
          } 
          rCoord = robotObj.getRow();
          cCoord = robotObj.getColumn(); 
     }
     
}
/*Implementation invariant:
 *                         Check() checks if the robot x coordinate and y coordinate are the same after it moves because then it knows that it hit the wall and then changes the grid of the robot to the next increment
 *                         getRow() gets the row of the robot
 *                         getColumn() gets the column of the robot
 *                         Rotate() rotates robot
 *                         This class inherits from interfaces of submersive and robot and its decended classes
 *                         
 */