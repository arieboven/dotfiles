## Networkmanager
This is for wifi fallover if wired is disconnected. I found it [here](https://matoski.com/article/wifi-ethernet-autoswitch/).

- /etc/NetworkManger/dispatcher.d/
  - 70-wifi-wired-exclusive<i></i>.sh

## Systemd scripts
If my system is in sleep mode, it sometimes randomly wakes up. The script `suspendfix` helps for this problem by disabeling some wake up signals. The scipt `usbsuspendfix` is for disabeling power on usb when suspanding
- /etc/systemd/system/
    - suspendfix.service
    - usbsuspendfix.service
