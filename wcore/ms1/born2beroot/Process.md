# Process to complete born2beroot

## Installing and Partitioning and StartUp

### 1. To do

1. Install Rocky or Debian without additional services and gui

2. Partitioning must be manually done according to the following. 

```
boot 	is 500MB
On a encrypted partition
root 	is 10G
swap 	is 2.3G
home 	is 5G
var 	is 3G
srv 	is 3G
tmp 	is 3G
var/log is 4G
```
3. On startup apparmor must be loaded and startup enabled

4. Partition check, Hardware check, Release Check, Connectivity, Security

### 2. Commands

`lsblk`

`df -h`

`free -h`

`uname -a`

`lsb_release -a`

`ls /sys/firmware/efi`

`ip a`

`ip route`

`ip link`

`timedatectl`

`cat /etc/hosts/`

`systemctl status apparmor`

`systemctl list-unit-files | grep apparmor`

## SSH and Firewall and sudo

### 1. To do

1. install SSH

2. open SSH port, root login deny, check PAM

3. check SSH port, check connectivity, check root login

4. install firewall

5. open SSH port, startup enable

6. install sudo

### 2. Commands

1. SSH

	1. `apt install openssh-server`

	2. `nano /etc/ssh/sshd_config`

	3. `Port` `PermitRootLogin` `UsePAM`

	4. `ss -tnlp`

	5. `ss -tt -p PORT USER@IP`

2. Firewall

	1. `apt install ufw`

	2. `sudo ufw status`

	3. `ufw allow PORT/PROTOCOL`

	4. `ufw enable`

	4. `ufw deny PORT/PROTOCOL`

	5. `ufw deny from IP`

	6. `ufw default deny incoming(or)outgoing`

3. Sudo

	1. `apt install sudo`

	2. `sudo -l`

## Sudo policy and Password policy

### 1. To do

1. update sudo policy according to the following policies

	1. password trial 3 times

	2. password wrong -> custom message

	3. sudo event log file

	4. sudo log for input and output must be stored in /var/log/sudo

	5. must require tty

	6. usr/local/sbin|bin: usr/sbin|bin: sbin|bin: snap/bin: must secured

	7. check sudo policies

2. update password aging and password quality

	1. max days 30, min days 2, warning days 7

	2. for root, retry is 3, minimal 10 chars, digit 1, upper 1, lower 1, repeat 3, not username

	3. for users, retry is 3, minimal 10 chars, digit 1, upper 1, lower 1, repeat 3, not username, diff from 7,

	4. bad password must be rejected!

### 2. Commands

1. sudo

	1. `mkdir /var/log/sudo`

	2. `chmod 700 /var/log/sudo`

	3. `chown root:root /var/log/sudo`

	4. `sudo visudo`

	5. ```
		Defaults passwd_tries=3
		Defaults badpass_message="Try Again"
		Defaults logfile="/var/log/sudo/sudo.log"
		Defaults log_input, log_output
		Defaults iologdir="/var/log/sudo"
		Defaults requiretty
		Defaults secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
		```

	6. `sudo -l`

2. password age

	1. `sudo nano /etc/login.defs`

	2. ```
		PASS_MAX_DAYS 30
		PASS_MIN_DAYS 2
		PASS_WARN_AGE 7
		```

	3. **editing /etc/login.defs will not update /etc/shadow**

	4. `chage -l user`

	5. `chage -M 30 -m 2 -W 7 user`

3. password quality

	1. `ls /lib/./security/pam_pwquality.so` && `skip` || `apt install libpam-pwquality.so`

	2. `nano /etc/pam.d/common-password`

	3. `password [success=1 default=ignore] pam_succeed_if.so uid=0`

	4. `password requisite pam_pwquality.so retry=3 enforcing=1 minlen=10 ucredit=-1 lcredit=-1 dcredit=-1 maxrepear=3 usercheck=1 difok=7`

	5. `password requisite pam_pwquality.so retry=3 enforcing=1 minlen=10 ucredit=-1 lcredit=-1 dcredit=-1 maxrepeat=3 usercheck=1`

## Hostname and User and Group

### 1. To do

* **check every stage!**

1. add a user or more

2. delete a user or more

3. add a group or more

4. delete a group or more

5. add a user into a group

6. remove a user from a group

7. change hostname

### 2. Commands

1. to check stages

	1. `users`

	2. `getent` + `group` || `passwd`

	3. `id username`

	4. `groups user`

	5. `hostnamectl`

2. user management

	1. `adduser <new>`

	2. `deluser <new>`

	3. `passwd <new>`

3. group management

	1. `sudo addgroup <new>`

	2. `sudo delgroup group`

4. user group management

	1. `sudo adduser <user> <group>`

	2. `sudo addgroup <user> <group>`

	3. `sudo deluser <user> <group>`

	4. `sudo delgroup <user> <group>`

	5. `sudo usermod -aG <group> <user>`

## Monitoring bash and Crontab

### 1. To do

1. setup a monitoring.sh which will relay the following details

	```bash
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
	#Network: IP 10.0.2.15 (08:00:27:51:9b:a5
	#Sudo : 42 cmd
	```

2. the message should be relayed to all

3. the message should be relayed every 10 minutes

4. you must interrupt the relay without editing the file

### 2. Commands

1. hints

	1. `uname`

	2. `proc/cpuinfo`

	3. `free -m`

	4. `df -m`

	5. `vmstat`

	6. `who`

	7. `lsblk`

	8. `ss`

	9. `users`

	10. `ip route`

	11. `ip link`

	12. `journalctl`

	13. `wall`

2. bash scripting

	```bash
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

	lvmuse=$(lsblk -o TYPE | grep -q "^lvm$" && echo yes || echo no)

	tcpcount=$(ss -tan | grep -c ESTAB)

	usercount=$(users | tr ' ' '\n' | sort -u | wc -l)

	read id ip <<< $(ip route | grep "default" | awk '{print $5, $9}')

	mac=$(ip link show $id | grep "link/ether" | awk '{print $2}')

	sudocount=$(journalctl _COMM=sudo --no-pager | grep -c "COMMAND")

	wall << EOF
	#Architecture: $architecture
	#CPU physical: $phyCPU
	#vCPU: $virCPU
	#Memory Usage: $usedmem/${totalmem}MB (${mempercent}%)
	#Disk Usage: $usedMB/${totalMB}Gb (${GBpercent}%)
	#CPU load: $cpupercent
	#Last boot: $lastboot
	#LVM use: $lvmuse
	#Connections TCP: $tcpcount ESTABLISHED
	#User log: $usercount
	#Network: IP $ip ($mac)
	#Sudo: $sudocount cmd
	EOF
	```

3. Preparing

	1. `sudo chmod +x /usr/local/bin/monitoring.sh`

	2. `sudo crontab -e`

	3. `sudo crontab -u others -e`

	4. `*/10 * * * * /usr/local/bin/hi.sh`

## Lighttpd Wordpress MariaDB PHP FTP

### 1. To do

1. Install lighttpd and fix firewall

2. Install Wordpress latest zip in /var/WWW/

3. Install mariaDB and run mysql_secure_installation

4. Install php and php_mysql

5. Setup Wordpress

6. Install ftp and update firewall

### 2. Commands

1. lighttpd

	1. `apt install lighttpd`

	2. `ufw allow 80/tcp && ufw allow 443/tcp`

	3. `ss -tnlp | grep 80 (or) 443`

2. wordpress

	1. `apt install wget zip`

	2. `cd /var/WWW`

	3. `wget https://wordpress.org/latest.zip`

	4. `sudo unzip latest.zip`

	5. `sudo mv html/ html/old/`

	6. `sudo mv wordpress html`

	7. `sudo chmod -R 755 html`

3. mariaDB

	1. `run mysql_secure_installation`
	```	
	Switch to unix_socket autentication? → N 
	Change the root password? → N
	Remove anonymous users? → Y 
	Disallow root login remotely? → Y 
	Remove test database and access to it? → Y 
	Reload privilege tables now? → Y
	```

	2. `mariadb`

		`CREATE DATABASE wp_database;`

		`SHOW DATABASES;`

		`CREATE USER 'gemartin'@'localhost' IDENTIFIED BY '12345';`

		`GRANT ALL PRIVILEGES ON wp_database.* TO 'gemartin'@'localhost';`

		`FLUSH PRIVILEGES;`

		`exit`

4. php

	1. `sudo apt install php-cgi php-mysql`

5. Wordpress setup

	1. `cd /var/www/html`

	2. `cp wp-config-sample.php wp-config.php`

	3. `sudo lighty-enable-mod fastcgi`

	4. `sudo lighty-enable-mod fastcgi-php`

	5. `sudo service lighttpd force-reload`

	6. `localhost` in browser

6. VSFTPD setup

	1. `apt install vsftpd`

	2. `sudo nano /etc/vsftpd.conf`

	```
	listen=YES
	listen_ipv6=NO

	anonymous_enable=NO
	local_enable=YES
	write_enable=YES

	chroot_local_user=YES
	allow_writeable_chroot=YES

	pasv_enable=YES
	pasv_min_port=10000
	pasv_max_port=10100
	```

	3. `ftp localhost`

	5. `firewall`

	```
	sudo ufw allow 21/tcp
	sudo ufw allow 10000:10100/tcp
	sudo ufw reload
	```

	6. `config`

	```
	sudo chown ftpuser:ftpuser /home/ftpuser
	sudo chmod 755 /home/ftpuser
	```

	7. `security`

	```
	ssl_enable=YES
	rsa_cert_file=/etc/ssl/certs/ssl-cert-snakeoil.pem
	rsa_private_key_file=/etc/ssl/private/ssl-cert-snakeoil.key
	```

	8. 