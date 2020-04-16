/* 
 * Author:Shaun Lee
 * Driver Overview: Tests out the functionality of Sensor.cs
 * Additional Note: In the output the number on the right side of isValid is the battery after isValid
 */
using System;
class MainClass 
{
        static int SIZE = 10;
        public static void Main(string[] args)
        {
                Sensor[] arr = getSensorArr();
                for(int i = 0; i < SIZE; i++)
                {
                        Console.WriteLine("Battery " + i + " initial battery " + arr[i].getBattery());
                        testisValid(arr[i]);
                        testRecharge(arr[i]);
                } 
                
        }
        /*
         *Precondition:none 
         *Postcondition: returns an array of sensor objects
         */
        
        static Sensor[] getSensorArr()
        { 
                Sensor[] arr = new Sensor[SIZE];
                for(int i = 0; i < SIZE; i++)
                {
                        arr[i] = new Sensor();
                }
                return arr;
        }
         /*
         *Precondition:sensor obj
         *Postcondition: tests out isValid() function
         */

        static void testisValid(Sensor obj)
        {
                int count = 0;
                while(obj.getState())
                {
                        Console.WriteLine("isValid: " + obj.isValid() + " Battery:" + obj.getBattery());
                        count++;
                }
                Console.WriteLine("usage: " + count + "\n");
        }
         /*
         *Precondition:sensor obj
         *Postcondition: tests out recharge function
         */

        static void testRecharge(Sensor obj)
        {
                Console.WriteLine("recharging Sensor takes 2 seconds...");
                obj.Recharge();
                Console.WriteLine("Is sensor on? " + obj.getState() + ". testing isValid: " + obj.isValid() + "\n");
        }

}