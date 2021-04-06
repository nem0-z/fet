#!/bin/bash

VM_NAME=stretch

#######################################################################
set +e
cloonix_cli nemo kil
set -e
echo waiting 5 sec
echo
sleep 5 
cloonix_net nemo
cloonix_gui nemo
#----------------------------------------------------------------------


#######################################################################
cloonix_cli nemo add kvm one 200 2 1 0 ${VM_NAME}.qcow2 & 
cloonix_cli nemo add kvm two 200 2 1 0 ${VM_NAME}.qcow2 & 
cloonix_cli nemo add kvm three 200 2 1 0 ${VM_NAME}.qcow2 & 
#----------------------------------------------------------------------
cloonix_cli nemo add kvm router1 200 2 2 0 ${VM_NAME}.qcow2 & 
cloonix_cli nemo add kvm router2 200 2 3 0 ${VM_NAME}.qcow2 & 
cloonix_cli nemo add kvm router3 200 2 2 0 ${VM_NAME}.qcow2 & 
cloonix_cli nemo add kvm router4 200 2 2 0 ${VM_NAME}.qcow2 & 
#----------------------------------------------------------------------
for i in {1..6}; do
  cloonix_cli nemo add snf sniffer${i}
done
#----------------------------------------------------------------------


#######################################################################
cloonix_cli nemo add lan one 0 lan1
cloonix_cli nemo add lan router1 0 lan1
#----------------------------------------------------------------------
cloonix_cli nemo add lan router1 1 lan2
cloonix_cli nemo add lan router2 0 lan2
#----------------------------------------------------------------------
cloonix_cli nemo add lan router2 1 lan3
cloonix_cli nemo add lan router3 0 lan3
#----------------------------------------------------------------------
cloonix_cli nemo add lan router2 2 lan4
cloonix_cli nemo add lan router4 0 lan4
#----------------------------------------------------------------------
cloonix_cli nemo add lan router3 1 lan5
cloonix_cli nemo add lan two 0 lan5
#----------------------------------------------------------------------
cloonix_cli nemo add lan router4 1 lan6
cloonix_cli nemo add lan three 0 lan6
#----------------------------------------------------------------------
for i in {1..6}; do
  cloonix_cli nemo add lan sniffer${i} 0 lan${i}
done
#----------------------------------------------------------------------


#######################################################################
sleep 10
set +e
for i in one two three router1 router2 router3 router4; do
  while ! cloonix_ssh nemo ${i} "echo" 2>/dev/null; do
    echo ${i} not ready, waiting 5 sec
    sleep 5
  done
done
set -e
#----------------------------------------------------------------------


#######################################################################
for i in one two three router1 router2 router3 router4; do
  cloonix_ssh nemo ${i} "sysctl -w net.ipv6.conf.all.disable_ipv6=1"
  cloonix_ssh nemo ${i} "sysctl -w net.ipv6.conf.default.disable_ipv6=1"
  cloonix_ssh nemo ${i} "hostnamectl set-hostname ${i}"
  cloonix_ssh nemo ${i} "sysctl net.ipv4.tcp_timestamps=0"
  cloonix_ssh nemo ${i} "systemctl stop systemd-timesyncd"
  if [[ ${i} == "router"* ]]; then
    cloonix_ssh nemo ${i} "sysctl -w net.ipv4.ip_forward=1"
  fi
done
#----------------------------------------------------------------------


#######################################################################
for i in one two three router1 router2 router3 router4; do
  cloonix_ssh nemo ${i} "ip link set dev eth0 up"
done
#----------------------------------------------------------------------
for i in router1 router2 router3 router4; do
  cloonix_ssh nemo ${i} "ip link set dev eth1 up"
done
#----------------------------------------------------------------------
cloonix_ssh nemo router2 "ip link set dev eth2 up"
#----------------------------------------------------------------------


#######################################################################
cloonix_ssh nemo one "ip addr add dev eth0 10.0.0.2/8"
cloonix_ssh nemo one "ip route add default via 10.0.0.1"
cloonix_ssh nemo router1 "ip addr add dev eth0 10.0.0.1/8"
#----------------------------------------------------------------------
cloonix_ssh nemo two "ip addr add dev eth0 192.168.0.2/16"
cloonix_ssh nemo two "ip route add default via 192.168.0.1"
cloonix_ssh nemo router3 "ip addr add dev eth1 192.168.0.1/16"
#----------------------------------------------------------------------
cloonix_ssh nemo three "ip addr add dev eth0 192.167.0.2/16"
cloonix_ssh nemo three "ip route add default via 192.167.0.1"
cloonix_ssh nemo router4 "ip addr add dev eth1 192.167.0.1/16"
#----------------------------------------------------------------------
cloonix_ssh nemo router1 "ip addr add dev eth1 1.1.1.1/30"
cloonix_ssh nemo router2 "ip addr add dev eth0 1.1.1.2/30"
#----------------------------------------------------------------------
cloonix_ssh nemo router2 "ip addr add dev eth1 2.2.2.0/31"
cloonix_ssh nemo router3 "ip addr add dev eth0 2.2.2.1/31" 
#----------------------------------------------------------------------
cloonix_ssh nemo router2 "ip addr add dev eth2 3.3.3.0/31"
cloonix_ssh nemo router4 "ip addr add dev eth0 3.3.3.1/31"
#----------------------------------------------------------------------
