# SETUP GRAFANA
## Download
```
wget -q -O - https://packages.grafana.com/gpg.key | sudo apt-key add -
sudo add-apt-repository "deb https://packages.grafana.com/oss/deb stable main"
sudo apt-get update
sudo apt-get install grafana
sudo systemctl start grafana-server
sudo systemctl enable grafana-server
```

You can access to grafana on `http://your.server.ip:3000`

## Configuration
The configuration file is located on `/etc/grafana/grafana.ini`  
Following options useless:
|Option|Descrption|
|:-:|:-|
|`allowenbedding true`|You can embed graphs on a html/php page|
|`alloworgcreate`|Anonymous users can't create new organization|
|`allowsignup flase`|Anonymous users can't create a new account|
|`[auth anonymous] enabled true`|Anonymous users can view unprotected graph|
|`[auth anonymous] org role viewer`|Anonymous can only view unprotected graph, not modify them|