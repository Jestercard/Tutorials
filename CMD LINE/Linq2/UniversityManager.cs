using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Linq2
{
    class UniversityManager
    {
        public List<University> universities;
        public List<Student> students;

        public UniversityManager()
        {
            universities = new List<University>();
            students = new List<Student>();

            universities.Add(new University { Id = 1, Name = "Yale" });
            universities.Add(new University { Id = 2, Name = "Beijing Tech" });

            students.Add(new Student { Id = 1, Name = "Carla", Gender = "Female", Age = 17, UniversityId = 1 });
            students.Add(new Student { Id = 2, Name = "Toni", Gender = "Male", Age = 21, UniversityId = 1 });
            students.Add(new Student { Id = 3, Name = "Frank", Gender = "Male", Age = 22, UniversityId = 2 });
            students.Add(new Student { Id = 4, Name = "Leyla", Gender = "Female", Age = 19, UniversityId = 2 });
            students.Add(new Student { Id = 5, Name = "James", Gender = "Trans-Gender", Age = 25, UniversityId = 2 });
            students.Add(new Student { Id = 6, Name = "Linda", Gender = "Female", Age = 22, UniversityId = 2 });
        }

        public void MaleStudents()
        {
            IEnumerable<Student> maleStudents = from student in students where student.Gender == "Male" select student;
            Console.WriteLine("Male - Students: ");
            foreach(Student student in maleStudents)
            {
                student.Print();
            }
        }
        public void FemaleStudents()
        {
            IEnumerable<Student> femaleStudents = from student in students where student.Gender == "Female" select student;
            Console.WriteLine("Female - Students: ");
            foreach(Student student in femaleStudents)
            {
                student.Print();
            }
        }
        public void SortStudentsByAge()
        {
            var sortedStudents = from student in students orderby student.Age select student;

            Console.WriteLine("Students sorted by Age: ");

            foreach(Student student in sortedStudents)
            {
                student.Print();
            }
        }

        public void AllStudentsFromBeijingTech()
        {
            IEnumerable<Student> bjtStudents = from student in students
                                               join university in universities
                                               on student.UniversityId equals university.Id
                                               where university.Name == "Beijing Tech"
                                               select student;

            Console.WriteLine("Students in Beijing Tech: ");

            foreach(Student student in bjtStudents)
            {
                student.Print();
            }
        }
        public void AllStudentsFromThatUni(int id)
        {
            IEnumerable<Student> uniStudents = from student in students
                                               join university in universities
                                               on student.UniversityId equals university.Id
                                               where university.Id == id
                                               select student;

            Console.WriteLine("Students in the selected university ({0}) are: ", id);

            foreach(Student student in uniStudents)
            {
                student.Print();
            }
        }
        public void StudentAndUniversityNameCollection()
        {
            var newCollection = from student in students
                                join university in universities
                                on student.UniversityId equals university.Id
                                orderby student.Name
                                select new { StudentName = student.Name, UniversityName = university.Name };

            Console.WriteLine("New Collections: ");
            foreach(var col in newCollection)
            {
                Console.WriteLine("Student {0} from University {1}", col.StudentName, col.UniversityName);
            }
        }
    }
}
