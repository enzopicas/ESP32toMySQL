# SETUP APACHE 2

## Download packages
On a terminal :
```bash
sudo apt-get update
sudo apt-get install apache2
sudo systemctl start apache2
```
Check on your browser if you see the default apache2 index.  
Now your apache2 server is running, but you can setup more options.

## Configuration
### Get rights
Your website/scripts will be placed in the folder `/var/www/html/`. To copy or modify files on this folder, you must be owner:
```
sudo chmod 755 -R /var/www/html
sudo chown username:usergroup -R /var/www/html
```

### Secure index
I higly recommend to disable file index on your server. If not, each user can access to the list of your websites files, and, for example, add datas on your mysql database using your .php script.

To disable it :  
`vim /etc/apache2/sites-available/000-default.conf`  
Add or create a section `Directory` and add the following line:  
```
<Directory "/var/www/html/">
    Options -Indexes
</Directory>
```

Each time you modify apache2 doncifguration, you must reload your server by using `sudo systemctl reload apache2`

## Few commands
apache2 commands:
|Command|Descrption|
|:-:|:-|
|`sudo systemctl enable apache2`|Start apache2 each time you restart your server|
|`sudo systemctl disable apache2`|Didn't start apache2 when your system restart|
|`sudo systemctl start apache2`|Start apache2|
|`sudo systemctl stop apache2`|Stop apache2|
|`sudo systemctl reload apache2`|Reload apache2 configuration file|
|`sudo systemctl restart apache2`|Restart apache2|
