EESchema Schematic File Version 4
LIBS:Snack Machine-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 3
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 6300 2750 2    50   Input ~ 0
RX_USB
Text HLabel 6300 2450 2    50   Input ~ 0
TX_USB
$Comp
L MCU_Microchip_ATmega:ATmega8U2-AU U?
U 1 1 5BC6B5AA
P 4900 2800
F 0 "U?" H 4900 1314 50  0000 C CNN
F 1 "ATmega8U2-AU" H 4900 1223 50  0000 C CNN
F 2 "Package_QFP:TQFP-32_7x7mm_P0.8mm" H 4900 2800 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/doc7799.pdf" H 4900 2800 50  0001 C CNN
	1    4900 2800
	1    0    0    -1  
$EndComp
$Comp
L Connector:USB_B_Micro J?
U 1 1 5BC6B6B2
P 1250 2300
F 0 "J?" H 1305 2767 50  0000 C CNN
F 1 "USB_B_Micro" H 1305 2676 50  0000 C CNN
F 2 "" H 1400 2250 50  0001 C CNN
F 3 "~" H 1400 2250 50  0001 C CNN
	1    1250 2300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5BC6B75C
P 2100 2200
F 0 "R?" V 1893 2200 50  0000 C CNN
F 1 "22R" V 1984 2200 50  0000 C CNN
F 2 "" V 2030 2200 50  0001 C CNN
F 3 "~" H 2100 2200 50  0001 C CNN
	1    2100 2200
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5BC6B7F9
P 2100 2500
F 0 "R?" V 1893 2500 50  0000 C CNN
F 1 "22R" V 1984 2500 50  0000 C CNN
F 2 "" V 2030 2500 50  0001 C CNN
F 3 "~" H 2100 2500 50  0001 C CNN
	1    2100 2500
	0    1    1    0   
$EndComp
Wire Wire Line
	1550 2300 1850 2300
Wire Wire Line
	1850 2300 1950 2200
Wire Wire Line
	1550 2400 1850 2400
Wire Wire Line
	1850 2400 1950 2500
Wire Wire Line
	4200 2300 2350 2300
Wire Wire Line
	2350 2300 2250 2200
Wire Wire Line
	2250 2500 2350 2400
Wire Wire Line
	2350 2400 4200 2400
Text Label 4800 1400 1    50   ~ 0
USBVCC
Text Label 1550 2100 0    50   ~ 0
USBVCC
$Comp
L power:+5V #PWR?
U 1 1 5BC6B9E6
P 4900 1300
F 0 "#PWR?" H 4900 1150 50  0001 C CNN
F 1 "+5V" H 4915 1473 50  0000 C CNN
F 2 "" H 4900 1300 50  0001 C CNN
F 3 "" H 4900 1300 50  0001 C CNN
	1    4900 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 1300 4900 1400
Wire Wire Line
	4900 1300 5000 1300
Wire Wire Line
	5000 1300 5000 1400
Connection ~ 4900 1300
$Comp
L power:+5V #PWR?
U 1 1 5BC6BA8F
P 2300 750
F 0 "#PWR?" H 2300 600 50  0001 C CNN
F 1 "+5V" H 2315 923 50  0000 C CNN
F 2 "" H 2300 750 50  0001 C CNN
F 3 "" H 2300 750 50  0001 C CNN
	1    2300 750 
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5BC6BAD9
P 2300 900
F 0 "C?" H 2415 946 50  0000 L CNN
F 1 "100n" H 2415 855 50  0000 L CNN
F 2 "" H 2338 750 50  0001 C CNN
F 3 "~" H 2300 900 50  0001 C CNN
	1    2300 900 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BC6BB5F
P 2300 1050
F 0 "#PWR?" H 2300 800 50  0001 C CNN
F 1 "GND" H 2305 877 50  0000 C CNN
F 2 "" H 2300 1050 50  0001 C CNN
F 3 "" H 2300 1050 50  0001 C CNN
	1    2300 1050
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5BC6BC6A
P 6050 2450
F 0 "R?" V 5843 2450 50  0000 C CNN
F 1 "1k" V 5934 2450 50  0000 C CNN
F 2 "" V 5980 2450 50  0001 C CNN
F 3 "~" H 6050 2450 50  0001 C CNN
	1    6050 2450
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5BC6BCEC
P 6050 2750
F 0 "R?" V 5843 2750 50  0000 C CNN
F 1 "1k" V 5934 2750 50  0000 C CNN
F 2 "" V 5980 2750 50  0001 C CNN
F 3 "~" H 6050 2750 50  0001 C CNN
	1    6050 2750
	0    1    1    0   
$EndComp
Wire Wire Line
	6300 2450 6200 2450
Wire Wire Line
	6300 2750 6200 2750
NoConn ~ 5600 2700
NoConn ~ 5600 2600
NoConn ~ 5600 3200
$Comp
L Device:LED D?
U 1 1 5BC6CB7D
P 6050 3100
F 0 "D?" H 6041 3316 50  0000 C CNN
F 1 "YELLOW" H 6041 3225 50  0000 C CNN
F 2 "" H 6050 3100 50  0001 C CNN
F 3 "~" H 6050 3100 50  0001 C CNN
	1    6050 3100
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D?
U 1 1 5BC6CBD2
P 6050 3450
F 0 "D?" H 6041 3666 50  0000 C CNN
F 1 "YELLOW" H 6041 3575 50  0000 C CNN
F 2 "" H 6050 3450 50  0001 C CNN
F 3 "~" H 6050 3450 50  0001 C CNN
	1    6050 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	5900 2750 5800 2750
Wire Wire Line
	5800 2750 5650 2900
Wire Wire Line
	5650 2900 5600 2900
Wire Wire Line
	5600 2800 5650 2800
Wire Wire Line
	5650 2800 5800 2650
Wire Wire Line
	5800 2650 5800 2550
Wire Wire Line
	5800 2550 5900 2450
Wire Wire Line
	5600 3000 5650 3000
Wire Wire Line
	5650 3000 5800 3100
Wire Wire Line
	5800 3100 5900 3100
Wire Wire Line
	5600 3100 5650 3100
Wire Wire Line
	5650 3100 5800 3200
Wire Wire Line
	5800 3200 5800 3350
Wire Wire Line
	5800 3350 5900 3450
$Comp
L Device:R R?
U 1 1 5BC6D0D2
P 6350 3100
F 0 "R?" V 6143 3100 50  0000 C CNN
F 1 "1k" V 6234 3100 50  0000 C CNN
F 2 "" V 6280 3100 50  0001 C CNN
F 3 "~" H 6350 3100 50  0001 C CNN
	1    6350 3100
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5BC6D155
P 6350 3450
F 0 "R?" V 6143 3450 50  0000 C CNN
F 1 "1k" V 6234 3450 50  0000 C CNN
F 2 "" V 6280 3450 50  0001 C CNN
F 3 "~" H 6350 3450 50  0001 C CNN
	1    6350 3450
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5BC6D37F
P 6700 3300
F 0 "#PWR?" H 6700 3150 50  0001 C CNN
F 1 "+5V" H 6715 3473 50  0000 C CNN
F 2 "" H 6700 3300 50  0001 C CNN
F 3 "" H 6700 3300 50  0001 C CNN
	1    6700 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 3100 6500 3300
Wire Wire Line
	6700 3300 6500 3300
Connection ~ 6500 3300
Wire Wire Line
	6500 3300 6500 3450
$Comp
L Connector:AVR-ISP-6 J?
U 1 1 5BC73D10
P 7850 1550
F 0 "J?" H 7570 1646 50  0000 R CNN
F 1 "AVR-ISP-6" H 7570 1555 50  0000 R CNN
F 2 "" V 7600 1600 50  0001 C CNN
F 3 " ~" H 6575 1000 50  0001 C CNN
	1    7850 1550
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5BC73E28
P 7750 1050
F 0 "#PWR?" H 7750 900 50  0001 C CNN
F 1 "+5V" H 7765 1223 50  0000 C CNN
F 2 "" H 7750 1050 50  0001 C CNN
F 3 "" H 7750 1050 50  0001 C CNN
	1    7750 1050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BC73EDD
P 7750 1950
F 0 "#PWR?" H 7750 1700 50  0001 C CNN
F 1 "GND" H 7755 1777 50  0000 C CNN
F 2 "" H 7750 1950 50  0001 C CNN
F 3 "" H 7750 1950 50  0001 C CNN
	1    7750 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	7750 1050 7050 1050
Wire Wire Line
	7050 1050 7050 2250
Connection ~ 7750 1050
$Comp
L Device:R R?
U 1 1 5BC741B3
P 8250 1950
F 0 "R?" H 8320 1996 50  0000 L CNN
F 1 "R" H 8320 1905 50  0000 L CNN
F 2 "" V 8180 1950 50  0001 C CNN
F 3 "~" H 8250 1950 50  0001 C CNN
	1    8250 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	8250 1650 8250 1800
Wire Wire Line
	7050 2250 8250 2250
Wire Wire Line
	8250 2250 8250 2100
Text Label 8250 1650 0    50   ~ 0
~RESET
Text Label 8250 1550 0    50   ~ 0
SCK
Text Label 8250 1350 0    50   ~ 0
MISO
Text Label 8250 1450 0    50   ~ 0
MOSI
NoConn ~ 5600 1700
NoConn ~ 5600 2100
NoConn ~ 5600 2200
NoConn ~ 5600 2300
NoConn ~ 5600 2400
Text Label 5600 2000 0    50   ~ 0
MISO
Text Label 5600 1900 0    50   ~ 0
MOSI
Text Label 5600 1800 0    50   ~ 0
SCK
Text Label 4200 1700 2    50   ~ 0
~RESET
$Comp
L Device:R R?
U 1 1 5BC76053
P 3850 2150
F 0 "R?" V 3643 2150 50  0000 C CNN
F 1 "R" V 3734 2150 50  0000 C CNN
F 2 "" V 3780 2150 50  0001 C CNN
F 3 "~" H 3850 2150 50  0001 C CNN
	1    3850 2150
	0    1    1    0   
$EndComp
$Comp
L Device:Crystal Y?
U 1 1 5BC76455
P 3250 2000
F 0 "Y?" V 3204 2131 50  0000 L CNN
F 1 "Crystal" V 3295 2131 50  0000 L CNN
F 2 "" H 3250 2000 50  0001 C CNN
F 3 "~" H 3250 2000 50  0001 C CNN
	1    3250 2000
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5BC6C229
P 3850 1850
F 0 "R?" V 3643 1850 50  0000 C CNN
F 1 "R" V 3734 1850 50  0000 C CNN
F 2 "" V 3780 1850 50  0001 C CNN
F 3 "~" H 3850 1850 50  0001 C CNN
	1    3850 1850
	0    1    1    0   
$EndComp
Wire Wire Line
	3700 1850 3250 1850
Wire Wire Line
	3250 2150 3700 2150
$Comp
L Device:R R?
U 1 1 5BC6CF74
P 2950 2000
F 0 "R?" H 3020 2046 50  0000 L CNN
F 1 "1M" H 3020 1955 50  0000 L CNN
F 2 "" V 2880 2000 50  0001 C CNN
F 3 "~" H 2950 2000 50  0001 C CNN
	1    2950 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2950 1850 3250 1850
Connection ~ 3250 1850
Wire Wire Line
	3250 2150 2950 2150
Connection ~ 3250 2150
$Comp
L Device:C C?
U 1 1 5BC6D8E3
P 2750 1800
F 0 "C?" V 2498 1800 50  0000 C CNN
F 1 "22p" V 2589 1800 50  0000 C CNN
F 2 "" H 2788 1650 50  0001 C CNN
F 3 "~" H 2750 1800 50  0001 C CNN
	1    2750 1800
	0    1    1    0   
$EndComp
$Comp
L Device:C C?
U 1 1 5BC6D985
P 2750 2200
F 0 "C?" V 2498 2200 50  0000 C CNN
F 1 "22p" V 2589 2200 50  0000 C CNN
F 2 "" H 2788 2050 50  0001 C CNN
F 3 "~" H 2750 2200 50  0001 C CNN
	1    2750 2200
	0    1    1    0   
$EndComp
Connection ~ 2950 2150
Wire Wire Line
	2900 2200 2950 2150
Wire Wire Line
	2900 1800 2950 1850
Connection ~ 2950 1850
Wire Wire Line
	4000 1850 4050 1900
Wire Wire Line
	4050 1900 4200 1900
Wire Wire Line
	4000 2150 4050 2100
Wire Wire Line
	4050 2100 4200 2100
$Comp
L power:GND #PWR?
U 1 1 5BC6F517
P 2600 2000
F 0 "#PWR?" H 2600 1750 50  0001 C CNN
F 1 "GND" V 2605 1872 50  0000 R CNN
F 2 "" H 2600 2000 50  0001 C CNN
F 3 "" H 2600 2000 50  0001 C CNN
	1    2600 2000
	0    1    1    0   
$EndComp
Wire Wire Line
	2600 1800 2600 2000
Connection ~ 2600 2000
Wire Wire Line
	2600 2000 2600 2200
$EndSCHEMATC
