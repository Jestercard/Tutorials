using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PolyTutorial
{
    class Program
    {
        static void Main(string[] args)
        {
            var cars = new List<Car>
            {
                new Audi("A4", 200, "blue"),
                new BMW("M3", 250, "red")
            };

            foreach(var car in cars)
            {
                car.Repair();
            }

            Car bmwZ3 = new BMW("Z3", 200, "black");
            Car audiA3 = new Audi("A3", 150, "green");

            bmwZ3.ShowDetails();
            audiA3.ShowDetails();

            bmwZ3.SetCarIDInfo(1234, "Jesse B");
            audiA3.SetCarIDInfo(1235, "Sanders B");

            bmwZ3.GetCarIDInfo();
            audiA3.GetCarIDInfo();

            BMW bmwM5 = new BMW("M5", 250, "purple");
            bmwM5.ShowDetails();

            Car carb = (Car)bmwM5;
            carb.ShowDetails();

            BMW carc = (BMW)bmwZ3;
            carc.ShowDetails();

            M3 myM3 = new M3("M3 Super", 260, "Brown");
            myM3.Repair();

            Console.ReadLine();
        }
    }
}
