using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassesChallenge
{
    class Trainee:Employee
    {
        protected int WorkingHours { get; set; }
        protected int SchoolHours { get; set; }

        public Trainee() { }
        public Trainee(string name, string firstName, int salary, int workingHours, int schoolHours):base(name, firstName, salary)
        {
            this.WorkingHours = workingHours;
            this.SchoolHours = schoolHours;
        }

        public void Learn()
        {
            Console.WriteLine("I, {0}, learn for {1} hours.", FirstName, SchoolHours);
        }

        public new void Work()
        {
            Console.WriteLine("I, {0}, work for {1} hours.", FirstName, WorkingHours);
        }

    }
}
