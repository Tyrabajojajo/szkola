
using System.Windows;

namespace LicznikWPF
{
    public partial class MainWindow : Window
    {
        private int count = 0;

        public MainWindow()
        {
            InitializeComponent();
        }

        private void Increment(object sender, RoutedEventArgs e)
        {
            count++;
            CounterBlock.Text = count.ToString();
        }

        private void Decrement(object sender, RoutedEventArgs e)
        {
            count--;
            CounterBlock.Text = count.ToString();
        }

        private void ResetCounter(object sender, RoutedEventArgs e)
        {
            count = 0;
            CounterBlock.Text = count.ToString();
        }
    }
}
