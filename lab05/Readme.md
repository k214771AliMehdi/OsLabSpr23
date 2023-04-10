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
    
# Task 5,6

    ![image](https://user-images.githubusercontent.com/123717138/230983587-4b97c3bd-19b3-461c-9956-96c7bf7baf97.png)
    
    **script**
    
    #!/bin/bash
    # User input
    sender="k214771@nu.edu.pk"
    read -p "enter the mail u want to send: " receiver
    gapp="nvmtowprjxljoych"
    read -p "Enter Subject: " sub
    read -p "Enter body: " body

    # check for provided attachment file as a positional parameter
    # -z indicating an empty positional parameter
    # attachment doesn't exist condition



        file="note.txt"           # set file as the 1st positional parameter

        # MIME type for multiple type of input file extensions

        MIMEType=`file --mime-type "$file" | sed 's/.*: //'`
        curl -s --url 'smtps://smtp.gmail.com:465' --ssl-reqd \
        --mail-from $sender \
        --mail-rcpt $receiver\
        --user $sender:$gapp \
         -H "Subject: $sub" -H "From: $sender" -H "To: $receiver" -F \
        '=(;type=multipart/mixed' -F "=$body;type=text/plain" -F \
          "file=@$file;type=$MIMEType;encoder=base64" -F '=)'


