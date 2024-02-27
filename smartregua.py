#TESTE DE MODEM VIVO WNC
#DEV BY vitor.nunciatelli@eletromidia.com.br
#V1.1 - 27/02/2024
# repositório GIT https://github.com/vnunciatelli/regua_inteligente.git
#======================================================================#

import socket
from time import sleep
import sys

def broad():
    interfaces = socket.getaddrinfo(host=socket.gethostname(), port=None, family=socket.AF_INET)
    allips = [ip[-1][0] for ip in interfaces]

    #msg = b'teste broaderagem'
    msg = str.encode(sys.argv[1])
    while True:

        for ip in allips:
            print(f'sending on {ip}')
            sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP)  # UDP
            sock.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
            sock.bind((ip,0))
            sock.sendto(msg, ("255.255.255.255", 44404))
            sock.close()

        sleep(2)
        
broad()