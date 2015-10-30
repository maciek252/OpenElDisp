# OpenElDisp
Open source software for ElDisp telemetry display 

It receives telemetry data in the Eleres protocol from the RC transmitter (in fact, transceiver), and displays them on a LCD display.

## Features

-displaying flight parameters: heading, number of satellites seen by GPS, position, speed, distance and direction to base, etc

-storing the flight log in a memory


##Connections:

How to use the ISP port:

![](https://github.com/maciek252/OpenElDisp/blob/master/schematElDisp.png)


##BOOTLOADER

Because of non-standard architecture of the board, a customized bootloader needs to be installed.

##TODO

-accept MAVlink as an input

-test if using ISP port for installing the software is necessary 

-use buttons for switching screens