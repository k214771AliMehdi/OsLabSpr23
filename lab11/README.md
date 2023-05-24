# lab_11

##  task_01

### summary of the manual

Objective: The objective of today's OS lab is to cover essential topics in securing a Linux system, including hardening techniques, firewall configuration, and security best practices, as well as setting up and configuring a Squid proxy server.

Introduction to Squid: Squid is an open-source caching and proxy server used to improve network performance, filter requests, and enforce access control policies.

Squid installation and configuration:

Install the Squid package using the commands "sudo apt-get update" and "sudo apt-get install squid".
Configure Squid by modifying the main configuration file located at "/etc/squid/squid.conf".
Change the default port and customize other settings as needed.
Create a file to list the sites you want to block at "/etc/squid/blocksite".
Restart Squid using the command "sudo systemctl restart squid".
Configure your browser to use the Squid proxy server.
Introduction to Linux hardening, security, and firewall:

Linux hardening refers to securing a Linux system by implementing proactive measures to mitigate security threats and vulnerabilities.
Basic Linux hardening techniques include disabling unnecessary services, keeping the system up-to-date with security patches, configuring a firewall, implementing strong password policies, configuring file system permissions, and implementing user management best practices.
Disabling unnecessary services and applications using the "systemctl disable <service-name>" command.
Keeping the system up-to-date with security patches and updates using package management tools like "apt" or "yum".
Configuring and using a firewall to control network traffic, with options like iptables, ufw, or firewalld.
Configuring nftables for firewall management and setting up firewall rules in the configuration file.
Implementing strong password policies by setting minimum length, complexity, age, and history requirements in password policy files.
Configuring file system permissions to restrict access to sensitive files and directories using commands like chown, chgrp, and chmod.
Implementing user management best practices by limiting user privileges, enforcing strong password policies, and monitoring user activity.
Note: Please note that the instructions provided are in a simplified format and may require further research and understanding of specific commands and configurations.


##  task_02

### UFW

i.The **ufw** (Uncomplicated Firewall) is a streamlined and user-friendly interface for controlling the iptables firewall on Linux computers. It can be installed on other Linux distributions in addition to Ubuntu, which already has it preinstalled.

ii.To effectively use ufw, you need to understand how to create and manage firewall rules using its syntax. You can then use the ufw command-line interface to manage firewall rules, including allowing or blocking incoming and outgoing traffic based on IP addresses, ports, or protocols.

iii.Due to its reliance on iptables, ufw has the drawback of not offering granular control over individual network packets. Additionally, it might not support some sophisticated firewall functions that are accessible in other firewall programmes.

iv.Other alternatives or competitors to ufw include the conventional iptables, on which ufw is based, and more modern firewall programmes such as firewalld, which offers more advanced functionality such as zone-based setups and SELinux integration. Finally, the selection of a firewall tool is dependent on your demands, knowledge, and the specific requirements of your environment.


### Fail2ban


i. **Fail2ban** is a utility that automatically bans IP addresses linked with suspicious activity, such as repeated failed login attempts,_ to avoid brute-force assaults on Linux systems_. It accomplishes this by monitoring log files for suspicious activity and blocking offending IP addresses with iptables or other firewall technologies. Fail2ban is extremely customizable and can monitor a wide range of log files.

ii. To use Fail2ban properly, you must configure it to monitor relevant log files on your system and set up rules for when to ban IP addresses. When suspicious behaviour is discovered, you may set Fail2ban to send email notifications or log messages.

iii.Fail2ban has a limitation in that it may not be successful against increasingly complex attacks including distributed networks of attackers or spoofed IP addresses. It may also restrict innocent users mistakenly if they activate the same rules as an attacker.

iv.Other alternatives or competitors to Fail2ban include DenyHosts and SSHGuard, which are also meant to prevent brute-force attacks by automatically restricting IP addresses. Again, the tool you use is determined by your individual goals and the system requirements.


### squid

i.Squid is a free and open-source cache and proxy server that operates on Linux and Unix-like computers. It has a number of functions, such as caching web pages, filtering requests, and tracking user activities. Organisations frequently employ Squid to improve network performance by decreasing bandwidth usage and speeding up web page loading times for users.

ii.To utilise Squid efficiently, you must configure it to match the specific demands of your organisation. Setting up caching policies, creating access limits, and interacting with other network services may all be part of this. Squid can also be set to log user activities, which can help with network monitoring and identifying potential security breaches.

iii.One potential weakness of Squid is that it may be ineffective against more sophisticated attacks involving encrypted communications or targeted attacks. Furthermore, Squid may demand significant resources to function well, especially in large-scale deployments.

iv.Squid alternatives or competitors include Apache Traffic Server, Varnish, and Nginx, which are also open-source cache and proxy servers. The tool you select should be based on your organization's specific goals and requirements, as well as aspects such as performance, security, and convenience of use.
