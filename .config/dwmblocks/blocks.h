//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
    {"", "~/bin/dwm/statusbar/openweather.sh",  1800,   0   },

    {"", "~/bin/dwm/statusbar/data",            30,     0   },
    
    {"", "~/bin/dwm/statusbar/microphone.sh",   0,      12  },

    {"", "~/bin/dwm/statusbar/volume",          0,      10  },

    {"", "~/bin/dwm/statusbar/network",         30,     11  },

	{"", "~/bin/dwm/statusbar/time",			1,		0   },
	{"", "~/bin/dwm/statusbar/date",			1,		0   },
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
