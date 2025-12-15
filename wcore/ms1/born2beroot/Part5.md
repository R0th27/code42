# Part 5 Monitoring

## monitoring.sh

At the server startup, the script will display some information on all terminals and every 10 minutes (wall)

1. Architecture of the operating system + kernel version

2. physical processors

3. virtual processors

4. available RAM and utilization rate as percentage

5. available storage and utilization rate as percentage

6. date and time of last reboot

7. LVM is active or not

8. number of active connections

9. number of users

10. IPv4 address and MAC

11. sudo command counts

**you will aslo have to interrupt it without modifying it**

## hints

1. head -n 2 /etc/os-release

2. /usr/sbin/aa-status

3. ss -tunlp

4. /usr/sbin/ufw status

Formats

Broadcast message from root@wil (tty1) (Sun Apr 25 15:45:00 2021):
#Architecture: Linux wil 4.19.0-16-amd64 #1 SMP Debian 4.19.181-1 (2021-03-19) x86_64 GNU/Linux
#CPU physical : 1
#vCPU : 1
#Memory Usage: 74/987MB (7.50%)
#Disk Usage: 1009/2Gb (49%)
#CPU load: 6.7%
#Last boot: 2021-04-25 14:45
#LVM use: yes
#Connections TCP : 1 ESTABLISHED
#User log: 1
#Network: IP 10.0.2.15 (08:00:27:51:9b:a5)
#Sudo : 42 cmd
