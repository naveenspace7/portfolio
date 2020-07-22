---
layout: post
title: Setting a static-IP address on Raspberry Pi
excerpt_separator: <!--more-->
tags: networking rpi
---

This post describes how to setup a static IP address on a Raspberry Pi, in fact this can be used on any Linux machine. This post is meant mainly for my reference, while also giving the actual reference.

<!--more-->

### Setup
* Navigate to `/etc`.
* Make a backup of file `dhcpcd.conf`.
* Add the following line depending on the interface:

```
# For a wired connection
interface eth0

# The desired static address
static ip_address=192.168.0.197/24
static routers=192.168.0.1
static domain_name_servers=192.168.0.1

# For a wireless connection
interface wlan0

# The desired static address
static ip_address=192.168.0.200/24
static routers=192.168.0.1
static domain_name_servers=192.168.0.1
```

* Reboot the system.


[Reference](https://thepihut.com/blogs/raspberry-pi-tutorials/how-to-give-your-raspberry-pi-a-static-ip-address-update)