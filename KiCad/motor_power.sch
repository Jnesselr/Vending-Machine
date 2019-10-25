EESchema Schematic File Version 4
LIBS:Snack Machine-cache
EELAYER 29 0
EELAYER END
$Descr B 17000 11000
encoding utf-8
Sheet 2 5
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
L Transistor_Array:TBD62783A U?
U 1 1 5DBB3D66
P 6450 1450
F 0 "U?" H 6550 2000 50  0000 C CNN
F 1 "TBD62783A" H 6700 1900 50  0000 C CNN
F 2 "" H 6450 900 50  0001 C CNN
F 3 "http://toshiba.semicon-storage.com/info/docget.jsp?did=30523&prodName=TBD62783APG" H 6150 1850 50  0001 C CNN
	1    6450 1450
	1    0    0    -1  
$EndComp
Text HLabel 6050 1150 0    50   Input ~ 0
row_a_ctrl
Text HLabel 6050 1250 0    50   Input ~ 0
row_b_ctrl
Text HLabel 6050 1350 0    50   Input ~ 0
row_c_ctrl
Text HLabel 6050 1450 0    50   Input ~ 0
row_d_ctrl
Text HLabel 6050 1550 0    50   Input ~ 0
row_e_ctrl
Text HLabel 6050 1650 0    50   Input ~ 0
row_f_ctrl
Text HLabel 6050 1750 0    50   Input ~ 0
row_g_ctrl
Text HLabel 6050 1850 0    50   Input ~ 0
row_h_ctrl
Text HLabel 6850 1150 2    50   Output ~ 0
row_a_motor
Text HLabel 6850 1250 2    50   Output ~ 0
row_b_motor
Text HLabel 6850 1350 2    50   Output ~ 0
row_c_motor
Text HLabel 6850 1450 2    50   Output ~ 0
row_d_motor
Text HLabel 6850 1550 2    50   Output ~ 0
row_e_motor
Text HLabel 6850 1650 2    50   Output ~ 0
row_f_motor
Text HLabel 6850 1750 2    50   Output ~ 0
row_g_motor
Text HLabel 6850 1850 2    50   Output ~ 0
row_h_motor
$Comp
L power:GND #PWR?
U 1 1 5DBB77A2
P 6450 2050
F 0 "#PWR?" H 6450 1800 50  0001 C CNN
F 1 "GND" H 6455 1877 50  0000 C CNN
F 2 "" H 6450 2050 50  0001 C CNN
F 3 "" H 6450 2050 50  0001 C CNN
	1    6450 2050
	1    0    0    -1  
$EndComp
$Comp
L Snack_Machine:DPS1133FIA-13 U?
U 1 1 5DBBF2A8
P 2450 1150
F 0 "U?" H 2775 1315 50  0000 C CNN
F 1 "DPS1133FIA-13" H 2775 1224 50  0000 C CNN
F 2 "kicad_pcb:QFN-17-Diodes1" H 2450 1200 50  0001 L CNN
F 3 "" V 2700 1150 50  0001 C CNN
	1    2450 1150
	1    0    0    -1  
$EndComp
$Comp
L power:+24V #PWR?
U 1 1 5DBC2919
P 850 850
F 0 "#PWR?" H 850 700 50  0001 C CNN
F 1 "+24V" H 865 1023 50  0000 C CNN
F 2 "" H 850 850 50  0001 C CNN
F 3 "" H 850 850 50  0001 C CNN
	1    850  850 
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5DBC434E
P 1550 1000
F 0 "C?" H 1665 1046 50  0000 L CNN
F 1 "2.2 uF" H 1665 955 50  0000 L CNN
F 2 "" H 1588 850 50  0001 C CNN
F 3 "~" H 1550 1000 50  0001 C CNN
	1    1550 1000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5DBC4F97
P 850 1150
F 0 "#PWR?" H 850 900 50  0001 C CNN
F 1 "GND" H 855 977 50  0000 C CNN
F 2 "" H 850 1150 50  0001 C CNN
F 3 "" H 850 1150 50  0001 C CNN
	1    850  1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	850  850  1000 850 
Wire Wire Line
	850  1150 1000 1150
$Comp
L Device:CP C?
U 1 1 5DBC5CDD
P 1000 1000
F 0 "C?" H 1118 1046 50  0000 L CNN
F 1 "220 uF" H 1118 955 50  0000 L CNN
F 2 "" H 1038 850 50  0001 C CNN
F 3 "~" H 1000 1000 50  0001 C CNN
	1    1000 1000
	1    0    0    -1  
$EndComp
Connection ~ 1000 850 
Wire Wire Line
	1000 850  1550 850 
Connection ~ 1000 1150
Wire Wire Line
	1000 1150 1550 1150
Wire Wire Line
	1550 850  2200 850 
Wire Wire Line
	2200 850  2200 1250
Wire Wire Line
	2200 1250 2350 1250
Connection ~ 1550 850 
Wire Wire Line
	2350 1450 2300 1450
Wire Wire Line
	2300 1450 2300 1550
Wire Wire Line
	2350 1850 2300 1850
Connection ~ 2300 1850
Wire Wire Line
	2300 1850 2300 1900
Wire Wire Line
	2350 1650 2300 1650
Connection ~ 2300 1650
Wire Wire Line
	2350 1550 2300 1550
Connection ~ 2300 1550
Wire Wire Line
	2300 1550 2300 1650
$Comp
L power:GND #PWR?
U 1 1 5DBC71ED
P 2300 1900
F 0 "#PWR?" H 2300 1650 50  0001 C CNN
F 1 "GND" H 2305 1727 50  0000 C CNN
F 2 "" H 2300 1900 50  0001 C CNN
F 3 "" H 2300 1900 50  0001 C CNN
	1    2300 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 1650 2300 1850
Wire Wire Line
	2350 1750 2000 1750
$Comp
L Device:C C?
U 1 1 5DBC7B72
P 2000 2250
F 0 "C?" H 2115 2296 50  0000 L CNN
F 1 "100 nF" H 2115 2205 50  0000 L CNN
F 2 "" H 2038 2100 50  0001 C CNN
F 3 "~" H 2000 2250 50  0001 C CNN
	1    2000 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	2000 2100 2000 1750
$Comp
L power:GND #PWR?
U 1 1 5DBC8EA8
P 2000 2400
F 0 "#PWR?" H 2000 2150 50  0001 C CNN
F 1 "GND" H 2005 2227 50  0000 C CNN
F 2 "" H 2000 2400 50  0001 C CNN
F 3 "" H 2000 2400 50  0001 C CNN
	1    2000 2400
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5DBC9344
P 3250 2100
F 0 "C?" H 3365 2146 50  0000 L CNN
F 1 "1 nF" H 3365 2055 50  0000 L CNN
F 2 "" H 3288 1950 50  0001 C CNN
F 3 "~" H 3250 2100 50  0001 C CNN
	1    3250 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3250 1950 3250 1850
Wire Wire Line
	3250 1850 3200 1850
$Comp
L power:GND #PWR?
U 1 1 5DBC9FCA
P 3250 2250
F 0 "#PWR?" H 3250 2000 50  0001 C CNN
F 1 "GND" H 3255 2077 50  0000 C CNN
F 2 "" H 3250 2250 50  0001 C CNN
F 3 "" H 3250 2250 50  0001 C CNN
	1    3250 2250
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5DBCADD5
P 3700 1900
F 0 "R?" H 3770 1946 50  0000 L CNN
F 1 "330 k" H 3770 1855 50  0000 L CNN
F 2 "" V 3630 1900 50  0001 C CNN
F 3 "~" H 3700 1900 50  0001 C CNN
	1    3700 1900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5DBCB9DA
P 3700 2050
F 0 "#PWR?" H 3700 1800 50  0001 C CNN
F 1 "GND" H 3705 1877 50  0000 C CNN
F 2 "" H 3700 2050 50  0001 C CNN
F 3 "" H 3700 2050 50  0001 C CNN
	1    3700 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 1750 3200 1750
$Comp
L Device:R R?
U 1 1 5DBCC131
P 4100 1800
F 0 "R?" H 4170 1846 50  0000 L CNN
F 1 "270 k" H 4170 1755 50  0000 L CNN
F 2 "" V 4030 1800 50  0001 C CNN
F 3 "~" H 4100 1800 50  0001 C CNN
	1    4100 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	3200 1650 4100 1650
$Comp
L power:GND #PWR?
U 1 1 5DBCCDD6
P 4100 1950
F 0 "#PWR?" H 4100 1700 50  0001 C CNN
F 1 "GND" H 4105 1777 50  0000 C CNN
F 2 "" H 4100 1950 50  0001 C CNN
F 3 "" H 4100 1950 50  0001 C CNN
	1    4100 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3200 1450 4500 1450
Wire Wire Line
	4500 1450 4500 2300
$Comp
L Device:R R?
U 1 1 5DBCD7A6
P 4500 2450
F 0 "R?" H 4570 2496 50  0000 L CNN
F 1 "100 k" H 4570 2405 50  0000 L CNN
F 2 "" V 4430 2450 50  0001 C CNN
F 3 "~" H 4500 2450 50  0001 C CNN
	1    4500 2450
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5DBCDD32
P 4050 2450
F 0 "C?" H 4165 2496 50  0000 L CNN
F 1 "100 nF" H 4165 2405 50  0000 L CNN
F 2 "" H 4088 2300 50  0001 C CNN
F 3 "~" H 4050 2450 50  0001 C CNN
	1    4050 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 2300 4500 2300
Connection ~ 4500 2300
$Comp
L power:GND #PWR?
U 1 1 5DBCF155
P 4050 2600
F 0 "#PWR?" H 4050 2350 50  0001 C CNN
F 1 "GND" H 4055 2427 50  0000 C CNN
F 2 "" H 4050 2600 50  0001 C CNN
F 3 "" H 4050 2600 50  0001 C CNN
	1    4050 2600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5DBCF407
P 4500 2600
F 0 "#PWR?" H 4500 2350 50  0001 C CNN
F 1 "GND" H 4505 2427 50  0000 C CNN
F 2 "" H 4500 2600 50  0001 C CNN
F 3 "" H 4500 2600 50  0001 C CNN
	1    4500 2600
	1    0    0    -1  
$EndComp
Text Notes 3850 1450 0    50   ~ 0
10 uA / A\n1 V/A with 100k
Wire Wire Line
	3200 1250 5000 1250
Wire Wire Line
	5000 1250 5000 950 
Wire Wire Line
	5000 950  6450 950 
$Comp
L Device:D D?
U 1 1 5DBD46CB
P 4850 950
F 0 "D?" H 4850 1166 50  0000 C CNN
F 1 "S1GTR" H 4850 1075 50  0000 C CNN
F 2 "" H 4850 950 50  0001 C CNN
F 3 "~" H 4850 950 50  0001 C CNN
	1    4850 950 
	1    0    0    -1  
$EndComp
Connection ~ 5000 950 
$Comp
L power:+24V #PWR?
U 1 1 5DBD523E
P 4700 950
F 0 "#PWR?" H 4700 800 50  0001 C CNN
F 1 "+24V" V 4715 1078 50  0000 L CNN
F 2 "" H 4700 950 50  0001 C CNN
F 3 "" H 4700 950 50  0001 C CNN
	1    4700 950 
	0    -1   -1   0   
$EndComp
$Comp
L Device:C C?
U 1 1 5DBD5801
P 5000 1400
F 0 "C?" H 5115 1446 50  0000 L CNN
F 1 "2.2 uF" H 5115 1355 50  0000 L CNN
F 2 "" H 5038 1250 50  0001 C CNN
F 3 "~" H 5000 1400 50  0001 C CNN
	1    5000 1400
	1    0    0    -1  
$EndComp
Connection ~ 5000 1250
$Comp
L power:GND #PWR?
U 1 1 5DBD5EEA
P 5000 1550
F 0 "#PWR?" H 5000 1300 50  0001 C CNN
F 1 "GND" H 5005 1377 50  0000 C CNN
F 2 "" H 5000 1550 50  0001 C CNN
F 3 "" H 5000 1550 50  0001 C CNN
	1    5000 1550
	1    0    0    -1  
$EndComp
Wire Notes Line
	7500 450  7500 2850
Wire Notes Line
	7500 2850 450  2850
$Comp
L Device:Q_TRIAC_A1A2G D?
U 1 1 5DBD7FE7
P 1750 3100
F 0 "D?" H 1878 3146 50  0000 L CNN
F 1 "Q_TRIAC_A1A2G" H 1878 3055 50  0000 L CNN
F 2 "" V 1825 3125 50  0001 C CNN
F 3 "~" V 1750 3100 50  0001 C CNN
	1    1750 3100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5DBD98A7
P 1750 3250
F 0 "#PWR?" H 1750 3000 50  0001 C CNN
F 1 "GND" H 1755 3077 50  0000 C CNN
F 2 "" H 1750 3250 50  0001 C CNN
F 3 "" H 1750 3250 50  0001 C CNN
	1    1750 3250
	1    0    0    -1  
$EndComp
Text HLabel 2500 2950 2    50   Output ~ 0
col_1_motor
Wire Wire Line
	2500 2950 1750 2950
$Comp
L Device:R R?
U 1 1 5DBDA986
P 1200 3200
F 0 "R?" V 1407 3200 50  0000 C CNN
F 1 "1 k" V 1316 3200 50  0000 C CNN
F 2 "" V 1130 3200 50  0001 C CNN
F 3 "~" H 1200 3200 50  0001 C CNN
	1    1200 3200
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1350 3200 1600 3200
Text HLabel 1050 3200 0    50   Input ~ 0
col_1_ctrl
$Comp
L Device:Q_TRIAC_A1A2G D?
U 1 1 5DBDFB59
P 1750 3750
F 0 "D?" H 1878 3796 50  0000 L CNN
F 1 "Q_TRIAC_A1A2G" H 1878 3705 50  0000 L CNN
F 2 "" V 1825 3775 50  0001 C CNN
F 3 "~" V 1750 3750 50  0001 C CNN
	1    1750 3750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5DBDFB5F
P 1750 3900
F 0 "#PWR?" H 1750 3650 50  0001 C CNN
F 1 "GND" H 1755 3727 50  0000 C CNN
F 2 "" H 1750 3900 50  0001 C CNN
F 3 "" H 1750 3900 50  0001 C CNN
	1    1750 3900
	1    0    0    -1  
$EndComp
Text HLabel 2500 3600 2    50   Output ~ 0
col_3_motor
Wire Wire Line
	2500 3600 1750 3600
$Comp
L Device:R R?
U 1 1 5DBDFB67
P 1200 3850
F 0 "R?" V 1407 3850 50  0000 C CNN
F 1 "1 k" V 1316 3850 50  0000 C CNN
F 2 "" V 1130 3850 50  0001 C CNN
F 3 "~" H 1200 3850 50  0001 C CNN
	1    1200 3850
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1350 3850 1600 3850
Text HLabel 1050 3850 0    50   Input ~ 0
col_3_ctrl
$Comp
L Device:Q_TRIAC_A1A2G D?
U 1 1 5DBE1AE3
P 1750 4400
F 0 "D?" H 1878 4446 50  0000 L CNN
F 1 "Q_TRIAC_A1A2G" H 1878 4355 50  0000 L CNN
F 2 "" V 1825 4425 50  0001 C CNN
F 3 "~" V 1750 4400 50  0001 C CNN
	1    1750 4400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5DBE1AE9
P 1750 4550
F 0 "#PWR?" H 1750 4300 50  0001 C CNN
F 1 "GND" H 1755 4377 50  0000 C CNN
F 2 "" H 1750 4550 50  0001 C CNN
F 3 "" H 1750 4550 50  0001 C CNN
	1    1750 4550
	1    0    0    -1  
$EndComp
Text HLabel 2500 4250 2    50   Output ~ 0
col_5_motor
Wire Wire Line
	2500 4250 1750 4250
$Comp
L Device:R R?
U 1 1 5DBE1AF1
P 1200 4500
F 0 "R?" V 1407 4500 50  0000 C CNN
F 1 "1 k" V 1316 4500 50  0000 C CNN
F 2 "" V 1130 4500 50  0001 C CNN
F 3 "~" H 1200 4500 50  0001 C CNN
	1    1200 4500
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1350 4500 1600 4500
Text HLabel 1050 4500 0    50   Input ~ 0
col_5_ctrl
$Comp
L Device:Q_TRIAC_A1A2G D?
U 1 1 5DBE2D93
P 1750 5050
F 0 "D?" H 1878 5096 50  0000 L CNN
F 1 "Q_TRIAC_A1A2G" H 1878 5005 50  0000 L CNN
F 2 "" V 1825 5075 50  0001 C CNN
F 3 "~" V 1750 5050 50  0001 C CNN
	1    1750 5050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5DBE2D99
P 1750 5200
F 0 "#PWR?" H 1750 4950 50  0001 C CNN
F 1 "GND" H 1755 5027 50  0000 C CNN
F 2 "" H 1750 5200 50  0001 C CNN
F 3 "" H 1750 5200 50  0001 C CNN
	1    1750 5200
	1    0    0    -1  
$EndComp
Text HLabel 2500 4900 2    50   Output ~ 0
col_7_motor
Wire Wire Line
	2500 4900 1750 4900
$Comp
L Device:R R?
U 1 1 5DBE2DA1
P 1200 5150
F 0 "R?" V 1407 5150 50  0000 C CNN
F 1 "1 k" V 1316 5150 50  0000 C CNN
F 2 "" V 1130 5150 50  0001 C CNN
F 3 "~" H 1200 5150 50  0001 C CNN
	1    1200 5150
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1350 5150 1600 5150
Text HLabel 1050 5150 0    50   Input ~ 0
col_7_ctrl
Wire Notes Line
	3050 2850 3050 5450
$Comp
L Device:Q_TRIAC_A1A2G D?
U 1 1 5DBEA91F
P 4350 3100
F 0 "D?" H 4478 3146 50  0000 L CNN
F 1 "Q_TRIAC_A1A2G" H 4478 3055 50  0000 L CNN
F 2 "" V 4425 3125 50  0001 C CNN
F 3 "~" V 4350 3100 50  0001 C CNN
	1    4350 3100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5DBEA925
P 4350 3250
F 0 "#PWR?" H 4350 3000 50  0001 C CNN
F 1 "GND" H 4355 3077 50  0000 C CNN
F 2 "" H 4350 3250 50  0001 C CNN
F 3 "" H 4350 3250 50  0001 C CNN
	1    4350 3250
	1    0    0    -1  
$EndComp
Text HLabel 5100 2950 2    50   Output ~ 0
col_2_motor
Wire Wire Line
	5100 2950 4350 2950
$Comp
L Device:R R?
U 1 1 5DBEA92D
P 3800 3200
F 0 "R?" V 4007 3200 50  0000 C CNN
F 1 "1 k" V 3916 3200 50  0000 C CNN
F 2 "" V 3730 3200 50  0001 C CNN
F 3 "~" H 3800 3200 50  0001 C CNN
	1    3800 3200
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3950 3200 4200 3200
Text HLabel 3650 3200 0    50   Input ~ 0
col_2_ctrl
$Comp
L Device:Q_TRIAC_A1A2G D?
U 1 1 5DBEA936
P 4350 3750
F 0 "D?" H 4478 3796 50  0000 L CNN
F 1 "Q_TRIAC_A1A2G" H 4478 3705 50  0000 L CNN
F 2 "" V 4425 3775 50  0001 C CNN
F 3 "~" V 4350 3750 50  0001 C CNN
	1    4350 3750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5DBEA93C
P 4350 3900
F 0 "#PWR?" H 4350 3650 50  0001 C CNN
F 1 "GND" H 4355 3727 50  0000 C CNN
F 2 "" H 4350 3900 50  0001 C CNN
F 3 "" H 4350 3900 50  0001 C CNN
	1    4350 3900
	1    0    0    -1  
$EndComp
Text HLabel 5100 3600 2    50   Output ~ 0
col_4_motor
Wire Wire Line
	5100 3600 4350 3600
$Comp
L Device:R R?
U 1 1 5DBEA944
P 3800 3850
F 0 "R?" V 4007 3850 50  0000 C CNN
F 1 "1 k" V 3916 3850 50  0000 C CNN
F 2 "" V 3730 3850 50  0001 C CNN
F 3 "~" H 3800 3850 50  0001 C CNN
	1    3800 3850
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3950 3850 4200 3850
Text HLabel 3650 3850 0    50   Input ~ 0
col_4_ctrl
$Comp
L Device:Q_TRIAC_A1A2G D?
U 1 1 5DBEA94D
P 4350 4400
F 0 "D?" H 4478 4446 50  0000 L CNN
F 1 "Q_TRIAC_A1A2G" H 4478 4355 50  0000 L CNN
F 2 "" V 4425 4425 50  0001 C CNN
F 3 "~" V 4350 4400 50  0001 C CNN
	1    4350 4400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5DBEA953
P 4350 4550
F 0 "#PWR?" H 4350 4300 50  0001 C CNN
F 1 "GND" H 4355 4377 50  0000 C CNN
F 2 "" H 4350 4550 50  0001 C CNN
F 3 "" H 4350 4550 50  0001 C CNN
	1    4350 4550
	1    0    0    -1  
$EndComp
Text HLabel 5100 4250 2    50   Output ~ 0
col_6_motor
Wire Wire Line
	5100 4250 4350 4250
$Comp
L Device:R R?
U 1 1 5DBEA95B
P 3800 4500
F 0 "R?" V 4007 4500 50  0000 C CNN
F 1 "1 k" V 3916 4500 50  0000 C CNN
F 2 "" V 3730 4500 50  0001 C CNN
F 3 "~" H 3800 4500 50  0001 C CNN
	1    3800 4500
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3950 4500 4200 4500
Text HLabel 3650 4500 0    50   Input ~ 0
col_6_motor
$Comp
L Device:Q_TRIAC_A1A2G D?
U 1 1 5DBEA964
P 4350 5050
F 0 "D?" H 4478 5096 50  0000 L CNN
F 1 "Q_TRIAC_A1A2G" H 4478 5005 50  0000 L CNN
F 2 "" V 4425 5075 50  0001 C CNN
F 3 "~" V 4350 5050 50  0001 C CNN
	1    4350 5050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5DBEA96A
P 4350 5200
F 0 "#PWR?" H 4350 4950 50  0001 C CNN
F 1 "GND" H 4355 5027 50  0000 C CNN
F 2 "" H 4350 5200 50  0001 C CNN
F 3 "" H 4350 5200 50  0001 C CNN
	1    4350 5200
	1    0    0    -1  
$EndComp
Text HLabel 5100 4900 2    50   Output ~ 0
col_8_motor
Wire Wire Line
	5100 4900 4350 4900
$Comp
L Device:R R?
U 1 1 5DBEA972
P 3800 5150
F 0 "R?" V 4007 5150 50  0000 C CNN
F 1 "1 k" V 3916 5150 50  0000 C CNN
F 2 "" V 3730 5150 50  0001 C CNN
F 3 "~" H 3800 5150 50  0001 C CNN
	1    3800 5150
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3950 5150 4200 5150
Text HLabel 3650 5150 0    50   Input ~ 0
col_8_ctrl
Wire Notes Line
	5650 2850 5650 5450
Wire Notes Line
	450  3500 5650 3500
Wire Notes Line
	450  4150 5650 4150
Wire Notes Line
	450  4800 5650 4800
Wire Notes Line
	450  5450 5650 5450
Text HLabel 4500 2050 2    50   Output ~ 0
MOTOR_CURRENT
Text HLabel 3200 1350 2    50   Output ~ 0
MOTOR_FAULT
$EndSCHEMATC
