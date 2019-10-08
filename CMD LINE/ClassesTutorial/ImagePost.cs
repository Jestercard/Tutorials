using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassesTutorial
{
    // ImagePost derives from Post and adds a property (ImageURL) and two constructors

    class ImagePost:Post
    {
        protected string ImageURL { get; set; }

        public ImagePost() { }

        public ImagePost(string title, string sendByUsername, string imageURL, bool isPublic)
        {
            // THe following properties and the GetNextID are inherited from Post
            this.ID = GetNextID();
            this.Title = title;
            this.SendByUsername = sendByUsername;
            this.IsPublic = IsPublic;

            // Property ImageURL is a member of ImagePost, but not Post
            this.ImageURL = imageURL;

        }

        public override string ToString()
        {
            return String.Format("{0} - {1} - {2} - by {3}", this.ID, this.Title, this.ImageURL, this.SendByUsername);
        }

    }
}
