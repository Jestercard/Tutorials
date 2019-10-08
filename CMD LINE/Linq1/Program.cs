using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Linq1
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] number = new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

            OddNumbers(number);

            Console.ReadLine();

        }

        static void OddNumbers(int[] numbers)
        {
            Console.WriteLine("Odd Numbers: ");

            IEnumerable<int> oddNumbers = from number in numbers where number % 2 != 0 select number;

            Console.WriteLine(oddNumbers);

            foreach(int i in oddNumbers)
            {
                Console.WriteLine(i);
            }
        }
    }
}
