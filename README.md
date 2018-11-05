# USBdriver
A USB linux driver


#Comandos
ver o ID: lsusb -> 	colocar pen drive -> lsusb

sudo make

sudo rmmod uas usb_storage

sudo rmmod stick_driver.ko

sudo insmod stick_driver.ko


Log do sistema em tempo real: tail -f /var/log/syslog

Permições e informações do driver: ls -l /dev/nome_driver

Lista de dispositivos: cat /proc/devices
