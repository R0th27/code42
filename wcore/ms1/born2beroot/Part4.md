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

## Questions so far

1. how to set up sudo 

2. how to limit attempt and how to display custom message

3. how to log sudo inputs and outputs

5. what is TTY mode

6. How to enable it

7. How to restrict sudo to certain paths

8. Why is it important to protect bin and sbin

9. how to create a user

10. how to create user group

11. how to set a user to a certain group