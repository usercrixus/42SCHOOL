#!/bin/bash

# 1. System architecture and kernel version
architecture=$(uname -m)
kernel_version=$(uname -r)

# 2. Number of physical processors (sockets)
physical_processors=$(lscpu | grep "Socket(s):" | awk '{print $2}')

# 3. Number of virtual processors (cores)
virtual_processors=$(nproc)

# 4. Available RAM and its usage percentage
total_memory=$(free -m | awk '/Mem:/ {print $2}')
used_memory=$(free -m | awk '/Mem:/ {print $3}')
memory_usage=$(awk "BEGIN {printf \"%.2f\", ($used_memory/$total_memory)*100}")

# 5. Available disk space and its usage percentage
total_disk=$(df -h --total | grep 'total' | awk '{print $2}')
used_disk=$(df -h --total | grep 'total' | awk '{print $3}')
disk_usage=$(df -h --total | grep 'total' | awk '{print $5}')

# 6. CPU usage percentage
cpu_usage=$(top -bn1 | grep "Cpu(s)" | awk '{print $2 + $4}')

# 7. Date and time of the last reboot
last_reboot=$(who -b | awk '{print $3, $4}')

# 8. LVM status (active or not)
lvm_status=$(lsblk | grep -q 'lvm' && echo "Active" || echo "Inactive")

# 9. Number of active connections
active_connections=$(ss -tun | grep -c ESTAB)

# 10. Number of users currently logged in
logged_in_users=$(who | wc -l)

# 11. IPv4 address and MAC address
ip_address=$(hostname -I | awk '{print $1}')
mac_address=$(ip link show | awk '/ether/ {print $2}')

# 12. Number of commands executed with sudo
sudo_commands=$(journalctl _COMM=sudo | grep -c COMMAND)

# Display the information
echo "System Architecture      : $architecture"
echo "Kernel Version           : $kernel_version"
echo "Physical Processors      : $physical_processors"
echo "Virtual Processors       : $virtual_processors"
echo "Total RAM (MB)           : $total_memory MB"
echo "Used RAM (MB)            : $used_memory MB"
echo "RAM Usage (%)            : $memory_usage %"
echo "Total Disk Space         : $total_disk"
echo "Used Disk Space          : $used_disk"
echo "Disk Usage               : $disk_usage"
echo "CPU Usage (%)            : $cpu_usage %"
echo "Last Reboot              : $last_reboot"
echo "LVM Status               : $lvm_status"
echo "Active Connections       : $active_connections"
echo "Logged-in Users          : $logged_in_users"
echo "IPv4 Address             : $ip_address"
echo "MAC Address              : $mac_address"
echo "Sudo Commands Executed   : $sudo_commands"
