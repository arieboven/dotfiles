/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int statuspadding = 5;    /* Padding on left and right side status */
static const unsigned int gappih    = 8;        /* horiz inner gap between windows */
static const unsigned int gappiv    = 8;        /* vert inner gap between windows */
static const unsigned int gappoh    = 8;        /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 8;        /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int attachbelow        = 0;        /* 1 means attach to bottom of the stack, 0 means attach on top of the stack*/
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=10", "JoyPixels:pixelsize=11:antialias=true:autohint=true" };
static const char dmenufont[]       = "monospace:size=11";
static char normbgcolor[]     = "#222222";
static char normbordercolor[] = "#444444";
static char normfgcolor[]     = "#bbbbbb";
static char selfgcolor[]      = "#eeeeee";
static char selbordercolor[]  = "#005577";
static char selbgcolor[]      = "#005577";
static char sellinecolor[]    = "#d3a04d";
static char normlinecolor[]   = "#444444";
static const unsigned int baralpha = 0xd0;
static const unsigned int borderalpha = OPAQUE;
static char *colors[][4] = {
	/*               fg           bg           border			line   */
	[SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor, normlinecolor },
	[SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor,  sellinecolor  },
};

static const unsigned int alphas[][4]      = {
	/*               fg      bg        border		line    */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha,	borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha,	borderalpha },
};

/* staticstatus */
static const int statmonval = 0;

/* tagging */
#define TAGLENGTH 9
static const char *tags[][TAGLENGTH] = { 
	{ "1: Home", "2: Editing", "3: Media", "4: Office", "5: Games", "6", "7", "8", "9" },
	{ "1: Music", "2: Virtualbox", "3", "4", "5", "6", "7", "8", "9"},
	{ "1", "2", "3", "4", "5", "6", "7", "8", "9"},
};

typedef struct {
	const char *name;
	const void *cmd;
} Sp;
const char *spcmd1[] = {"st", "-n", "spterm", "-g", "120x34", "-A", "1", "-U", "1", NULL };
const char *spcmd2[] = {"st", "-n", "spfm", "-g", "144x41", "-A", "1", "-U", "1", "-e", "ranger", NULL };
static Sp scratchpads[] = {
	/* name          cmd  */
	{"spterm",      spcmd1},
	{"spranger",    spcmd2},
};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
		*	switchtag has different options: 
		*  - 0 is default behaviour
		*  - 1 automatically moves you to the tag of the newly opened application
		*  - 2 enables the tag of the newly opened application in addition to your existing enabled tags
		*  - 3 as 1, but closing that window reverts the view back to what it was previously (*)
		*  - 4 as 2, but closing that window reverts the view back to what it was previously (*)
	 */
	/* class                 instance  title           tags mask  exactname switchtag  focusonclick iscentered isfloating  isterminal   noswallow  monitor */
	{ "Gimp",                NULL,     NULL,           1 << 1,    0,        3,         0,           1,         1,          0,           0,        -1 },
	{ NULL,                  NULL,     "accessgranted",0,         0,        0,         0,           1,         1,          0,           0,         0 },
	{ "St",                  NULL,     NULL,           0,         0,        0,         0,           0,         0,          1,           0,        -1 },
	{ "Spotify",             NULL,     NULL,           1 << 0,    0,        0,         0,           0,         0,          0,           0,         1 },
	{ NULL,                  NULL,     "tty-clock",    1 << 0,    0,        0,         1,           0,         0,          0,           0,         1 },
	{ NULL,                  NULL,     "vis",          1 << 0,    0,        0,         1,           0,         0,          0,           0,         1 },
	{ "VirtualBox",          NULL,     NULL,           1 << 1,    1,        0,         0,           0,         0,          0,           1,         1 },
	{ NULL, NULL,   "Oracle VM VirtualBox Manager",    1 << 1,    0,        3,         0,           0,         0,          0,           0,         1 },
	{ "VirtualBoxVM",        NULL,  "VirtualBoxVM",    1 << 8,    1,        0,         0,           0,         0,          0,           1,         0 },
	{ "VirtualBoxVM", NULL, "Oracle VM VirtualBox",    1 << 8,    0,        3,         0,           0,         0,          0,           0,         0 },
	{ "minecraft-launcher",  NULL,     NULL,           1 << 4,    0,        1,         0,           1,         0,          0,           0,         0 },
	{ "libreoffice-startcenter", NULL, NULL,           1 << 3,    0,        3,         0,           0,         0,          0,           0,         0 },
	{ "Soffice",             NULL,     NULL,           1 << 3,    0,        4,         0,           0,         0,          0,           0,        -1 },
	{ "vlc",                 NULL,     NULL,           1 << 2,    0,        1,         0,           0,         0,          0,           0,         0 },
	{ "Kodi",                NULL,     NULL,           1 << 2,    0,        1,         0,           0,         0,          0,           0,         0 },
	{ "kdenlive",            NULL,     NULL,           1 << 1,    0,        1,         0,           0,         0,          0,           0,         0 },
	{ "Ghb",                 NULL,     NULL,           1 << 1,    0,        1,         0,           0,         0,          0,           0,         0 },
	{ "Blender",             NULL,     NULL,           1 << 1,    0,        1,         0,           0,         0,          0,           0,         0 },
	{ "obs",                 NULL,     NULL,           1 << 3,    0,        3,         0,           0,         0,          0,           0,         1 },
	{ "Inkscape",            NULL,     NULL,           1 << 1,    0,        1,         0,           0,         0,          0,           0,         0 },
	{ "Tor Browser",         NULL,     NULL,           0,         0,        0,         0,           1,         1,          0,           0,         0 },
	{ NULL,                  NULL,     "Discord",      1 << 2,    0,        3,         0,           1,         1,          0,           0,         1 },
	{ NULL,                  NULL,  "Discord Updater", 1 << 2,    0,        0,         0,           1,         1,          0,           1,         1 },
	{ NULL,                  NULL,     "Event Tester", 0,         0,        0,         0,           0,         0,          0,           1,        -1 }, /* xev */
	{ NULL,                  "spterm", NULL,           SPTAG(0),  0,        0,         0,           1,         1,          1,           1,        -1 },
	{ NULL,                  "spfm",   NULL,           SPTAG(1),  0,        0,         0,           1,         1,          1,           1,        -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "[M]",      monocle },
	{ "[@]",      spiral },
	{ "[\\]",     dwindle },
	{ "H[]",      deck },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
	{ "HHH",      grid },
	{ "###",      nrowgrid },
	{ "---",      horizgrid },
	{ ":::",      gaplessgrid },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define SECMODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} }, \
	{ MODKEY|SECMODKEY,             KEY,      viewnextmon,    {.ui = 1 << TAG} }, \
	{ MODKEY|SECMODKEY|ShiftMask,   KEY,      tagnextmon,     {.ui = 1 << TAG} }, \
	{ MODKEY|SECMODKEY|ControlMask, KEY,      tagswaptonextmon, {.ui = 1 << TAG} },
#define STACKKEYS(MOD,ACTION) \
	{ MOD, XK_j,     ACTION##stack, {.i = INC(+1) } }, \
	{ MOD, XK_k,     ACTION##stack, {.i = INC(-1) } }, \
	{ MOD, XK_w,     ACTION##stack, {.i = PREVSEL } }, \
	{ MOD, XK_q,     ACTION##stack, {.i = 0 } }, \
	{ MOD, XK_a,     ACTION##stack, {.i = 1 } }, \
	{ MOD, XK_z,     ACTION##stack, {.i = 2 } }, \
	{ MOD, XK_x,     ACTION##stack, {.i = -1 } },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbordercolor, "-sf", selfgcolor, topbar ? "-b":NULL, NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *layoutmenu_cmd = "$HOME/.config/git/dwm/layoutmenu.sh";

#include <X11/XF86keysym.h>

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_grave,  togglescratch,  {.ui = 0 } },
	{ MODKEY|ShiftMask,             XK_grave,  togglescratch,  {.ui = 1 } },
	{ MODKEY,                       XK_b,      spawn,          SHCMD("firefox") },
	{ MODKEY,                       XK_v,      spawn,          SHCMD("discord") },
	{ MODKEY,                       XK_e,      spawn,          SHCMD("$HOME/bin/searchWeb") },
	{ MODKEY|ShiftMask,             XK_b,      togglebar,      {0} },
	{ MODKEY|ShiftMask,             XK_d,      toggleattach,   {0} },
	STACKKEYS(MODKEY,                          focus)
	STACKKEYS(MODKEY|ShiftMask,                push)
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_r,      resetlayout,    {0} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY|SECMODKEY,             XK_u,      incrgaps,       {.i = +1 } },
	{ MODKEY|SECMODKEY|ShiftMask,   XK_u,      incrgaps,       {.i = -1 } },
	{ MODKEY|SECMODKEY,             XK_i,      incrigaps,      {.i = +1 } },
	{ MODKEY|SECMODKEY|ShiftMask,   XK_i,      incrigaps,      {.i = -1 } },
	{ MODKEY|SECMODKEY,             XK_o,      incrogaps,      {.i = +1 } },
	{ MODKEY|SECMODKEY|ShiftMask,   XK_o,      incrogaps,      {.i = -1 } },
	{ MODKEY|SECMODKEY,             XK_0,      togglegaps,     {0} },
	{ MODKEY|SECMODKEY|ShiftMask,   XK_0,      defaultgaps,    {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[13]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_y,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_u,      setlayout,      {.v = &layouts[5]} },
	{ MODKEY|ControlMask,           XK_comma,  cyclelayout,    {.i = -1 } },
	{ MODKEY|ControlMask,           XK_period, cyclelayout,    {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_f,      togglefullscreen, {0} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY|SECMODKEY|ControlMask, XK_comma,  tagswapmon,     {.i = +1 } },
	{ MODKEY|SECMODKEY|ControlMask, XK_period, tagswapmon,     {.i = -1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ 0,    XF86XK_AudioMute,                  spawn,          SHCMD("pamixer -t; kill -44 $(pidof dwmblocks)") },
	{ 0,    XF86XK_AudioRaiseVolume,           spawn,          SHCMD("pamixer -i 5 -u; kill -44 $(pidof dwmblocks)") },
	{ 0,    XF86XK_AudioLowerVolume,           spawn,          SHCMD("pamixer -d 5 -u; kill -44 $(pidof dwmblocks)") },
	{ 0,    XF86XK_AudioPrev,                  spawn,          SHCMD("playerctl --player=spotify previous") },
	{ 0,    XF86XK_AudioNext,                  spawn,          SHCMD("playerctl --player=spotify next") },
	{ 0,    XF86XK_AudioPause,                 spawn,          SHCMD("playerctl --player=spotify play-pause") },
	{ 0,    XF86XK_AudioPlay,                  spawn,          SHCMD("playerctl --player=spotify play-pause") },
	{ 0,    XF86XK_AudioStop,                  spawn,          SHCMD("playerctl --player=spotify stop") },
	{ 0,    XK_Break,                          spawn,          SHCMD("pactl set-source-mute @DEFAULT_SOURCE@ toggle") },
	{ MODKEY,                       XK_s,      spawn,          SHCMD("scrot -m '%Y-%m-%d_%H%M%S.png' -e 'mv $f ~/Pictures/screenshots/'") },
	{ MODKEY|ShiftMask,             XK_s,      spawn,          SHCMD("sleep 0.2; scrot -s '%Y-%m-%d_%H%M%S.png' -e 'mv $f ~/Pictures/screenshots/'") },
	{ MODKEY|ControlMask,           XK_s,      spawn,          SHCMD("scrot -u '%Y-%m-%d_%H%M%S.png' -e 'mv $f ~/Pictures/screenshots/'") },
	{ MODKEY|ShiftMask,             XK_m,      spawn,          SHCMD("pactl set-source-mute @DEFAULT_SOURCE@ toggle ; pkill -RTMIN+12 dwmblocks") },
	{ MODKEY|ShiftMask,             XK_t,      spawn,          SHCMD("pgrep picom && killall picom || picom -b") },
	{ MODKEY,                       XK_BackSpace, spawn,       SHCMD("$HOME/bin/locker") },
	{ MODKEY,                       XK_F5,     xrdb,           {.v = NULL } },
	{ MODKEY|ShiftMask,             XK_BackSpace, spawn,       SHCMD("$HOME/.config/git/dwm/powermenu") },
	{ MODKEY|ControlMask|ShiftMask, XK_BackSpace, quit,        {1} },
	{ MODKEY|SECMODKEY|ControlMask, XK_BackSpace, quit,        {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {.v = &layouts[0] } },
	{ ClkLtSymbol,          0,              Button3,        layoutmenu,     {0} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

