using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace LinqXML
{
    class Program
    {
        static void Main(string[] args)
        {
            string studentXML =
                @"<Students>
                    <Student>
                        <Name>Toni</Name>
                        <Age>21</Age>
                        <University>Yale</University>
                        <Graduationyear>2012</Graduationyear>
                    </Student>
                    <Student>
                        <Name>Carla</Name>
                        <Age>17</Age>
                        <University>Yale</University>
                        <Graduationyear>2015</Graduationyear>
                    </Student>
                    <Student>
                        <Name>Leyla</Name>
                        <Age>19</Age>
                        <University>Beijing Tech</University>
                        <Graduationyear>2016</Graduationyear>
                    </Student>
                    <Student>
                        <Name>Frank</Name>
                        <Age>37</Age>
                        <University>Yale</University>
                        <Graduationyear>1987</Graduationyear>
                    </Student>
                </Students>";

            XDocument studentsXdoc = new XDocument();
            studentsXdoc = XDocument.Parse(studentXML);

            var students = from student in studentsXdoc.Descendants("Student")
                           select new
                           {
                               Name = student.Element("Name").Value,
                               Age = student.Element("Age").Value,
                               University = student.Element("University").Value,
                               Graduationyear = student.Element("Graduationyear").Value
                           };
            foreach (var student in students)
            {
                Console.WriteLine($"Student {student.Name} with age {student.Age} from University {student.University} graduated in {student.Graduationyear}");
            }

            var studentsSort = from student in students orderby student.Age select student;

            foreach (var student in studentsSort)
            {
                Console.WriteLine($"Student {student.Name} with age {student.Age} from University {student.University} graduated in {student.Graduationyear}");
            }
            Console.ReadLine();
        }
    }
}
