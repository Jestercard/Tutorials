using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace FileIOTutorial
{
    class Program
    {
        static void Main(string[] args)
        {

            // Method 1 - write
            string[] lines = { "First 250", "100", "260", "Third 472" };
            File.WriteAllLines(@"G:\Repositories\_NOT_ON_GIT\FileIOTutorial\HighScores.txt", lines);
            
            // Method 2 - write
            Console.WriteLine("Please give the file a name");
            string filename = Console.ReadLine();
            Console.WriteLine("Please give the text for the file");
            string input = Console.ReadLine();
            File.WriteAllText(@"G:\Repositories\_NOT_ON_GIT\FileIOTutorial\" + filename + ".txt", input);
            
            //Method 3 - write
            using(StreamWriter file = new StreamWriter(@"G:\Repositories\_NOT_ON_GIT\FileIOTutorial\myText2.txt"))
            {
                foreach(string line in lines)
                {
                    if (line.Contains("2"))
                    {
                        file.WriteLine(line);
                    }
                }
            }
            using(StreamWriter file = new StreamWriter(@"G:\Repositories\_NOT_ON_GIT\FileIOTutorial\myText2.txt", true))
            {
                file.WriteLine("Additional line");
            }
            
            //Example 1 = reading Text
            string text = System.IO.File.ReadAllText(@"G:\Repositories\_NOT_ON_GIT\FileIOTutorial\TextFile.txt");
            Console.WriteLine("TextFile contains the following text: {0}", text);

            //Example 2 = reading Lines
            string[] lines2 = System.IO.File.ReadAllLines(@"G:\Repositories\_NOT_ON_GIT\FileIOTutorial\TextFile.txt");
            Console.WriteLine("Contents of TextFile.txt = ");
            foreach(string line in lines2)
            {
                Console.WriteLine("\t" + line);
            }           

            Console.ReadLine();
        }
    }
}
