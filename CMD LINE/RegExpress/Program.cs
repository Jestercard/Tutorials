using System;
using System.Text.RegularExpressions;

namespace RegExpress
{
    class Program
    {
        static void Main(string[] args)
        {
            /*
            Console.WriteLine("Hello World!");
            string pattern = @"\d{5}";
            Regex regex = new Regex(pattern);

            string text = "Hi there, my number is 12314";

            MatchCollection matchcollection = regex.Matches(text);

            Console.WriteLine("{0} hits found:\n {1}", matchcollection.Count, text);

            foreach(Match hit in matchcollection)
            {
                GroupCollection group = hit.Groups;
                Console.WriteLine("{0} found at {1}", group[0].Value, group[0].Index);
            }
            */

            DateTime dateTime = new DateTime();
            DateTime now = DateTime.Now;

            Console.WriteLine(DateTime.Today.DayOfWeek);

            Console.WriteLine("The time is {0} o'clock and {1} minutes and {2} seconds", DateTime.Now.Hour, DateTime.Now.Minute, DateTime.Now.Second);

            Console.WriteLine("Enter Your Birthday in this format: yyyy-mm-dd: ");
            string input = Console.ReadLine();
            if(DateTime.TryParse(input, out dateTime))
            {
                Console.WriteLine(dateTime);
                TimeSpan dayspassed = now.Subtract(dateTime);
                Console.WriteLine("You are {0} days old!", dayspassed.Days);
            }
            else
            {
                Console.WriteLine("Wrong Input");
            }


            Console.Write("Press any key to continue...");
            Console.ReadLine();
        }
    }
}
