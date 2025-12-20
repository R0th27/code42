# Part 3 Hostname and password

## hostname

The hostname must be <login>42 (htoe42)

It will be modified later

## password

# Timeline

1. Expire every 30 days

2. Before modification, minimum numbers of days allowed is 2.

3. Before 7 days prior to the expiration date, warning message.

# Rules

1. at least 10 characters long

2. uppercase, lowercasse, number

3. no more than 3 consecutive idential characters

4. no user name

5. excluding root: must have at least 7 characters differenced from the former password.

## Notes

### hostname check and modify

`hostname`

**to modify hostname during runtime**

`hostname -b <new>` 

**to modify persistent hostname**

`sudo nano /etc/hostname`

`sudo nano /etc/hosts`

`or`

`sudo hostnamectl set-hostname new`

>127.0.0.1 localhost RFC convention

>127.0.1.1 hostname if no dhcp or static config

>169.254.0.0/16 in APIPA of MS

### password services

**PAM stack**

1. auth - who are you?

	* **pam_unix.so**

2. account - are you allowed here? password definitions?

	* **pam_unix.so** 

	* **/etc/shadow**

3. password - if pw change, allow?

	* **pam_pwquality.so**

4. session - home/ mount/ logging

	* **pam_limits.so**


**check for pam_unix.so**

`cat /etc/pam.d/common-account`

**account pam_unix.so is critical**

**PAM requisite vs required**

1. requisite quit immediately showing error

2. required still continue to other process resulting confusing error

### basic password age

`nano /etc/login.defs` 

```
PASS_MAX_DAYS 30
PASS_MIN_DAYS 2
PASS_WARN_AGE 7
```

to verify `chage -l user`

#### Important about login.defs

1. pam_unix.so read from /etc/shadow which will not be updated even after changing login.defs

2. so if you have pre exist users, you should manually enforce password aging to users

`chage -l user`

`chage -M 30 -m 2 -W 7 user`


### password quality enforce

`apt install libpam-pwquality`

`ls /lib/x86_64-linux-gnu/security/pam_pwquality.so`

`sudo nano /etc/pam.d/common-password`

```
password        [success=1 default=ignore]      pam_succeed_if.so uid=0
password        requisite                       pam_pwquality.so retry=3 dcredit=-1 difok=7 lcredit=-1 maxrepeat=3 minlen=10 ucredit=-1 usercheck=1 enforce_for_root
password        requisite                       pam_pwquality.so retry=3 dcredit=-1 difok-7 lcredit=-1 maxrepeat=3 minlen=10 ucredit=-1 usercheck=1 difok=7

```

```
password        [success=1 default=ignore]      pam_succeed_if.so uid=0
password        requisite                       pam_pwquality.so retry=3 dcredit=-1 difok=7 lcredit=-1 maxrepeat=3 minlen=10 ucredit=-1 usercheck=1 enforce_for_root
password        requisite                       pam_pwquality.so retry=3 dcredit=-1 difok-7 lcredit=-1 maxrepeat=3 minlen=10 ucredit=-1 usercheck=1 difok=7
password        [success=1 default=ignore]      pam_unix.so obscure try_first_pass yescrypt
# here's the fallback if no module succeeds
password        requisite                       pam_deny.so
# prime the stack with a positive return value if there isn't one already;
# this avoids us returning an error just because nothing sets a success code
# since the modules above will each just jump around
password        required                        pam_permit.so

```

`sudo -i` for root access during editing serious pam

`enforce_for_root` is excluded according to born2beroot

**all rules are appied to root except difof** **rules of PAM**

`chage -l root`

`grep pam_pwquality /etc/pam.d/common-password/`


