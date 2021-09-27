#  Video Lecture: 20
#  Programmer: Arif Butt
#  Course: System Programming with Linux
#  Writing a long-lived process process in language of your choice

import socket
sockfd = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sockfd.bind(('0.0.0.0', 54154))
print("My echo server is listening on port: 54154")
while True:
	payload, client_addr = sockfd.recvfrom(1024)
	sockfd.sendto(payload, client_addr)
