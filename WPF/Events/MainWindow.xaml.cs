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

namespace WPFTutorial3
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

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            MessageBox.Show("Button Was Clicked - Direct Event");
        }

        private void Button_MouseUp(object sender, MouseButtonEventArgs e)
        {
            MessageBox.Show("Mouse Button Went Up - Bubbling Event");
        }

        private void Button_PreviewMouseUp(object sender, MouseButtonEventArgs e)
        {
            MessageBox.Show("Mouse Button Went Up - Tunneling Event");
        }

        private void Button_PreviewMouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            MessageBox.Show("Left Mouse Button Went Down - Tunneling Event");
        }

        private void Button_PreviewMouseRightButtonUp(object sender, MouseButtonEventArgs e)
        {
            MessageBox.Show("Right Mouse Button Went Up - Tunneling Event");
        }
        /*
         * Routed Events - WPF mechanisms to handle events
         * Direct routed events - handled by the item itself (e.g. click)
         * 
         * Bubbling Event - Bubbling happens when the event is not handled by the element
         * (say a textbox) and the event "bubbles" its way up the UI containers which hold it.
         * For Example, let's say you have a window that contains a panel. Inside the panel
         * you have a grid, and inside the grid you have a textbox. If the event is not handled by the textbox,
         * then it moves, is passed or "bubbles" up the grid level (as the grid contains the textbox),
         * if it is not handled at that level then the event bubbles further up the "tree" (known as the visual tree)
         * to the panel where it may or may not be handled. This process continues until it is handled or the event
         * "escapes" the top most element.
         * Examples of a bubbling event would be something like a MouseButtoneDown event, or a Keydown event.
         * 
         * Tunneling Event - Tunneling is the opposite of Bubbling. So instead of an event going "up" the visual tree,
         * the event travels down the visual tree toward the element that is considered the source.
         * That standard WPF naming definition of a tunneling event is that they all start with "preview"
         * for examples PreviewDownKey and PreviewMouseButtonDown. You can catch them on their way to the "Target"
         * element and handle it. An example for this might be perhaps you have some controls inside
         * a grid control and for some reason you have decided that no control within the grid will
         * be allowed to have the letter "t" reach it.
         */
    }
}
