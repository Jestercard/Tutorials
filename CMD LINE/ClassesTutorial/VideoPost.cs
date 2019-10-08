using System;
using System.Threading;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassesTutorial
{
    class VideoPost:Post
    {
        // member fields
        protected bool isPlaying = false;
        protected int currentDuration = 0;
        Timer timer;


        // Properties
        protected string VideoURL { get; set; }
        protected int Length { get; set; }

        public VideoPost() { }
        public VideoPost(string title, string sendByUsername, string videoURL, int length, bool isPublic)
        {
            this.ID = GetNextID();
            this.Title = title;
            this.SendByUsername = sendByUsername;
            this.VideoURL = videoURL;
            this.Length = length;
            this.IsPublic = isPublic;
        }

        public override string ToString()
        {
            return String.Format("{0} - {1} - {2} - {3} seconds - by {4}",
                this.ID, this.Title, this.VideoURL, this.Length, this.SendByUsername);
        }

        public void Play()
        {
            if (!isPlaying)
            {
                isPlaying = true;
                Console.WriteLine("Playing...");
                timer = new Timer(TimerCallback, null, 0, 1000);
            }
        }

        private void TimerCallback(object o)
        {
            if (currentDuration < Length)
            {
                currentDuration++;
                Console.WriteLine("Video at {0}s", currentDuration);
                GC.Collect();
            }
            else
            {
                Stop();
            }
        }

        public void Stop()
        {
            if (isPlaying)
            {
                isPlaying = false;
                Console.WriteLine("Stopped at {0}", currentDuration);
                currentDuration = 0;
                timer.Dispose();
            }
        }
    }
}
