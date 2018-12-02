EESchema Schematic File Version 4
LIBS:Snack Machine-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 4
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
L Snack_Machine:W5500 U8
U 1 1 5C0721C1
P 3400 3450
F 0 "U8" H 4250 2450 50  0000 L CNN
F 1 "W5500" H 2450 2450 50  0000 L CNN
F 2 "Package_QFP:TQFP-48_7x7mm_P0.5mm" H 3400 3450 50  0001 C CNN
F 3 "" H 3400 3450 50  0001 C CNN
	1    3400 3450
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0123
U 1 1 5C07227B
P 3800 1700
F 0 "#PWR0123" H 3800 1550 50  0001 C CNN
F 1 "+3.3V" H 3815 1873 50  0000 C CNN
F 2 "" H 3800 1700 50  0001 C CNN
F 3 "" H 3800 1700 50  0001 C CNN
	1    3800 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	3950 2300 3950 2150
$Comp
L Device:R R72
U 1 1 5C0726A6
P 3800 1950
F 0 "R72" H 3870 1996 50  0000 L CNN
F 1 "10k" H 3870 1905 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 3730 1950 50  0001 C CNN
F 3 "~" H 3800 1950 50  0001 C CNN
	1    3800 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 2300 3650 2150
$Comp
L Device:R R70
U 1 1 5C072754
P 3300 1950
F 0 "R70" H 3370 1996 50  0000 L CNN
F 1 "10k" H 3370 1905 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 3230 1950 50  0001 C CNN
F 3 "~" H 3300 1950 50  0001 C CNN
	1    3300 1950
	1    0    0    -1  
$EndComp
$Comp
L Device:R R71
U 1 1 5C07255F
P 3550 1950
F 0 "R71" H 3620 1996 50  0000 L CNN
F 1 "10k" H 3620 1905 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 3480 1950 50  0001 C CNN
F 3 "~" H 3550 1950 50  0001 C CNN
	1    3550 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3800 2150 3800 2100
Wire Wire Line
	3650 2150 3800 2150
Wire Wire Line
	3550 2100 3550 2300
Wire Wire Line
	3300 2100 3300 2150
Wire Wire Line
	3300 2150 3450 2150
Wire Wire Line
	3450 2150 3450 2300
$Comp
L power:+3.3V #PWR0121
U 1 1 5C072DC9
P 3550 1700
F 0 "#PWR0121" H 3550 1550 50  0001 C CNN
F 1 "+3.3V" H 3565 1873 50  0000 C CNN
F 2 "" H 3550 1700 50  0001 C CNN
F 3 "" H 3550 1700 50  0001 C CNN
	1    3550 1700
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0119
U 1 1 5C072DFE
P 3300 1700
F 0 "#PWR0119" H 3300 1550 50  0001 C CNN
F 1 "+3.3V" H 3315 1873 50  0000 C CNN
F 2 "" H 3300 1700 50  0001 C CNN
F 3 "" H 3300 1700 50  0001 C CNN
	1    3300 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 1700 3300 1800
Wire Wire Line
	3550 1800 3550 1700
Wire Wire Line
	3800 1700 3800 1800
NoConn ~ 3350 2300
NoConn ~ 3250 2300
NoConn ~ 3150 2300
NoConn ~ 3050 2300
NoConn ~ 2950 2300
NoConn ~ 2850 4600
NoConn ~ 2250 3900
$Comp
L Device:R R69
U 1 1 5C0748ED
P 2850 1950
F 0 "R69" H 2920 1996 50  0000 L CNN
F 1 "10k" H 2920 1905 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 2780 1950 50  0001 C CNN
F 3 "~" H 2850 1950 50  0001 C CNN
	1    2850 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	2850 2300 2850 2100
$Comp
L power:+3.3V #PWR0117
U 1 1 5C074ACB
P 2850 1700
F 0 "#PWR0117" H 2850 1550 50  0001 C CNN
F 1 "+3.3V" H 2865 1873 50  0000 C CNN
F 2 "" H 2850 1700 50  0001 C CNN
F 3 "" H 2850 1700 50  0001 C CNN
	1    2850 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	2850 1700 2850 1800
$Comp
L Device:R R67
U 1 1 5C0750AA
P 1950 2700
F 0 "R67" H 2020 2746 50  0000 L CNN
F 1 "10k" H 2020 2655 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 1880 2700 50  0001 C CNN
F 3 "~" H 1950 2700 50  0001 C CNN
	1    1950 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 2850 1950 2900
Wire Wire Line
	1950 2900 2250 2900
$Comp
L power:+3.3V #PWR0115
U 1 1 5C075336
P 1950 2450
F 0 "#PWR0115" H 1950 2300 50  0001 C CNN
F 1 "+3.3V" H 1965 2623 50  0000 C CNN
F 2 "" H 1950 2450 50  0001 C CNN
F 3 "" H 1950 2450 50  0001 C CNN
	1    1950 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 2450 1950 2550
Text HLabel 2100 3000 0    50   Input ~ 0
MOSI
Text HLabel 2100 3200 0    50   Input ~ 0
SCK
Text HLabel 900  3300 0    50   Input ~ 0
CS
Wire Wire Line
	2100 3000 2250 3000
Wire Wire Line
	2100 3100 2250 3100
Wire Wire Line
	2250 3200 2100 3200
$Comp
L Device:Crystal Y3
U 1 1 5C07687B
P 1100 4150
F 0 "Y3" H 1100 4418 50  0000 C CNN
F 1 "Crystal" H 1100 4327 50  0000 C CNN
F 2 "" H 1100 4150 50  0001 C CNN
F 3 "~" H 1100 4150 50  0001 C CNN
	1    1100 4150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R64
U 1 1 5C076964
P 1100 3500
F 0 "R64" V 1200 3500 50  0000 C CNN
F 1 "1M" V 1100 3500 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 1030 3500 50  0001 C CNN
F 3 "~" H 1100 3500 50  0001 C CNN
	1    1100 3500
	0    1    1    0   
$EndComp
Wire Wire Line
	2250 3400 950  3400
Wire Wire Line
	1250 3500 2250 3500
$Comp
L Device:C C32
U 1 1 5C0778C5
P 1300 4500
F 0 "C32" H 1415 4546 50  0000 L CNN
F 1 "22pF" H 1415 4455 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 1338 4350 50  0001 C CNN
F 3 "~" H 1300 4500 50  0001 C CNN
	1    1300 4500
	1    0    0    -1  
$EndComp
$Comp
L Device:C C31
U 1 1 5C07792B
P 900 4500
F 0 "C31" H 1015 4546 50  0000 L CNN
F 1 "22pF" H 1015 4455 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 938 4350 50  0001 C CNN
F 3 "~" H 900 4500 50  0001 C CNN
	1    900  4500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0110
U 1 1 5C07871D
P 1300 4750
F 0 "#PWR0110" H 1300 4500 50  0001 C CNN
F 1 "GND" H 1305 4577 50  0000 C CNN
F 2 "" H 1300 4750 50  0001 C CNN
F 3 "" H 1300 4750 50  0001 C CNN
	1    1300 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	1300 4750 1300 4650
$Comp
L power:GND #PWR0107
U 1 1 5C078C86
P 900 4750
F 0 "#PWR0107" H 900 4500 50  0001 C CNN
F 1 "GND" H 905 4577 50  0000 C CNN
F 2 "" H 900 4750 50  0001 C CNN
F 3 "" H 900 4750 50  0001 C CNN
	1    900  4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	900  4750 900  4650
$Comp
L power:GND #PWR0113
U 1 1 5C0796BA
P 1550 3600
F 0 "#PWR0113" H 1550 3350 50  0001 C CNN
F 1 "GND" H 1555 3427 50  0000 C CNN
F 2 "" H 1550 3600 50  0001 C CNN
F 3 "" H 1550 3600 50  0001 C CNN
	1    1550 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	1550 3600 2250 3600
$Comp
L Device:C C34
U 1 1 5C07A163
P 1700 5650
F 0 "C34" H 1815 5696 50  0000 L CNN
F 1 "0.1" H 1815 5605 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 1738 5500 50  0001 C CNN
F 3 "~" H 1700 5650 50  0001 C CNN
	1    1700 5650
	1    0    0    -1  
$EndComp
$Comp
L Device:C C33
U 1 1 5C07A1CE
P 1350 5650
F 0 "C33" H 1465 5696 50  0000 L CNN
F 1 "10u" H 1465 5605 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 1388 5500 50  0001 C CNN
F 3 "~" H 1350 5650 50  0001 C CNN
	1    1350 5650
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0111
U 1 1 5C07A266
P 1350 5400
F 0 "#PWR0111" H 1350 5250 50  0001 C CNN
F 1 "+3.3V" H 1365 5573 50  0000 C CNN
F 2 "" H 1350 5400 50  0001 C CNN
F 3 "" H 1350 5400 50  0001 C CNN
	1    1350 5400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0112
U 1 1 5C07A929
P 1350 5900
F 0 "#PWR0112" H 1350 5650 50  0001 C CNN
F 1 "GND" H 1355 5727 50  0000 C CNN
F 2 "" H 1350 5900 50  0001 C CNN
F 3 "" H 1350 5900 50  0001 C CNN
	1    1350 5900
	1    0    0    -1  
$EndComp
Wire Wire Line
	1350 5900 1350 5800
$Comp
L power:GND #PWR0114
U 1 1 5C07B019
P 1700 5900
F 0 "#PWR0114" H 1700 5650 50  0001 C CNN
F 1 "GND" H 1705 5727 50  0000 C CNN
F 2 "" H 1700 5900 50  0001 C CNN
F 3 "" H 1700 5900 50  0001 C CNN
	1    1700 5900
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 5900 1700 5800
Wire Wire Line
	1700 5450 1700 5500
Wire Wire Line
	1700 5450 1700 3700
Wire Wire Line
	1700 3700 2250 3700
Connection ~ 1700 5450
Wire Wire Line
	1250 3500 1250 4350
Wire Wire Line
	950  3400 950  4350
$Comp
L Device:R R68
U 1 1 5C07DF85
P 2150 4250
F 0 "R68" H 2220 4296 50  0000 L CNN
F 1 "470" H 2220 4205 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 2080 4250 50  0001 C CNN
F 3 "~" H 2150 4250 50  0001 C CNN
	1    2150 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	2250 4000 2150 4000
Wire Wire Line
	2150 4000 2150 4100
$Comp
L Device:R R66
U 1 1 5C07E885
P 1850 4250
F 0 "R66" H 1920 4296 50  0000 L CNN
F 1 "470" H 1920 4205 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 1780 4250 50  0001 C CNN
F 3 "~" H 1850 4250 50  0001 C CNN
	1    1850 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	1850 3800 1850 4100
Wire Wire Line
	1850 3800 2250 3800
Wire Wire Line
	1850 4400 1850 5150
Text Label 1850 5150 1    50   ~ 0
YELLOWLED
Wire Wire Line
	2150 4400 2150 5150
Text Label 2150 5150 1    50   ~ 0
GREENLED
Wire Wire Line
	1350 5450 1350 5400
Wire Wire Line
	1350 5450 1700 5450
Wire Wire Line
	1350 5450 1350 5500
Connection ~ 1350 5450
$Comp
L power:GND #PWR0118
U 1 1 5C083D29
P 2950 4700
F 0 "#PWR0118" H 2950 4450 50  0001 C CNN
F 1 "GND" H 2955 4527 50  0000 C CNN
F 2 "" H 2950 4700 50  0001 C CNN
F 3 "" H 2950 4700 50  0001 C CNN
	1    2950 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	2950 4600 2950 4700
$Comp
L Device:C C35
U 1 1 5C08483E
P 3050 5250
F 0 "C35" H 3165 5296 50  0000 L CNN
F 1 "0.1uF" H 3165 5205 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3088 5100 50  0001 C CNN
F 3 "~" H 3050 5250 50  0001 C CNN
	1    3050 5250
	1    0    0    -1  
$EndComp
Text Label 3950 5100 2    50   ~ 0
AVDD
Wire Wire Line
	3750 5000 3750 4600
Wire Wire Line
	3350 4700 3350 4600
Wire Wire Line
	3650 4700 3650 4600
Wire Wire Line
	3850 4700 3850 4600
$Comp
L Device:C C36
U 1 1 5C089DF1
P 3500 5250
F 0 "C36" H 3615 5296 50  0000 L CNN
F 1 "10uF" H 3615 5205 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3538 5100 50  0001 C CNN
F 3 "~" H 3500 5250 50  0001 C CNN
	1    3500 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3250 4600 3250 5100
Wire Wire Line
	3050 4600 3050 5100
Wire Wire Line
	3750 5000 3550 5000
Wire Wire Line
	3150 5000 3150 4600
Wire Wire Line
	3550 4600 3550 5000
Connection ~ 3550 5000
Wire Wire Line
	3550 5000 3150 5000
Wire Wire Line
	4650 3700 4550 3700
Wire Wire Line
	4550 3100 4650 3100
Wire Wire Line
	4550 3900 5000 3900
Wire Wire Line
	5000 3900 5000 3600
Wire Wire Line
	5000 2900 5150 2900
Wire Wire Line
	4550 3600 5000 3600
Connection ~ 5000 3600
Wire Wire Line
	5000 3600 5000 3200
Wire Wire Line
	4550 3200 5000 3200
Connection ~ 5000 3200
Wire Wire Line
	5000 3200 5000 2900
$Comp
L Device:C C37
U 1 1 5C0957B0
P 5150 3050
F 0 "C37" H 5265 3096 50  0000 L CNN
F 1 "0.1uF" H 5265 3005 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 5188 2900 50  0001 C CNN
F 3 "~" H 5150 3050 50  0001 C CNN
	1    5150 3050
	1    0    0    -1  
$EndComp
$Comp
L Device:C C38
U 1 1 5C09586A
P 5600 3050
F 0 "C38" H 5715 3096 50  0000 L CNN
F 1 "0.1uF" H 5715 3005 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 5638 2900 50  0001 C CNN
F 3 "~" H 5600 3050 50  0001 C CNN
	1    5600 3050
	1    0    0    -1  
$EndComp
$Comp
L Device:C C39
U 1 1 5C096C6A
P 6050 3050
F 0 "C39" H 6165 3096 50  0000 L CNN
F 1 "0.1uF" H 6165 3005 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 6088 2900 50  0001 C CNN
F 3 "~" H 6050 3050 50  0001 C CNN
	1    6050 3050
	1    0    0    -1  
$EndComp
$Comp
L Device:C C40
U 1 1 5C096D2B
P 6500 3050
F 0 "C40" H 6615 3096 50  0000 L CNN
F 1 "0.1uF" H 6615 3005 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 6538 2900 50  0001 C CNN
F 3 "~" H 6500 3050 50  0001 C CNN
	1    6500 3050
	1    0    0    -1  
$EndComp
$Comp
L Device:C C41
U 1 1 5C096DE5
P 6950 3050
F 0 "C41" H 7065 3096 50  0000 L CNN
F 1 "10uF" H 7065 3005 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 6988 2900 50  0001 C CNN
F 3 "~" H 6950 3050 50  0001 C CNN
	1    6950 3050
	1    0    0    -1  
$EndComp
Connection ~ 5950 3200
Wire Wire Line
	5950 3200 5600 3200
Connection ~ 5150 2900
Connection ~ 5950 2900
Wire Wire Line
	5950 2900 6050 2900
Wire Wire Line
	5950 2900 5950 2800
Text Label 5950 2800 0    50   ~ 0
AVDD
Text Label 5950 3350 0    50   ~ 0
AGND
Wire Wire Line
	5950 3350 5950 3200
Text Label 4650 3700 0    50   ~ 0
AGND
Text Label 4650 3100 0    50   ~ 0
AGND
Text Label 3950 2150 0    50   ~ 0
AGND
Text Label 3500 5600 1    50   ~ 0
AGND
Text Label 3050 5600 1    50   ~ 0
AGND
Wire Wire Line
	3050 5400 3050 5600
$Comp
L Device:R R73
U 1 1 5C0A1491
P 5250 3800
F 0 "R73" V 5043 3800 50  0000 C CNN
F 1 "R" V 5134 3800 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 5180 3800 50  0001 C CNN
F 3 "~" H 5250 3800 50  0001 C CNN
	1    5250 3800
	0    1    1    0   
$EndComp
Wire Wire Line
	5100 3800 4550 3800
Text Label 5500 3800 0    50   ~ 0
AGND
Wire Wire Line
	5500 3800 5400 3800
Wire Wire Line
	3750 5100 3750 5000
Connection ~ 3750 5000
Wire Wire Line
	3750 5100 3950 5100
$Comp
L Device:Ferrite_Bead FB2
U 1 1 5C0A9856
P 4950 5900
F 0 "FB2" V 4676 5900 50  0000 C CNN
F 1 "Ferrite_Bead" V 4767 5900 50  0000 C CNN
F 2 "" V 4880 5900 50  0001 C CNN
F 3 "~" H 4950 5900 50  0001 C CNN
	1    4950 5900
	0    1    1    0   
$EndComp
$Comp
L Device:Ferrite_Bead FB3
U 1 1 5C0A9937
P 4950 6400
F 0 "FB3" V 4676 6400 50  0000 C CNN
F 1 "Ferrite_Bead" V 4767 6400 50  0000 C CNN
F 2 "" V 4880 6400 50  0001 C CNN
F 3 "~" H 4950 6400 50  0001 C CNN
	1    4950 6400
	0    1    1    0   
$EndComp
$Comp
L power:+3.3V #PWR0125
U 1 1 5C0A9A19
P 4500 5900
F 0 "#PWR0125" H 4500 5750 50  0001 C CNN
F 1 "+3.3V" H 4515 6073 50  0000 C CNN
F 2 "" H 4500 5900 50  0001 C CNN
F 3 "" H 4500 5900 50  0001 C CNN
	1    4500 5900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 5900 4800 5900
$Comp
L power:GND #PWR0126
U 1 1 5C0AB32B
P 4500 6400
F 0 "#PWR0126" H 4500 6150 50  0001 C CNN
F 1 "GND" H 4505 6227 50  0000 C CNN
F 2 "" H 4500 6400 50  0001 C CNN
F 3 "" H 4500 6400 50  0001 C CNN
	1    4500 6400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 6400 4800 6400
Text Label 5400 5900 0    50   ~ 0
AVDD
Wire Wire Line
	5400 5900 5100 5900
Text Label 5400 6400 0    50   ~ 0
AGND
Wire Wire Line
	5400 6400 5100 6400
$Comp
L Device:R R65
U 1 1 5C0B07F0
P 1200 3150
F 0 "R65" H 1270 3196 50  0000 L CNN
F 1 "10K" H 1270 3105 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 1130 3150 50  0001 C CNN
F 3 "~" H 1200 3150 50  0001 C CNN
	1    1200 3150
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0109
U 1 1 5C0B3FAA
P 1200 2900
F 0 "#PWR0109" H 1200 2750 50  0001 C CNN
F 1 "+3.3V" H 1215 3073 50  0000 C CNN
F 2 "" H 1200 2900 50  0001 C CNN
F 3 "" H 1200 2900 50  0001 C CNN
	1    1200 2900
	1    0    0    -1  
$EndComp
$Comp
L Snack_Machine:74AHC1G125 U7
U 1 1 5C0F2F7F
P 1800 7000
F 0 "U7" H 1800 7365 50  0000 C CNN
F 1 "74AHC1G125" H 1800 7274 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-5_HandSoldering" H 1800 7000 50  0001 C CNN
F 3 "" H 1800 7000 50  0001 C CNN
	1    1800 7000
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0116
U 1 1 5C0F30A8
P 2500 6900
F 0 "#PWR0116" H 2500 6750 50  0001 C CNN
F 1 "+3.3V" H 2515 7073 50  0000 C CNN
F 2 "" H 2500 6900 50  0001 C CNN
F 3 "" H 2500 6900 50  0001 C CNN
	1    2500 6900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2500 6900 2300 6900
$Comp
L power:GND #PWR0108
U 1 1 5C0F4E4D
P 1000 7100
F 0 "#PWR0108" H 1000 6850 50  0001 C CNN
F 1 "GND" H 1005 6927 50  0000 C CNN
F 2 "" H 1000 7100 50  0001 C CNN
F 3 "" H 1000 7100 50  0001 C CNN
	1    1000 7100
	1    0    0    -1  
$EndComp
Wire Wire Line
	1000 7100 1300 7100
Text Label 2100 3100 2    50   ~ 0
MISO_TRISTATE
Wire Wire Line
	1200 3000 1200 2900
Wire Wire Line
	1200 3300 2250 3300
Wire Wire Line
	1200 3300 900  3300
Connection ~ 1200 3300
Text Label 1200 7000 2    50   ~ 0
MISO_TRISTATE
Wire Wire Line
	1200 7000 1300 7000
Text HLabel 1200 6900 0    50   Input ~ 0
CS
Wire Wire Line
	1200 6900 1300 6900
Text HLabel 2400 7100 2    50   Input ~ 0
MISO
Wire Wire Line
	2400 7100 2300 7100
$Comp
L Snack_Machine:RB1-125BAG1A U9
U 1 1 5BFFEBDB
P 10050 2250
F 0 "U9" H 10477 2296 50  0000 L CNN
F 1 "RB1-125BAG1A" H 10477 2205 50  0000 L CNN
F 2 "Snack Machine:RB1-125BAG1A" H 10050 2250 50  0001 C CNN
F 3 "" H 10050 2250 50  0001 C CNN
	1    10050 2250
	1    0    0    -1  
$EndComp
$Comp
L Device:R R77
U 1 1 5BFFF1A2
P 8700 1250
F 0 "R77" H 8770 1296 50  0000 L CNN
F 1 "49.9" H 8770 1205 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 8630 1250 50  0001 C CNN
F 3 "~" H 8700 1250 50  0001 C CNN
	1    8700 1250
	1    0    0    -1  
$EndComp
$Comp
L Device:R R78
U 1 1 5BFFF24E
P 9000 1250
F 0 "R78" H 9070 1296 50  0000 L CNN
F 1 "10" H 9070 1205 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 8930 1250 50  0001 C CNN
F 3 "~" H 9000 1250 50  0001 C CNN
	1    9000 1250
	1    0    0    -1  
$EndComp
$Comp
L Device:R R75
U 1 1 5BFFF33C
P 8400 1250
F 0 "R75" H 8470 1296 50  0000 L CNN
F 1 "49.9" H 8470 1205 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 8330 1250 50  0001 C CNN
F 3 "~" H 8400 1250 50  0001 C CNN
	1    8400 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	9850 1700 8400 1700
Wire Wire Line
	8400 1400 8400 1700
Wire Wire Line
	9850 1500 8700 1500
Wire Wire Line
	8700 1500 8700 1400
Wire Wire Line
	9000 1400 9000 1600
Wire Wire Line
	9000 1600 9850 1600
Text Label 8700 800  0    50   ~ 0
AVDD
Wire Wire Line
	8700 800  8700 900 
Wire Wire Line
	8700 900  9000 900 
Wire Wire Line
	9000 900  9000 1100
Wire Wire Line
	8700 900  8700 1100
Connection ~ 8700 900 
Wire Wire Line
	8700 900  8400 900 
Wire Wire Line
	8400 900  8400 1100
Text Label 9300 1900 0    50   ~ 0
GREENLED
Wire Wire Line
	9300 1900 9850 1900
$Comp
L power:+3.3V #PWR0127
U 1 1 5C014190
P 9100 2000
F 0 "#PWR0127" H 9100 1850 50  0001 C CNN
F 1 "+3.3V" H 9115 2173 50  0000 C CNN
F 2 "" H 9100 2000 50  0001 C CNN
F 3 "" H 9100 2000 50  0001 C CNN
	1    9100 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	9100 2000 9850 2000
Text Label 9300 2300 0    50   ~ 0
YELLOWLED
Wire Wire Line
	9300 2300 9850 2300
$Comp
L power:+3.3V #PWR0128
U 1 1 5C0198FE
P 9100 2300
F 0 "#PWR0128" H 9100 2150 50  0001 C CNN
F 1 "+3.3V" H 9115 2473 50  0000 C CNN
F 2 "" H 9100 2300 50  0001 C CNN
F 3 "" H 9100 2300 50  0001 C CNN
	1    9100 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	9100 2300 9200 2300
Wire Wire Line
	9200 2300 9200 2200
Wire Wire Line
	9200 2200 9850 2200
$Comp
L Device:C C42
U 1 1 5C01C925
P 8550 2500
F 0 "C42" V 8298 2500 50  0000 C CNN
F 1 "6.8nF" V 8389 2500 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 8588 2350 50  0001 C CNN
F 3 "~" H 8550 2500 50  0001 C CNN
	1    8550 2500
	0    1    1    0   
$EndComp
Wire Wire Line
	8700 2500 9850 2500
$Comp
L Device:C C44
U 1 1 5C01F62A
P 9350 2700
F 0 "C44" V 9600 2700 50  0000 C CNN
F 1 "6.8nF" V 9500 2700 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 9388 2550 50  0001 C CNN
F 3 "~" H 9350 2700 50  0001 C CNN
	1    9350 2700
	0    1    1    0   
$EndComp
$Comp
L Device:R R76
U 1 1 5C022E18
P 8600 2950
F 0 "R76" H 8670 2996 50  0000 L CNN
F 1 "49.9" H 8670 2905 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 8530 2950 50  0001 C CNN
F 3 "~" H 8600 2950 50  0001 C CNN
	1    8600 2950
	1    0    0    -1  
$EndComp
$Comp
L Device:R R74
U 1 1 5C028965
P 8300 2950
F 0 "R74" H 8370 2996 50  0000 L CNN
F 1 "49.9" H 8370 2905 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 8230 2950 50  0001 C CNN
F 3 "~" H 8300 2950 50  0001 C CNN
	1    8300 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 5600 3500 5400
Wire Wire Line
	3250 5100 3500 5100
Text Label 8100 2500 0    50   ~ 0
RX+
Wire Wire Line
	8100 2500 8300 2500
Wire Wire Line
	8300 2800 8300 2500
Connection ~ 8300 2500
Wire Wire Line
	8300 2500 8400 2500
Text Label 8100 2700 0    50   ~ 0
RX-
Wire Wire Line
	8100 2700 8600 2700
Wire Wire Line
	8600 2800 8600 2700
Wire Wire Line
	8300 3100 8300 3300
Wire Wire Line
	8300 3300 8600 3300
Wire Wire Line
	8600 3300 8600 3100
Wire Wire Line
	8600 3300 8900 3300
Wire Wire Line
	8900 2600 9850 2600
Connection ~ 8600 3300
Wire Wire Line
	8900 2600 8900 3300
Wire Wire Line
	9200 2700 8600 2700
Connection ~ 8600 2700
Wire Wire Line
	9500 2700 9850 2700
$Comp
L Device:C C43
U 1 1 5C052D28
P 8600 3650
F 0 "C43" H 8715 3696 50  0000 L CNN
F 1 "10nF" H 8715 3605 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 8638 3500 50  0001 C CNN
F 3 "~" H 8600 3650 50  0001 C CNN
	1    8600 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	8600 3500 8600 3300
Text Label 8600 4050 1    50   ~ 0
AGND
Wire Wire Line
	8600 4050 8600 3800
$Comp
L power:GND #PWR0129
U 1 1 5C05DFBE
P 9700 3100
F 0 "#PWR0129" H 9700 2850 50  0001 C CNN
F 1 "GND" H 9705 2927 50  0000 C CNN
F 2 "" H 9700 3100 50  0001 C CNN
F 3 "" H 9700 3100 50  0001 C CNN
	1    9700 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	9700 3100 9700 3000
Wire Wire Line
	9700 3000 9850 3000
Wire Wire Line
	9850 2900 9700 2900
Wire Wire Line
	9700 2900 9700 3000
Connection ~ 9700 3000
Connection ~ 5600 2900
Wire Wire Line
	5600 2900 5950 2900
Connection ~ 5600 3200
Connection ~ 6050 2900
Connection ~ 6050 3200
Wire Wire Line
	6050 3200 5950 3200
Connection ~ 6500 2900
Connection ~ 6500 3200
Wire Wire Line
	5150 3200 5600 3200
Wire Wire Line
	6050 3200 6500 3200
Wire Wire Line
	5150 2900 5600 2900
Wire Wire Line
	6050 2900 6500 2900
Wire Wire Line
	6500 3200 6950 3200
Wire Wire Line
	6500 2900 6950 2900
Wire Wire Line
	900  4350 950  4350
Wire Wire Line
	1250 4350 1300 4350
Wire Wire Line
	3350 4700 3650 4700
Wire Wire Line
	3650 4700 3850 4700
Connection ~ 3650 4700
Wire Wire Line
	3850 4700 3850 4800
Connection ~ 3850 4700
Text Label 4050 4800 2    50   ~ 0
AGND
Wire Wire Line
	4050 4800 3850 4800
$EndSCHEMATC
