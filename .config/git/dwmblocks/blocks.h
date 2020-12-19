//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
    {"", "$XDG_DWMBLOCKS/openweather",  1800,   0   },

    {"", "$XDG_DWMBLOCKS/data",         30,     0   },
    
    {"", "$XDG_DWMBLOCKS/microphone",   0,      12  },

    {"", "$XDG_DWMBLOCKS/volume",       0,      10  },

    {"", "$XDG_DWMBLOCKS/network",      30,     11  },

    {"", "$XDG_DWMBLOCKS/time",		    1,		0   },
    {"", "$XDG_DWMBLOCKS/date",		    1,		0   },
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
