#!/bin/bash

GPIO_PATH=/sys/class/gpio

omxplayer -o local /home/pi/embarcados/projeto_final/sons/sim.mp3
echo 4 >> $GPIO_PATH/export
sudo echo out > $GPIO_PATH/gpio4/direction
sudo echo 1 > $GPIO_PATH/gpio4/value
sleep 3
echo 0 > $GPIO_PATH/gpio4/value
echo 4 >> $GPIO_PATH/unexport
