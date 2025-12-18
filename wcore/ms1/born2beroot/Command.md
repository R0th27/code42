## to check architecture

uname -a

## to check physical cpu core

grep "physical id" /proc/cpuinfo | sort -u | wc -l

## to check processor

grep "processor" /proc/cpuinfo | wc -l

## to check used ram

total memory = free --mega | awk '/Mem:/ {print $2}'
used memory = free --mega | awk '/Mem:/ {print $3}'
percentage = free --mega | awk '/Mem:/ {printf "(%.2f%%)\n", $3/$2*100}'

## to check disk memory

df -m -x tmpfs -x devtmpfs | awk '$1 ~ "^/dev/" && $6 != "/boot" {use += $3; total += $2} END {printf "(%.2f%%)\n", use/total * 100}'

## to check cpu usage

vmstat 1 2 | awk 'END {printf "%.1f%%\n", 100 - $15}'

## to check last reboot

who -b | awk '{print $(NF - 1), $NF}

## to check active LVM

lsblk -o TYPE | grep -q "^lvm$" && echo yes || echo no

## to check tcp connection

ss -tan state established | wc -l

## to check number of users

users | tr -s ' ' '\n' | sort -u | wc -l

## to check ip address & mac

ip route | awk '/default/ {print $9}'

ip link show $(ip route | awk '/default/ {print $5}') | awk '/link\/ether/ {print $2}'

## to check number of commands executed with sudo

journalctl _COMM=sudo | grep -c COMMAND