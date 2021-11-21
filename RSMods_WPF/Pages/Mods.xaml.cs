﻿using System;
using System.Collections.Generic;
using System.Globalization;
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
using RSMods_WPF.Pages.ModPages;

namespace RSMods_WPF.Pages
{
    /// <summary>
    /// Interaction logic for Mods.xaml
    /// </summary>
    public partial class Mods : Page
    {
        public static Mods Instance = new();
        public Mods()
        {
            InitializeComponent();
            Startup_FillModsList();
        }

        private void Startup_FillModsList()
        {
            _ = new LoadMods();
            ModsDataGrid.ItemsSource = LoadMods.Mods.Where(mod => mod.ShowInModsTab == true).ToList();
        }

        private void ModEnabledStateChange(object sender, RoutedEventArgs e)
        {
            string content = ((DataGridCell)sender).Content.ToString();
            bool @checked = Convert.ToBoolean(content[(content.IndexOf("IsChecked:") + "IsChecked:".Length)..].ToLower());
            string result = @checked ? "on" : "off";

            if (ModsDataGrid.SelectedItem != null && Mod.WhereSettingName(((Mod)ModsDataGrid.SelectedItem).SettingName) != null)
                Mod.WhereSettingName(((Mod)ModsDataGrid.SelectedItem).SettingName).Value = result;
        }

        private void ModSelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (ModsDataGrid.SelectedItem == null || !((Mod)ModsDataGrid.SelectedItem).ShowMoreInfo)
            {
                MoreInfo.Visibility = Visibility.Hidden;
                return;
            }

            MoreInfo.Visibility = Visibility.Visible;
            MoreInfo.DataContext = ((Mod)ModsDataGrid.SelectedItem).ModPage;
        }

        private void MoreInfo_Button(object sender, RoutedEventArgs e)
        {
            ((Mod)ModsDataGrid.SelectedItem).ModPage.LoadSettings(); // Load settings for the Mod Page

            NavigationService.GetNavigationService(this).Navigate(((Mod)ModsDataGrid.SelectedItem).ModPage);
        }
    }

    /// <summary>
    /// Only used for initialization of a Mod's "Enabled" Checkbox.
    /// </summary>
    public class ModEnabledState : IValueConverter
    {
        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            string modState = (string)value;
            return modState == "on";
        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {
            bool modState = (bool)value;
            return modState ? "on" : "off";
        }
    }
}