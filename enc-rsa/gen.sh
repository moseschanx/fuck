#!/bin/sh 
#

#Enviroment variable declaration
current_dir=$(pwd)

	#color variable declaration
	RED='\033[0;31m'
	GREEN='\033[0;32m'
	BLUE='\033[0;34m'
	NONE='\033[0m'
	# echo Template : echo -e " ### ${}  ${NONE} ### "

#Writing config files

echo -e " ### ${BLUE} Writing server config files. ${NONE} ### "

echo "
port 1194
proto tcp
dev tun
ca ca.crt
cert server/server.crt
key server/server.key
dh dh2048.pem
server 108.0.0 255.255.255.0
ifconfig-pool-persist /var/log/openvpn/ipp.txt
keepalive 10 120
tls-auth ta.key 0
cipher AES-256-CBC
persist-key
persist-tun
status /var/log/openvpn/openvpn-status.log
verb 3
explicit-exit-notify 0
" > server.conf

echo -e " ### ${GREEN} Writing server config files done. ${NONE} ### "

echo -e " ### ${BLUE} Writing client config files. ${NONE} ### "
echo "
client
dev tun
proto tcp
resolv-retry infinite
nobind
persist-key
persist-tun
ca ca.crt
cert client.crt
key client.key
tls-auth ta.key 1
cipher AES-256-CBC
verb 3
" > client.conf

echo -e " ### ${GREEN} Writing client config files done. ${NONE} ### "


#generating root CA certificate and key
echo -e " ### ${BLUE}  generating root CA certificate and key ${NONE} ### "
openssl req -days 365  -newkey rsa:2048 -keyout $current_dir/ca.key -x509 -nodes -new -out $current_dir/ca.crt 
echo -e " ### ${GREEN}  root CA certificate and key generated ${NONE} ### "


#generating certificate and key for server 
echo -e " ### ${BLUE}  generating certificate and key for server ${NONE} ### "
mkdir -p $current_dir/server
cd $current_dir/server

openssl req -days 365  -newkey rsa:2048	-keyout server.key -nodes -new -out server.csr 

openssl x509 -req -days 365 -in server.csr -CA $current_dir/ca.crt -CAkey $current_dir/ca.key --CAcreateserial -out server.crt 
echo -e " ### ${GREEN} certificate and key for server generated ${NONE} ### "


#generating certificate and key for clients
client_list="
client0
client1
client2
client3
client4
client5
"

for client in $client_list
do
	mkdir -p $current_dir/clients/$client
	cd $current_dir/clients/$client	

	openssl req -days 365  -newkey rsa:2048	-keyout $client.key -nodes -new -out $client.csr 

	openssl x509 -req -days 365 -in $client.csr -CA $current_dir/ca.crt -CAkey $current_dir/ca.key --CAcreateserial -out $client.crt  
done

#generating tls-auth key
openvpn --genkey -secret $current_dir/ta.key

#generating the Diffie hellman parameters
openssl dhparam -out $current_dir/dh2048.pem 2048

exit
