using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassesChallenge
{
    class Employee
    {
        // properties
        protected string Name { get; set; }
        protected string FirstName { get; set; }
        protected int Salary { get; set; }

        // constructors
        public Employee()
        {
            Name = "Barajas";
            FirstName = "Jesse";
            Salary = 10000;
        }
        public Employee(string name, string firstName, int salary)
        {
            this.Name = name;
            this.FirstName = firstName;
            this.Salary = salary;
        }


        // methods
        public void Work()
        {
            Console.WriteLine("{0} is working.", FirstName);
        }

        public void Pause()
        {
            Console.WriteLine("{0} {1} is having a break.", FirstName, Name);
        }
    }
}
