# Part 2 Connectivity

## Connectivity

### SSH

`SSH` Service will be running on the mandatory port 4242 in the virtual machine. 

> it must not be possible to connect using SSH as root

### Firewall

`UFW` for debian must be configrued 

`firewalld` for rocky must be configured

**firewall must be active at startup**

**only port 4242 must be opened**

## Notes

## SSH processes

```bash
/etc/ssh/sshd_config   → server rules
/etc/ssh/ssh_config    → client defaults
/etc/pam.d/sshd        → auth + session setup
/dev/pts/*             → SSH terminals
/var/run/utmp          → who / wall visibility
/var/log/auth.log      → SSH logs
```

**SSH itself has three sub-protocols (RFC 4251):**

1. Transport Layer Protocol → Encryption, integrity, key exchange

2. User Authentication Protocol → Password, public key

3. Connection Protocol → Channels for terminal sessions, port forwarding, SFTP, etc.

**packet timeline**

>Three way handshake

1. Client → Server: TCP SYN

2. Server → Client: SYN-ACK

3. Client → Server: ACK

>SSH information exchange, authentication

SSH version strings exchanged (plaintext)

Key exchange → establish AES/ChaCha key

Client → Server: encrypted authentication (password/public key)

Server → Client: encrypted success/failure

>Data exchange

Channel open → encrypted terminal data (ls, cat, etc.)

>resting
Keep-alive packets (optional)

>exit
Exit / TCP FIN → session ends

### Firewall process

1. Firewall types

	* layer 3 packet filter 

	* layer 4 transport filter or stateful firewall

	* layer 5 - 7 DPI firewall

2. incoming packet is inspected for layer 4 ports and flags then allowed or rejected

### ssh setup

`apt install openssh-server`

`nano /etc/ssh/sshd_config`

`nano /etc/ssh/ssh_config`

`systemctl restart ssh`

`systemctl status ssh`

`ss -tnlp | grep ssh`

`apt purge openssh-server`

`apt autoremove --purge`

`ssh -tt -p 4242 user@ip`


### Firewall setup

`apt install ufw`

`sudo ufw allow 22/tcp`

`sudo ufw deny 23/tcp`

`sudo ufw deny from 192.168.1.100`

`sudo ufw default deny incoming`

`sudo ufw default deny outgoing`

`sudo ufw enable`

`sudo ufw status`

`apt purge ufw`

`apt autoremove --purge`


