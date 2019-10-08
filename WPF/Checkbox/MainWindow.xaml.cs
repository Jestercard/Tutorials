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

namespace Checkbox
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void cbAllCheckedChanged(object sender, RoutedEventArgs e)
        {
            bool newVal  = (cbAllToppings.IsChecked == true);
            cbSalami.IsChecked = newVal;
            cbMushroom.IsChecked = newVal;
            cbPepporoni.IsChecked = newVal;

        }
        private void cbSingleCheckedChanged(object sender, RoutedEventArgs e)
        {
            cbAllToppings.IsChecked = null;
            if((cbSalami.IsChecked == true) && (cbMushroom.IsChecked == true) && (cbPepporoni.IsChecked == true))
            {
                cbAllToppings.IsChecked = true;
            }
            if ((cbSalami.IsChecked == false) && (cbMushroom.IsChecked == false) && (cbPepporoni.IsChecked == false))
            {
                cbAllToppings.IsChecked = false;
            }
        }
    }
}
