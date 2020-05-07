/**
 * Author:Shaun Lee
 * Platform:CLion
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




public class sensor
{

	//TODO don't forget to remove this function
	public double getdrainRate()
	{
		return drainRate;
	}

	public sensor(double input)
	{
		if (input > 100 || input < 0)
		{
			input = 1; //document this design decision
		}
		battery = 100;
		drainRate = input;
		state = true;
	}

	/*
	*Precondition: initialized class
	*Postcondition: decreases the battery based on the drainRate.
	*/
	public void drain()
	{
		if (battery == 0 || !state)
		{
			return;
		}
		battery -= drainRate;
		if (battery < 0)
		{
			battery = 0;
		}
	}

	/*
	*Precondition:None
	*Postcondition: returns true or false based on the battery
	 */
	public bool isValid(int digit)
	{
		checkBattery();
		if (state)
		{
			drain();
			return (digit == 1);
		}
		return false;
	}

	/*
	   *Precondition:none
	   *Postcondition: changes the state to true and battery to 100
	   */
	public void Recharge()
	{
		std::this_thread.sleep_for(std::chrono.milliseconds(200));
		battery = 100;
		state = true;
	}

	public double getBattery()
	{
		return battery;
	}

	private bool state;
	private double battery;
	private double drainRate;
	/*
	 *Precondition:none
	 *Postcondition:changes the state of state if battery is at 10% or below
	 */
	private void checkBattery()
	{
		if (battery <= 10)
		{
			state = false;
		}
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
 * changed the drainRate of the battery for the sensor instead of internally generated. We pass in the drainRate through the sensor's constructor
 */