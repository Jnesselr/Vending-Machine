EESchema Schematic File Version 4
LIBS:Snack Machine-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 5
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Snack_Machine:Huzzah32 U?
U 1 1 5DE46DB4
P 5050 2900
AR Path="/5DE46DB4" Ref="U?"  Part="1" 
AR Path="/5DE1B8F8/5DE46DB4" Ref="U5"  Part="1" 
F 0 "U5" H 5050 3825 50  0000 C CNN
F 1 "Huzzah32" H 5050 3734 50  0000 C CNN
F 2 "Snack Machine:HUZZAH32" H 4600 2050 50  0001 C CNN
F 3 "" H 4600 2050 50  0001 C CNN
	1    5050 2900
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5DE46DBA
P 4300 2100
AR Path="/5BCD883C/5DE46DBA" Ref="#PWR?"  Part="1" 
AR Path="/5DE46DBA" Ref="#PWR?"  Part="1" 
AR Path="/5DE1B8F8/5DE46DBA" Ref="#PWR0138"  Part="1" 
F 0 "#PWR0138" H 4300 1950 50  0001 C CNN
F 1 "+5V" H 4315 2273 50  0000 C CNN
F 2 "" H 4300 2100 50  0001 C CNN
F 3 "" H 4300 2100 50  0001 C CNN
	1    4300 2100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5DE46DC0
P 5900 2600
AR Path="/5DE46DC0" Ref="#PWR?"  Part="1" 
AR Path="/5DE1B8F8/5DE46DC0" Ref="#PWR0139"  Part="1" 
F 0 "#PWR0139" H 5900 2350 50  0001 C CNN
F 1 "GND" H 5900 2450 50  0000 C CNN
F 2 "" H 5900 2600 50  0001 C CNN
F 3 "" H 5900 2600 50  0001 C CNN
	1    5900 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 3500 6300 3500
Wire Wire Line
	5700 3600 6300 3600
Text Label 5750 3600 0    50   ~ 0
HUZZAH_TX
$Comp
L power:+3.3V #PWR?
U 1 1 5DE46DCA
P 5800 2100
AR Path="/5DE46DCA" Ref="#PWR?"  Part="1" 
AR Path="/5DE1B8F8/5DE46DCA" Ref="#PWR0140"  Part="1" 
F 0 "#PWR0140" H 5800 1950 50  0001 C CNN
F 1 "+3.3V" H 5815 2273 50  0000 C CNN
F 2 "" H 5800 2100 50  0001 C CNN
F 3 "" H 5800 2100 50  0001 C CNN
	1    5800 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 2400 4300 2400
Wire Wire Line
	4300 2400 4300 2100
Wire Wire Line
	5700 2300 5800 2300
Wire Wire Line
	5800 2300 5800 2100
Wire Wire Line
	5900 2500 5900 2600
NoConn ~ 5700 2400
NoConn ~ 4400 2200
NoConn ~ 4400 2300
NoConn ~ 4400 2500
NoConn ~ 4400 2600
NoConn ~ 4400 2700
NoConn ~ 4400 2800
NoConn ~ 4400 2900
NoConn ~ 4400 3000
NoConn ~ 4400 3100
NoConn ~ 4400 3200
NoConn ~ 4400 3300
NoConn ~ 5700 3700
NoConn ~ 5700 3400
NoConn ~ 5700 3300
NoConn ~ 5700 3200
NoConn ~ 5700 3100
NoConn ~ 5700 3000
NoConn ~ 5700 2900
NoConn ~ 5700 2800
NoConn ~ 5700 2700
NoConn ~ 5700 2600
Wire Wire Line
	5700 2500 5900 2500
$Comp
L Logic_LevelTranslator:SN74LVC1T45DBV U7
U 1 1 5DE48758
P 7800 2800
F 0 "U7" H 8150 2650 50  0000 L CNN
F 1 "SN74LVC1T45DBV" H 8150 2550 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6" H 7800 2350 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74lvc1t45.pdf" H 6900 2150 50  0001 C CNN
	1    7800 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 3500 6300 2800
Wire Wire Line
	6300 2800 7400 2800
$Comp
L power:+5V #PWR0141
U 1 1 5DE4B549
P 7700 2400
F 0 "#PWR0141" H 7700 2250 50  0001 C CNN
F 1 "+5V" H 7715 2573 50  0000 C CNN
F 2 "" H 7700 2400 50  0001 C CNN
F 3 "" H 7700 2400 50  0001 C CNN
	1    7700 2400
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0142
U 1 1 5DE4BB78
P 7900 2400
F 0 "#PWR0142" H 7900 2250 50  0001 C CNN
F 1 "+3.3V" H 7915 2573 50  0000 C CNN
F 2 "" H 7900 2400 50  0001 C CNN
F 3 "" H 7900 2400 50  0001 C CNN
	1    7900 2400
	1    0    0    -1  
$EndComp
Text HLabel 8200 2800 2    50   Input ~ 0
HUZZAH_RX
$Comp
L power:GND #PWR0143
U 1 1 5DE4C602
P 7800 3200
F 0 "#PWR0143" H 7800 2950 50  0001 C CNN
F 1 "GND" H 7805 3027 50  0000 C CNN
F 2 "" H 7800 3200 50  0001 C CNN
F 3 "" H 7800 3200 50  0001 C CNN
	1    7800 3200
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0144
U 1 1 5DE4EE17
P 7700 3650
F 0 "#PWR0144" H 7700 3500 50  0001 C CNN
F 1 "+5V" H 7715 3823 50  0000 C CNN
F 2 "" H 7700 3650 50  0001 C CNN
F 3 "" H 7700 3650 50  0001 C CNN
	1    7700 3650
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0145
U 1 1 5DE4EE1D
P 7900 3650
F 0 "#PWR0145" H 7900 3500 50  0001 C CNN
F 1 "+3.3V" H 7915 3823 50  0000 C CNN
F 2 "" H 7900 3650 50  0001 C CNN
F 3 "" H 7900 3650 50  0001 C CNN
	1    7900 3650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0146
U 1 1 5DE4EE24
P 7800 4450
F 0 "#PWR0146" H 7800 4200 50  0001 C CNN
F 1 "GND" H 7805 4277 50  0000 C CNN
F 2 "" H 7800 4450 50  0001 C CNN
F 3 "" H 7800 4450 50  0001 C CNN
	1    7800 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 3600 6300 4050
Wire Wire Line
	6300 4050 7400 4050
Text HLabel 8200 4050 2    50   Input ~ 0
HUZZAH_TX
$Comp
L power:GND #PWR0147
U 1 1 5DE4FCE2
P 7400 3000
F 0 "#PWR0147" H 7400 2750 50  0001 C CNN
F 1 "GND" H 7405 2827 50  0000 C CNN
F 2 "" H 7400 3000 50  0001 C CNN
F 3 "" H 7400 3000 50  0001 C CNN
	1    7400 3000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0148
U 1 1 5DE515C6
P 8200 4250
F 0 "#PWR0148" H 8200 4000 50  0001 C CNN
F 1 "GND" H 8205 4077 50  0000 C CNN
F 2 "" H 8200 4250 50  0001 C CNN
F 3 "" H 8200 4250 50  0001 C CNN
	1    8200 4250
	1    0    0    -1  
$EndComp
$Comp
L Logic_LevelTranslator:SN74LVC1T45DBV U8
U 1 1 5DE4EE10
P 7800 4050
F 0 "U8" H 8150 3900 50  0000 L CNN
F 1 "SN74LVC1T45DBV" H 8150 3800 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6" H 7800 3600 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74lvc1t45.pdf" H 6900 3400 50  0001 C CNN
	1    7800 4050
	-1   0    0    -1  
$EndComp
Wire Wire Line
	5700 2200 6050 2200
$Comp
L Transistor_BJT:MMBT3904 Q?
U 1 1 5DE58D00
P 6850 1300
AR Path="/5BA75957/5DE58D00" Ref="Q?"  Part="1" 
AR Path="/5DE58D00" Ref="Q?"  Part="1" 
AR Path="/5DE1B8F8/5DE58D00" Ref="Q2"  Part="1" 
F 0 "Q2" H 7041 1346 50  0000 L CNN
F 1 "MMBT3904" H 7041 1255 50  0000 L CNN
F 2 "Snack Machine:SOT-23_Handsoldering_Lite" H 7050 1225 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N3904.pdf" H 6850 1300 50  0001 L CNN
F 4 "MMBT3904-TP" H 6850 1300 50  0001 C CNN "Part Number"
F 5 "MCC" H 6850 1300 50  0001 C CNN "Manufacturer"
	1    6850 1300
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R28
U 1 1 5DE58D08
P 7550 1550
F 0 "R28" H 7400 1600 50  0000 C CNN
F 1 "4.7k" H 7400 1500 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 7480 1550 50  0001 C CNN
F 3 "~" H 7550 1550 50  0001 C CNN
F 4 "RC0603FR-074K7L" H 7550 1550 50  0001 C CNN "Part Number"
F 5 "Yageo" H 7550 1550 50  0001 C CNN "Manufacturer"
	1    7550 1550
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R27
U 1 1 5DE58D10
P 7300 1300
F 0 "R27" V 7200 1300 50  0000 C CNN
F 1 "4.7k" V 7400 1300 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 7230 1300 50  0001 C CNN
F 3 "~" H 7300 1300 50  0001 C CNN
F 4 "RC0603FR-074K7L" V 7300 1300 50  0001 C CNN "Part Number"
F 5 "Yageo" V 7300 1300 50  0001 C CNN "Manufacturer"
	1    7300 1300
	0    -1   1    0   
$EndComp
$Comp
L power:GND #PWR0149
U 1 1 5DE58D16
P 7550 1800
F 0 "#PWR0149" H 7550 1550 50  0001 C CNN
F 1 "GND" H 7600 1650 50  0000 R CNN
F 2 "" H 7550 1800 50  0001 C CNN
F 3 "" H 7550 1800 50  0001 C CNN
	1    7550 1800
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR0150
U 1 1 5DE58D1C
P 6750 1600
F 0 "#PWR0150" H 6750 1350 50  0001 C CNN
F 1 "GND" H 6800 1450 50  0000 R CNN
F 2 "" H 6750 1600 50  0001 C CNN
F 3 "" H 6750 1600 50  0001 C CNN
	1    6750 1600
	-1   0    0    -1  
$EndComp
Wire Wire Line
	7550 1400 7550 1300
Wire Wire Line
	7450 1300 7550 1300
Wire Wire Line
	7550 1700 7550 1800
Wire Wire Line
	7150 1300 7050 1300
Wire Wire Line
	6750 1100 6750 1050
Wire Wire Line
	6750 1050 6050 1050
Wire Wire Line
	6750 1500 6750 1600
Wire Wire Line
	6050 2200 6050 1050
Text HLabel 7550 1300 2    50   Input ~ 0
RESET
$Comp
L power:+3.3V #PWR?
U 1 1 5DD23E2B
P 5150 1500
F 0 "#PWR?" H 5150 1350 50  0001 C CNN
F 1 "+3.3V" H 5165 1673 50  0000 C CNN
F 2 "" H 5150 1500 50  0001 C CNN
F 3 "" H 5150 1500 50  0001 C CNN
	1    5150 1500
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG?
U 1 1 5DD24501
P 5150 1500
F 0 "#FLG?" H 5150 1575 50  0001 C CNN
F 1 "PWR_FLAG" H 5150 1673 50  0000 C CNN
F 2 "" H 5150 1500 50  0001 C CNN
F 3 "~" H 5150 1500 50  0001 C CNN
	1    5150 1500
	-1   0    0    1   
$EndComp
$EndSCHEMATC
