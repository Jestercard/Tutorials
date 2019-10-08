using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassesChallenge
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Test");
            Console.ReadLine();

            Employee jesse = new Employee("Barajas", "Jesse", 50000);
            jesse.Work();
            jesse.Pause();

            Boss chuck = new Boss("Norris", "Chuck", 100000, "Chrysler");
            chuck.Work();
            chuck.Lead();
            chuck.Pause();

            Trainee sandra = new Trainee("Barajas", "Sandra", 30000, 40, 40);
            sandra.Learn();
            sandra.Work();
            sandra.Pause();


            Console.ReadLine();
        }
    }
}
