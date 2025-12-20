#!/bin/bash

architecture=$(uname -a)

phyCPU=$(grep "physical id" /proc/cpuinfo | sort -u | wc -l)

virCPU=$(grep "processor" /proc/cpuinfo | wc -l)

read totalmem usedmem <<< $(free -m | awk '/Mem:/ {print $2, $3}')

mempercent=$(echo "scale=2; $usedmem/$totalmem*100" | bc)

read totalMB usedMB <<< $(df -m -x tmpfs -x devtmpfs | awk '$1 ~ "^/dev/" && $6 != "/boot" && $6 != "/boot/efi" {u+=$3; t+=$2} END {print t, u}'
)

GBpercent=$(echo "scale=2; $usedMB/$totalMB*100" | bc)

if [ $totalMB -gt 1024 ]; then
	totalMB=$(echo "scale=1; $totalMB/1024" | bc);
fi

if [ $usedMB -gt 1024 ]; then
	usedMB=$(echo "scale=1; $usedMB/1024" | bc);
fi

cpupercent=$(vmstat 1 2 | awk 'END {printf "%.2f%%", 100 - $15}')

lastboot=$(who -b | awk '{print $(NF - 1), $NF}')

lvmuse=$(lsblk -f | grep -q "^lvm$" && echo yes || echo no)

tcpcount=$(($(ss -tan state established | wc -l) - 1))

usercount=$(users | tr ' ' '\n' | sort -u | wc -l)

read id ip <<< $(ip route | grep "default" | awk '{print $5, $9}')

mac=$(ip link show $id | grep "link/ether" | awk '{print $2}')

sudocount=$(journalctl _COMM=sudo | grep -c "COMMAND")

wall << EOF
#Architecture: $architecture
#CPU physical: $phyCPU
#vCPU: $virCPU
#Memory Usage: $usedmem/${totalmem}MB (${mempercent}%)
#Disk Usage: $usedMB/${totalMB}GB (${GBpercent}%)
#CPU load: $cpupercent
#Last boot: $lastboot
#LVM use: $lvmuse
#Connections TCP: $tcpcount ESTABLISHED
#User log: $usercount
#Network: IP $ip ($mac)
#Sudo: $sudocount cmd
EOF