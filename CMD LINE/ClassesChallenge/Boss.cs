using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassesChallenge
{
    class Boss:Employee
    {
        protected string CompanyCar { get; set; }

        public Boss() { }
        public Boss(string name, string firstName, int salary, string companyCar):base(name, firstName, salary)
        {
            this.CompanyCar = companyCar;
        }

        public void Lead()
        {
            Console.WriteLine("I, {0}, am the boss! I make {1} money a year", FirstName, Salary);
        }
    }
}
