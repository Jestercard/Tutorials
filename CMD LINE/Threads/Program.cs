using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Threads
{
    class Program
    {
        static void Main(string[] args)
        {

            Enumerable.Range(0, 1000).ToList().ForEach(f =>
             {
                 ThreadPool.QueueUserWorkItem((o) =>
                 {
                     Console.WriteLine($"Thread number: {Thread.CurrentThread.ManagedThreadId} started");
                     Thread.Sleep(1000);
                     Console.WriteLine($"Thread number: {Thread.CurrentThread.ManagedThreadId} ended");
                 });
             });

            Console.ReadLine();
        }
    }
}
