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
            
        }
        static public int[,] readfile(string filename)
        {
        const int SIZE = 11;
        int[,] grid = new int [SIZE,SIZE];
        int count = 0;
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

        return grid;
    }
 
}
