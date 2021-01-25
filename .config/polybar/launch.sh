#!/bin/bash

# Terminate already running bar instances
killall -q polybar

# Wait until the processes have been shut down
while pgrep -u $UID -x polybar >/dev/null; do sleep 1; done

# Launch Polybar, using default config location ~/.config/polybar/config

#polybar example &

#unset MONITOR
if [[ $(xrandr | awk '/DP-4/ {print $2}') == "connected" ]]; then
	polybar first >>/tmp/polybar1.log 2>&1 &
fi
 
if [[ $(xrandr | awk '/DP-2/ {print $2}') == "connected" ]]; then
	polybar second >>/tmp/polybar2.log 2>&1 &		
fi

echo "Polybar launched..."
