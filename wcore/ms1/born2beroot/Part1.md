# Part 1 Partitioning

## Partitioning

```
sda is 30.8GB 											type is disk
├── sda1 is mounted at boot with 500 MB					type is part
├── sda2 is 1KB											type is part
├── sda5 is 30.3GB										type is part
	├── sda5_crypt is 30.3GB crypted					type is crypt
	├── LVMGroup-root is 10G mounted at root			type is lvm
	├── LVMGroup-swap is 2.3G moutned as [SWAP]			type is lvm
	├── LVMGroup-home is 5G mounted at /home			type is lvm
	├── LVMGroup-var is 3G mounted at /var				type is lvm
	├── LVMGroup-srv is 3G mounted at /srv				type is lvm
	├── LVMGroup-tmp is 3G mounted at /tmp				type is lvm
	├── LVMGroup-var--log is 4G mounted at /var/log		type is lvm
sr0	is 1024MB											type is rom

```

we can detemine the appropriate size for each partition to ensure proper operation

At start up we should run

- Rocky - SELinux -no KDump

- Debian - AppArmor

## Questions so far

1. what is debain and rocky and their differences

2. what is SELinux and AppArmor

3. how to set them up

4. what are the purposes of each partitions 

5. minimum storage for them to function properly

6. part, lvm and crypt and rom

7. How to set them up during OS installation

8. or after OS

9. what is aptitude and apt