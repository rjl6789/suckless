#!/bin/sh -e
#
#

THEMELOC="$HOME/src/suckless/themes"
BUILDLOC="$HOME/src/suckless"

set_background() {
    if [ -f "$1" ] ; then
        cp -f "$1" "${XDG_CACHE_HOME}"/wall 2>/dev/null ||:
        background "$1"
    fi
}

gen_st() {
cat > "${THEMELOC}"/st-theme.h << EOF
const char *colorname[] = {
  [0] = "$color0",
  [1] = "$color1",
  [2] = "$color2",
  [3] = "$color3",
  [4] = "$color4",
  [5] = "$color5",
  [6] = "$color6",
  [7] = "$color7",
  [8]  = "$color8",
  [9]  = "$color9",
  [10] = "$color10",
  [11] = "$color11",
  [12] = "$color12",
  [13] = "$color13",
  [14] = "$color14",
  [15] = "$color15",
  [256] = "$background",
  [257] = "$foreground",
  [258] = "$cursor",
};
unsigned int defaultbg = 256;
unsigned int defaultfg = 257;
unsigned int defaultcs = 258;
unsigned int defaultrcs = 257;
EOF
}

gen_dmenu() {
cat > "${THEMELOC}"/dmenu-theme.h << EOF
static const char *colors[SchemeLast][2] = {
    [SchemeNorm] = { "$foreground", "$background" },
    [SchemeSel]  = { "$foreground", "$color6" },
    [SchemeOut]  = { "$foreground", "$color5" },
};
EOF
}

gen_slock() {
cat > "${THEMELOC}"/slock-theme.h << EOF
static const char *colorname[NUMCOLS] = {
	[INIT] =   "$color6",     /* after initialization */
	[INPUT] =  "$color4",   /* during input */
	[FAILED] = "$color14",   /* wrong password */
	[CAPS] = "$color1",         /* CapsLock on */
};
EOF
}

gen_dwm() {
cat > "${THEMELOC}"/dwm-theme.h << EOF
static const char *colors[][3]      = {
    [SchemeNorm] = { "$foreground", "$background", "$color6" },
    [SchemeSel]  = { "$foreground", "$color6", "$color4" },
    [SchemeUrg] =  { "$foreground", "$color1", "$color1" },
};
EOF
}

gen_tabbed() {
cat > "${THEMELOC}"/tabbed-theme.h << EOF
    static const char* selfgcolor   = "$foreground";
    static const char* selbgcolor   = "$background";
    static const char* normfgcolor  = "$foreground";
    static const char* normbgcolor  = "$color2";
    static const char* urgfgcolor   = "$foreground";
    static const char* urgbgcolor   = "$color1";
EOF
}


rebuild() {
    # rebuild suckless tools
    "${BUILDLOC}"/build.sh st dwm dmenu tabbed slock

    # # rebuild start page
    # if type sassc >/dev/null ; then
    #     # generate web browser startpage css
    #     # this also copies to to my site
    #     (cd ~/src/wvr.sh ; make)
    # fi
}

usage() {
    >&2 printf '%s wallpaper\n' "${0##*/}"
    exit 1
}

main() {
    case ${1#-} in
        h)
            usage
            ;;
    esac

    mkdir -p "${THEMELOC}"

    # set background if given
    set_background "$1"

    # load current theme into environment
    . "${THEMELOC}"/current

    # generate .h theme files for suckless tools
    gen_st
    gen_dwm
    gen_dmenu
    gen_tabbed
    gen_slock

    # set xresources colors
    sed -i "s/.*foreground.*/\*foreground:$foreground/g" ~/.Xresources
    sed -i "s/.*background.*/\*background:$background/g" ~/.Xresources
    xrdb load ~/.Xresources

    # rebuild tools
    rebuild
}

main "$@"
