# Set display layout
if [[ $(xrandr | awk '/DP-4/ {print $2}') == "connected" && $(xrandr | awk '/DP-2/ {print $2}') == "connected" ]]; then
    xrandr --output DP-4 --mode 2560x1440 --pos 1920x0 --primary --output DP-2 --mode 1920x1080 --pos 0x180
fi

# Enable numlock at startup
numlockx &

# Remap escape with capslock
remaps &

# Disable screen blanking
xset s off
xset dpms 0 0 0

# Load gnome-keyring
#eval $(/usr/bin/gnome-keyring-daemon --start --components=pkcs11,secrets,ssh)
#export SSH_AUTH_SOCK

# Start clipmenu
systemctl --user import-environment DISPLAY
systemctl --user start clipmenud

# Start Dunst notification daemon
dunst &

# Mount NAS
sudo $HOME/bin/mountNAS

# Load Xresources
[[ -f ~/.Xresources ]] && xrdb -merge ~/.Xresources

# Set background
feh --bg-fill $HOME/background1.jpg $HOME/background2.jpg

picom -b

dwmblocks &

$HOME/bin/dwm/startup.sh &

# Exec dwm
exec dwm 2> ~/.cache/dwm.log
