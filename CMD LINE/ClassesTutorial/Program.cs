using System;
using System.Globalization;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassesTutorial
{
    class Program
    {
        static void Main(string[] args)
        {
            Post post1 = new Post("Thanks for the birthday wishes", true, "Jesse Barajas");
            Console.WriteLine(post1.ToString());
            

            ImagePost imagePost1 = new ImagePost("Check out my new shoes", "Jesse Barajas", 
                "https://images.com/shoes", true);
            Console.WriteLine(imagePost1.ToString());

            VideoPost videoPost1 = new VideoPost("Here I am on Vacation!", "Jesse Barajas",
                "https://video.com/vacation", 30, true);
            Console.WriteLine(videoPost1.ToString());

            videoPost1.Play();
            Console.WriteLine("Press any key to stop the video.");
            Console.ReadKey();
            videoPost1.Stop();

            Console.ReadLine();
        }
    }
}
