EESchema Schematic File Version 4
LIBS:Snack Machine-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 5 5
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	5150 5500 5100 5500
Wire Wire Line
	5100 5500 5100 5350
Wire Wire Line
	5150 5800 5100 5800
$Comp
L power:GND #PWR0152
U 1 1 5DD6C299
P 5100 6000
F 0 "#PWR0152" H 5100 5750 50  0001 C CNN
F 1 "GND" H 5150 5850 50  0000 R CNN
F 2 "" H 5100 6000 50  0001 C CNN
F 3 "" H 5100 6000 50  0001 C CNN
	1    5100 6000
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 5800 5100 6000
$Comp
L Connector_Generic:Conn_02x05_Odd_Even J12
U 1 1 5DD6C2A3
P 5350 5700
F 0 "J12" H 5400 6117 50  0000 C CNN
F 1 "Display Serial Header" H 5600 6050 50  0000 C CNN
F 2 "Snack Machine:PinHeader_2x05_P2.54mm_Vertical" H 5350 5700 50  0001 C CNN
F 3 "~" H 5350 5700 50  0001 C CNN
F 4 "5103308-1" H 5350 5700 50  0001 C CNN "Part Number"
F 5 "TE Connectivity AMP Connectors" H 5350 5700 50  0001 C CNN "Manufacturer"
	1    5350 5700
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:MMBT3904 Q?
U 1 1 5DD6C2AB
P 3450 6250
AR Path="/5BA75957/5DD6C2AB" Ref="Q?"  Part="1" 
AR Path="/5DD6C2AB" Ref="Q?"  Part="1" 
AR Path="/5DD3CEE8/5DD6C2AB" Ref="Q3"  Part="1" 
F 0 "Q3" H 3641 6296 50  0000 L CNN
F 1 "MMBT3904" H 3641 6205 50  0000 L CNN
F 2 "Snack Machine:SOT-23_Handsoldering_Lite" H 3650 6175 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N3904.pdf" H 3450 6250 50  0001 L CNN
F 4 "MCC" H 3450 6250 50  0001 C CNN "Manufacturer"
F 5 "MMBT3904-TP" H 3450 6250 50  0001 C CNN "Part Number"
F 6 "12" H 3450 6250 50  0001 C CNN "Bin"
	1    3450 6250
	1    0    0    -1  
$EndComp
$Comp
L Device:R R29
U 1 1 5DD6C2B3
P 2750 6500
F 0 "R29" H 2600 6550 50  0000 C CNN
F 1 "4.7k" H 2600 6450 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 2680 6500 50  0001 C CNN
F 3 "~" H 2750 6500 50  0001 C CNN
F 4 "RC0603FR-074K7L" H 2750 6500 50  0001 C CNN "Part Number"
F 5 "Yageo" H 2750 6500 50  0001 C CNN "Manufacturer"
F 6 "5" H 2750 6500 50  0001 C CNN "Bin"
	1    2750 6500
	1    0    0    -1  
$EndComp
$Comp
L Device:R R30
U 1 1 5DD6C2BB
P 3000 6250
F 0 "R30" V 2900 6250 50  0000 C CNN
F 1 "4.7k" V 3100 6250 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 2930 6250 50  0001 C CNN
F 3 "~" H 3000 6250 50  0001 C CNN
F 4 "RC0603FR-074K7L" V 3000 6250 50  0001 C CNN "Part Number"
F 5 "Yageo" V 3000 6250 50  0001 C CNN "Manufacturer"
F 6 "5" V 3000 6250 50  0001 C CNN "Bin"
	1    3000 6250
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0153
U 1 1 5DD6C2C1
P 2750 6750
F 0 "#PWR0153" H 2750 6500 50  0001 C CNN
F 1 "GND" H 2800 6600 50  0000 R CNN
F 2 "" H 2750 6750 50  0001 C CNN
F 3 "" H 2750 6750 50  0001 C CNN
	1    2750 6750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0154
U 1 1 5DD6C2C7
P 3550 6550
F 0 "#PWR0154" H 3550 6300 50  0001 C CNN
F 1 "GND" H 3600 6400 50  0000 R CNN
F 2 "" H 3550 6550 50  0001 C CNN
F 3 "" H 3550 6550 50  0001 C CNN
	1    3550 6550
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 6350 2750 6250
Wire Wire Line
	2850 6250 2750 6250
Wire Wire Line
	2750 6650 2750 6750
Wire Wire Line
	3150 6250 3250 6250
Wire Wire Line
	3550 6050 3550 6000
Wire Wire Line
	3550 6450 3550 6550
Text HLabel 5150 5600 0    50   Input ~ 0
RX_DISPLAY
Text HLabel 5150 5700 0    50   Output ~ 0
TX_DISPLAY
Text HLabel 2350 6250 0    50   Input ~ 0
RESET_DISPLAY
Wire Wire Line
	2350 6250 2750 6250
Connection ~ 2750 6250
$Comp
L Connector_Generic_MountingPin:Conn_01x30_MountingPin J4
U 1 1 5DB44749
P 4600 3000
F 0 "J4" H 4688 2914 50  0000 L CNN
F 1 "V2 Display Ribbon Cable" H 4688 2823 50  0000 L CNN
F 2 "Snack Machine:FPC30" H 4600 3000 50  0001 C CNN
F 3 "~" H 4600 3000 50  0001 C CNN
F 4 "3-1734839-0" H 4600 3000 50  0001 C CNN "Part Number"
F 5 "TE Connectivity AMP Connectors" H 4600 3000 50  0001 C CNN "Manufacturer"
	1    4600 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 1600 4300 1600
Wire Wire Line
	4300 1600 4300 3600
Wire Wire Line
	4300 3600 4400 3600
Wire Wire Line
	4300 3600 4300 4000
Wire Wire Line
	4300 4000 4400 4000
Connection ~ 4300 3600
Wire Wire Line
	4300 4000 4300 4500
Wire Wire Line
	4300 4500 4400 4500
Connection ~ 4300 4000
Wire Wire Line
	4600 4700 4300 4700
Wire Wire Line
	4300 4700 4300 4500
Connection ~ 4300 4500
$Comp
L power:GND #PWR0155
U 1 1 5DB48D6A
P 4300 4700
F 0 "#PWR0155" H 4300 4450 50  0001 C CNN
F 1 "GND" H 4305 4527 50  0000 C CNN
F 2 "" H 4300 4700 50  0001 C CNN
F 3 "" H 4300 4700 50  0001 C CNN
	1    4300 4700
	1    0    0    -1  
$EndComp
Connection ~ 4300 4700
NoConn ~ 4400 4400
NoConn ~ 4400 4300
Wire Wire Line
	4400 4200 4400 4100
Wire Wire Line
	4400 4100 4150 4100
Connection ~ 4400 4100
NoConn ~ 4400 3300
NoConn ~ 4400 3200
NoConn ~ 4400 3100
NoConn ~ 4400 1700
NoConn ~ 4400 1800
NoConn ~ 4400 1900
NoConn ~ 4400 2000
NoConn ~ 4400 2100
NoConn ~ 4400 2200
NoConn ~ 4400 2300
NoConn ~ 4400 2400
NoConn ~ 4400 2500
NoConn ~ 4400 2600
NoConn ~ 4400 2700
NoConn ~ 4400 2800
NoConn ~ 4400 2900
NoConn ~ 4400 3000
NoConn ~ 4400 3400
NoConn ~ 4400 3500
Wire Wire Line
	5150 5900 4650 5900
Text Label 4650 5900 0    50   ~ 0
RESET
Text Label 3800 6000 2    50   ~ 0
RESET
Wire Wire Line
	3800 6000 3550 6000
Text Label 4050 3700 0    50   ~ 0
RESET
Wire Wire Line
	4050 3700 4400 3700
Wire Wire Line
	4250 3900 4400 3900
Wire Wire Line
	4250 3800 4400 3800
NoConn ~ 5650 5500
NoConn ~ 5650 5600
NoConn ~ 5650 5700
NoConn ~ 5650 5800
NoConn ~ 5650 5900
$Comp
L power:+5V #PWR0151
U 1 1 5E060D8D
P 5100 5350
F 0 "#PWR0151" H 5100 5200 50  0001 C CNN
F 1 "+5V" H 5115 5523 50  0000 C CNN
F 2 "" H 5100 5350 50  0001 C CNN
F 3 "" H 5100 5350 50  0001 C CNN
	1    5100 5350
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0156
U 1 1 5E0610F1
P 4150 4100
F 0 "#PWR0156" H 4150 3950 50  0001 C CNN
F 1 "+5V" V 4165 4228 50  0000 L CNN
F 2 "" H 4150 4100 50  0001 C CNN
F 3 "" H 4150 4100 50  0001 C CNN
	1    4150 4100
	0    -1   -1   0   
$EndComp
Text HLabel 4250 3900 0    50   Input ~ 0
RX_DISPLAY
Text HLabel 4250 3800 0    50   Output ~ 0
TX_DISPLAY
$EndSCHEMATC
