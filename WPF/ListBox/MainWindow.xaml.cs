using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace ListBox
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            List<Match> matches = new List<Match>();
            matches.Add(new Match() { Team1 = "Bayern Munich", Team2 = "Real Madrid", Score1 = 3, Score2 = 2, Completion = 85 });
            matches.Add(new Match() { Team1 = "Dallas Cowboys", Team2 = "Houston Astros", Score1 = 6, Score2 = 5, Completion = 70 });
            matches.Add(new Match() { Team1 = "Philly", Team2 = "Oh you know", Score1 = 2, Score2 = 9, Completion = 40 });
            matches.Add(new Match() { Team1 = "Dat one team", Team2 = "o hai!", Score1 = 63, Score2 = 76, Completion = 23 });

            lbMatches.ItemsSource = matches;
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            if(lbMatches.SelectedItem != null)
            {
                MessageBox.Show("Selected Match: "
                    + (lbMatches.SelectedItem as Match).Team1 + " "
                    + (lbMatches.SelectedItem as Match).Score1 + " "
                    + (lbMatches.SelectedItem as Match).Score2 + " "
                    + (lbMatches.SelectedItem as Match).Team2);
            }
        }
    }
    public class Match
    {
        public int Score1 { get; set; }
        public int Score2 { get; set; }
        public string Team1 { get; set; }
        public string Team2 { get; set; }
        public int Completion { get; set; }
    }
}
