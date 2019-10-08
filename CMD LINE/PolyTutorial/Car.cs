using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PolyTutorial
{
    class Car
    {
        protected int HP { get; set; }
        protected string Color { get; set; }

        // Has a relationship
        protected CarIDinfo carIDInfo = new CarIDinfo();

        public void SetCarIDInfo(int idNum, string owner)
        {
            carIDInfo.IDNum = idNum;
            carIDInfo.Owner = owner;
        }

        public void GetCarIDInfo()
        {
            Console.WriteLine("The car has the ID of {0} and is owned by {1}", carIDInfo.IDNum, carIDInfo.Owner);
        }

        public Car()
        {
            HP = 1000;
            Color = " ";
        }

        public Car(int hP, string color)
        {
            this.HP = hP;
            this.Color = color;
        }

        public void ShowDetails()
        {
            Console.WriteLine("The car is the color {0} and has {1} HorsePower!", Color, HP);
        }

        public virtual void Repair()
        {
            Console.WriteLine("The car was repaired!");
        }
    }
}
