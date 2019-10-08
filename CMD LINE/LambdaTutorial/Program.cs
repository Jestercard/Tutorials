using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LambdaTutorial
{
    class Program
    {
        public delegate int SomeMath(int i);

        public delegate bool Compare(int i, Number n);


        static void Main(string[] args)
        {
            DoSomething();
            Console.ReadLine();

        }

        public static void DoSomething()
        {
            SomeMath math = new SomeMath(Square);
            Console.WriteLine(math(8));

            List<int> list = new List<int> { 1, 2, 3, 4, 5, 6, 7 };

            List<int> evenNumbers = list.FindAll(delegate (int i)
            {
                return (i % 2 == 0);
            });
            foreach (int even in evenNumbers)
            {
                Console.WriteLine(even);
            }

            // lambda form
            // parameter => expression/statement block

            List<int> oddNumbers = list.FindAll(i => i % 2 != 0);
            oddNumbers.ForEach(i =>
            {
                Console.Write("Odd Number: ");
                Console.WriteLine(i);
            });

            math = new SomeMath(x => x * x * x);
            Console.WriteLine(math(8));

            Compare comp = (a, number) => a == number.n;
            Console.WriteLine(comp(5, new Number { n = 5 }));
        }

        public static int Add(int a, int b)
        {
            return a + b;
        }
        public static int Square(int i)
        {
            return i * i;
        }
        public static int TimesTen(int i)
        {
            return i * 10;
        }
    }

    public class Number
    {
        public int n {get; set; }
    }
}
