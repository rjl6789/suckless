#!/bin/sh -e

# -*-*-*-*-*-*-*-*- SETTINGS -*-*-*-*-*-*-*-*-*-*-*-*-*-*--*
DWM_VERSION=bb2e7222baeec7776930354d0e9f210cc2aaad5f       # 08 Jul 2020
ST_VERSION=4ef0cbd8b9371f37f7d02ef37b5378b879e6b8bf        # 18 OCT 2020
DMENU_VERSION=1a13d0465d1a6f4f74bc5b07b04c9bd542f20ba6     # 02 SEP 2020
TABBED_VERSION=dabf6a25ab01107fc1e0464ee6a3e369d1626f97    # 12 May 2020
SURF_VERSION=d068a3878b6b9f2841a49cd7948cdf9d62b55585      # 08 Feb 2019
SENT_VERSION=2649e8d5334f7e37a1710c60fb740ecfe91b9f9e      # 13 May 2020
SLOCK_VERSION=35633d45672d14bd798c478c45d1a17064701aa9     # Sat Mar 25 21:16:01 2017
ASLSTATUS_VERSION=d3bd38cd213015cb19c668506d74eae1aca66e58 # Thu Feb 4 23:16:28 2021 +0200

export PREFIX="${HOME}"/.local
export THEMELOC="${HOME}"/src/suckless/themes
export CFLAGS='-O2 -pipe -s -pedantic -std=c99 -fstack-protector-strong -fexceptions'
export LDFLAGS=-s
# -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

usage() {
    die 'Usage: ./build.sh [dwm] [st] [dmenu] [tabbed] [surf] [slock]'
}

die() {
    >&2 printf '%s\n' "$*"
    exit 1
}

clone() {
    mkdir -p "$1"
    cd "$1"
    [ -d "$1" ] || case $1 in
        aslstatus) git clone "$2" ;;
        *) git clone "$2/$1"
    esac

    cd "$1"
    git clean -df
    git fetch --all
    git reset --hard "$3"
    cd "$START_PWD"
}

[ "$1" ] || usage

build() {
    START_PWD=$(dirname "$0")
    [ "$START_PWD" = . ] && START_PWD=$PWD
    for name ; do
        cd "$START_PWD"

        sl=git://git.suckless.org
	aslstat=https://notabug.org/dm9pZCAq/aslstatus.git
        case $name in
            st) clone "$name" $sl $ST_VERSION ;;
            dwm) clone "$name" $sl $DWM_VERSION ;;
            surf) clone "$name" $sl $SURF_VERSION ;;
            dmenu) clone "$name" $sl $DMENU_VERSION ;;
            tabbed) clone "$name" $sl $TABBED_VERSION ;;
            sent) clone "$name" $sl $SENT_VERSION ;;
            slock) clone "$name" $sl $SLOCK_VERSION ;;
	    aslstatus) clone "$name" $aslstat $ASLSTATUS_VERSION ;;
            *) usage
        esac

        cd "$name"

        [ -d patches ] &&
        for patch in patches/* ; do
            printf '\n%s\n\n' "===> applying ${patch#patches/}..."
            patch -l -p0 < "$patch" || exit 1
        done

        [ -f cfg/config.h  ] && cp -f cfg/config.h  "$name"/config.h
        [ -f cfg/config.mk ] && cp -f cfg/config.mk "$name"/config.mk

        cd "$name"
        make -s clean
	case $name in
		aslstatus) make -s PREFIX="$PREFIX" AUDIO="ALSA" ;;
		*) make -s -j"${NPROC:-1}" CC="${CC:-gcc}" THEMELOC="${THEMELOC}"
	esac
	case $name in
		slock) sudo make -s PREFIX="$PREFIX" install ;;
		aslstatus) make -s PREFIX="$PREFIX" AUDIO="ALSA" install ;;
		*) make -s PREFIX="$PREFIX" install
	esac
    done
}

comptest() {
    printf 'Running compiler test...'
    echo 'int main() { return 0 ; }' > /tmp/$$.c
    ${CC:-gcc} /tmp/$$.c -o /tmp/$$
    chmod +x /tmp/$$
    if /tmp/$$ ; then
        rm /tmp/$$.c /tmp/$$
        printf ' %s\n\n' 'Passed!'
    else
        die "Something wrong with your compiler! Aborting."
    fi
}

main() {
    for cmd in make ${CC:-gcc} patch ; do
        command -v "$cmd" >/dev/null || die "missing: $cmd"
    done
    comptest
    build "$@"
}

main "$@"
