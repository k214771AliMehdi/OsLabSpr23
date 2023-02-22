# Task 01

**apache2**

![image](https://user-images.githubusercontent.com/123717138/220518131-24870d29-fc20-4b43-a2b5-9f770275f92d.png)

**My SQL**

![image](https://user-images.githubusercontent.com/123717138/220520505-38374307-b4d5-4558-bb94-f710c55ce2c6.png)

**PHP**

![image](https://user-images.githubusercontent.com/123717138/220520912-0e3cee21-35de-4e69-87d4-1bec258d6203.png)

**shell script**

    echo "	Updating packages!"
    sudo apt-get update -y

    echo "	downloading Apache Mysql-server and php!"

    sudo apt install apache2 -y
    sudo apt install mysql-server -y
    sudo apt install php libapache2-mod-php php-mysql -y


    echo "	done !"
    
    
    
# Task 02

    #!/bin/bash

    # Start Apache
    echo "Starting Apache..."
    sudo systemctl start apache2

    # Check the status of Apache
    echo "Checking Apache status..."
    sudo systemctl status apache2 > status.txt
    cat status.txt

    # Stop Apache
    echo "Stopping Apache..."
    sudo systemctl stop apache2
    
# Task 03

#!/bin/bash

    # Start sql
    echo "Starting sql..."
    sudo systemctl start mysql

    # Check the status of sql
    echo "Checking sql status..."
    sudo systemctl status mysql > statussql.txt

    cat statussql.txt

    # Stop sql
    echo "Stopping sql..."
    sudo systemctl stop mysql
