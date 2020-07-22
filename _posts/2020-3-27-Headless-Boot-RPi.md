---
layout: post
title: Headless First-Time Boot of RPi
excerpt_separator: <!--more-->
tags: rpi booting tricks
---

This post describes how to connect the raspberry pi (with a interface by Raspberry Pi foundations) to the internet and enable the ssh, all on the first boot. This post is meant mainly for my reference, while also giving the actual reference.

<!--more-->

### Connecting to WiFi on first boot
* Download the raspbian image and write the image to the SD card.
* Navigate to the `boot` directory of the image.
* Create a new file there with the name `wpa_supplicant.conf`.
* In the above created file, add the following into it:
```
country=US
ctrl_interface=DIR=/var/run/wpa_supplicant GROUP=netdev
update_config=1
network={
        ssid="SYSLink123"
        psk="hellowifi"
        key_mgmt=WPA-PSK
}
```
* In the same navigated directory, create a file without any extension and name it as `ssh`.

### Checking the connection
* To find if process was successful, run the following command:
`$ sudo nmap -sn 192.168.0.0/24`

[Reference](https://desertbot.io/blog/headless-pi-zero-w-wifi-setup-windows)