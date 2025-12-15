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
