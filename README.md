# Dotfiles

In this repo are my edited dotfiles which I use for my arch based system.\
Feel free to take a look at how I have set things up and copy lines/files if you find something interesting. I have created most of these files by looking at others dotfiles and searching the web.

Config files of:
- nvim
- git
  - st
  - dwm
  - dwmblocks

## Installations
---
**WARNING:** This will delete all corresponding old configuration files.\
I want to discourage to use this, use this *only* if you want all files and do not want to keep anything from your old corresponding files.

    cd $HOME

    git clone --bare https://github.com/arieboven/dotfiles dotfiles

    alias config='/usr/bin/git --git-dir=$HOME/dotfiles --work-tree=$HOME'

    config config --local status.showUntrackedFiles no

    config reset HEAD

