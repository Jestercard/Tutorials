using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PolyTutorial
{
    class BMW:Car
    {
        private string Brand = "BMW";

        protected string Model { get; set; }

        public BMW() { }

        public BMW(string model, int hP, string color) :base(hP, color)
        {
            this.Model = model;
        }

        public new void ShowDetails()
        {
            Console.WriteLine("The {0} is the color {1} and has {2} HorsePower!", Brand, Color, HP);
        }

        public sealed override void Repair()
        {
            Console.WriteLine("The BMW {0} was repaired!", Model);
        }
    }
}
