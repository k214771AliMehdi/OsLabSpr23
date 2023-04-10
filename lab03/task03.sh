#!/bin/bash

sudo apt install samba -y
whereis smb.conf

sudo mkdir /home/sambashare
sudo chmod 777 /home/sambashare
echo "folder has been created for sambashare"
echo "now starting samba services"

sudo service smbd start
