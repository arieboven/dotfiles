#
# ~/.bash_profile
#

[[ -f ~/.bashrc ]] && . ~/.bashrc

[[ -d $HOME/.local/bin ]] && export PATH="$HOME/.local/bin:${PATH}"
[[ -d $HOME/bin ]] && export PATH="$HOME/bin:${PATH}"

export EDITOR="nvim"
export TERMINAL="st"
export TERMCMD="st"
export BROWSER="firefox"
export READER="zathura"

export XDG_DOCUMENTS_DIR="$HOME/Documents"
export XDG_DOWNLOAD_DIR="$HOME/Downloads"
export XDG_MUSIC_DIR="$HOME/Music"
export XDG_PICTURES_DIR="$HOME/Pictures"
export XDG_VIDEOS_DIR="$HOME/Videos"

export XDG_CONFIG_HOME="$HOME/.config"
export XDG_CACHE_HOME="$HOME/.cache"

export XDG_DWMBLOCKS="$HOME/.config/git/dwmblocks/scripts"

if [[ "$(tty)" = "/dev/tty1" ]]; then
	pgrep dwm || startx
fi
