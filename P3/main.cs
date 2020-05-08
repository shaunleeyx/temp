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
        
            // string text = System.IO.File.ReadAllText("grid.txt");
            // string ss = text.Replace("\n", " ");
            // ss = string.Join( " ", ss.Split( new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries ));
            // string[] arr = ss.Split(' ');
            // for(int i = 0; i < arr.Length; i++)
            // {
            //     Console.WriteLine(arr[i]);
            // }
            robot a = new robot("grid.txt",1);
            a.Move(0);
            a.Move(3);
            Console.WriteLine(a.getColumn() + " " + a.getRow()); 



        }
}