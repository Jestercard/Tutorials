using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PolyTutorial
{
    class M3:BMW
    {

        public M3(string model, int hP, string color) : base(model, hP, color) { }

        /*
        public override void Repair()
        {
            base.Repair();
        }
        */
    }
}
