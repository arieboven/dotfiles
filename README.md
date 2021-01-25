# Dotfiles

In this repo are my edited dotfiles which I use for my arch based system.\
Feel free to take a look at how I have set things up and copy lines/files if you find something interesting. I have created most of these files by looking at others dotfiles and searching the web.


Config files of:
- dunst
- git
  - st
  - dmenu
  - dwm
  - dwmblocks
- i3 (*old*)
- mpv
- nvim
- picom
- polybar (*old*)
- spicetify
- zathura


I am currently using dwm as window manager so i3 is not up to date, but I will try to give it an update. I used polybar with i3, so that is also not up to date. I want to try bspwm, in which I can update polybar. Some configurations are not yet optimized for my use, in which I want to optimized over time.


## Installations
**WARNING:** This will delete all corresponding old configuration files.\
I want to discourage to use this, use this *only* if you want all files and do not want to keep anything from your old corresponding files.\
Also I would recommend to take a look at `.bashrc`, `.xinitrc`, and `.bash_profile` before rebooting, to prevent errors.

    cd $HOME

    git clone --bare https://github.com/arieboven/dotfiles dotfiles

    alias config='/usr/bin/git --git-dir=$HOME/dotfiles --work-tree=$HOME'

    config config --local status.showUntrackedFiles no

    config reset HEAD

