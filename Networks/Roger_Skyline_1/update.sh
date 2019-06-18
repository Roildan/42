#!/bin/bash

sudo echo "" >> /var/log/update_script.log
sudo echo "----------------------- UPDATE ---------------------------" >> /var/log/update_script.log

sudo apt-get update -y >> /var/log/update_script.log

sudo echo "----------------------- UPGRADE --------------------------" >> /var/log/update_script.log

sudo apt-get upgrade -y >> /var/log/update_script.log
sudo echo "" >> /var/log/update_script.log

sudo echo "-----------------------  CLEAN  --------------------------" >> /var/log/update_script.log

sudo apt-get autoremove -y >> /var/log/update_script.log
sudo echo "" >> /var/log/update_script.log

sudo echo "-----------------------   END   --------------------------" >> /var/log/update_script.log

sudo date >> /var/log/update_script.log
sudo echo "" >> /var/log/update_script.log
sudo echo "" >> /var/log/update_script.log
