using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Interface
{
    public interface INotifications
    {
        // members
        void showNotification();
        string getDate();
    }

    public class Notification : INotifications
    {
        private string sender;
        private string message;
        private string date;

        public Notification()
        {
            sender = "Admin";
            message = "Hey there!";
            date = " ";
        }

        public Notification(string mySender, string myMessage, string myDate)
        {
            this.sender = mySender;
            this.message = myMessage;
            this.date = myDate;
        }

        public void showNotification()
        {
            Console.WriteLine("Message {0} - was sent by {1} - at {2}", message, sender, date);
        }

        public string getDate()
        {
            return date;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Notification n1 = new Notification("Jesse", "ohai!", "2019-08-01");
            Notification n2 = new Notification("Sandra", "herro", "2019-08-01");

            n1.showNotification();
            n2.showNotification();
            Console.Read();
        }
    }
}
