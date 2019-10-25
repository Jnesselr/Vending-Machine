EESchema Schematic File Version 4
LIBS:Snack Machine-cache
EELAYER 29 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 3 5
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 8500 4650 2    50   Input ~ 0
RX_USB
Text HLabel 8500 4550 2    50   Input ~ 0
TX_USB
$Comp
L Device:R R56
U 1 1 5BC6B75C
P 5000 4400
F 0 "R56" V 4950 4200 50  0000 C CNN
F 1 "22R" V 4950 4600 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 4930 4400 50  0001 C CNN
F 3 "~" H 5000 4400 50  0001 C CNN
F 4 "RC0603FR-0722RL" V 5000 4400 50  0001 C CNN "Part Number"
F 5 "Yageo" V 5000 4400 50  0001 C CNN "Manufacturer"
	1    5000 4400
	0    1    1    0   
$EndComp
$Comp
L Device:R R57
U 1 1 5BC6B7F9
P 5000 4500
F 0 "R57" V 4950 4300 50  0000 C CNN
F 1 "22R" V 4950 4700 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 4930 4500 50  0001 C CNN
F 3 "~" H 5000 4500 50  0001 C CNN
F 4 "RC0603FR-0722RL" V 5000 4500 50  0001 C CNN "Part Number"
F 5 "Yageo" V 5000 4500 50  0001 C CNN "Manufacturer"
	1    5000 4500
	0    1    1    0   
$EndComp
Text Label 6350 2150 0    50   ~ 0
USBVCC
Text Label 1650 2400 0    50   ~ 0
XVCC
$Comp
L power:+5V #PWR099
U 1 1 5BC6B9E6
P 6750 2400
F 0 "#PWR099" H 6750 2250 50  0001 C CNN
F 1 "+5V" H 6765 2573 50  0000 C CNN
F 2 "" H 6750 2400 50  0001 C CNN
F 3 "" H 6750 2400 50  0001 C CNN
	1    6750 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	6750 2450 6750 2550
Wire Wire Line
	6750 2450 6850 2450
Wire Wire Line
	6850 2450 6850 2550
Connection ~ 6750 2450
$Comp
L power:+5V #PWR0102
U 1 1 5BC6BA8F
P 6750 1000
F 0 "#PWR0102" H 6750 850 50  0001 C CNN
F 1 "+5V" H 6765 1173 50  0000 C CNN
F 2 "" H 6750 1000 50  0001 C CNN
F 3 "" H 6750 1000 50  0001 C CNN
	1    6750 1000
	1    0    0    -1  
$EndComp
$Comp
L Device:C C28
U 1 1 5BC6BAD9
P 6750 1150
F 0 "C28" H 6865 1196 50  0000 L CNN
F 1 "100nF" H 6865 1105 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 6788 1000 50  0001 C CNN
F 3 "~" H 6750 1150 50  0001 C CNN
F 4 "CC0603KRX7R9BB104" H 6750 1150 50  0001 C CNN "Part Number"
F 5 "Yageo" H 6750 1150 50  0001 C CNN "Manufacturer"
	1    6750 1150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 5BC6BB5F
P 6750 1300
F 0 "#PWR0103" H 6750 1050 50  0001 C CNN
F 1 "GND" H 6755 1127 50  0000 C CNN
F 2 "" H 6750 1300 50  0001 C CNN
F 3 "" H 6750 1300 50  0001 C CNN
	1    6750 1300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R59
U 1 1 5BC6BC6A
P 8150 4550
F 0 "R59" V 8100 4350 50  0000 C CNN
F 1 "1k" V 8100 4750 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 8080 4550 50  0001 C CNN
F 3 "~" H 8150 4550 50  0001 C CNN
F 4 "RC0603FR-071KL" V 8150 4550 50  0001 C CNN "Part Number"
F 5 "Yageo" V 8150 4550 50  0001 C CNN "Manufacturer"
	1    8150 4550
	0    1    1    0   
$EndComp
$Comp
L Device:R R60
U 1 1 5BC6BCEC
P 8150 4650
F 0 "R60" V 8100 4450 50  0000 C CNN
F 1 "1k" V 8100 4850 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 8080 4650 50  0001 C CNN
F 3 "~" H 8150 4650 50  0001 C CNN
F 4 "RC0603FR-071KL" V 8150 4650 50  0001 C CNN "Part Number"
F 5 "Yageo" V 8150 4650 50  0001 C CNN "Manufacturer"
	1    8150 4650
	0    1    1    0   
$EndComp
Wire Wire Line
	8500 4550 8300 4550
Wire Wire Line
	8500 4650 8300 4650
NoConn ~ 7450 3850
NoConn ~ 7450 3750
NoConn ~ 7450 4350
$Comp
L Device:LED D5
U 1 1 5BC6CB7D
P 9200 4500
F 0 "D5" V 9150 4650 50  0000 C CNN
F 1 "YELLOW" V 9250 4700 50  0000 C CNN
F 2 "LED_SMD:LED_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 9200 4500 50  0001 C CNN
F 3 "~" H 9200 4500 50  0001 C CNN
F 4 "150060YS75000" V 9200 4500 50  0001 C CNN "Part Number"
F 5 "Würth Elektronik" V 9200 4500 50  0001 C CNN "Manufacturer"
	1    9200 4500
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D6
U 1 1 5BC6CBD2
P 9550 4500
F 0 "D6" V 9500 4300 50  0000 C CNN
F 1 "YELLOW" V 9600 4250 50  0000 C CNN
F 2 "LED_SMD:LED_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 9550 4500 50  0001 C CNN
F 3 "~" H 9550 4500 50  0001 C CNN
F 4 "150060YS75000" V 9550 4500 50  0001 C CNN "Part Number"
F 5 "Würth Elektronik" V 9550 4500 50  0001 C CNN "Manufacturer"
	1    9550 4500
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R62
U 1 1 5BC6D0D2
P 9200 4100
F 0 "R62" H 9050 4200 50  0000 C CNN
F 1 "1k" H 9100 4100 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 9130 4100 50  0001 C CNN
F 3 "~" H 9200 4100 50  0001 C CNN
F 4 "RC0603FR-071KL" H 9200 4100 50  0001 C CNN "Part Number"
F 5 "Yageo" H 9200 4100 50  0001 C CNN "Manufacturer"
	1    9200 4100
	-1   0    0    1   
$EndComp
$Comp
L Device:R R63
U 1 1 5BC6D155
P 9550 4100
F 0 "R63" H 9400 4200 50  0000 C CNN
F 1 "1k" H 9450 4100 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 9480 4100 50  0001 C CNN
F 3 "~" H 9550 4100 50  0001 C CNN
F 4 "RC0603FR-071KL" H 9550 4100 50  0001 C CNN "Part Number"
F 5 "Yageo" H 9550 4100 50  0001 C CNN "Manufacturer"
	1    9550 4100
	-1   0    0    1   
$EndComp
$Comp
L power:+5V #PWR0106
U 1 1 5BC6D37F
P 9550 3850
F 0 "#PWR0106" H 9550 3700 50  0001 C CNN
F 1 "+5V" H 9565 4023 50  0000 C CNN
F 2 "" H 9550 3850 50  0001 C CNN
F 3 "" H 9550 3850 50  0001 C CNN
	1    9550 3850
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
F 1 "10k" H 5870 1105 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 5730 1150 50  0001 C CNN
F 3 "~" H 5800 1150 50  0001 C CNN
F 4 "RC0603FR-0710KL" H 5800 1150 50  0001 C CNN "Part Number"
F 5 "Yageo" H 5800 1150 50  0001 C CNN "Manufacturer"
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
NoConn ~ 7450 2850
Text Label 7550 3150 0    50   ~ 0
MISO2
Text Label 7550 3050 0    50   ~ 0
MOSI2
Text Label 7550 2950 0    50   ~ 0
SCK2
Text Label 5950 2850 2    50   ~ 0
~RESET2
$Comp
L Device:R R55
U 1 1 5BC6CF74
P 4450 2500
F 0 "R55" H 4520 2546 50  0000 L CNN
F 1 "1M" H 4520 2455 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 4380 2500 50  0001 C CNN
F 3 "~" H 4450 2500 50  0001 C CNN
F 4 "RC0603FR-071ML" H 4450 2500 50  0001 C CNN "Part Number"
F 5 "Yageo" H 4450 2500 50  0001 C CNN "Manufacturer"
	1    4450 2500
	1    0    0    -1  
$EndComp
$Comp
L Device:C C23
U 1 1 5BC6D8E3
P 3950 2900
F 0 "C23" H 3800 3000 50  0000 C CNN
F 1 "22pF" H 3750 2900 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3988 2750 50  0001 C CNN
F 3 "~" H 3950 2900 50  0001 C CNN
F 4 "C0603C220J1GACTU" H 3950 2900 50  0001 C CNN "Part Number"
F 5 "KEMET" H 3950 2900 50  0001 C CNN "Manufacturer"
	1    3950 2900
	-1   0    0    1   
$EndComp
$Comp
L Device:C C25
U 1 1 5BC6D985
P 4350 2900
F 0 "C25" H 4200 3000 50  0000 C CNN
F 1 "22pF" H 4150 2900 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 4388 2750 50  0001 C CNN
F 3 "~" H 4350 2900 50  0001 C CNN
F 4 "C0603C220J1GACTU" H 4350 2900 50  0001 C CNN "Part Number"
F 5 "KEMET" H 4350 2900 50  0001 C CNN "Manufacturer"
	1    4350 2900
	-1   0    0    1   
$EndComp
$Comp
L Device:C C29
U 1 1 5BE8C422
P 7200 1150
F 0 "C29" H 7315 1196 50  0000 L CNN
F 1 "1uF" H 7315 1105 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 7238 1000 50  0001 C CNN
F 3 "~" H 7200 1150 50  0001 C CNN
F 4 "C1608X7R1A105K080AC" H 7200 1150 50  0001 C CNN "Part Number"
F 5 "TDK" H 7200 1150 50  0001 C CNN "Manufacturer"
	1    7200 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 1000 6750 1000
Connection ~ 6750 1000
Wire Wire Line
	7200 1300 6750 1300
Connection ~ 6750 1300
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
	7450 4750 9200 4750
Wire Wire Line
	7450 4850 9550 4850
$Comp
L power:+5V #PWR0105
U 1 1 5BEA01B7
P 9200 3850
F 0 "#PWR0105" H 9200 3700 50  0001 C CNN
F 1 "+5V" H 9215 4023 50  0000 C CNN
F 2 "" H 9200 3850 50  0001 C CNN
F 3 "" H 9200 3850 50  0001 C CNN
	1    9200 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	9200 4650 9200 4750
Wire Wire Line
	9550 4650 9550 4850
Wire Wire Line
	9200 4250 9200 4350
Wire Wire Line
	9550 4250 9550 4350
Wire Wire Line
	9550 3850 9550 3950
Wire Wire Line
	9200 3850 9200 3950
$Comp
L power:GND #PWR091
U 1 1 5BEAE949
P 3950 3150
F 0 "#PWR091" H 3950 2900 50  0001 C CNN
F 1 "GND" H 4050 3000 50  0000 R CNN
F 2 "" H 3950 3150 50  0001 C CNN
F 3 "" H 3950 3150 50  0001 C CNN
	1    3950 3150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR094
U 1 1 5BEAF600
P 4350 3150
F 0 "#PWR094" H 4350 2900 50  0001 C CNN
F 1 "GND" H 4450 3000 50  0000 R CNN
F 2 "" H 4350 3150 50  0001 C CNN
F 3 "" H 4350 3150 50  0001 C CNN
	1    4350 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4350 3050 4350 3150
Wire Wire Line
	3950 3050 3950 3150
Wire Wire Line
	5450 4400 5450 3450
Wire Wire Line
	5450 3450 6050 3450
Wire Wire Line
	5550 3550 6050 3550
Wire Wire Line
	6650 2550 6650 2150
Wire Wire Line
	6050 2850 5650 2850
Wire Wire Line
	4350 2750 4350 2650
Wire Wire Line
	3950 2750 3950 2350
Wire Wire Line
	7450 2950 7850 2950
Wire Wire Line
	7450 3050 7850 3050
Wire Wire Line
	7450 3150 7850 3150
$Comp
L power:GND #PWR0100
U 1 1 5BEE3114
P 6750 5550
F 0 "#PWR0100" H 6750 5300 50  0001 C CNN
F 1 "GND" H 6755 5377 50  0000 C CNN
F 2 "" H 6750 5550 50  0001 C CNN
F 3 "" H 6750 5550 50  0001 C CNN
	1    6750 5550
	1    0    0    -1  
$EndComp
Wire Wire Line
	6750 5350 6750 5550
$Comp
L Device:R R61
U 1 1 5BF00241
P 8150 5300
F 0 "R61" H 8000 5250 50  0000 C CNN
F 1 "1k" H 8050 5350 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 8080 5300 50  0001 C CNN
F 3 "~" H 8150 5300 50  0001 C CNN
F 4 "RC0603FR-071KL" H 8150 5300 50  0001 C CNN "Part Number"
F 5 "Yageo" H 8150 5300 50  0001 C CNN "Manufacturer"
	1    8150 5300
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 5BF002A7
P 8150 5550
F 0 "#PWR0104" H 8150 5300 50  0001 C CNN
F 1 "GND" H 8155 5377 50  0000 C CNN
F 2 "" H 8150 5550 50  0001 C CNN
F 3 "" H 8150 5550 50  0001 C CNN
	1    8150 5550
	1    0    0    -1  
$EndComp
Wire Wire Line
	8150 5450 8150 5550
$Comp
L Device:C C30
U 1 1 5BF013CC
P 8500 5050
F 0 "C30" V 8650 5000 50  0000 L CNN
F 1 "100nF" V 8750 5000 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 8538 4900 50  0001 C CNN
F 3 "~" H 8500 5050 50  0001 C CNN
F 4 "CC0603KRX7R9BB104" V 8500 5050 50  0001 C CNN "Part Number"
F 5 "Yageo" V 8500 5050 50  0001 C CNN "Manufacturer"
	1    8500 5050
	0    1    1    0   
$EndComp
Wire Wire Line
	7450 5050 8150 5050
Wire Wire Line
	8150 5050 8150 5150
Connection ~ 8150 5050
Wire Wire Line
	8150 5050 8350 5050
Wire Wire Line
	8650 5050 9250 5050
Text Label 3250 4400 0    50   ~ 0
USB_D+
Text Label 3250 4500 0    50   ~ 0
USB_D-
Wire Wire Line
	5550 4500 5550 3550
Wire Wire Line
	5450 4400 5150 4400
Wire Wire Line
	5150 4500 5550 4500
Wire Wire Line
	6650 5350 6650 5550
Wire Wire Line
	3950 4400 3950 4600
Connection ~ 3950 4400
Wire Wire Line
	3950 4400 4850 4400
Wire Wire Line
	4650 4500 4650 4600
Connection ~ 4650 4500
Wire Wire Line
	4650 4500 4850 4500
$Comp
L Device:Varistor_US RV2
U 1 1 5BF566F2
P 4650 4750
F 0 "RV2" H 4753 4796 50  0000 L CNN
F 1 "CG0603MLC" H 4753 4705 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 4580 4750 50  0001 C CNN
F 3 "~" H 4650 4750 50  0001 C CNN
F 4 "Bourns" H 4650 4750 50  0001 C CNN "Manufacturer"
F 5 "CG0603MLC-05E" H 4650 4750 50  0001 C CNN "Part Number"
	1    4650 4750
	1    0    0    -1  
$EndComp
$Comp
L Device:Varistor_US RV1
U 1 1 5BF64D0F
P 3950 4750
F 0 "RV1" H 4053 4796 50  0000 L CNN
F 1 "CG0603MLC" H 4053 4705 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 3880 4750 50  0001 C CNN
F 3 "~" H 3950 4750 50  0001 C CNN
F 4 "Bourns" H 3950 4750 50  0001 C CNN "Manufacturer"
F 5 "CG0603MLC-05E" H 3950 4750 50  0001 C CNN "Part Number"
	1    3950 4750
	1    0    0    -1  
$EndComp
$Comp
L MCU_Microchip_ATmega:ATmega16U2-MU U6
U 1 1 5BF71146
P 6750 3950
F 0 "U6" H 7100 2600 50  0000 C CNN
F 1 "ATmega16U2-MU" H 7200 2500 50  0000 C CNN
F 2 "Package_DFN_QFN:QFN-32-1EP_5x5mm_P0.5mm_EP3.1x3.1mm" H 6750 3950 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/doc7799.pdf" H 6750 3950 50  0001 C CNN
	1    6750 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	6050 3050 5550 3050
Wire Wire Line
	5550 3050 5550 2350
Wire Wire Line
	5550 2350 5100 2350
$Comp
L Device:Polyfuse F2
U 1 1 5BF7827A
P 3800 3550
F 0 "F2" V 3600 3500 50  0000 C CNN
F 1 "500mA" V 3700 3500 50  0000 C CNN
F 2 "Snack Machine:MF-MSMF050-2" H 3850 3350 50  0001 L CNN
F 3 "~" H 3800 3550 50  0001 C CNN
F 4 "Bourns" V 3800 3550 50  0001 C CNN "Manufacturer"
F 5 "MF-MSMF050-2" V 3800 3550 50  0001 C CNN "Part Number"
	1    3800 3550
	0    1    1    0   
$EndComp
Wire Wire Line
	5100 2650 5100 2750
Wire Wire Line
	5100 3250 6050 3250
Wire Wire Line
	3550 3550 3650 3550
$Comp
L Device:C C24
U 1 1 5BF8F730
P 4050 3800
F 0 "C24" H 4165 3846 50  0000 L CNN
F 1 "100nF" H 4165 3755 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 4088 3650 50  0001 C CNN
F 3 "~" H 4050 3800 50  0001 C CNN
F 4 "CC0603KRX7R9BB104" H 4050 3800 50  0001 C CNN "Part Number"
F 5 "Yageo" H 4050 3800 50  0001 C CNN "Manufacturer"
	1    4050 3800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR092
U 1 1 5BF8F7C8
P 4050 4050
F 0 "#PWR092" H 4050 3800 50  0001 C CNN
F 1 "GND" H 4055 3877 50  0000 C CNN
F 2 "" H 4050 4050 50  0001 C CNN
F 3 "" H 4050 4050 50  0001 C CNN
	1    4050 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3950 3550 4050 3550
Wire Wire Line
	4050 3550 4050 3650
Wire Wire Line
	4050 3950 4050 4050
Wire Wire Line
	4050 3550 4550 3550
Connection ~ 4050 3550
Text Label 4700 3550 0    50   ~ 0
USBVCC
$Comp
L Device:C C26
U 1 1 5BF9753C
P 4550 3800
F 0 "C26" H 4665 3846 50  0000 L CNN
F 1 "1uF" H 4665 3755 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 4588 3650 50  0001 C CNN
F 3 "~" H 4550 3800 50  0001 C CNN
F 4 "C1608X7R1A105K080AC" H 4550 3800 50  0001 C CNN "Part Number"
F 5 "TDk" H 4550 3800 50  0001 C CNN "Manufacturer"
	1    4550 3800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR095
U 1 1 5BF9A0E5
P 4550 4050
F 0 "#PWR095" H 4550 3800 50  0001 C CNN
F 1 "GND" H 4555 3877 50  0000 C CNN
F 2 "" H 4550 4050 50  0001 C CNN
F 3 "" H 4550 4050 50  0001 C CNN
	1    4550 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4550 3950 4550 4050
Wire Wire Line
	4550 3550 4550 3650
Connection ~ 4550 3550
Wire Wire Line
	4550 3550 5050 3550
$Comp
L Device:C C27
U 1 1 5BFA2633
P 5750 4000
F 0 "C27" H 5865 4046 50  0000 L CNN
F 1 "1uF" H 5865 3955 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 5788 3850 50  0001 C CNN
F 3 "~" H 5750 4000 50  0001 C CNN
F 4 "C1608X7R1A105K080AC" H 5750 4000 50  0001 C CNN "Part Number"
F 5 "TDK" H 5750 4000 50  0001 C CNN "Manufacturer"
	1    5750 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 3850 5750 3750
Wire Wire Line
	5750 3750 6050 3750
Text Notes 6200 5950 0    50   ~ 0
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
	7450 4550 8000 4550
Wire Wire Line
	7450 4650 8000 4650
Text Label 7700 4850 0    50   ~ 0
TXL
Text Label 7700 4750 0    50   ~ 0
RXL
NoConn ~ 7450 3950
NoConn ~ 7450 4050
NoConn ~ 7450 4150
NoConn ~ 7450 4450
NoConn ~ 7450 4950
Text Notes 9900 5300 2    50   ~ 0
NOTE: This is the RESET\nline for the ATMEGA2560
Wire Wire Line
	7450 3550 7850 3550
Wire Wire Line
	7450 3450 7850 3450
Wire Wire Line
	7450 3350 7850 3350
Wire Wire Line
	7450 3250 7850 3250
Text Label 7550 3250 0    50   ~ 0
8PB4
Text Label 7550 3350 0    50   ~ 0
8PB5
Text Label 7550 3450 0    50   ~ 0
8PB6
Text Label 7550 3550 0    50   ~ 0
8PB7
Wire Wire Line
	8950 1200 9350 1200
Wire Wire Line
	8950 1100 9350 1100
Wire Wire Line
	8050 1200 8450 1200
Wire Wire Line
	8050 1100 8450 1100
Text Label 8150 1100 0    50   ~ 0
8PB4
Text Label 8150 1200 0    50   ~ 0
8PB5
Text Label 9050 1100 0    50   ~ 0
8PB6
Text Label 9050 1200 0    50   ~ 0
8PB7
$Comp
L Connector_Generic:Conn_02x02_Odd_Even J18
U 1 1 5C0260BF
P 8650 1100
F 0 "J18" H 8700 1317 50  0000 C CNN
F 1 "Conn_02x02_Odd_Even" H 8700 1226 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x02_P2.54mm_Vertical" H 8650 1100 50  0001 C CNN
F 3 "~" H 8650 1100 50  0001 C CNN
	1    8650 1100
	1    0    0    -1  
$EndComp
Text Label 7700 5050 0    50   ~ 0
DTR
Text Label 1650 1750 2    50   ~ 0
USBVCC
Wire Wire Line
	1750 1750 1300 1750
$Comp
L power:+5V #PWR093
U 1 1 5C4A9D62
P 2200 1650
F 0 "#PWR093" H 2200 1500 50  0001 C CNN
F 1 "+5V" H 2215 1823 50  0000 C CNN
F 2 "" H 2200 1650 50  0001 C CNN
F 3 "" H 2200 1650 50  0001 C CNN
	1    2200 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 1750 2200 1650
Wire Wire Line
	6750 2400 6750 2450
Text HLabel 9250 5050 2    50   Input ~ 0
~RESET
$Comp
L Device:Crystal_GND2 Y?
U 1 1 5C2A9367
P 5100 2500
AR Path="/5C2A9367" Ref="Y?"  Part="1" 
AR Path="/5BCD883C/5C2A9367" Ref="Y2"  Part="1" 
F 0 "Y2" V 5146 2631 50  0000 L CNN
F 1 "16MHz" V 5055 2631 50  0000 L CNN
F 2 "Crystal:Resonator_SMD_muRata_CSTxExxV-3Pin_3.0x1.1mm_HandSoldering" H 5100 2500 50  0001 C CNN
F 3 "~" H 5100 2500 50  0001 C CNN
F 4 "Murata" H 5100 2500 50  0001 C CNN "Manufacturer"
F 5 "CSTCE16M0V53C-R0" H 5100 2500 50  0001 C CNN "Part Number"
	1    5100 2500
	0    1    -1   0   
$EndComp
$Comp
L power:GND #PWR096
U 1 1 5C2B0665
P 4800 2750
F 0 "#PWR096" H 4800 2500 50  0001 C CNN
F 1 "GND" H 4900 2600 50  0000 R CNN
F 2 "" H 4800 2750 50  0001 C CNN
F 3 "" H 4800 2750 50  0001 C CNN
	1    4800 2750
	1    0    0    -1  
$EndComp
Connection ~ 5100 2350
Wire Wire Line
	4900 2650 4900 2750
Wire Wire Line
	4900 2750 5100 2750
Connection ~ 5100 2750
Wire Wire Line
	5100 2750 5100 3250
Wire Wire Line
	4900 2500 4800 2500
Wire Wire Line
	4800 2500 4800 2750
Wire Wire Line
	3950 2350 4450 2350
Wire Wire Line
	4350 2650 4450 2650
Connection ~ 4450 2350
Wire Wire Line
	4450 2350 5100 2350
Connection ~ 4450 2650
Wire Wire Line
	4450 2650 4900 2650
Wire Wire Line
	2050 1750 2200 1750
$Comp
L Device:D_Schottky D8
U 1 1 5C21EC9A
P 1900 1750
F 0 "D8" H 1900 1534 50  0000 C CNN
F 1 "D_Schottky" H 1900 1625 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-323" H 1900 1750 50  0001 C CNN
F 3 "~" H 1900 1750 50  0001 C CNN
F 4 "Toshiba Semiconductor and Storage" H 1900 1750 50  0001 C CNN "Manufacturer"
F 5 "CUS08F30,H3F" H 1900 1750 50  0001 C CNN "Part Number"
	1    1900 1750
	-1   0    0    1   
$EndComp
Text Label 5550 3450 0    50   ~ 0
MICRO_D+
Text Label 5550 3550 0    50   ~ 0
MICRO_D-
Text Label 7450 4550 0    50   ~ 0
MICRO_TX
Text Label 7450 4650 0    50   ~ 0
MICRO_RX
Text Label 2650 1400 0    50   ~ 0
USBVCC
Wire Wire Line
	2600 1400 3050 1400
$Comp
L Connector:TestPoint TP93
U 1 1 5C3B0CCE
P 3150 1500
AR Path="/5BCD883C/5C3B0CCE" Ref="TP93"  Part="1" 
AR Path="/5C3B0CCE" Ref="TP?"  Part="1" 
F 0 "TP93" V 3100 1450 50  0000 L CNN
F 1 "TestPoint" V 3100 1700 50  0000 L CNN
F 2 "Snack Machine:TestPoint_THTPad_D0.8mm_Drill0.4mm" H 3350 1500 50  0001 C CNN
F 3 "~" H 3350 1500 50  0001 C CNN
	1    3150 1500
	0    1    1    0   
$EndComp
$Comp
L Connector:TestPoint TP92
U 1 1 5C3B7E84
P 3150 1400
AR Path="/5BCD883C/5C3B7E84" Ref="TP92"  Part="1" 
AR Path="/5C3B7E84" Ref="TP?"  Part="1" 
F 0 "TP92" V 3100 1350 50  0000 L CNN
F 1 "TestPoint" V 3100 1600 50  0000 L CNN
F 2 "Snack Machine:TestPoint_THTPad_D0.8mm_Drill0.4mm" H 3350 1400 50  0001 C CNN
F 3 "~" H 3350 1400 50  0001 C CNN
	1    3150 1400
	0    1    1    0   
$EndComp
Wire Wire Line
	3050 1400 3050 1500
Wire Wire Line
	3050 1500 3150 1500
Connection ~ 3050 1400
Wire Wire Line
	3050 1400 3150 1400
$Comp
L Connector:USB_C_Receptacle_USB2.0 J3
U 1 1 5DCD228D
P 1050 3000
F 0 "J3" H 1157 3867 50  0000 C CNN
F 1 "USB_C_Receptacle_USB2.0" H 1157 3776 50  0000 C CNN
F 2 "" H 1200 3000 50  0001 C CNN
F 3 "https://www.usb.org/sites/default/files/documents/usb_type-c.zip" H 1200 3000 50  0001 C CNN
	1    1050 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	1650 2400 2050 2400
Wire Wire Line
	3550 2400 3550 3550
$Comp
L Device:R R26
U 1 1 5DD148A8
P 3150 2750
F 0 "R26" H 3220 2796 50  0000 L CNN
F 1 "5.1 k" H 3220 2705 50  0000 L CNN
F 2 "" V 3080 2750 50  0001 C CNN
F 3 "~" H 3150 2750 50  0001 C CNN
	1    3150 2750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0131
U 1 1 5DD14F21
P 3150 2900
F 0 "#PWR0131" H 3150 2650 50  0001 C CNN
F 1 "GND" H 3250 2750 50  0000 R CNN
F 2 "" H 3150 2900 50  0001 C CNN
F 3 "" H 3150 2900 50  0001 C CNN
	1    3150 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	1650 2600 3150 2600
$Comp
L Device:R R25
U 1 1 5DD1F62A
P 2800 2850
F 0 "R25" H 2870 2896 50  0000 L CNN
F 1 "5.1 k" H 2870 2805 50  0000 L CNN
F 2 "" V 2730 2850 50  0001 C CNN
F 3 "~" H 2800 2850 50  0001 C CNN
	1    2800 2850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0132
U 1 1 5DD1F630
P 2800 3000
F 0 "#PWR0132" H 2800 2750 50  0001 C CNN
F 1 "GND" H 2900 2850 50  0000 R CNN
F 2 "" H 2800 3000 50  0001 C CNN
F 3 "" H 2800 3000 50  0001 C CNN
	1    2800 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	1650 2700 2800 2700
Wire Wire Line
	1650 3200 1650 3100
Connection ~ 1650 3200
Wire Wire Line
	1650 3000 1650 2900
Wire Wire Line
	1650 2900 2600 2900
Wire Wire Line
	2600 2900 2600 4500
Wire Wire Line
	2600 4500 4650 4500
Connection ~ 1650 2900
Wire Wire Line
	2500 4400 2500 3200
Wire Wire Line
	2500 4400 3950 4400
Wire Wire Line
	1650 3200 2500 3200
$Comp
L power:GND #PWR0133
U 1 1 5DD44A01
P 5750 4150
F 0 "#PWR0133" H 5750 3900 50  0001 C CNN
F 1 "GND" H 5755 3977 50  0000 C CNN
F 2 "" H 5750 4150 50  0001 C CNN
F 3 "" H 5750 4150 50  0001 C CNN
	1    5750 4150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0134
U 1 1 5DD45C8E
P 3950 4900
F 0 "#PWR0134" H 3950 4650 50  0001 C CNN
F 1 "GND" H 3955 4727 50  0000 C CNN
F 2 "" H 3950 4900 50  0001 C CNN
F 3 "" H 3950 4900 50  0001 C CNN
	1    3950 4900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0135
U 1 1 5DD4657F
P 4650 4900
F 0 "#PWR0135" H 4650 4650 50  0001 C CNN
F 1 "GND" H 4655 4727 50  0000 C CNN
F 2 "" H 4650 4900 50  0001 C CNN
F 3 "" H 4650 4900 50  0001 C CNN
	1    4650 4900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0136
U 1 1 5DD476D8
P 1050 3900
F 0 "#PWR0136" H 1050 3650 50  0001 C CNN
F 1 "GND" H 1055 3727 50  0000 C CNN
F 2 "" H 1050 3900 50  0001 C CNN
F 3 "" H 1050 3900 50  0001 C CNN
	1    1050 3900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0137
U 1 1 5DD48029
P 750 3900
F 0 "#PWR0137" H 750 3650 50  0001 C CNN
F 1 "GND" H 755 3727 50  0000 C CNN
F 2 "" H 750 3900 50  0001 C CNN
F 3 "" H 750 3900 50  0001 C CNN
	1    750  3900
	1    0    0    -1  
$EndComp
NoConn ~ 1650 3600
NoConn ~ 1650 3500
Wire Wire Line
	6350 2150 6650 2150
$Comp
L power:PWR_FLAG #FLG0104
U 1 1 5DD1AB73
P 1300 1750
F 0 "#FLG0104" H 1300 1825 50  0001 C CNN
F 1 "PWR_FLAG" V 1300 1877 50  0000 L CNN
F 2 "" H 1300 1750 50  0001 C CNN
F 3 "~" H 1300 1750 50  0001 C CNN
	1    1300 1750
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6650 5550 6750 5550
Connection ~ 6750 5550
$Comp
L power:PWR_FLAG #FLG?
U 1 1 5DD22228
P 2050 2400
F 0 "#FLG?" H 2050 2475 50  0001 C CNN
F 1 "PWR_FLAG" H 2050 2573 50  0000 C CNN
F 2 "" H 2050 2400 50  0001 C CNN
F 3 "~" H 2050 2400 50  0001 C CNN
	1    2050 2400
	1    0    0    -1  
$EndComp
Connection ~ 2050 2400
Wire Wire Line
	2050 2400 3550 2400
$EndSCHEMATC
