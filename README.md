# About

rpiswitch is for controlling rc remote controlled power sockets 
with the raspberry pi.


# Usage

First you have to install the [wiringpi](https://projects.drogon.net/raspberry-pi/wiringpi/download-and-install/) library.
After that you can compile the example program *send* by executing *make*. 
You may want to changet the used GPIO pin before compilation in the send.cpp source file.
Standart datapin for low cost 433Mhz sender is GPIO17 (PIN11)

Integraded Intertechno Switches

send: House - Group - Device - Command

Example:
sudo ./send a 1 1 1
sudo ./send a 1 1 0


# How to install

## wiring-pi
cd /opt

sudo git clone git://git.drogon.net/wiringPi

cd wiringPi/

sudo ./build

## rpiswitch
cd /opt

sudo git clone https://github.com/baseship/rpiswitch.git

cd rpiswitch

sudo make

## Make ./send starting at root
cd /opt/rpiswitch

sudo chown root ./send

sudo chmod 4711 ./send


## Intertechno example
cd /opt/rpiswitch

./send d 1 1 1
