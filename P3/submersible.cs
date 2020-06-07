
using System;
public class submersible : isubmersible
{
    private int rCoord;
    private int cCoord;
    string[] arrayofgrid;
    
   public submersible(int n)
    {
        arrayofgrid = new string[n];
        rCoord = 5;
        cCoord = 5;
        for(int i = 0; i < n; i ++)
        {
            arrayofgrid[i] = "Grid" + i + ".txt";
            Console.WriteLine(arrayofgrid[i]);
        }
    }

    public void printArr(int num)
    {
 
    }

    int[,] readfile(string filename)
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