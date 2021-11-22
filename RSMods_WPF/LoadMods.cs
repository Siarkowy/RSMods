﻿using System.Collections.Generic;
using System.IO;

namespace RSMods_WPF
{
    class LoadMods
    {
        /// <summary>
        /// Load Mods into a list, title LoadMods.Mods;
        /// </summary>
        public LoadMods()
        {
            Mods.Clear();

            // Toggle Loft
            _ = new Mod("Toggle Loft", "Toggle Switches", "ToggleLoft", "Make the background of the game black", "on", new Pages.ModPages.ToggleLoft());
            _ = new Mod("Toggle Loft When", "Toggle Switches", "ToggleLoftWhen", "When should we make the background of the game black?", "manual", _ShowInModsTab: false);

            // Disable Headstock
            _ = new Mod("Remove Headstock", "Toggle Switches", "Headstock", "Removes the headstock", "off", new Pages.ModPages.DisableHeadstock());
            _ = new Mod("Remove Headstock When", "Toggle Switches", "RemoveHeadstockWhen", "When should we disabled the headstock?", "song", _ShowInModsTab: false);

            // Song Timer
            _ = new Mod("Show Song Timer", "Toggle Switches", "ShowSongTimer", "Show the current time in the song", "off", new Pages.ModPages.SongTimer());
            _ = new Mod("Show Song Timer When", "Toggle Switches", "ShowSongTimerWhen", "When should we show the song timer?", "manual", _ShowInModsTab: false);

            // Remove Inlays
            _ = new Mod("Remove Inlays", "Toggle Switches", "Inlays", "Removes the inlays from your guitar or bass. Use the dot inlay when using this.", "off");

            // Fretless / Remove Frets
            _ = new Mod("Remove Frets", "Toggle Switches", "Fretless", "Removes the fret-wire on frets to appear as if you're playing a fretless instrument.", "off");

            // Remove Lane Markers
            _ = new Mod("Remove Lanemarkers", "Toggle Switches", "LaneMarkers", "Removes un-used lanes when playing a song to create a cleaner UI.", "off");

            // Stop Song Previews
            _ = new Mod("Stop Song Previews", "Toggle Switches", "SongPreviews", "Stops the song automatically playing when hovering over it in the menu.", "off");

            // Rainbow Strings
            _ = new Mod("Rainbow Strings", "Toggle Switches", "RainbowStrings", "Make your strings scroll through the color wheel.", "off");

            // Rainbow Notes
            _ = new Mod("Rainbow Notes", "Toggle Switches", "RainbowNotes", "Make the notes scroll through the color wheel.", "off");

            // Green Screen Wall (like Toggle Loft but amps are still visible)
            _ = new Mod("Greenscreen Wall", "Toggle Switches", "GreenScreenWall", "Remove the back wall of the game. Similar to \"Toggle Loft\" but you can see the amps.", "off");

            // Screenshot Scores
            _ = new Mod("Screenshot Scores", "Toggle Switches", "ScreenShotScores", "Automatically takes a Steam screenshot (by pressing F12) when you finish a song.", "off");

            // Show Current Note on Screen
            _ = new Mod("Show Current Note on Screen", "Toggle Switches", "ShowCurrentNoteOnScreen", "Shows you the name of the note you are currently playing. Does not work with chords.", "off");

            Mods.Sort((x, y) => string.Compare(x.UIName, y.UIName));
            WriteSettingsFile();
        }

        /// <summary>
        /// <para>A dictionary of what the Settings File says the mod should be.</para>
        /// <para>Use this for caching the Settings File so we aren't wasting time re-reading the same file over, and over again.</para>
        /// </summary>
        public static Dictionary<string, object> SettingsFile_Cache = new();

        /// <summary>
        /// A list of all the Mods.
        /// </summary>
        public static List<Mod> Mods = new();

        public static void WriteSettingsFile(Mod changedMod = null)
        {
            using StreamWriter sw = File.CreateText(Settings.SettingsFile);
            Dictionary<string, List<Mod>> splitModsIntoSections = new();

            foreach (Mod mod in Mods)
            {
                if (splitModsIntoSections.ContainsKey(mod.Section))
                    splitModsIntoSections[mod.Section].Add(mod);
                else
                    splitModsIntoSections.Add(mod.Section, new() { mod });
            }

            if (changedMod != null)
                splitModsIntoSections[changedMod.Section][splitModsIntoSections[changedMod.Section].FindIndex(mod => mod.SettingName == changedMod.SettingName)] = changedMod;

            foreach (string section in splitModsIntoSections.Keys)
            {
                sw.WriteLine("[" + section + "]");

                foreach (Mod mod in splitModsIntoSections[section])
                {
                    if (mod.Value == null)
                        sw.WriteLine(mod.SettingName + " = " + mod.DefaultValue);
                    else
                        sw.WriteLine(mod.SettingName + " = " + mod.Value);
                }
            }
        }
    }
}
