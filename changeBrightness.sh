#/bin/bash

echo $1 > | sudo tee /sys/class/backlight/intel_backlight/brightness
echo $2 > | sudo tee /sys/class/leds/mmc0::

