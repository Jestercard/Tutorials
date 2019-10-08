using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IntrotoClasses
{
    //this class is a blueprint for a datatype
    class Human
    {
        //member variable
        private string firstName;
        private string lastName;
        private string eyeColer;
        private int age;

        //constructor
        public Human(string firstName, string lastName, string eyeColer, int age)
        {
            this.firstName = firstName;
            this.lastName = lastName;
            this.eyeColer = eyeColer;
            this.age = age;
        }

        //member method
        public void IntroduceMyself()
        {
            Console.WriteLine("Hi, I'm {0} {1}", firstName, lastName);
            Console.WriteLine("My eyecolor is {0} and I am {1} years old.", eyeColer, age);
        }
    }
}
