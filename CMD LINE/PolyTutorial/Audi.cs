using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PolyTutorial
{
    class Audi:Car
    {
        private string Brand = "Audi";

        protected string Model { get; set; }

        public Audi() { }

        public Audi(string model, int hP, string color) : base(hP, color)
        {
            this.Model = model;
        }
        public new void ShowDetails()
        {
            Console.WriteLine("The {0} is the color {1} and has {2} HorsePower!", Brand, Color, HP);
        }

        public override void Repair()
        {
            Console.WriteLine("The Audi {0} was repaired!", Model);
        }
    }
}
