/* 
 * Author:Shaun Lee
 * Driver Overview: Tests out the functionality of Sensor.cs
 * Additional Note: In the output the number on the right side of isValid is the battery after isValid
 */
using System;

class MainClass 
{
        public static void Main(string[] args)
        {
            // robot a = new robot("/Users/shaunlee/Documents/GitHub/temp/P3/grid.txt",1);
        
            string text = System.IO.File.ReadAllText(@"grid.txt");

            System.Console.WriteLine("Contents of test.txt = {0}", text);

            Console.ReadLine();


        }
}