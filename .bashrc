#
# ~/.bashrc
#

# don't put duplicate lines or lines starting with space in the history
HISTCONTROL=ignoreboth
# ignore commands such as history and ls, to appand separate with ':'
HISTIGNORE="history:ls"
# store hist file in ~/.cache
HISTFILE=~/.cache/.bash_history
# Length of histfile
HISTFILESIZE=2500
# Append command directly after execude
PROMPT_COMMAND='history -a'

stty -ixon          # Disables ctrl-s and ctrl-q
shopt -s histappend # Append to the history file, don't overwrite it
shopt -s autocd     # Allows you to cd into dir by typing dir name

set -o vi           # Enable vim commands

# If not running interactively, don't do anything
[[ $- != *i* ]] && return

gb() {
    echo -n ' (' && git branch 2>/dev/null | grep '^*' | colrm 1 2 | tr -d '\n' && echo  -n ')'
}
git_branch() {
    gb | sed 's/ ()//'
}

# Bash prompt
if [ "$EUID" -ne 0 ]; then
    export PS1='\[\e[1;32m\]$(git_branch)\[\e[1;31m\] [\u@\h]\[\033[00m\]: \[\033[01;34m\]\W\[\e[0m\] \$ '
else
    export PS1="\[\e[1;31m\] [ROOT@$(hostname | awk '{print toupper($0)}')]\[\033[00m\]: \[\033[01;34m\]\W\[\e[0m\] # "
fi

# My custom aliases
alias c='clear'
alias p='sudo pacman'
alias g='git'
[ -f /usr/bin/nvim ] && alias vim='nvim'
alias video="youtube-dl -i --merge-output-format mp4 -o '~/Videos/YoutubeVideos/%(title)s.%(ext)s'"
alias music="youtube-dl --add-metadata --extract-audio --audio-format mp3 -o '~/Music/%(title)s.%(ext)s'"
alias ff='find . -type f -iname'
alias fd='find . -type d -iname'
alias cp='cp -i'
alias mv='mv -i'
# If ranger close set window title back to St
alias ranger='ranger; echo -ne "\033]0;St\007"'
alias dutch='trans en:nl'
alias english='trans nl:en'

alias la='ls -A'
alias ll='ls -alF'
alias ..='cd ..'
alias school='. ~/Documents/school/.bashrc_school'

# Aliases color related
alias ls='ls -hN --color=auto --group-directories-first'
alias grep='grep --color=auto'
alias ip='ip --color=auto'

# Alias for home server
alias server='ssh -p 2048 account@192.168.178.20'

# Alias for git repo of dotfiles 
function config(){
    # GIT_DIR=$HOME/dotfiles GIT_WORK_TREE=$HOME /usr/bin/git "$@"
    /usr/bin/git --git-dir=$HOME/dotfiles --work-tree=$HOME "$@"
    if [ "$1" == "restore" ]; then
        # The config files of the suckless build are hard linked to the git repos of the build
        # If git restores files the link is removed. This funcition checks if there is a restore
        # if so, create new links to config files
        ln -f $HOME/.config/git/dmenu/config.h $HOME/git/dmenu/config.h
        ln -f $HOME/.config/git/dwm/config.h $HOME/git/dwm/config.h
        ln -f $HOME/.config/git/st/config.h $HOME/git/st/config.h
        ln -f $HOME/.config/git/dwmblocks/blocks.h $HOME/git/dwmblocks/blocks.h
    fi
}

[ -f /usr/share/bash-completion/completions/git ] && . /usr/share/bash-completion/completions/git && __git_complete g __git_main; __git_complete config __git_main

# Run neofetch add startup terminal
#neofetch
