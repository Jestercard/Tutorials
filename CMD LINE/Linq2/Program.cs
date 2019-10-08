using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Linq2
{
    class Program
    {
        static void Main(string[] args)
        {
            UniversityManager um = new UniversityManager();

            um.StudentAndUniversityNameCollection();

            //um.MaleStudents();
            //Console.WriteLine("");
            //um.FemaleStudents();
            //Console.WriteLine("");
            //um.SortStudentsByAge();
            //Console.WriteLine("");
            //um.AllStudentsFromBeijingTech();
            //Console.Write("Enter a Uni ID: ");
            //string input = Console.ReadLine();
            //bool success = int.TryParse(input, out int uniID);
            //if (success)
            //{
            //    um.AllStudentsFromThatUni(uniID);
            //}
            //else
            //{
            //    Console.WriteLine("What you doin?");
            //}


            Console.ReadLine();
        }
    }
}
