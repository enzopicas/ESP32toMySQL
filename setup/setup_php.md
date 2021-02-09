# SETUP PHP
## Download
On a terminal :
```
sudo apt-get update
sudo apt-get install libapache2-mod-php php php-mysql
sudo systemctl restart apache2
```

## Install phpmyadmin (optional)
If you want to administrate MySQL databases with a GUI on your web browser, you can install phpmyadmin.  
`sudo apt-get install phpmyadmin`  
This will ask some questions about the phpmyadmin mysql account, and the root account.

When installed, you can access to phpmyadmin on your web browser : https://your.server.ip/phpmyadmin

If you canno't access to phpmyadmin, run `sudo dpkg-reconfigure phpmyadmin` to reload the setup.
