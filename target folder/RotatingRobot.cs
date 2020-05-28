using System;
public class RotatingRobot : robot
{
    private sensor leftSensor;
    private sensor rightSensor;
    private sensor straightSensor;
    private int rotateNum;
    private orientation objOrientation;
    protected enum orientation
        {
            Up,
            Down,
            Left,
            Right
        }

    public RotatingRobot(string str,int drainRate) : base(str,drainRate)
    {
       objOrientation = orientation.Up; 
    }
    public void Rotate()
    {
        if(objOrientation = orientation.Up) objOrientation = orientation.Right;
        else if(objOrientation = orientation.Right) objOrientation = orientation.Down;
        else if(objOrientation = orientation.Down) objOrientation = orientation.Left;
        else objOrientation = orientation.Up;
    }

}