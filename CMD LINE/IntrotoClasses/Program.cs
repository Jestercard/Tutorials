using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IntrotoClasses
{
    class Program
    {
        static void Main(string[] args)
        {

            Human jesse = new Human("Jesse", "Barajas", "Brown", 25);
            jesse.IntroduceMyself();
            
            Human michael = new Human("Carly", "Burkhard", "Hazel", 25);
            michael.IntroduceMyself();

            Console.ReadLine();
        }
    }
}
