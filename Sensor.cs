/**
 * Author:Shaun Lee
 * Platform:VSCode
 * Class Overview: 
 * Class Invariant:
 * Interface Invariant:
 **/

using System;
public class Sensor
{
   private bool state;
   private double battery;
   private double drainRate;
   private readonly double min = 0.1;
   private readonly double max = 100;
   private Random random = new Random();  
   public Sensor()
   {
      battery = 15;
      // drainRate = random.NextDouble() * (max - min) + min;
      drainRate = 1;
      state = true;
   }

   private void drain()
   {
      battery -= drainRate;
   }
   public bool isValid()
   {
      checkBattery();
      if(state)
      {
         drain();
         return true;
      }
      return false;
   }

   private void checkBattery()
   {
      if (battery <= 10) state = false;
   }

   public bool getState()
   {
      return state;
   }

   public void Recharge()
   {
      System.Threading.Thread.Sleep(2000);
      battery = 100;
      state = true;
   }
   
}
//Implementation invariant: