static const char *fonts[] = {
    "SauceCodePro Nerd Font Mono:pixelsize=20:antialias=true:autohint=true",
    "Terminus:pixelsize=20:antialias=false:autohint=false",
    //"Noto Color Emoji:pixelsize=22:antialias=true:autohint=true",
    //"Noto Sans:pixelsize=22:antialias=true:autohint=true",
    //"Unifont:pixelsize=22"
};
    /* "cozette:size=10:antialias=false:autohint=false", */
    /* "Terminus:pixelsize=18:antialias=false:autohint=false" */
    /* "Hack:pixelsize=20:antialias=true:autohint=true", */
    /* "Noto Sans CJK JP:pixelsize=22:antialias=true:autohint=true", */
    /* "Noto Sans CJK HK:pixelsize=22:antialias=true:autohint=true", */
    /* "Noto Sans CJK KR:pixelsize=22:antialias=true:autohint=true", */
    /* "Noto Sans CJK SC:pixelsize=22:antialias=true:autohint=true", */
    /* "Noto Sans CJK TC:pixelsize=22:antialias=true:autohint=true", */

static const unsigned int border_width = 2;
static int fuzzy = 1;

// theme, included from ${HOME}/src/suckless/themes in config.mk
#include <dmenu-theme.h>

static const char *prompt = NULL;  /* -p  option; prompt to the left of input field */
static const char worddelimiters[] = " /?\"&[].:,";
static int topbar = 1;
static unsigned int lines = 0;
