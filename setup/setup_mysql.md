# SETUP MySQL
## Download
```
sudo apt-get install mysql-server
sudo systemctl start mysql
```

## Configuration
`sudo mysql_secure_installation`  
Follow instructions.

Then, check if you can access to mysql : `sudo mysql -u root -p`

In mysql terminal, change, are type again your password to update him :  
```
mysql> ALTER USER 'root'@'localhost' IDENTIFIED WITH mysql_native_password BY 'your_new_password';
mysql> FLUSH PRIVILEGES;
mysql> QUIT;
```

## Few commands
You can add users, databases or tables with phpmyadmin.

|Command|Descrption|
|:-:|:-|
|`sudo systemctl enable mysql`|Start mysql each time you restart your server|
|`sudo systemctl disable mysql`|Didn't start mysql when your system restart|
|`sudo systemctl start mysql`|Start mysql|
|`sudo systemctl stop mysql`|Stop mysql|
|`sudo systemctl restart mysql`|Restart mysql|
