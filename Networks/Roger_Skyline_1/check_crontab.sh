#!/bin/bash

TODAY=$(date +%d -d "yesterday")
FILE=$(stat -c %y /etc/crontab | cut -c 9,10)

if [ $TODAY = $FILE ] ; then
	sudo touch email.txt
	sudo chmod 777 email.txt
	sudo echo -e 'Subject:Crontab Modification \n\n The Crontab file was modified yesterday!\n' > email.txt
	sudo sendmail root < email.txt
	sudo rm email.txt
fi
