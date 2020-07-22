---
layout: post
title: Port Forwarding
excerpt_separator: <!--more-->
tags: networking
---

Over the past one year I learnt a lot about networking. Yet, there has been a hunch that I have bearly scratched the surface of networking concepts. But having done something today (which I'll brief out) gave me some amount of satisifaction.

<!--more-->

With my knowledge I was able to establish communication between computers within a network. I have pretty much seen it working with C, Python and little in C#. But I had many project ideas that would need connectivity to other external networks. This need lead me to explore how this can be achieved. Lucky enough I am to know the that there is something called port forwarding exists that lets us do exactly this.

Wikipedia defines port forwarding as follows:

> In computer networking, port forwarding or port mapping is an application of network address translation (NAT) that redirects a communication request from one address and port number combination to another while the packets are traversing a network gateway, such as a router or firewall.


Port forwarding has to be configured in the router that is connected to the server. The port number and IP address of the server has to be mentioned in the router settings page. This opens the firewall to let only the following port flow into the network. However, the client side needs to have the public IP address of the router to which the server is connected to.

When I wrote the first socket program to test this today, I was elated to see it working as expected. I had connected the server to my home network and used mobile network's access point to create another network and use it to connect to the server. I had also written a small ping program with which I can ping the server from any other computer connected to other network.