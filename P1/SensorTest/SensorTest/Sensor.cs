/**
 * Author:Shaun Lee
 * Platform:VSCode
 * Class Overview:This class is for a sensor that sense something that hasn't been implmented probably in p2. For now it
 *                just works if the battery is above a certain threhold 
 * 
 * Class Invariant:  battery cannot be negative. If the battery is below 0 it will default to 0.
 *                   the number variables are all doubles so don't overflow beyond what a double can hold
 *                   isValid has nothing passed in param so its hard to mutate it
 *                   min is the lowest drain rate it can be 
 *                   max is the highest number that the drain rate can be
 *                   drain rate is randomly generated between min and max
 *                 
 * Interface Invariant:     implemented a get call for the client. Because I think it is necessary for the client to know what battery is the sensor at. just like this laptop I'm using
 *                          State is essentially if the sensor is on or off. On is true and off is false.
 *                          getState is a public functionality for the client to know whether the sensor is off or on
 *                          battery starts off at 100% when the sensor is created
 *                          drain() will not work if the sensor is turned off 
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
      battery = 100;
      drainRate = random.NextDouble() * (max - min) + min;
      state = true;
   }
  /*
   *Precondition: initialized class 
   *Postcondition: decreases the battery based on the drainRate.
   */
   private void drain()
   {
      if (battery == 0 || state == false) return;
      battery -= drainRate;
      if(battery < 0) battery = 0;
   }
  /*
   *Precondition:None
   *Postcondition: returns true or false based on the battery
   */
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
  /*
   *Precondition:none
   *Postcondition:changes the state of state if battery is at 10% or below
   */
   private void checkBattery()
   {
      if (battery <= 10) state = false;
   }
   /*
   *Precondition:none
   *Postcondition: returns state
   */   
   public bool getState()
   {
      return state;
   }
  /*
   *Precondition:none
   *Postcondition: changes the state to true and battery to 100
   */
   public void Recharge()
   {
      System.Threading.Thread.Sleep(2000);
      battery = 100;
      state = true;
   }
  /*
   *Precondition:none
   *Postcondition: returns battery
   */
   public double getBattery()
   {
      return battery;
   }
   
}
/*Implementation invariant: 
 * Recharge has a 2 second delay using thread.sleep(2000)
 * getBattery and getState doesn't mutate the data. So its okay functionality for client to have
 * isValid checks the battery every single time its called
 * isValid returns a bool for this version. Will change in future projects.
 * State is off/on of the sensor
 * Sensor is turned off when battery is 10%
 * Battery starts off at 100
 */