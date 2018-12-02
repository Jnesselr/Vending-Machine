EESchema Schematic File Version 4
LIBS:Snack Machine-cache
EELAYER 26 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 3 4
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 7250 4600 2    50   Input ~ 0
RX_USB
Text HLabel 7250 4500 2    50   Input ~ 0
TX_USB
$Comp
L Device:R R56
U 1 1 5BC6B75C
P 3750 4350
F 0 "R56" V 3700 4150 50  0000 C CNN
F 1 "22R" V 3700 4550 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 3680 4350 50  0001 C CNN
F 3 "~" H 3750 4350 50  0001 C CNN
	1    3750 4350
	0    1    1    0   
$EndComp
$Comp
L Device:R R57
U 1 1 5BC6B7F9
P 3750 4450
F 0 "R57" V 3700 4250 50  0000 C CNN
F 1 "22R" V 3700 4650 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 3680 4450 50  0001 C CNN
F 3 "~" H 3750 4450 50  0001 C CNN
	1    3750 4450
	0    1    1    0   
$EndComp
Text Label 5400 2100 2    50   ~ 0
USBVCC
Text Label 2000 4150 0    50   ~ 0
XVCC
$Comp
L power:+5V #PWR099
U 1 1 5BC6B9E6
P 5500 2350
F 0 "#PWR099" H 5500 2200 50  0001 C CNN
F 1 "+5V" H 5515 2523 50  0000 C CNN
F 2 "" H 5500 2350 50  0001 C CNN
F 3 "" H 5500 2350 50  0001 C CNN
	1    5500 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 2400 5500 2500
Wire Wire Line
	5500 2400 5600 2400
Wire Wire Line
	5600 2400 5600 2500
Connection ~ 5500 2400
$Comp
L power:+5V #PWR0102
U 1 1 5BC6BA8F
P 6450 2000
F 0 "#PWR0102" H 6450 1850 50  0001 C CNN
F 1 "+5V" H 6465 2173 50  0000 C CNN
F 2 "" H 6450 2000 50  0001 C CNN
F 3 "" H 6450 2000 50  0001 C CNN
	1    6450 2000
	1    0    0    -1  
$EndComp
$Comp
L Device:C C28
U 1 1 5BC6BAD9
P 6450 2150
F 0 "C28" H 6565 2196 50  0000 L CNN
F 1 "100nF" H 6565 2105 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 6488 2000 50  0001 C CNN
F 3 "~" H 6450 2150 50  0001 C CNN
	1    6450 2150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 5BC6BB5F
P 6450 2300
F 0 "#PWR0103" H 6450 2050 50  0001 C CNN
F 1 "GND" H 6455 2127 50  0000 C CNN
F 2 "" H 6450 2300 50  0001 C CNN
F 3 "" H 6450 2300 50  0001 C CNN
	1    6450 2300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R59
U 1 1 5BC6BC6A
P 6900 4500
F 0 "R59" V 6850 4300 50  0000 C CNN
F 1 "1k" V 6850 4700 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 6830 4500 50  0001 C CNN
F 3 "~" H 6900 4500 50  0001 C CNN
	1    6900 4500
	0    1    1    0   
$EndComp
$Comp
L Device:R R60
U 1 1 5BC6BCEC
P 6900 4600
F 0 "R60" V 6850 4400 50  0000 C CNN
F 1 "1k" V 6850 4800 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 6830 4600 50  0001 C CNN
F 3 "~" H 6900 4600 50  0001 C CNN
	1    6900 4600
	0    1    1    0   
$EndComp
Wire Wire Line
	7250 4500 7050 4500
Wire Wire Line
	7250 4600 7050 4600
NoConn ~ 6200 3800
NoConn ~ 6200 3700
NoConn ~ 6200 4300
$Comp
L Device:LED D5
U 1 1 5BC6CB7D
P 7950 4450
F 0 "D5" H 7941 4666 50  0000 C CNN
F 1 "YELLOW" H 7941 4575 50  0000 C CNN
F 2 "LED_SMD:LED_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 7950 4450 50  0001 C CNN
F 3 "~" H 7950 4450 50  0001 C CNN
	1    7950 4450
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D6
U 1 1 5BC6CBD2
P 8300 4450
F 0 "D6" H 8291 4666 50  0000 C CNN
F 1 "YELLOW" H 8291 4575 50  0000 C CNN
F 2 "LED_SMD:LED_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 8300 4450 50  0001 C CNN
F 3 "~" H 8300 4450 50  0001 C CNN
	1    8300 4450
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R62
U 1 1 5BC6D0D2
P 7950 4050
F 0 "R62" H 7850 4150 50  0000 C CNN
F 1 "1k" H 7850 4050 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 7880 4050 50  0001 C CNN
F 3 "~" H 7950 4050 50  0001 C CNN
	1    7950 4050
	-1   0    0    1   
$EndComp
$Comp
L Device:R R63
U 1 1 5BC6D155
P 8300 4050
F 0 "R63" H 8200 4150 50  0000 C CNN
F 1 "1k" H 8200 4050 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 8230 4050 50  0001 C CNN
F 3 "~" H 8300 4050 50  0001 C CNN
	1    8300 4050
	-1   0    0    1   
$EndComp
$Comp
L power:+5V #PWR0106
U 1 1 5BC6D37F
P 8300 3800
F 0 "#PWR0106" H 8300 3650 50  0001 C CNN
F 1 "+5V" H 8315 3973 50  0000 C CNN
F 2 "" H 8300 3800 50  0001 C CNN
F 3 "" H 8300 3800 50  0001 C CNN
	1    8300 3800
	1    0    0    -1  
$EndComp
$Comp
L Connector:AVR-ISP-6 J17
U 1 1 5BC73D10
P 4950 1350
F 0 "J17" H 4670 1446 50  0000 R CNN
F 1 "AVR-ISP-6" H 4670 1355 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x03_P2.54mm_Vertical" V 4700 1400 50  0001 C CNN
F 3 " ~" H 3675 800 50  0001 C CNN
	1    4950 1350
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR097
U 1 1 5BC73E28
P 4850 850
F 0 "#PWR097" H 4850 700 50  0001 C CNN
F 1 "+5V" H 4865 1023 50  0000 C CNN
F 2 "" H 4850 850 50  0001 C CNN
F 3 "" H 4850 850 50  0001 C CNN
	1    4850 850 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR098
U 1 1 5BC73EDD
P 4850 1750
F 0 "#PWR098" H 4850 1500 50  0001 C CNN
F 1 "GND" H 4855 1577 50  0000 C CNN
F 2 "" H 4850 1750 50  0001 C CNN
F 3 "" H 4850 1750 50  0001 C CNN
	1    4850 1750
	1    0    0    -1  
$EndComp
$Comp
L Device:R R58
U 1 1 5BC741B3
P 5800 1150
F 0 "R58" H 5870 1196 50  0000 L CNN
F 1 "R" H 5870 1105 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 5730 1150 50  0001 C CNN
F 3 "~" H 5800 1150 50  0001 C CNN
	1    5800 1150
	1    0    0    -1  
$EndComp
Text Label 5350 1450 0    50   ~ 0
~RESET2
Text Label 5350 1350 0    50   ~ 0
SCK2
Text Label 5350 1150 0    50   ~ 0
MISO2
Text Label 5350 1250 0    50   ~ 0
MOSI2
NoConn ~ 6200 2800
Text Label 6300 3100 0    50   ~ 0
MISO2
Text Label 6300 3000 0    50   ~ 0
MOSI2
Text Label 6300 2900 0    50   ~ 0
SCK2
Text Label 4700 2800 2    50   ~ 0
~RESET2
$Comp
L Device:R R55
U 1 1 5BC6CF74
P 3200 2450
F 0 "R55" H 3270 2496 50  0000 L CNN
F 1 "1M" H 3270 2405 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 3130 2450 50  0001 C CNN
F 3 "~" H 3200 2450 50  0001 C CNN
	1    3200 2450
	1    0    0    -1  
$EndComp
$Comp
L Device:C C23
U 1 1 5BC6D8E3
P 2700 2850
F 0 "C23" H 2550 2950 50  0000 C CNN
F 1 "22pF" H 2500 2850 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 2738 2700 50  0001 C CNN
F 3 "~" H 2700 2850 50  0001 C CNN
	1    2700 2850
	-1   0    0    1   
$EndComp
$Comp
L Device:C C25
U 1 1 5BC6D985
P 3100 2850
F 0 "C25" H 2950 2950 50  0000 C CNN
F 1 "22pF" H 2900 2850 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3138 2700 50  0001 C CNN
F 3 "~" H 3100 2850 50  0001 C CNN
	1    3100 2850
	-1   0    0    1   
$EndComp
$Comp
L Device:C C29
U 1 1 5BE8C422
P 6900 2150
F 0 "C29" H 7015 2196 50  0000 L CNN
F 1 "1uF" H 7015 2105 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 6938 2000 50  0001 C CNN
F 3 "~" H 6900 2150 50  0001 C CNN
	1    6900 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	6900 2000 6450 2000
Connection ~ 6450 2000
Wire Wire Line
	6900 2300 6450 2300
Connection ~ 6450 2300
Wire Wire Line
	5350 1450 5800 1450
Wire Wire Line
	5800 1450 5800 1300
$Comp
L power:+5V #PWR0101
U 1 1 5BE95368
P 5800 900
F 0 "#PWR0101" H 5800 750 50  0001 C CNN
F 1 "+5V" H 5815 1073 50  0000 C CNN
F 2 "" H 5800 900 50  0001 C CNN
F 3 "" H 5800 900 50  0001 C CNN
	1    5800 900 
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 900  5800 950 
Wire Wire Line
	5350 1350 5650 1350
Wire Wire Line
	5350 1250 5650 1250
Wire Wire Line
	5350 1150 5650 1150
Wire Wire Line
	6200 4700 7950 4700
Wire Wire Line
	6200 4800 8300 4800
$Comp
L power:+5V #PWR0105
U 1 1 5BEA01B7
P 7950 3800
F 0 "#PWR0105" H 7950 3650 50  0001 C CNN
F 1 "+5V" H 7965 3973 50  0000 C CNN
F 2 "" H 7950 3800 50  0001 C CNN
F 3 "" H 7950 3800 50  0001 C CNN
	1    7950 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	7950 4600 7950 4700
Wire Wire Line
	8300 4600 8300 4800
Wire Wire Line
	7950 4200 7950 4300
Wire Wire Line
	8300 4200 8300 4300
Wire Wire Line
	8300 3800 8300 3900
Wire Wire Line
	7950 3800 7950 3900
$Comp
L power:GND #PWR091
U 1 1 5BEAE949
P 2700 3100
F 0 "#PWR091" H 2700 2850 50  0001 C CNN
F 1 "GND" H 2800 2950 50  0000 R CNN
F 2 "" H 2700 3100 50  0001 C CNN
F 3 "" H 2700 3100 50  0001 C CNN
	1    2700 3100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR094
U 1 1 5BEAF600
P 3100 3100
F 0 "#PWR094" H 3100 2850 50  0001 C CNN
F 1 "GND" H 3200 2950 50  0000 R CNN
F 2 "" H 3100 3100 50  0001 C CNN
F 3 "" H 3100 3100 50  0001 C CNN
	1    3100 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 3000 3100 3100
Wire Wire Line
	2700 3000 2700 3100
Wire Wire Line
	4200 4350 4200 3400
Wire Wire Line
	4200 3400 4800 3400
Wire Wire Line
	4300 3500 4800 3500
Wire Wire Line
	1950 4150 2300 4150
Wire Wire Line
	5400 2500 5400 2100
Wire Wire Line
	5400 2100 5050 2100
Wire Wire Line
	4800 2800 4400 2800
Wire Wire Line
	3100 2700 3100 2600
Wire Wire Line
	2700 2700 2700 2300
Wire Wire Line
	6200 2900 6600 2900
Wire Wire Line
	6200 3000 6600 3000
Wire Wire Line
	6200 3100 6600 3100
$Comp
L power:GND #PWR0100
U 1 1 5BEE3114
P 5500 5500
F 0 "#PWR0100" H 5500 5250 50  0001 C CNN
F 1 "GND" H 5505 5327 50  0000 C CNN
F 2 "" H 5500 5500 50  0001 C CNN
F 3 "" H 5500 5500 50  0001 C CNN
	1    5500 5500
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 5300 5500 5500
$Comp
L Device:Ferrite_Bead FB1
U 1 1 5BEFDE4B
P 3750 5300
F 0 "FB1" V 3600 5200 50  0000 C CNN
F 1 "600R@100MHz" V 3600 5700 50  0000 C CNN
F 2 "Inductors_SMD:L_0603_HandSoldering" V 3680 5300 50  0001 C CNN
F 3 "~" H 3750 5300 50  0001 C CNN
F 4 "TDK" H 3750 5300 50  0001 C CNN "Manufacturer"
F 5 "MPZ1608S601ATA00" H 3750 5300 50  0001 C CNN "Part Number"
	1    3750 5300
	0    1    1    0   
$EndComp
$Comp
L Device:R R61
U 1 1 5BF00241
P 6900 5250
F 0 "R61" H 6800 5200 50  0000 C CNN
F 1 "1k" H 6800 5300 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 6830 5250 50  0001 C CNN
F 3 "~" H 6900 5250 50  0001 C CNN
	1    6900 5250
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 5BF002A7
P 6900 5500
F 0 "#PWR0104" H 6900 5250 50  0001 C CNN
F 1 "GND" H 6905 5327 50  0000 C CNN
F 2 "" H 6900 5500 50  0001 C CNN
F 3 "" H 6900 5500 50  0001 C CNN
	1    6900 5500
	1    0    0    -1  
$EndComp
Wire Wire Line
	6900 5400 6900 5500
$Comp
L Device:C C30
U 1 1 5BF013CC
P 7250 5000
F 0 "C30" V 7400 4950 50  0000 L CNN
F 1 "100nF" V 7500 4950 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 7288 4850 50  0001 C CNN
F 3 "~" H 7250 5000 50  0001 C CNN
	1    7250 5000
	0    1    1    0   
$EndComp
Wire Wire Line
	6200 5000 6900 5000
Wire Wire Line
	6900 5000 6900 5100
Connection ~ 6900 5000
Wire Wire Line
	6900 5000 7100 5000
Wire Wire Line
	7400 5000 8000 5000
$Comp
L Connector:USB_B_Mini J15
U 1 1 5BF070B3
P 1650 4350
F 0 "J15" H 1705 4817 50  0000 C CNN
F 1 "USB_B_Mini" H 1705 4726 50  0000 C CNN
F 2 "Connector_USB:USB_Mini-B_Lumberg_2486_01_Horizontal" H 1800 4300 50  0001 C CNN
F 3 "~" H 1800 4300 50  0001 C CNN
	1    1650 4350
	1    0    0    -1  
$EndComp
$Comp
L Connector:USB_B_Micro J16
U 1 1 5BF07281
P 1650 6200
F 0 "J16" H 1705 6667 50  0000 C CNN
F 1 "USB_B_Micro" H 1705 6576 50  0000 C CNN
F 2 "" H 1800 6150 50  0001 C CNN
F 3 "~" H 1800 6150 50  0001 C CNN
	1    1650 6200
	1    0    0    -1  
$EndComp
Text Label 2000 4350 0    50   ~ 0
USB_D+
Text Label 2000 4450 0    50   ~ 0
USB_D-
Wire Wire Line
	1950 6000 2350 6000
Wire Wire Line
	1950 6200 2350 6200
Wire Wire Line
	1950 6300 2350 6300
Wire Wire Line
	1950 6400 2100 6400
Wire Wire Line
	1950 4550 2050 4550
Text Label 2000 6000 0    50   ~ 0
XVCC
Text Label 2000 6200 0    50   ~ 0
USB_D+
Text Label 2000 6300 0    50   ~ 0
USB_D-
Wire Wire Line
	1650 4750 1650 4800
Wire Wire Line
	1650 4800 2350 4800
Text Label 1750 4800 0    50   ~ 0
USB_GND
Wire Wire Line
	1650 6600 1650 6750
Wire Wire Line
	1650 6750 2350 6750
Text Label 1850 6750 0    50   ~ 0
USB_GND
$Comp
L Connector:TestPoint TP86
U 1 1 5BF1286E
P 2100 6400
F 0 "TP86" V 2050 6350 50  0000 L CNN
F 1 "TestPoint" V 2050 6600 50  0000 L CNN
F 2 "TestPoint:TestPoint_THTPad_D1.0mm_Drill0.5mm" H 2300 6400 50  0001 C CNN
F 3 "~" H 2300 6400 50  0001 C CNN
	1    2100 6400
	0    1    1    0   
$EndComp
$Comp
L Connector:TestPoint TP85
U 1 1 5BF144D7
P 2050 4550
F 0 "TP85" V 2000 4500 50  0000 L CNN
F 1 "TestPoint" V 2000 4750 50  0000 L CNN
F 2 "TestPoint:TestPoint_THTPad_D1.0mm_Drill0.5mm" H 2250 4550 50  0001 C CNN
F 3 "~" H 2250 4550 50  0001 C CNN
	1    2050 4550
	0    1    1    0   
$EndComp
Wire Wire Line
	1550 6600 1550 6850
Wire Wire Line
	1550 6850 2350 6850
Text Label 1850 6850 0    50   ~ 0
USB_SHIELD
Wire Wire Line
	1550 4750 1550 5300
Wire Wire Line
	1550 5300 2700 5300
Text Label 1750 5300 0    50   ~ 0
USB_SHIELD
Wire Wire Line
	1950 4350 2700 4350
Wire Wire Line
	4300 4450 4300 3500
Wire Wire Line
	1950 4450 3400 4450
Wire Wire Line
	4200 4350 3900 4350
Wire Wire Line
	3900 4450 4300 4450
Wire Wire Line
	4700 5500 5400 5500
Text Label 4800 5500 0    50   ~ 0
USB_GND
Wire Wire Line
	5400 5300 5400 5500
Wire Wire Line
	2700 4850 2700 5300
Connection ~ 2700 5300
Wire Wire Line
	2700 5300 3400 5300
Wire Wire Line
	3400 4850 3400 5300
Connection ~ 3400 5300
Wire Wire Line
	3400 5300 3600 5300
Wire Wire Line
	2700 4350 2700 4550
Connection ~ 2700 4350
Wire Wire Line
	2700 4350 3600 4350
Wire Wire Line
	3400 4450 3400 4550
Connection ~ 3400 4450
Wire Wire Line
	3400 4450 3600 4450
$Comp
L Device:Varistor_US RV2
U 1 1 5BF566F2
P 3400 4700
F 0 "RV2" H 3503 4746 50  0000 L CNN
F 1 "CG0603MLC" H 3503 4655 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 3330 4700 50  0001 C CNN
F 3 "~" H 3400 4700 50  0001 C CNN
F 4 "Bourns" H 3400 4700 50  0001 C CNN "Manufacturer"
F 5 "CG0603MLC-05E" H 3400 4700 50  0001 C CNN "Part Number"
	1    3400 4700
	1    0    0    -1  
$EndComp
$Comp
L Device:Varistor_US RV1
U 1 1 5BF64D0F
P 2700 4700
F 0 "RV1" H 2803 4746 50  0000 L CNN
F 1 "CG0603MLC" H 2803 4655 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 2630 4700 50  0001 C CNN
F 3 "~" H 2700 4700 50  0001 C CNN
F 4 "Bourns" H 2700 4700 50  0001 C CNN "Manufacturer"
F 5 "CG0603MLC-05E" H 2700 4700 50  0001 C CNN "Part Number"
	1    2700 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 5300 4400 5300
Text Label 4000 5300 0    50   ~ 0
USB_GND
$Comp
L MCU_Microchip_ATmega:ATmega16U2-MU U6
U 1 1 5BF71146
P 5500 3900
F 0 "U6" H 5850 2550 50  0000 C CNN
F 1 "ATmega16U2-MU" H 5950 2450 50  0000 C CNN
F 2 "Package_DFN_QFN:QFN-32-1EP_5x5mm_P0.5mm_EP3.1x3.1mm" H 5500 3900 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/doc7799.pdf" H 5500 3900 50  0001 C CNN
	1    5500 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 3000 4300 3000
Wire Wire Line
	4300 3000 4300 2300
Wire Wire Line
	4300 2300 3850 2300
$Comp
L Device:Polyfuse F2
U 1 1 5BF7827A
P 2550 3500
F 0 "F2" V 2350 3450 50  0000 C CNN
F 1 "500mA" V 2450 3450 50  0000 C CNN
F 2 "Snack Machine:MF-MSMF050-2" H 2600 3300 50  0001 L CNN
F 3 "~" H 2550 3500 50  0001 C CNN
F 4 "Bourns" V 2550 3500 50  0001 C CNN "Manufacturer"
F 5 "MF-MSMF050-2" V 2550 3500 50  0001 C CNN "Part Number"
	1    2550 3500
	0    1    1    0   
$EndComp
Wire Wire Line
	3850 2600 3850 2700
Wire Wire Line
	3850 3200 4800 3200
Wire Wire Line
	2300 4150 2300 3500
Wire Wire Line
	2300 3500 2400 3500
$Comp
L Device:C C24
U 1 1 5BF8F730
P 2800 3750
F 0 "C24" H 2915 3796 50  0000 L CNN
F 1 "100nF" H 2915 3705 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 2838 3600 50  0001 C CNN
F 3 "~" H 2800 3750 50  0001 C CNN
	1    2800 3750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR092
U 1 1 5BF8F7C8
P 2800 4000
F 0 "#PWR092" H 2800 3750 50  0001 C CNN
F 1 "GND" H 2805 3827 50  0000 C CNN
F 2 "" H 2800 4000 50  0001 C CNN
F 3 "" H 2800 4000 50  0001 C CNN
	1    2800 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2700 3500 2800 3500
Wire Wire Line
	2800 3500 2800 3600
Wire Wire Line
	2800 3900 2800 4000
Wire Wire Line
	2800 3500 3300 3500
Connection ~ 2800 3500
Text Label 3450 3500 0    50   ~ 0
USBVCC
$Comp
L Device:C C26
U 1 1 5BF9753C
P 3300 3750
F 0 "C26" H 3415 3796 50  0000 L CNN
F 1 "1uF" H 3415 3705 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3338 3600 50  0001 C CNN
F 3 "~" H 3300 3750 50  0001 C CNN
	1    3300 3750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR095
U 1 1 5BF9A0E5
P 3300 4000
F 0 "#PWR095" H 3300 3750 50  0001 C CNN
F 1 "GND" H 3305 3827 50  0000 C CNN
F 2 "" H 3300 4000 50  0001 C CNN
F 3 "" H 3300 4000 50  0001 C CNN
	1    3300 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 3900 3300 4000
Wire Wire Line
	3300 3500 3300 3600
Connection ~ 3300 3500
Wire Wire Line
	3300 3500 3800 3500
$Comp
L Device:C C27
U 1 1 5BFA2633
P 4500 3950
F 0 "C27" H 4615 3996 50  0000 L CNN
F 1 "1uF" H 4615 3905 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 4538 3800 50  0001 C CNN
F 3 "~" H 4500 3950 50  0001 C CNN
	1    4500 3950
	1    0    0    -1  
$EndComp
Text Label 4100 4950 0    50   ~ 0
USB_GND
Wire Wire Line
	4500 4100 4500 4950
Wire Wire Line
	4500 4950 4050 4950
Wire Wire Line
	4500 3800 4500 3700
Wire Wire Line
	4500 3700 4800 3700
Text Notes 4950 5900 0    50   ~ 0
NOTE: Connect PAD to GND
$Comp
L Device:D D4
U 1 1 5BFAB456
P 6100 1150
F 0 "D4" V 6054 1229 50  0000 L CNN
F 1 "D" V 6145 1229 50  0000 L CNN
F 2 "Diode_SMD:D_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 6100 1150 50  0001 C CNN
F 3 "~" H 6100 1150 50  0001 C CNN
F 4 "Bourns" V 6100 1150 50  0001 C CNN "Manufacturer"
F 5 "CD1206-S01575" V 6100 1150 50  0001 C CNN "Part Number"
	1    6100 1150
	0    1    1    0   
$EndComp
Wire Wire Line
	6100 1000 6100 950 
Wire Wire Line
	6100 950  5800 950 
Connection ~ 5800 950 
Wire Wire Line
	5800 950  5800 1000
Wire Wire Line
	6100 1300 6100 1450
Wire Wire Line
	6100 1450 5800 1450
Connection ~ 5800 1450
Wire Wire Line
	6200 4500 6750 4500
Wire Wire Line
	6200 4600 6750 4600
Text Label 6450 4800 0    50   ~ 0
TXL
Text Label 6450 4700 0    50   ~ 0
RXL
NoConn ~ 6200 3900
NoConn ~ 6200 4000
NoConn ~ 6200 4100
NoConn ~ 6200 4400
NoConn ~ 6200 4900
Text Notes 8100 5150 0    50   ~ 0
NOTE: This is the RESET line for the ATMEGA2560
Wire Wire Line
	6200 3500 6600 3500
Wire Wire Line
	6200 3400 6600 3400
Wire Wire Line
	6200 3300 6600 3300
Wire Wire Line
	6200 3200 6600 3200
Text Label 6300 3200 0    50   ~ 0
8PB4
Text Label 6300 3300 0    50   ~ 0
8PB5
Text Label 6300 3400 0    50   ~ 0
8PB6
Text Label 6300 3500 0    50   ~ 0
8PB7
Wire Wire Line
	8200 2950 8600 2950
Wire Wire Line
	8200 2850 8600 2850
Wire Wire Line
	7300 2950 7700 2950
Wire Wire Line
	7300 2850 7700 2850
Text Label 7400 2850 0    50   ~ 0
8PB4
Text Label 7400 2950 0    50   ~ 0
8PB5
Text Label 8300 2850 0    50   ~ 0
8PB6
Text Label 8300 2950 0    50   ~ 0
8PB7
$Comp
L Connector_Generic:Conn_02x02_Odd_Even J18
U 1 1 5C0260BF
P 7900 2850
F 0 "J18" H 7950 3067 50  0000 C CNN
F 1 "Conn_02x02_Odd_Even" H 7950 2976 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x02_P2.54mm_Vertical" H 7900 2850 50  0001 C CNN
F 3 "~" H 7900 2850 50  0001 C CNN
	1    7900 2850
	1    0    0    -1  
$EndComp
Text Label 6450 5000 0    50   ~ 0
DTR
Text Label 2350 1700 2    50   ~ 0
USBVCC
Wire Wire Line
	2450 1700 2000 1700
$Comp
L Device:D_Zener D3
U 1 1 5C49C1BC
P 2600 1700
F 0 "D3" H 2600 1484 50  0000 C CNN
F 1 "D_Zener" H 2600 1575 50  0000 C CNN
F 2 "Diodes_SMD:D_SMB_Handsoldering" H 2600 1700 50  0001 C CNN
F 3 "~" H 2600 1700 50  0001 C CNN
F 4 "Micro Commercial" H 2600 1700 50  0001 C CNN "Manufacturer"
F 5 "3SMBJ5925B-TP" H 2600 1700 50  0001 C CNN "Part Number"
	1    2600 1700
	-1   0    0    1   
$EndComp
$Comp
L power:+5V #PWR093
U 1 1 5C4A9D62
P 2900 1600
F 0 "#PWR093" H 2900 1450 50  0001 C CNN
F 1 "+5V" H 2915 1773 50  0000 C CNN
F 2 "" H 2900 1600 50  0001 C CNN
F 3 "" H 2900 1600 50  0001 C CNN
	1    2900 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 1700 2900 1700
Wire Wire Line
	2900 1700 2900 1600
Wire Wire Line
	5500 2350 5500 2400
Text HLabel 8000 5000 2    50   Input ~ 0
~RESET
$Comp
L Device:Crystal_GND2 Y?
U 1 1 5C2A9367
P 3850 2450
AR Path="/5C2A9367" Ref="Y?"  Part="1" 
AR Path="/5BCD883C/5C2A9367" Ref="Y2"  Part="1" 
F 0 "Y2" V 3896 2581 50  0000 L CNN
F 1 "16MHz" V 3805 2581 50  0000 L CNN
F 2 "Crystal:Resonator_SMD_muRata_CSTxExxV-3Pin_3.0x1.1mm_HandSoldering" H 3850 2450 50  0001 C CNN
F 3 "~" H 3850 2450 50  0001 C CNN
F 4 "Murata" H 3850 2450 50  0001 C CNN "Manufacturer"
F 5 "CSTCE16M0V53C-R0" H 3850 2450 50  0001 C CNN "Part Number"
	1    3850 2450
	0    1    -1   0   
$EndComp
$Comp
L power:GND #PWR096
U 1 1 5C2B0665
P 3550 2700
F 0 "#PWR096" H 3550 2450 50  0001 C CNN
F 1 "GND" H 3650 2550 50  0000 R CNN
F 2 "" H 3550 2700 50  0001 C CNN
F 3 "" H 3550 2700 50  0001 C CNN
	1    3550 2700
	1    0    0    -1  
$EndComp
Connection ~ 3850 2300
Wire Wire Line
	3650 2600 3650 2700
Wire Wire Line
	3650 2700 3850 2700
Connection ~ 3850 2700
Wire Wire Line
	3850 2700 3850 3200
Wire Wire Line
	3650 2450 3550 2450
Wire Wire Line
	3550 2450 3550 2700
Wire Wire Line
	2700 2300 3200 2300
Wire Wire Line
	3100 2600 3200 2600
Connection ~ 3200 2300
Wire Wire Line
	3200 2300 3850 2300
Connection ~ 3200 2600
Wire Wire Line
	3200 2600 3650 2600
Text Label 4300 3400 0    50   ~ 0
MICRO_D+
Text Label 4300 3500 0    50   ~ 0
MICRO_D-
Text Label 6200 4500 0    50   ~ 0
MICRO_TX
Text Label 6200 4600 0    50   ~ 0
MICRO_RX
$EndSCHEMATC
