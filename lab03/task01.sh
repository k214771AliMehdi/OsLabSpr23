#!/bin/bash

# User input
sender="k214771@nu.edu.pk"
receiver="k214754@nu.edu.pk"
gapp="nvmtowprjxljoych"
sub="testing network sniffing"
body="the body of the mail"

# check for provided attachment file as a positional parameter
# -z indicating an empty positional parameter
# attachment doesn't exist condition

netstat > net.txt

    file="net.txt"           # set file as the 1st positional parameter
    
    # MIME type for multiple type of input file extensions
    
    MIMEType=`file --mime-type "$file" | sed 's/.*: //'`
    curl -s --url 'smtps://smtp.gmail.com:465' --ssl-reqd \
    --mail-from $sender \
    --mail-rcpt $receiver\
    --user $sender:$gapp \
     -H "Subject: $sub" -H "From: $sender" -H "To: $receiver" -F \
    '=(;type=multipart/mixed' -F "=$body;type=text/plain" -F \
      "file=@$file;type=$MIMEType;encoder=base64" -F '=)'

rm net.txt
