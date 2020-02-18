import socket  
s= socket.socket()
host = socket.gethostname()
ip = socket.gethostbyname(host)
port = int(input)