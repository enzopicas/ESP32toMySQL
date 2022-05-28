# ESP32toMySQL
This project provide instructions and code examples to push datas from esp32 to grafana server using php and mysql.

## HARDWARE REQUIREMENTS
* Linux Server
* ESP32
    * Any ESP32 eval board with WiFi antenna

## Final architecture
```mermaid
graph LR

Sensors-->Data

subgraph ESP32
    Data
end;

Data--:80-->Apache

subgraph Server
    Apache-->php_example.php-->MySQL_DB[(MySQL_DB)]-->Grafana
end;
```

## SERVER SETUP INSTRUCTIONS
To push datas to grafana server, you must got a linux server available, with differents services enabled.  
Instructions are written for linux debian OS (debian, ubuntu, raspbian, ...), but you can adapt them with your own linux OS.  
**Project is tested with Raspberry Pi 4, 4Go RAM, ubuntu-server OS.**

There is the list of services required (LAMP server + Grafana).
* **Apache2 server**
    * Used to listening to 80 port.
* **MySQL**
    * Used to save datas, and send them to Grafana.
* **PHP**
    * Used to catch ESP32 datas on 80 port and add them to MySQL database.
* *phpmyadmin*
    * Optional, but easier to create table in database.
* **Grafana**
    * Used to display datas on web browser.

## CODES EXAMPLES

### SETUP MYSQL
#### Create new databse and user
```
sudo mysql -u root
mysql> CREATE DATABASE project_db;
mysql> CREATE USER 'username'@'localhost' IDENTIFIED BY 'password';
mysql> GRANT ALL PRIVILEGES ON project_db.* TO 'username'@'localhost'
mysql> QUIT;
```
#### Create data table
On php myadmin `http://your.ip.adress/phpmyadmin` :
* Sign in with the new account
* On the left panel, click on project_db
* Click on new table
* Specify your data types, names, allow or not null value. One of them must be a number, and be specify as PIMARY KEY. The PRIMARY KEY can't have 2 times the same value. Some of your values can be auto-increment, it is recommend to auto-increment the PRIMARY KEY.
* Save your table

### PHP SCRIPT
An example php script is provided [here](php_example.php).  
You must copy this file on your server at `/var/www/html/`.

### ESP32 EXAMPLE
An example esp32 code is provided [here](esp32_example.cpp)

### GRAFANA
Log in on your grafana admin account at `http://your.server.ip:3000`.
* Connect your database
    * Settings
    * Data Sources
    * Add data source
    * MySQL

![data_source](assets/grafana/mysql.PNG)

* Create a new dashboard

![new_dashboard](assets/grafana/new_dashboard.PNG)

* Click on add panel
    * Here you can choose pabel type. To choose wich data to display, in the panel settings, choose the right database, table, and data.
