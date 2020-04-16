using Microsoft.VisualStudio.TestTools.UnitTesting;


[TestClass]
public class SensorTest
{
    [TestMethod]
    public void CheckifBatteryIsOnInitially()
    {
        Sensor obj = new Sensor();
        Assert.IsTrue(obj.getState());
    }

    [TestMethod]
    public void CheckIfFirstisValidCallIsTrue()
    {
        Sensor obj = new Sensor();
        Assert.IsTrue(obj.isValid());
    }

    [TestMethod]
    public void CheckIfBatterycanBeDischarged()
    {
        Sensor obj = new Sensor();
        while(obj.getState())
        {
            obj.isValid();
        }
        Assert.IsFalse(obj.isValid());
    }

    [TestMethod]
    public void TestRecharge()
    {
        Sensor obj = new Sensor();
        while (obj.getState())
        {
            obj.isValid();
        }
        obj.Recharge();
        Assert.IsTrue(obj.isValid());

    }
}
