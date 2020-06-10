/* 
 * Author:Shaun Lee
 * Driver Overview: This tests out robot,rotatingRobot,TranRobot 
 */
using System;

class MainClass 
{
        const string directory = "grid.txt"; 
        const int SIZE = 9;
        public static void Main(string[] args)
        {
            robot[] arr = generateRobot(); 
            Console.WriteLine("\n");
            Console.WriteLine("intializing test for robot");
            for(int i = 0; i < 3; i++)
            {
                testRobot(arr[i]);
            }
            Console.WriteLine("\n");
            Console.WriteLine("intializing test for rotatingbot");
            for(int i = 3;i < 6; i++)
            {
                testRotatingRobot((RotatingRobot)arr[i]);
            }
            Console.WriteLine("\n");
            Console.WriteLine("intializing test for transRobot");
            for(int i = 6; i < 9; i++)
            {
                testTranRobot((TranRobot)arr[i]);
            }
        }
        
        public static void testRobot(robot obj)
        {
            printRobotCoord(obj);
            Console.WriteLine("used moveone()");
            obj.MoveOne();
            printRobotCoord(obj);
            obj.Move();
            Console.WriteLine("used move()");
            printRobotCoord(obj);
        }

        public static void testRotatingRobot(RotatingRobot obj)
        {

            Console.Write("object initially facing north "); 
            printRotationRobotCoord(obj);
            obj.Move();
            Console.Write("used move() ");
            printRotationRobotCoord(obj);
            Console.Write("used Rotate() ");
            obj.Rotate();
            Console.Write("object facing east ");
            printRotationRobotCoord(obj);
            obj.Move();
            Console.Write("used move() ");
            printRotationRobotCoord(obj);
            obj.Rotate();
            Console.Write("used Rotate() ");
            Console.Write("object facing south ");
            printRotationRobotCoord(obj);
            obj.Move();
            Console.Write("used move() ");
            printRotationRobotCoord(obj);
            obj.Rotate();
            Console.Write("used Rotate() ");
            Console.Write("object facing west ");
            printRotationRobotCoord(obj);
            obj.Move();
            Console.Write("used move() ");

        }


        public static void testTranRobot(TranRobot obj)
        {
            Console.WriteLine("robot is intially at ");
            printTransRobotCoord(obj);
            obj.Forward();
            Console.Write("robot used forward()");
            printTransRobotCoord(obj);
            obj.Forward();
            Console.Write("robot used forward()");
            printTransRobotCoord(obj);
            obj.Left();
            Console.Write("robot used left()");
            printTransRobotCoord(obj);
            obj.Right(); 
            Console.Write("robot used Right()");
            printTransRobotCoord(obj);
            obj.Back();
            Console.Write("robot used Back()");
            printTransRobotCoord(obj);

        }

        public static void printRobotCoord(robot obj)
        {
            Console.WriteLine("row:{0} Column:{1}",obj.getRow(),obj.getColumn());
        }
        public static void printRotationRobotCoord(RotatingRobot obj)
        {
            Console.WriteLine("row:{0} Column:{1}",obj.getRow(),obj.getColumn()); 
        }
        public static void printTransRobotCoord(TranRobot obj)
        {
            Console.WriteLine("row:{0} Column:{1}",obj.getRow(),obj.getColumn()); 
        }
        public static robot[] generateRobot()
        {
           int batterylife = 1;
           robot[] arr = new robot[SIZE];
           for(int i = 0; i < 3; i++)
           {
             arr[i] = new robot(directory,batterylife);
           } 

           for(int i = 3; i < 6; i++)
           { 
             arr[i] = new RotatingRobot(directory,batterylife);
           } 

           for(int i = 6; i < 9; i++)
           {
               arr[i] = new TranRobot(directory,batterylife);
           } 
           return arr;
        }
}
