//General Configuration 
1) go to : https://fischl.de/usbasp/
   and download the latest version (usbasp.2011-05-28.tar.gz )

2) extract the file and open the terminal in the same directory

3) write down these two commands without ">>"
   >> sudo apt-get update
   >> sudo apt-get install avrdude

4) connect the programmer with the microcontroller chip (see the schematic) then write the following command:
   >> avrdude -F -B 1500kHz -c usbasp -p "chip" -U lock:r:lock.hex:h
   >> avrdude -F -B 1500kHz -c usbasp -p atmega16 -U lock:r:lock.hex:h
   
5) Assuming you have already your hex file : in the directory of the hex file write this command
   >> avrdude -p "chip" -c usbasp -U flash:w:"hex file":i -F -P usb
   >> avrdude -p atmega16 -c usbasp -U flash:w:blink.hex:i -F -P usb

volia you have just uploaded your first program on your chip!!

references :
[1] https://www.youtube.com/watch?v=A-6HLM1XL3M
[2] https://blog.podkalicki.com/how-to-compile-and-burn-the-code-to-avr-chip-on-linuxmacosxwindows/
===========================================================================

//Converting c file in hex file :
1) >> sudo apt-get install gcc-avr avr-libc avrdude
2) >> avr-gcc -Wall -g -Os -mmcu=attiny13 -o main.bin main.c
3) >> avr-objcopy -j .text -j .data -O ihex main.bin main.hex

(or make file if you wish)
references :
[2] https://blog.podkalicki.com/how-to-compile-and-burn-the-code-to-avr-chip-on-linuxmacosxwindows/
===========================================================================

//schematic (usbasp connection to atmega16/atmega32
1) see the image : https://aaroneiche.com/files/2016/11/ISP-10-pin.jpg
2) have a look at the datasheet : http://ww1.microchip.com/downloads/en/devicedoc/doc2466.pdf (page 2 : pin Configuration)
3) connect each pin in the usbasp to the corresponding one in the chip (6 wires - 6 connections)

references :
[3] http://www.learningaboutelectronics.com/Articles/Program-AVR-chip-using-a-USBASP-with-10-pin-cable.php
[4] https://aaroneiche.com/files/2016/11/ISP-10-pin.jpg
[5] http://ww1.microchip.com/downloads/en/devicedoc/doc2466.pdf 
