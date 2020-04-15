/* 
 * Author:Shaun Lee
 * Driver Overview:
 */
using System;
class MainClass 
{
        public static void Main(string[] args)
        {
                Sensor myObj = new Sensor();
                Console.WriteLine(myObj.isValid());
                Console.WriteLine(myObj.isValid());
                Console.WriteLine(myObj.isValid());
                Console.WriteLine(myObj.isValid());
                Console.WriteLine(myObj.isValid());
                Console.WriteLine(myObj.isValid());
                Console.WriteLine(myObj.isValid());
                Console.WriteLine(myObj.isValid());
                Console.WriteLine(myObj.isValid());
                Console.WriteLine(myObj.isValid());
                Console.WriteLine(myObj.isValid());
                myObj.Recharge();
                Console.WriteLine(myObj.isValid());

        }
}