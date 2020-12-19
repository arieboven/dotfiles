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

if [[ "$(tty)" = "/dev/tty1" ]]; then
	pgrep dwm || startx
fi
