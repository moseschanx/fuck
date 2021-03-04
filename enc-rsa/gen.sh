#!/bin/sh 

echo "#generating CA certificate and key"
openssl req -days 365  -newkey rsa:2048 -keyout ca.key -x509 -nodes -new -out ca.crt 
dir

echo "#generating certificate and key for server" 
openssl req -days 365  -newkey rsa:2048	-keyout server.key -nodes -new -out server.csr -extensions server 

openssl x509 -req -days 365 -in server.csr -CA ca.crt -CAkey ca.key --CAcreateserial -out server.crt -extensions server 
dir

echo "#generating certificate and key for client"
openssl req -days 365  -newkey rsa:2048	-keyout client.key -nodes -new -out client.csr -extensions client 

openssl x509 -req -days 365 -in client.csr -CA ca.crt -CAkey ca.key --CAcreateserial -out client.crt  -extensions client
dir

echo "#generating tls-auth key"
openvpn --genkey -secret ta.key

echo "#generating the Diffie hellman parameters"
openssl dhparam -out dh2048.pem 2048


