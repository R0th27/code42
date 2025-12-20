# Part 4 Sudo & User & User Group

## sudo

`sudo` must be installed and configured following the strict rules

1. authentication chance to try sudo is 3 attempts if password is wrong

2. if wrong password is used, a custom message will be displayed

3. inputs and outputs from sudo must be archived into /var/log/sudo/

4. TTY mode has to be enabled for security reasons.

5. the following paths must be restricted

	* /usr/local/sbin

	* /usr/local/bin

	* /usr/sbin

	* /usr/bin

	* /sbin

	* /bin

	* /snap/bin

## users

In addition to the root user, a user with your <login> has to be present

This user has to belong to the user42 and sudo groups.

## Notes

### sudo setup

`apt install sudo`

### add user

`sudo adduser <new>`

`sudo useradd -m <new>`

`sudo passwd <new>`

`sudo deluser username`

`rm -Rf /home/username`

`users`

`getent passwd username`

`id username` **user exist + primary group**

### add group

`sudo addgroup <new>`

`sudo groupadd -r <new>`

`getent group <new>`

### manage user with group

`sudo adduser user group`

`sudo usermod -aG group user`

`groups user`

`sudo deluser name group`

`sudo groupdel group`

### sudo policy

`mkdir /var/log/sudo`

`chmod 700 /var/log/sudo`

`sudo visudo`

`sudo l`

```
Defaults passwd_tries=3
Defaults badpass_message="wrong"
Defaults log_input
Defaults log_output
Defaults iolog_dir="/var/log/sudo"
Defaults requiretty
Defaults secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
Defaults logfile="/var/log/sudo/sudo_config"
```

**iolog is details**
**logfile is who what when**

### additional

```
r = 4, w = 2, x = 1
764 => rwxrw-r--
user -> 7 => 4(r) + 2(w) + 1(x)
group -> 6 => 4(r) + 2(w)
others -> 4 => 4(r)
```

`chmod u=rwx,g=rx,o= file`

`sudo chown user file`

`sudo chown -R user folder`

`sudo chgrp group file`

`sudo chgrp -R group folder`