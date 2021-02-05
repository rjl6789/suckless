/* -*--*-*-*-*-*-*-*-*- GAPS -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* */
/* #define GAPS_START 34 */
/* #define BORDERPX_START 2 */
/* -*-*-*-*-*-*-*-*-*- SMALL GAPS *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */
 #define GAPS_START 6 // */
 #define BORDERPX_START 3 // */
/* -*-*-*-*-*-*-*-*-*- NO GAPS *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */
/* #define GAPS_START 0 */
/* #define BORDERPX_START 2 */
/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* */
static const int topbar  = 1;

/* -*-*-*-*-*-*-*-*- FLOATING BAR -*-*-*-*-*-*-*-*-*-*-*-*-*-* */
 //static const int vertpad     = GAPS_START - GAPS_START / 2; // vertical padding of bar */
 //static const int sidepad     = GAPS_START - GAPS_START / 2; // horizontal padding of bar */
 static const int vertpad     = 6; // vertical padding of bar */
 static const int sidepad     = 8; // horizontal padding of bar */
 static const int horizpadbar = 2;   // horizontal padding for statusbar */
 static const int vertpadbar  = 2;  // vertical padding for statusbar */
 /* -*-*-*-*-*-*-*-* NON-FLOATING BAR -*-*-*-*-*-*-*-*-*-*-*-*- */
/*static const int vertpad     = 0; // vertical padding of bar */
/*static const int sidepad     = 0; // horizontal padding of bar */
/*static const int horizpadbar = 2; // horizontal padding for statusbar */
/*static const int vertpadbar  = 4; // vertical padding for statusbar */
/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */

// for use with the rounded corners patch (0 disables)
static const int CORNER_RADIUS = 0;

static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 4;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;     /* 0 means no systray */
// theme, included from ${HOME}/src/suckless/themes in config.mk
#include <dwm-theme.h>

static const char*fonts[] = {
    /*"Terminus:pixelsize=20", */
    /* "cozette:size=10", */
    //"Fira mono:pixelsize=17", 
    "SauceCodePro Nerd Font Mono:pixelsize=17",
};

static const Rule rules[] = {
    /* class         instance  title       tags mask  iscentered   isfloating  monitor */
    { "brws",        NULL,     NULL,       1,         0,           0,          -1 },
    /* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */
    { "pop",         NULL,     "pop",      0,         0,           1,          -1 },
    { "term",        NULL,     "term",     0,         1,           0,          -1 },
    { "x9term",      NULL,     "x9term",   0,         0,           1,          -1 },
    { "floating-st", NULL,     "floating-st", 0,      1,           1,          -1 },
    { "Simple Terminal", NULL, NULL,       0,         1,           0,          -1 },
    { NULL,          NULL, "Simple Terminal",       0,         1,           0,          -1 },
    /* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */
    { "htop",        NULL,     NULL,       0,         1,           1,          -1 },
    { "ranger",      NULL,     NULL,       0,         1,           1,          -1 },
    /* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- */
    { "feh",         NULL,     NULL,       0,         1,           1,          -1 },
    { "mailspring",  NULL,     NULL,       0,         1,           1,          -1 },
    { "Mailspring",  NULL,     NULL,       0,         1,           1,          -1 },
    { "mpv",         NULL,     NULL,       0,         1,           1,          -1 },
    { "sxiv",        NULL,     NULL,       0,         1,           1,          -1 },
    { "Sxiv",        NULL,     NULL,       0,         1,           1,          -1 },
    { "pcmanfm",     NULL,     NULL,       0,         1,           1,          -1 },
    { "Pcmanfm",     NULL,     NULL,       0,         1,           1,          -1 },
    { "mupdf",       NULL,     NULL,       0,         1,           0,          -1 },
    { "MuPDF",       NULL,     NULL,       0,         1,           0,          -1 },
    { "virt-manager", NULL,    NULL,       0,         1,           1,          -1 },
    { "Virt-manager", NULL,    NULL,       0,         1,           1,          -1 },
};

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* */
/*
 * cool emojis to use for tags:
 *
 * "", "爵", "", "", "ﭮ", "", "", "", "","", "﬐", "ﳨ"
 * "ﯙ", "", "", "", "", "", "", "", "", "", "", "" ""
 * "", "", "", "", "", "", "", "", "", "", "", "", "ﭮ"
 */
/* static const char *tags[] = { "", "", "", "", "", "ﭮ" }; */
/* static const char *tags[] = { "","","","","","ﭮ" }; */
static const char *tags[] = { "1","2","3","4","5","6" };
/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* */

static const int showbar = 1;
static const float mfact = 0.5;
static const Layout layouts[] = {
    { "|  ", tile },
    { "| 缾 ", NULL }, // floating
    { "|  ", monocle },// */
};

#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) { MODKEY, KEY, view, {.ui = 1 << TAG} }, \
                         { MODKEY|ShiftMask, KEY, tag, {.ui = 1 << TAG} },
#define SH(cmd) { .v = (const char*[]) { "/bin/sh", "-c", cmd, NULL } }

// need this include for brightness/audio keys
#include <X11/XF86keysym.h>
static Key keys[] = {
    //
    // NOTE: regular program bindings now handled in sxhkdrc
    //

    /* modifier            key        function       argument */
    /* -*-*-*-*-*-*-*- dwm commands -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* */
    { MODKEY,            XK_space,  togglescratch, SH("st -A 1 -t scratchpad -g 68x18") },
    { MODKEY,            XK_q,      killclient,    {0} },
    { MODKEY,            XK_j,      focusstack,    {.i = +1 } },
    { MODKEY,            XK_k,      focusstack,    {.i = -1 } },
    { MODKEY|ShiftMask,  XK_h,      setmfact,      {.f = -0.05} },
    { MODKEY|ShiftMask,  XK_l,      setmfact,      {.f = +0.05} },
    { MODKEY,            XK_t,      setlayout,     {.v = &layouts[0]} },
    { MODKEY,            XK_f,      setlayout,     {.v = &layouts[1]} },
    { MODKEY,            XK_m,      setlayout,     {.v = &layouts[2]} },// */
    { MODKEY,            XK_b,      togglebar,     {0} },
    { MODKEY,            XK_s,      togglesticky,  {0} },
    { MODKEY|ShiftMask,  XK_space,  togglefloating,{0} },
    { MODKEY,            XK_h,      rotatestack,   {.i = -1 } },
    { MODKEY,            XK_l,      rotatestack,   {.i = +1 } },
    { MODKEY,            XK_Tab,    view,          {0} },
    { MODKEY|ShiftMask|ControlMask, XK_q,      quit,           {0} },
    /* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* */
    { MODKEY|ShiftMask,  XK_k,      setsmfact,      {.f = +0.05} },
    { MODKEY|ShiftMask,  XK_j,      setsmfact,      {.f = -0.05} },
    { MODKEY,            XK_g,      setgaps,        {.i = +4}    },
    { MODKEY|ShiftMask,  XK_g,      setgaps,        {.i = -4}    },
    { 0,                 XK_F11,    togglefullscr,  {0} },
    /* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* */
    TAGKEYS(XK_1,0) TAGKEYS(XK_2,1) TAGKEYS(XK_3,2) TAGKEYS(XK_4,3) 
    TAGKEYS(XK_5,4) TAGKEYS(XK_6,5) 
    TAGKEYS(XK_BackSpace,5)
};

static Button buttons[] = {
    { ClkClientWin,  MODKEY,      Button1, movemouse,   {0} },
    { ClkClientWin,  MODKEY,      Button3, resizemouse, {0} },
	{ ClkTagBar,     0,           Button1, view,        {0} },
    { ClkRootWin,    0,           Button3, spawn,       SH("x9term") },
    /* { ClkAny,        ControlMask, Button3, spawn,       SH("opn -c") }, */
};

// decor hints patch
static const int decorhints  = 1;

static unsigned int gappx = GAPS_START;
static unsigned int borderpx = BORDERPX_START;

static const unsigned int minwsz = 20; /* min height of a client for smfact */

/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* */
static const float smfact     = 0.00; /* factor of tiled clients [0.00..0.95] */
static const int resizehints  = 1;
static const int focusonwheel = 1;
static const char scratchpadname[] = "scratchpad";
static const int nmaster      = 1;


/* -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* */
static const char *const autostart[] = {
	"stwrapper", NULL,
	"sh", "-c", "sleep 8 && aslstatus", NULL,
	NULL /* terminate */
};

