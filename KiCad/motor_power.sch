EESchema Schematic File Version 4
LIBS:Snack Machine-cache
EELAYER 26 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 2 4
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
	1050 4450 1150 4450
$Comp
L Device:R R?
U 1 1 5BA8E124
P 1300 4950
AR Path="/5BA8E124" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BA8E124" Ref="R21"  Part="1" 
F 0 "R21" V 1093 4950 50  0000 C CNN
F 1 "1K" V 1184 4950 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 1230 4950 50  0001 C CNN
F 3 "~" H 1300 4950 50  0001 C CNN
	1    1300 4950
	0    1    1    0   
$EndComp
Wire Wire Line
	1450 4950 1450 4800
Wire Wire Line
	1650 4800 1450 4800
Connection ~ 1450 4800
Wire Wire Line
	1450 4800 1450 4650
Wire Wire Line
	1150 4950 1150 4450
Wire Wire Line
	1050 4250 1450 4250
Text HLabel 1050 4450 0    50   Input ~ 0
col_1_ctrl
Text Label 1650 4800 0    50   ~ 0
motor_common_gnd
Text Label 5000 6350 0    50   ~ 0
motor_common_gnd
$Comp
L Device:R R38
U 1 1 5BB1C4B9
P 5750 6850
F 0 "R38" H 5820 6896 50  0000 L CNN
F 1 "0.1R 1%" H 5820 6805 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 5680 6850 50  0001 C CNN
F 3 "~" H 5750 6850 50  0001 C CNN
	1    5750 6850
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 7000 5650 7000
Wire Wire Line
	5650 7000 5650 6900
Wire Wire Line
	5650 6900 5400 6900
Wire Wire Line
	5400 6800 5650 6800
Wire Wire Line
	5650 6800 5650 6700
Wire Wire Line
	5650 6700 5750 6700
Connection ~ 5750 6700
$Comp
L power:GND #PWR082
U 1 1 5BB27603
P 5750 7100
F 0 "#PWR082" H 5750 6850 50  0001 C CNN
F 1 "GND" H 5755 6927 50  0000 C CNN
F 2 "" H 5750 7100 50  0001 C CNN
F 3 "" H 5750 7100 50  0001 C CNN
	1    5750 7100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 7100 5750 7000
Connection ~ 5750 7000
Wire Wire Line
	5650 7000 5400 7000
Connection ~ 5650 7000
Text HLabel 4250 7100 0    50   Input ~ 0
SCL
Wire Wire Line
	4250 7100 4400 7100
Text HLabel 4250 7000 0    50   Input ~ 0
SDA
Wire Wire Line
	4250 7000 4400 7000
$Comp
L power:+24V #PWR?
U 1 1 5BCCBC60
P 1550 800
AR Path="/5BCCBC60" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BCCBC60" Ref="#PWR067"  Part="1" 
F 0 "#PWR067" H 1550 650 50  0001 C CNN
F 1 "+24V" H 1565 973 50  0000 C CNN
F 2 "" H 1550 800 50  0001 C CNN
F 3 "" H 1550 800 50  0001 C CNN
	1    1550 800 
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 800  1650 800 
$Comp
L Device:R R?
U 1 1 5BCD1BC4
P 1650 1000
AR Path="/5BCD1BC4" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BCD1BC4" Ref="R26"  Part="1" 
F 0 "R26" H 1720 1046 50  0000 L CNN
F 1 "1K" H 1720 955 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 1580 1000 50  0001 C CNN
F 3 "~" H 1650 1000 50  0001 C CNN
	1    1650 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	1650 850  1650 800 
Connection ~ 1650 800 
Wire Wire Line
	1650 800  1550 800 
Wire Wire Line
	1650 1150 1650 1250
Wire Wire Line
	1650 1250 1950 1250
Wire Wire Line
	1950 1250 1950 1100
$Comp
L Device:R R?
U 1 1 5BCEAFCA
P 1250 1450
AR Path="/5BCEAFCA" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BCEAFCA" Ref="R19"  Part="1" 
F 0 "R19" V 1350 1450 50  0000 C CNN
F 1 "R" V 1450 1450 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 1180 1450 50  0001 C CNN
F 3 "~" H 1250 1450 50  0001 C CNN
	1    1250 1450
	0    1    1    0   
$EndComp
Wire Wire Line
	1400 1450 1550 1450
$Comp
L Device:R R?
U 1 1 5BCEAFD2
P 1550 1700
AR Path="/5BCEAFD2" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BCEAFD2" Ref="R24"  Part="1" 
F 0 "R24" H 1700 1750 50  0000 C CNN
F 1 "1K" H 1650 1650 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 1480 1700 50  0001 C CNN
F 3 "~" H 1550 1700 50  0001 C CNN
	1    1550 1700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BCEAFDC
P 1950 2050
AR Path="/5BCEAFDC" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BCEAFDC" Ref="#PWR069"  Part="1" 
F 0 "#PWR069" H 1950 1800 50  0001 C CNN
F 1 "GND" H 1955 1877 50  0000 C CNN
F 2 "" H 1950 2050 50  0001 C CNN
F 3 "" H 1950 2050 50  0001 C CNN
	1    1950 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	1100 1450 950  1450
Text HLabel 950  1450 0    50   Input ~ 0
row_a_ctrl
Wire Wire Line
	1950 1650 1950 1950
Wire Wire Line
	1550 1450 1550 1550
Connection ~ 1550 1450
Wire Wire Line
	1550 1450 1650 1450
Wire Wire Line
	1550 1850 1550 1950
Wire Wire Line
	1550 1950 1950 1950
Connection ~ 1950 1950
Wire Wire Line
	1950 1950 1950 2050
$Comp
L Snack_Machine:INA219 U5
U 1 1 5BC6BBF3
P 4900 6950
F 0 "U5" H 4900 7365 50  0000 C CNN
F 1 "INA219" H 4900 7274 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:TSOT-23-8_HandSoldering" H 4900 6950 50  0001 C CNN
F 3 "" H 4900 6950 50  0001 C CNN
	1    4900 6950
	1    0    0    -1  
$EndComp
Text HLabel 2250 800  2    50   Input ~ 0
row_a_motor
Wire Wire Line
	2250 800  2150 800 
$Comp
L power:+24V #PWR?
U 1 1 5BC7E4FA
P 3900 800
AR Path="/5BC7E4FA" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BC7E4FA" Ref="#PWR076"  Part="1" 
F 0 "#PWR076" H 3900 650 50  0001 C CNN
F 1 "+24V" H 3915 973 50  0000 C CNN
F 2 "" H 3900 800 50  0001 C CNN
F 3 "" H 3900 800 50  0001 C CNN
	1    3900 800 
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 800  4000 800 
$Comp
L Device:R R?
U 1 1 5BC7E501
P 4000 1000
AR Path="/5BC7E501" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BC7E501" Ref="R36"  Part="1" 
F 0 "R36" H 4070 1046 50  0000 L CNN
F 1 "1K" H 4070 955 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 3930 1000 50  0001 C CNN
F 3 "~" H 4000 1000 50  0001 C CNN
	1    4000 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 850  4000 800 
Connection ~ 4000 800 
Wire Wire Line
	4000 800  3900 800 
Wire Wire Line
	4000 1150 4000 1250
Wire Wire Line
	4000 1250 4300 1250
Wire Wire Line
	4300 1250 4300 1100
$Comp
L Device:R R?
U 1 1 5BC7E515
P 3600 1450
AR Path="/5BC7E515" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BC7E515" Ref="R29"  Part="1" 
F 0 "R29" V 3700 1450 50  0000 C CNN
F 1 "R" V 3800 1450 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 3530 1450 50  0001 C CNN
F 3 "~" H 3600 1450 50  0001 C CNN
	1    3600 1450
	0    1    1    0   
$EndComp
Wire Wire Line
	3750 1450 3900 1450
$Comp
L Device:R R?
U 1 1 5BC7E51D
P 3900 1700
AR Path="/5BC7E51D" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BC7E51D" Ref="R34"  Part="1" 
F 0 "R34" H 4050 1750 50  0000 C CNN
F 1 "1K" H 4000 1650 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 3830 1700 50  0001 C CNN
F 3 "~" H 3900 1700 50  0001 C CNN
	1    3900 1700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BC7E524
P 4300 2050
AR Path="/5BC7E524" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BC7E524" Ref="#PWR078"  Part="1" 
F 0 "#PWR078" H 4300 1800 50  0001 C CNN
F 1 "GND" H 4305 1877 50  0000 C CNN
F 2 "" H 4300 2050 50  0001 C CNN
F 3 "" H 4300 2050 50  0001 C CNN
	1    4300 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 1450 3300 1450
Text HLabel 3300 1450 0    50   Input ~ 0
row_b_ctrl
Wire Wire Line
	4300 1650 4300 1950
Wire Wire Line
	3900 1450 3900 1550
Connection ~ 3900 1450
Wire Wire Line
	3900 1450 4000 1450
Wire Wire Line
	3900 1850 3900 1950
Wire Wire Line
	3900 1950 4300 1950
Connection ~ 4300 1950
Wire Wire Line
	4300 1950 4300 2050
Text HLabel 4600 800  2    50   Input ~ 0
row_b_motor
Wire Wire Line
	4600 800  4500 800 
$Comp
L power:+24V #PWR?
U 1 1 5BC81D07
P 6250 800
AR Path="/5BC81D07" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BC81D07" Ref="#PWR083"  Part="1" 
F 0 "#PWR083" H 6250 650 50  0001 C CNN
F 1 "+24V" H 6265 973 50  0000 C CNN
F 2 "" H 6250 800 50  0001 C CNN
F 3 "" H 6250 800 50  0001 C CNN
	1    6250 800 
	1    0    0    -1  
$EndComp
Wire Wire Line
	6450 800  6350 800 
$Comp
L Device:R R?
U 1 1 5BC81D0E
P 6350 1000
AR Path="/5BC81D0E" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BC81D0E" Ref="R45"  Part="1" 
F 0 "R45" H 6420 1046 50  0000 L CNN
F 1 "1K" H 6420 955 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 6280 1000 50  0001 C CNN
F 3 "~" H 6350 1000 50  0001 C CNN
	1    6350 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	6350 850  6350 800 
Connection ~ 6350 800 
Wire Wire Line
	6350 800  6250 800 
Wire Wire Line
	6350 1150 6350 1250
Wire Wire Line
	6350 1250 6650 1250
Wire Wire Line
	6650 1250 6650 1100
$Comp
L Device:R R?
U 1 1 5BC81D22
P 5950 1450
AR Path="/5BC81D22" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BC81D22" Ref="R39"  Part="1" 
F 0 "R39" V 6050 1450 50  0000 C CNN
F 1 "R" V 6150 1450 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 5880 1450 50  0001 C CNN
F 3 "~" H 5950 1450 50  0001 C CNN
	1    5950 1450
	0    1    1    0   
$EndComp
Wire Wire Line
	6100 1450 6250 1450
$Comp
L Device:R R?
U 1 1 5BC81D2A
P 6250 1700
AR Path="/5BC81D2A" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BC81D2A" Ref="R43"  Part="1" 
F 0 "R43" H 6400 1750 50  0000 C CNN
F 1 "1K" H 6350 1650 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 6180 1700 50  0001 C CNN
F 3 "~" H 6250 1700 50  0001 C CNN
	1    6250 1700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BC81D31
P 6650 2050
AR Path="/5BC81D31" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BC81D31" Ref="#PWR085"  Part="1" 
F 0 "#PWR085" H 6650 1800 50  0001 C CNN
F 1 "GND" H 6655 1877 50  0000 C CNN
F 2 "" H 6650 2050 50  0001 C CNN
F 3 "" H 6650 2050 50  0001 C CNN
	1    6650 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 1450 5650 1450
Text HLabel 5650 1450 0    50   Input ~ 0
row_c_ctrl
Wire Wire Line
	6650 1650 6650 1950
Wire Wire Line
	6250 1450 6250 1550
Connection ~ 6250 1450
Wire Wire Line
	6250 1450 6350 1450
Wire Wire Line
	6250 1850 6250 1950
Wire Wire Line
	6250 1950 6650 1950
Connection ~ 6650 1950
Wire Wire Line
	6650 1950 6650 2050
Text HLabel 6950 800  2    50   Input ~ 0
row_c_motor
Wire Wire Line
	6950 800  6850 800 
$Comp
L power:+24V #PWR?
U 1 1 5BC8690D
P 8600 800
AR Path="/5BC8690D" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BC8690D" Ref="#PWR087"  Part="1" 
F 0 "#PWR087" H 8600 650 50  0001 C CNN
F 1 "+24V" H 8615 973 50  0000 C CNN
F 2 "" H 8600 800 50  0001 C CNN
F 3 "" H 8600 800 50  0001 C CNN
	1    8600 800 
	1    0    0    -1  
$EndComp
Wire Wire Line
	8800 800  8700 800 
$Comp
L Device:R R?
U 1 1 5BC86914
P 8700 1000
AR Path="/5BC86914" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BC86914" Ref="R53"  Part="1" 
F 0 "R53" H 8770 1046 50  0000 L CNN
F 1 "1K" H 8770 955 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 8630 1000 50  0001 C CNN
F 3 "~" H 8700 1000 50  0001 C CNN
	1    8700 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	8700 850  8700 800 
Connection ~ 8700 800 
Wire Wire Line
	8700 800  8600 800 
Wire Wire Line
	8700 1150 8700 1250
Wire Wire Line
	8700 1250 9000 1250
Wire Wire Line
	9000 1250 9000 1100
$Comp
L Device:R R?
U 1 1 5BC86928
P 8300 1450
AR Path="/5BC86928" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BC86928" Ref="R47"  Part="1" 
F 0 "R47" V 8400 1450 50  0000 C CNN
F 1 "R" V 8500 1450 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 8230 1450 50  0001 C CNN
F 3 "~" H 8300 1450 50  0001 C CNN
	1    8300 1450
	0    1    1    0   
$EndComp
Wire Wire Line
	8450 1450 8600 1450
$Comp
L Device:R R?
U 1 1 5BC86930
P 8600 1700
AR Path="/5BC86930" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BC86930" Ref="R51"  Part="1" 
F 0 "R51" H 8750 1750 50  0000 C CNN
F 1 "1K" H 8700 1650 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 8530 1700 50  0001 C CNN
F 3 "~" H 8600 1700 50  0001 C CNN
	1    8600 1700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BC86937
P 9000 2050
AR Path="/5BC86937" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BC86937" Ref="#PWR089"  Part="1" 
F 0 "#PWR089" H 9000 1800 50  0001 C CNN
F 1 "GND" H 9005 1877 50  0000 C CNN
F 2 "" H 9000 2050 50  0001 C CNN
F 3 "" H 9000 2050 50  0001 C CNN
	1    9000 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	8150 1450 8000 1450
Text HLabel 8000 1450 0    50   Input ~ 0
row_d_ctrl
Wire Wire Line
	9000 1650 9000 1950
Wire Wire Line
	8600 1450 8600 1550
Connection ~ 8600 1450
Wire Wire Line
	8600 1450 8700 1450
Wire Wire Line
	8600 1850 8600 1950
Wire Wire Line
	8600 1950 9000 1950
Connection ~ 9000 1950
Wire Wire Line
	9000 1950 9000 2050
Text HLabel 9300 800  2    50   Input ~ 0
row_d_motor
Wire Wire Line
	9300 800  9200 800 
Wire Notes Line
	450  2300 9850 2300
$Comp
L Device:Q_PMOS_GSD Q?
U 1 1 5BC92720
P 1950 2750
AR Path="/5BC92720" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BC92720" Ref="Q7"  Part="1" 
F 0 "Q7" V 2300 2700 50  0000 L CNN
F 1 "P-CH 30V 3.8A" V 2200 2700 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:TSOT-23_HandSoldering" H 2150 2850 50  0001 C CNN
F 3 "~" H 1950 2750 50  0001 C CNN
F 4 "Diodes Incorporated" V 1950 2750 50  0001 C CNN "Manufacturer"
F 5 "DMP3099L-7" V 1950 2750 50  0001 C CNN "Part Number"
	1    1950 2750
	0    1    -1   0   
$EndComp
$Comp
L power:+24V #PWR?
U 1 1 5BC92727
P 1550 2650
AR Path="/5BC92727" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BC92727" Ref="#PWR068"  Part="1" 
F 0 "#PWR068" H 1550 2500 50  0001 C CNN
F 1 "+24V" H 1565 2823 50  0000 C CNN
F 2 "" H 1550 2650 50  0001 C CNN
F 3 "" H 1550 2650 50  0001 C CNN
	1    1550 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 2650 1650 2650
$Comp
L Device:R R?
U 1 1 5BC9272E
P 1650 2850
AR Path="/5BC9272E" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BC9272E" Ref="R27"  Part="1" 
F 0 "R27" H 1720 2896 50  0000 L CNN
F 1 "1K" H 1720 2805 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 1580 2850 50  0001 C CNN
F 3 "~" H 1650 2850 50  0001 C CNN
	1    1650 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	1650 2700 1650 2650
Connection ~ 1650 2650
Wire Wire Line
	1650 2650 1550 2650
Wire Wire Line
	1650 3000 1650 3100
Wire Wire Line
	1650 3100 1950 3100
Wire Wire Line
	1950 3100 1950 2950
$Comp
L Device:Q_NMOS_GSD Q?
U 1 1 5BC9273B
P 1850 3300
AR Path="/5BC9273B" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BC9273B" Ref="Q5"  Part="1" 
F 0 "Q5" H 2055 3346 50  0000 L CNN
F 1 "N-CH 50V 200mA" H 2055 3255 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:TSOT-23_HandSoldering" H 2050 3400 50  0001 C CNN
F 3 "~" H 1850 3300 50  0001 C CNN
F 4 "Rohm Semiconductor" H 1850 3300 50  0001 C CNN "Manufacturer"
F 5 "RUC002N05HZGT116" H 1850 3300 50  0001 C CNN "Part Number"
	1    1850 3300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5BC92742
P 1250 3300
AR Path="/5BC92742" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BC92742" Ref="R20"  Part="1" 
F 0 "R20" V 1350 3300 50  0000 C CNN
F 1 "R" V 1450 3300 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 1180 3300 50  0001 C CNN
F 3 "~" H 1250 3300 50  0001 C CNN
	1    1250 3300
	0    1    1    0   
$EndComp
Wire Wire Line
	1400 3300 1550 3300
$Comp
L Device:R R?
U 1 1 5BC9274A
P 1550 3550
AR Path="/5BC9274A" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BC9274A" Ref="R25"  Part="1" 
F 0 "R25" H 1700 3600 50  0000 C CNN
F 1 "1K" H 1650 3500 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 1480 3550 50  0001 C CNN
F 3 "~" H 1550 3550 50  0001 C CNN
	1    1550 3550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BC92751
P 1950 3900
AR Path="/5BC92751" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BC92751" Ref="#PWR070"  Part="1" 
F 0 "#PWR070" H 1950 3650 50  0001 C CNN
F 1 "GND" H 1955 3727 50  0000 C CNN
F 2 "" H 1950 3900 50  0001 C CNN
F 3 "" H 1950 3900 50  0001 C CNN
	1    1950 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	1100 3300 950  3300
Text HLabel 950  3300 0    50   Input ~ 0
row_e_ctrl
Connection ~ 1950 3100
Wire Wire Line
	1950 3500 1950 3800
Wire Wire Line
	1550 3300 1550 3400
Connection ~ 1550 3300
Wire Wire Line
	1550 3300 1650 3300
Wire Wire Line
	1550 3700 1550 3800
Wire Wire Line
	1550 3800 1950 3800
Connection ~ 1950 3800
Wire Wire Line
	1950 3800 1950 3900
Text HLabel 2250 2650 2    50   Input ~ 0
row_e_motor
Wire Wire Line
	2250 2650 2150 2650
$Comp
L power:+24V #PWR?
U 1 1 5BC9276C
P 3900 2650
AR Path="/5BC9276C" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BC9276C" Ref="#PWR077"  Part="1" 
F 0 "#PWR077" H 3900 2500 50  0001 C CNN
F 1 "+24V" H 3915 2823 50  0000 C CNN
F 2 "" H 3900 2650 50  0001 C CNN
F 3 "" H 3900 2650 50  0001 C CNN
	1    3900 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 2650 4000 2650
$Comp
L Device:R R?
U 1 1 5BC92773
P 4000 2850
AR Path="/5BC92773" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BC92773" Ref="R37"  Part="1" 
F 0 "R37" H 4070 2896 50  0000 L CNN
F 1 "1K" H 4070 2805 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 3930 2850 50  0001 C CNN
F 3 "~" H 4000 2850 50  0001 C CNN
	1    4000 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 2700 4000 2650
Connection ~ 4000 2650
Wire Wire Line
	4000 2650 3900 2650
Wire Wire Line
	4000 3000 4000 3100
Wire Wire Line
	4000 3100 4300 3100
Wire Wire Line
	4300 3100 4300 2950
$Comp
L Device:R R?
U 1 1 5BC92787
P 3600 3300
AR Path="/5BC92787" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BC92787" Ref="R30"  Part="1" 
F 0 "R30" V 3700 3300 50  0000 C CNN
F 1 "R" V 3800 3300 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 3530 3300 50  0001 C CNN
F 3 "~" H 3600 3300 50  0001 C CNN
	1    3600 3300
	0    1    1    0   
$EndComp
Wire Wire Line
	3750 3300 3900 3300
$Comp
L Device:R R?
U 1 1 5BC9278F
P 3900 3550
AR Path="/5BC9278F" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BC9278F" Ref="R35"  Part="1" 
F 0 "R35" H 4050 3600 50  0000 C CNN
F 1 "1K" H 4000 3500 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 3830 3550 50  0001 C CNN
F 3 "~" H 3900 3550 50  0001 C CNN
	1    3900 3550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BC92796
P 4300 3900
AR Path="/5BC92796" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BC92796" Ref="#PWR079"  Part="1" 
F 0 "#PWR079" H 4300 3650 50  0001 C CNN
F 1 "GND" H 4305 3727 50  0000 C CNN
F 2 "" H 4300 3900 50  0001 C CNN
F 3 "" H 4300 3900 50  0001 C CNN
	1    4300 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 3300 3300 3300
Text HLabel 3300 3300 0    50   Input ~ 0
row_f_ctrl
Wire Wire Line
	4300 3500 4300 3800
Wire Wire Line
	3900 3300 3900 3400
Connection ~ 3900 3300
Wire Wire Line
	3900 3300 4000 3300
Wire Wire Line
	3900 3700 3900 3800
Wire Wire Line
	3900 3800 4300 3800
Connection ~ 4300 3800
Wire Wire Line
	4300 3800 4300 3900
Text HLabel 4600 2650 2    50   Input ~ 0
row_f_motor
Wire Wire Line
	4600 2650 4500 2650
$Comp
L power:+24V #PWR?
U 1 1 5BC927B1
P 6250 2650
AR Path="/5BC927B1" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BC927B1" Ref="#PWR084"  Part="1" 
F 0 "#PWR084" H 6250 2500 50  0001 C CNN
F 1 "+24V" H 6265 2823 50  0000 C CNN
F 2 "" H 6250 2650 50  0001 C CNN
F 3 "" H 6250 2650 50  0001 C CNN
	1    6250 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	6450 2650 6350 2650
$Comp
L Device:R R?
U 1 1 5BC927B8
P 6350 2850
AR Path="/5BC927B8" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BC927B8" Ref="R46"  Part="1" 
F 0 "R46" H 6420 2896 50  0000 L CNN
F 1 "1K" H 6420 2805 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 6280 2850 50  0001 C CNN
F 3 "~" H 6350 2850 50  0001 C CNN
	1    6350 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	6350 2700 6350 2650
Connection ~ 6350 2650
Wire Wire Line
	6350 2650 6250 2650
Wire Wire Line
	6350 3000 6350 3100
Wire Wire Line
	6350 3100 6650 3100
Wire Wire Line
	6650 3100 6650 2950
$Comp
L Device:R R?
U 1 1 5BC927CC
P 5950 3300
AR Path="/5BC927CC" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BC927CC" Ref="R40"  Part="1" 
F 0 "R40" V 6050 3300 50  0000 C CNN
F 1 "R" V 6150 3300 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 5880 3300 50  0001 C CNN
F 3 "~" H 5950 3300 50  0001 C CNN
	1    5950 3300
	0    1    1    0   
$EndComp
Wire Wire Line
	6100 3300 6250 3300
$Comp
L Device:R R?
U 1 1 5BC927D4
P 6250 3550
AR Path="/5BC927D4" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BC927D4" Ref="R44"  Part="1" 
F 0 "R44" H 6400 3600 50  0000 C CNN
F 1 "1K" H 6350 3500 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 6180 3550 50  0001 C CNN
F 3 "~" H 6250 3550 50  0001 C CNN
	1    6250 3550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BC927DB
P 6650 3900
AR Path="/5BC927DB" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BC927DB" Ref="#PWR086"  Part="1" 
F 0 "#PWR086" H 6650 3650 50  0001 C CNN
F 1 "GND" H 6655 3727 50  0000 C CNN
F 2 "" H 6650 3900 50  0001 C CNN
F 3 "" H 6650 3900 50  0001 C CNN
	1    6650 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 3300 5650 3300
Text HLabel 5650 3300 0    50   Input ~ 0
row_g_ctrl
Wire Wire Line
	6650 3500 6650 3800
Wire Wire Line
	6250 3300 6250 3400
Connection ~ 6250 3300
Wire Wire Line
	6250 3300 6350 3300
Wire Wire Line
	6250 3700 6250 3800
Wire Wire Line
	6250 3800 6650 3800
Connection ~ 6650 3800
Wire Wire Line
	6650 3800 6650 3900
Text HLabel 6950 2650 2    50   Input ~ 0
row_g_motor
Wire Wire Line
	6950 2650 6850 2650
$Comp
L power:+24V #PWR?
U 1 1 5BC927F6
P 8600 2650
AR Path="/5BC927F6" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BC927F6" Ref="#PWR088"  Part="1" 
F 0 "#PWR088" H 8600 2500 50  0001 C CNN
F 1 "+24V" H 8615 2823 50  0000 C CNN
F 2 "" H 8600 2650 50  0001 C CNN
F 3 "" H 8600 2650 50  0001 C CNN
	1    8600 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	8800 2650 8700 2650
$Comp
L Device:R R?
U 1 1 5BC927FD
P 8700 2850
AR Path="/5BC927FD" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BC927FD" Ref="R54"  Part="1" 
F 0 "R54" H 8770 2896 50  0000 L CNN
F 1 "1K" H 8770 2805 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 8630 2850 50  0001 C CNN
F 3 "~" H 8700 2850 50  0001 C CNN
	1    8700 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	8700 2700 8700 2650
Connection ~ 8700 2650
Wire Wire Line
	8700 2650 8600 2650
Wire Wire Line
	8700 3000 8700 3100
Wire Wire Line
	8700 3100 9000 3100
Wire Wire Line
	9000 3100 9000 2950
$Comp
L Device:R R?
U 1 1 5BC92811
P 8300 3300
AR Path="/5BC92811" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BC92811" Ref="R48"  Part="1" 
F 0 "R48" V 8400 3300 50  0000 C CNN
F 1 "R" V 8500 3300 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 8230 3300 50  0001 C CNN
F 3 "~" H 8300 3300 50  0001 C CNN
	1    8300 3300
	0    1    1    0   
$EndComp
Wire Wire Line
	8450 3300 8600 3300
$Comp
L Device:R R?
U 1 1 5BC92819
P 8600 3550
AR Path="/5BC92819" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BC92819" Ref="R52"  Part="1" 
F 0 "R52" H 8750 3600 50  0000 C CNN
F 1 "1K" H 8700 3500 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 8530 3550 50  0001 C CNN
F 3 "~" H 8600 3550 50  0001 C CNN
	1    8600 3550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BC92820
P 9000 3900
AR Path="/5BC92820" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BC92820" Ref="#PWR090"  Part="1" 
F 0 "#PWR090" H 9000 3650 50  0001 C CNN
F 1 "GND" H 9005 3727 50  0000 C CNN
F 2 "" H 9000 3900 50  0001 C CNN
F 3 "" H 9000 3900 50  0001 C CNN
	1    9000 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	8150 3300 8000 3300
Text HLabel 8000 3300 0    50   Input ~ 0
row_h_ctrl
Wire Wire Line
	9000 3500 9000 3800
Wire Wire Line
	8600 3300 8600 3400
Connection ~ 8600 3300
Wire Wire Line
	8600 3300 8700 3300
Wire Wire Line
	8600 3700 8600 3800
Wire Wire Line
	8600 3800 9000 3800
Connection ~ 9000 3800
Wire Wire Line
	9000 3800 9000 3900
Text HLabel 9300 2650 2    50   Input ~ 0
row_h_motor
Wire Wire Line
	9300 2650 9200 2650
Wire Notes Line
	450  4150 9850 4150
Text HLabel 1050 4250 0    50   Input ~ 0
col_1_motor
Wire Wire Line
	3400 4450 3500 4450
$Comp
L Device:R R?
U 1 1 5BCA89FE
P 3650 4950
AR Path="/5BCA89FE" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BCA89FE" Ref="R31"  Part="1" 
F 0 "R31" V 3443 4950 50  0000 C CNN
F 1 "1K" V 3534 4950 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 3580 4950 50  0001 C CNN
F 3 "~" H 3650 4950 50  0001 C CNN
	1    3650 4950
	0    1    1    0   
$EndComp
Wire Wire Line
	3800 4950 3800 4800
Wire Wire Line
	4000 4800 3800 4800
Connection ~ 3800 4800
Wire Wire Line
	3800 4800 3800 4650
Wire Wire Line
	3500 4950 3500 4450
Wire Wire Line
	3400 4250 3800 4250
Text HLabel 3400 4450 0    50   Input ~ 0
col_2_ctrl
Text Label 4000 4800 0    50   ~ 0
motor_common_gnd
Text HLabel 3400 4250 0    50   Input ~ 0
col_2_motor
Wire Wire Line
	5750 4450 5850 4450
$Comp
L Device:R R?
U 1 1 5BCADB70
P 6000 4950
AR Path="/5BCADB70" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BCADB70" Ref="R41"  Part="1" 
F 0 "R41" V 5793 4950 50  0000 C CNN
F 1 "1K" V 5884 4950 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 5930 4950 50  0001 C CNN
F 3 "~" H 6000 4950 50  0001 C CNN
	1    6000 4950
	0    1    1    0   
$EndComp
Wire Wire Line
	6150 4950 6150 4800
Wire Wire Line
	6350 4800 6150 4800
Connection ~ 6150 4800
Wire Wire Line
	6150 4800 6150 4650
Wire Wire Line
	5850 4950 5850 4450
Wire Wire Line
	5750 4250 6150 4250
Text HLabel 5750 4450 0    50   Input ~ 0
col_3_ctrl
Text Label 6350 4800 0    50   ~ 0
motor_common_gnd
Text HLabel 5750 4250 0    50   Input ~ 0
col_3_motor
Wire Wire Line
	8100 4450 8200 4450
$Comp
L Device:R R?
U 1 1 5BCADB8A
P 8350 4950
AR Path="/5BCADB8A" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BCADB8A" Ref="R49"  Part="1" 
F 0 "R49" V 8143 4950 50  0000 C CNN
F 1 "1K" V 8234 4950 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 8280 4950 50  0001 C CNN
F 3 "~" H 8350 4950 50  0001 C CNN
	1    8350 4950
	0    1    1    0   
$EndComp
Wire Wire Line
	8500 4950 8500 4800
Wire Wire Line
	8700 4800 8500 4800
Connection ~ 8500 4800
Wire Wire Line
	8500 4800 8500 4650
Wire Wire Line
	8200 4950 8200 4450
Wire Wire Line
	8100 4250 8500 4250
Text HLabel 8100 4450 0    50   Input ~ 0
col_4_ctrl
Text Label 8700 4800 0    50   ~ 0
motor_common_gnd
Text HLabel 8100 4250 0    50   Input ~ 0
col_4_motor
Wire Notes Line
	450  5050 9850 5050
Wire Wire Line
	1050 5350 1150 5350
$Comp
L Device:R R?
U 1 1 5BCB38D9
P 1300 5850
AR Path="/5BCB38D9" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BCB38D9" Ref="R22"  Part="1" 
F 0 "R22" V 1093 5850 50  0000 C CNN
F 1 "1K" V 1184 5850 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 1230 5850 50  0001 C CNN
F 3 "~" H 1300 5850 50  0001 C CNN
	1    1300 5850
	0    1    1    0   
$EndComp
Wire Wire Line
	1450 5850 1450 5700
Wire Wire Line
	1650 5700 1450 5700
Connection ~ 1450 5700
Wire Wire Line
	1450 5700 1450 5550
Wire Wire Line
	1150 5850 1150 5350
Wire Wire Line
	1050 5150 1450 5150
Text HLabel 1050 5350 0    50   Input ~ 0
col_5_ctrl
Text Label 1650 5700 0    50   ~ 0
motor_common_gnd
Text HLabel 1050 5150 0    50   Input ~ 0
col_5_motor
Wire Wire Line
	3400 5350 3500 5350
$Comp
L Device:R R?
U 1 1 5BCB38F3
P 3650 5850
AR Path="/5BCB38F3" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BCB38F3" Ref="R32"  Part="1" 
F 0 "R32" V 3443 5850 50  0000 C CNN
F 1 "1K" V 3534 5850 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 3580 5850 50  0001 C CNN
F 3 "~" H 3650 5850 50  0001 C CNN
	1    3650 5850
	0    1    1    0   
$EndComp
Wire Wire Line
	3800 5850 3800 5700
Wire Wire Line
	4000 5700 3800 5700
Connection ~ 3800 5700
Wire Wire Line
	3800 5700 3800 5550
Wire Wire Line
	3500 5850 3500 5350
Wire Wire Line
	3400 5150 3800 5150
Text HLabel 3400 5350 0    50   Input ~ 0
col_6_ctrl
Text Label 4000 5700 0    50   ~ 0
motor_common_gnd
Text HLabel 3400 5150 0    50   Input ~ 0
col_6_motor
Wire Wire Line
	5750 5350 5850 5350
$Comp
L Device:R R?
U 1 1 5BCB390D
P 6000 5850
AR Path="/5BCB390D" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BCB390D" Ref="R42"  Part="1" 
F 0 "R42" V 5793 5850 50  0000 C CNN
F 1 "1K" V 5884 5850 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 5930 5850 50  0001 C CNN
F 3 "~" H 6000 5850 50  0001 C CNN
	1    6000 5850
	0    1    1    0   
$EndComp
Wire Wire Line
	6150 5850 6150 5700
Wire Wire Line
	6350 5700 6150 5700
Connection ~ 6150 5700
Wire Wire Line
	6150 5700 6150 5550
Wire Wire Line
	5850 5850 5850 5350
Wire Wire Line
	5750 5150 6150 5150
Text HLabel 5750 5350 0    50   Input ~ 0
col_7_ctrl
Text Label 6350 5700 0    50   ~ 0
motor_common_gnd
Text HLabel 5750 5150 0    50   Input ~ 0
col_7_motor
Wire Wire Line
	8100 5350 8200 5350
$Comp
L Device:R R?
U 1 1 5BCB3926
P 8350 5850
AR Path="/5BCB3926" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BCB3926" Ref="R50"  Part="1" 
F 0 "R50" V 8143 5850 50  0000 C CNN
F 1 "1K" V 8234 5850 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 8280 5850 50  0001 C CNN
F 3 "~" H 8350 5850 50  0001 C CNN
	1    8350 5850
	0    1    1    0   
$EndComp
Wire Wire Line
	8500 5850 8500 5700
Wire Wire Line
	8700 5700 8500 5700
Connection ~ 8500 5700
Wire Wire Line
	8500 5700 8500 5550
Wire Wire Line
	8200 5850 8200 5350
Wire Wire Line
	8100 5150 8500 5150
Text HLabel 8100 5350 0    50   Input ~ 0
col_8_ctrl
Text Label 8700 5700 0    50   ~ 0
motor_common_gnd
Text HLabel 8100 5150 0    50   Input ~ 0
col_8_motor
Wire Notes Line
	450  5950 9850 5950
Wire Notes Line
	2800 450  2800 5950
Wire Notes Line
	5150 450  5150 5950
Wire Notes Line
	7500 450  7500 5950
Wire Notes Line
	9850 450  9850 5950
Wire Notes Line
	10000 4150 10150 4150
Wire Notes Line
	10150 450  10000 450 
Text Notes 10500 3750 1    118  ~ 0
High Side\nMotor Driving
Wire Notes Line
	10150 5950 10000 5950
Wire Notes Line
	10150 450  10150 5950
Text Notes 10500 5850 1    118  ~ 0
Low Side\nMotor Driving
$Comp
L Device:R R33
U 1 1 5BCBF666
P 3800 7100
F 0 "R33" H 3870 7146 50  0000 L CNN
F 1 "10k" H 3870 7055 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 3730 7100 50  0001 C CNN
F 3 "~" H 3800 7100 50  0001 C CNN
	1    3800 7100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR075
U 1 1 5BCD27ED
P 3800 7300
F 0 "#PWR075" H 3800 7050 50  0001 C CNN
F 1 "GND" H 3805 7127 50  0000 C CNN
F 2 "" H 3800 7300 50  0001 C CNN
F 3 "" H 3800 7300 50  0001 C CNN
	1    3800 7300
	1    0    0    -1  
$EndComp
$Comp
L Device:C C22
U 1 1 5BCD303F
P 5550 7500
F 0 "C22" H 5665 7546 50  0000 L CNN
F 1 "0.1uF" H 5665 7455 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 5588 7350 50  0001 C CNN
F 3 "~" H 5550 7500 50  0001 C CNN
	1    5550 7500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR081
U 1 1 5BCEEBDE
P 5550 7650
F 0 "#PWR081" H 5550 7400 50  0001 C CNN
F 1 "GND" H 5555 7477 50  0000 C CNN
F 2 "" H 5550 7650 50  0001 C CNN
F 3 "" H 5550 7650 50  0001 C CNN
	1    5550 7650
	1    0    0    -1  
$EndComp
$Comp
L Snack_Machine:INA180B3 U4
U 1 1 5C27E419
P 2050 7050
F 0 "U4" H 2025 7375 50  0000 C CNN
F 1 "INA180B3" H 2025 7284 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-5_HandSoldering" H 1800 6950 50  0001 C CNN
F 3 "" H 1800 6950 50  0001 C CNN
	1    2050 7050
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR063
U 1 1 5C27F4F5
P 1100 6250
F 0 "#PWR063" H 1100 6100 50  0001 C CNN
F 1 "+5V" H 1115 6423 50  0000 C CNN
F 2 "" H 1100 6250 50  0001 C CNN
F 3 "" H 1100 6250 50  0001 C CNN
	1    1100 6250
	1    0    0    -1  
$EndComp
$Comp
L Device:C C21
U 1 1 5C27F640
P 1100 6450
F 0 "C21" H 1215 6496 50  0000 L CNN
F 1 "0.1uF" H 1215 6405 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 1138 6300 50  0001 C CNN
F 3 "~" H 1100 6450 50  0001 C CNN
	1    1100 6450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR064
U 1 1 5C291CA1
P 1100 6650
F 0 "#PWR064" H 1100 6400 50  0001 C CNN
F 1 "GND" H 1105 6477 50  0000 C CNN
F 2 "" H 1100 6650 50  0001 C CNN
F 3 "" H 1100 6650 50  0001 C CNN
	1    1100 6650
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR071
U 1 1 5C291D2E
P 2550 6850
F 0 "#PWR071" H 2550 6700 50  0001 C CNN
F 1 "+5V" H 2565 7023 50  0000 C CNN
F 2 "" H 2550 6850 50  0001 C CNN
F 3 "" H 2550 6850 50  0001 C CNN
	1    2550 6850
	1    0    0    -1  
$EndComp
Wire Wire Line
	2450 6950 2550 6950
Wire Wire Line
	2550 6950 2550 6850
Wire Wire Line
	1100 6250 1100 6300
Wire Wire Line
	1100 6600 1100 6650
Wire Wire Line
	5750 6700 5750 6350
Wire Wire Line
	5750 6350 4950 6350
$Comp
L Device:R R23
U 1 1 5C2D7083
P 1350 7350
F 0 "R23" H 1450 7300 50  0000 L CNN
F 1 "0.1R 1%" H 1450 7400 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 1280 7350 50  0001 C CNN
F 3 "~" H 1350 7350 50  0001 C CNN
	1    1350 7350
	-1   0    0    1   
$EndComp
Wire Wire Line
	2450 7150 2550 7150
Text Label 550  7150 0    50   ~ 0
motor_common_gnd
$Comp
L power:GND #PWR066
U 1 1 5C340246
P 1500 7750
F 0 "#PWR066" H 1500 7500 50  0001 C CNN
F 1 "GND" H 1505 7577 50  0000 C CNN
F 2 "" H 1500 7750 50  0001 C CNN
F 3 "" H 1500 7750 50  0001 C CNN
	1    1500 7750
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 7050 1500 7750
Text HLabel 1300 6950 0    50   Input ~ 0
MOTOR_CURRENT
Wire Wire Line
	1600 6950 1300 6950
Wire Wire Line
	550  7150 1350 7150
Wire Wire Line
	1600 7050 1500 7050
Wire Wire Line
	1350 7150 1350 7200
Connection ~ 1350 7150
Wire Wire Line
	1350 7150 1600 7150
Wire Wire Line
	1350 7500 1350 7550
$Comp
L power:GND #PWR065
U 1 1 5C3C541B
P 1350 7750
F 0 "#PWR065" H 1350 7500 50  0001 C CNN
F 1 "GND" H 1355 7577 50  0000 C CNN
F 2 "" H 1350 7750 50  0001 C CNN
F 3 "" H 1350 7750 50  0001 C CNN
	1    1350 7750
	1    0    0    -1  
$EndComp
Wire Wire Line
	1350 7550 2550 7550
Wire Wire Line
	2550 7150 2550 7550
Connection ~ 1350 7550
Wire Wire Line
	1350 7550 1350 7750
$Comp
L power:+5V #PWR080
U 1 1 5C4150EA
P 5550 7300
F 0 "#PWR080" H 5550 7150 50  0001 C CNN
F 1 "+5V" H 5565 7473 50  0000 C CNN
F 2 "" H 5550 7300 50  0001 C CNN
F 3 "" H 5550 7300 50  0001 C CNN
	1    5550 7300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5550 7350 5550 7300
Wire Wire Line
	5400 7100 5450 7100
Wire Wire Line
	5450 7100 5450 7350
Wire Wire Line
	5450 7350 5550 7350
Connection ~ 5550 7350
$Comp
L power:+5V #PWR074
U 1 1 5C4433AA
P 3800 6350
F 0 "#PWR074" H 3800 6200 50  0001 C CNN
F 1 "+5V" H 3750 6500 50  0000 L CNN
F 2 "" H 3800 6350 50  0001 C CNN
F 3 "" H 3800 6350 50  0001 C CNN
	1    3800 6350
	1    0    0    -1  
$EndComp
$Comp
L Jumper:SolderJumper_2_Open JP2
U 1 1 5C4436DC
P 3800 6550
F 0 "JP2" V 3750 6700 50  0000 C CNN
F 1 "SolderJumper_2_Open" V 3850 7050 50  0000 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_TrianglePad1.0x1.5mm" H 3800 6550 50  0001 C CNN
F 3 "~" H 3800 6550 50  0001 C CNN
	1    3800 6550
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR072
U 1 1 5C443BBD
P 3500 6350
F 0 "#PWR072" H 3500 6200 50  0001 C CNN
F 1 "+5V" H 3450 6500 50  0000 L CNN
F 2 "" H 3500 6350 50  0001 C CNN
F 3 "" H 3500 6350 50  0001 C CNN
	1    3500 6350
	1    0    0    -1  
$EndComp
$Comp
L Jumper:SolderJumper_2_Open JP1
U 1 1 5C443BC3
P 3500 6550
F 0 "JP1" V 3400 6400 50  0000 C CNN
F 1 "SolderJumper_2_Open" V 3500 6100 50  0000 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_TrianglePad1.0x1.5mm" H 3500 6550 50  0001 C CNN
F 3 "~" H 3500 6550 50  0001 C CNN
	1    3500 6550
	0    1    1    0   
$EndComp
$Comp
L Device:R R28
U 1 1 5C466872
P 3500 7100
F 0 "R28" H 3570 7146 50  0000 L CNN
F 1 "10k" H 3570 7055 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 3430 7100 50  0001 C CNN
F 3 "~" H 3500 7100 50  0001 C CNN
	1    3500 7100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR073
U 1 1 5C46696D
P 3500 7300
F 0 "#PWR073" H 3500 7050 50  0001 C CNN
F 1 "GND" H 3505 7127 50  0000 C CNN
F 2 "" H 3500 7300 50  0001 C CNN
F 3 "" H 3500 7300 50  0001 C CNN
	1    3500 7300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3800 6900 4400 6900
Wire Wire Line
	3800 6900 3800 6950
Wire Wire Line
	3500 6800 3500 6950
Wire Wire Line
	3500 6800 4400 6800
Wire Wire Line
	3800 6900 3800 6700
Connection ~ 3800 6900
Wire Wire Line
	3500 6700 3500 6800
Connection ~ 3500 6800
Wire Wire Line
	3500 7250 3500 7300
Wire Wire Line
	3800 7250 3800 7300
Wire Wire Line
	3500 6350 3500 6400
Wire Wire Line
	3800 6350 3800 6400
$Comp
L Device:Q_NMOS_GSD Q2
U 1 1 5C0128D5
P 1350 4450
F 0 "Q2" H 1555 4496 50  0000 L CNN
F 1 "Q_NMOS_SGD" H 1555 4405 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:TSOT-23_HandSoldering" H 1550 4550 50  0001 C CNN
F 3 "~" H 1350 4450 50  0001 C CNN
F 4 "ON Semiconductor" H 1350 4450 50  0001 C CNN "Manufacturer"
F 5 "NTR4003NT1G" H 1350 4450 50  0001 C CNN "Part Number"
	1    1350 4450
	1    0    0    -1  
$EndComp
Connection ~ 1150 4450
$Comp
L Device:Q_PMOS_GSD Q?
U 1 1 5C02569C
P 1950 900
AR Path="/5C02569C" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5C02569C" Ref="Q6"  Part="1" 
F 0 "Q6" V 2300 850 50  0000 L CNN
F 1 "P-CH 30V 3.8A" V 2200 850 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:TSOT-23_HandSoldering" H 2150 1000 50  0001 C CNN
F 3 "~" H 1950 900 50  0001 C CNN
F 4 "Diodes Incorporated" V 1950 900 50  0001 C CNN "Manufacturer"
F 5 "DMP3099L-7" V 1950 900 50  0001 C CNN "Part Number"
	1    1950 900 
	0    1    -1   0   
$EndComp
$Comp
L Device:Q_PMOS_GSD Q?
U 1 1 5C0257CD
P 4300 900
AR Path="/5C0257CD" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5C0257CD" Ref="Q12"  Part="1" 
F 0 "Q12" V 4650 850 50  0000 L CNN
F 1 "P-CH 30V 3.8A" V 4550 850 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:TSOT-23_HandSoldering" H 4500 1000 50  0001 C CNN
F 3 "~" H 4300 900 50  0001 C CNN
F 4 "Diodes Incorporated" V 4300 900 50  0001 C CNN "Manufacturer"
F 5 "DMP3099L-7" V 4300 900 50  0001 C CNN "Part Number"
	1    4300 900 
	0    1    -1   0   
$EndComp
$Comp
L Device:Q_PMOS_GSD Q?
U 1 1 5C031359
P 6650 900
AR Path="/5C031359" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5C031359" Ref="Q18"  Part="1" 
F 0 "Q18" V 7000 850 50  0000 L CNN
F 1 "P-CH 30V 3.8A" V 6900 850 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:TSOT-23_HandSoldering" H 6850 1000 50  0001 C CNN
F 3 "~" H 6650 900 50  0001 C CNN
F 4 "Diodes Incorporated" V 6650 900 50  0001 C CNN "Manufacturer"
F 5 "DMP3099L-7" V 6650 900 50  0001 C CNN "Part Number"
	1    6650 900 
	0    1    -1   0   
$EndComp
$Comp
L Device:Q_PMOS_GSD Q?
U 1 1 5C03CEE4
P 9000 900
AR Path="/5C03CEE4" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5C03CEE4" Ref="Q24"  Part="1" 
F 0 "Q24" V 9350 850 50  0000 L CNN
F 1 "P-CH 30V 3.8A" V 9250 850 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:TSOT-23_HandSoldering" H 9200 1000 50  0001 C CNN
F 3 "~" H 9000 900 50  0001 C CNN
F 4 "Diodes Incorporated" V 9000 900 50  0001 C CNN "Manufacturer"
F 5 "DMP3099L-7" V 9000 900 50  0001 C CNN "Part Number"
	1    9000 900 
	0    1    -1   0   
$EndComp
$Comp
L Device:Q_PMOS_GSD Q?
U 1 1 5C048A6C
P 4300 2750
AR Path="/5C048A6C" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5C048A6C" Ref="Q13"  Part="1" 
F 0 "Q13" V 4650 2700 50  0000 L CNN
F 1 "P-CH 30V 3.8A" V 4550 2700 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:TSOT-23_HandSoldering" H 4500 2850 50  0001 C CNN
F 3 "~" H 4300 2750 50  0001 C CNN
F 4 "Diodes Incorporated" V 4300 2750 50  0001 C CNN "Manufacturer"
F 5 "DMP3099L-7" V 4300 2750 50  0001 C CNN "Part Number"
	1    4300 2750
	0    1    -1   0   
$EndComp
$Comp
L Device:Q_PMOS_GSD Q?
U 1 1 5C0545EF
P 6650 2750
AR Path="/5C0545EF" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5C0545EF" Ref="Q19"  Part="1" 
F 0 "Q19" V 7000 2700 50  0000 L CNN
F 1 "P-CH 30V 3.8A" V 6900 2700 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:TSOT-23_HandSoldering" H 6850 2850 50  0001 C CNN
F 3 "~" H 6650 2750 50  0001 C CNN
F 4 "Diodes Incorporated" V 6650 2750 50  0001 C CNN "Manufacturer"
F 5 "DMP3099L-7" V 6650 2750 50  0001 C CNN "Part Number"
	1    6650 2750
	0    1    -1   0   
$EndComp
$Comp
L Device:Q_PMOS_GSD Q?
U 1 1 5C06017B
P 9000 2750
AR Path="/5C06017B" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5C06017B" Ref="Q25"  Part="1" 
F 0 "Q25" V 9350 2700 50  0000 L CNN
F 1 "P-CH 30V 3.8A" V 9250 2700 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:TSOT-23_HandSoldering" H 9200 2850 50  0001 C CNN
F 3 "~" H 9000 2750 50  0001 C CNN
F 4 "Diodes Incorporated" V 9000 2750 50  0001 C CNN "Manufacturer"
F 5 "DMP3099L-7" V 9000 2750 50  0001 C CNN "Part Number"
	1    9000 2750
	0    1    -1   0   
$EndComp
$Comp
L Device:Q_NMOS_GSD Q?
U 1 1 5C06BD83
P 1850 1450
AR Path="/5C06BD83" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5C06BD83" Ref="Q4"  Part="1" 
F 0 "Q4" H 2055 1496 50  0000 L CNN
F 1 "N-CH 50V 200mA" H 2055 1405 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:TSOT-23_HandSoldering" H 2050 1550 50  0001 C CNN
F 3 "~" H 1850 1450 50  0001 C CNN
F 4 "Rohm Semiconductor" H 1850 1450 50  0001 C CNN "Manufacturer"
F 5 "RUC002N05HZGT116" H 1850 1450 50  0001 C CNN "Part Number"
	1    1850 1450
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_NMOS_GSD Q?
U 1 1 5C077903
P 4200 1450
AR Path="/5C077903" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5C077903" Ref="Q10"  Part="1" 
F 0 "Q10" H 4405 1496 50  0000 L CNN
F 1 "N-CH 50V 200mA" H 4405 1405 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:TSOT-23_HandSoldering" H 4400 1550 50  0001 C CNN
F 3 "~" H 4200 1450 50  0001 C CNN
F 4 "Rohm Semiconductor" H 4200 1450 50  0001 C CNN "Manufacturer"
F 5 "RUC002N05HZGT116" H 4200 1450 50  0001 C CNN "Part Number"
	1    4200 1450
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_NMOS_GSD Q?
U 1 1 5C083490
P 6550 1450
AR Path="/5C083490" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5C083490" Ref="Q16"  Part="1" 
F 0 "Q16" H 6755 1496 50  0000 L CNN
F 1 "N-CH 50V 200mA" H 6755 1405 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:TSOT-23_HandSoldering" H 6750 1550 50  0001 C CNN
F 3 "~" H 6550 1450 50  0001 C CNN
F 4 "Rohm Semiconductor" H 6550 1450 50  0001 C CNN "Manufacturer"
F 5 "RUC002N05HZGT116" H 6550 1450 50  0001 C CNN "Part Number"
	1    6550 1450
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_NMOS_GSD Q?
U 1 1 5C08F030
P 8900 1450
AR Path="/5C08F030" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5C08F030" Ref="Q22"  Part="1" 
F 0 "Q22" H 9105 1496 50  0000 L CNN
F 1 "N-CH 50V 200mA" H 9105 1405 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:TSOT-23_HandSoldering" H 9100 1550 50  0001 C CNN
F 3 "~" H 8900 1450 50  0001 C CNN
F 4 "Rohm Semiconductor" H 8900 1450 50  0001 C CNN "Manufacturer"
F 5 "RUC002N05HZGT116" H 8900 1450 50  0001 C CNN "Part Number"
	1    8900 1450
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_NMOS_GSD Q?
U 1 1 5C09ABCB
P 8900 3300
AR Path="/5C09ABCB" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5C09ABCB" Ref="Q23"  Part="1" 
F 0 "Q23" H 9105 3346 50  0000 L CNN
F 1 "N-CH 50V 200mA" H 9105 3255 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:TSOT-23_HandSoldering" H 9100 3400 50  0001 C CNN
F 3 "~" H 8900 3300 50  0001 C CNN
F 4 "Rohm Semiconductor" H 8900 3300 50  0001 C CNN "Manufacturer"
F 5 "RUC002N05HZGT116" H 8900 3300 50  0001 C CNN "Part Number"
	1    8900 3300
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_NMOS_GSD Q?
U 1 1 5C0A677F
P 6550 3300
AR Path="/5C0A677F" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5C0A677F" Ref="Q17"  Part="1" 
F 0 "Q17" H 6755 3346 50  0000 L CNN
F 1 "N-CH 50V 200mA" H 6755 3255 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:TSOT-23_HandSoldering" H 6750 3400 50  0001 C CNN
F 3 "~" H 6550 3300 50  0001 C CNN
F 4 "Rohm Semiconductor" H 6550 3300 50  0001 C CNN "Manufacturer"
F 5 "RUC002N05HZGT116" H 6550 3300 50  0001 C CNN "Part Number"
	1    6550 3300
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_NMOS_GSD Q?
U 1 1 5C0B230E
P 4200 3300
AR Path="/5C0B230E" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5C0B230E" Ref="Q11"  Part="1" 
F 0 "Q11" H 4405 3346 50  0000 L CNN
F 1 "N-CH 50V 200mA" H 4405 3255 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:TSOT-23_HandSoldering" H 4400 3400 50  0001 C CNN
F 3 "~" H 4200 3300 50  0001 C CNN
F 4 "Rohm Semiconductor" H 4200 3300 50  0001 C CNN "Manufacturer"
F 5 "RUC002N05HZGT116" H 4200 3300 50  0001 C CNN "Part Number"
	1    4200 3300
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_NMOS_GSD Q3
U 1 1 5C0BE13A
P 1350 5350
F 0 "Q3" H 1555 5396 50  0000 L CNN
F 1 "Q_NMOS_SGD" H 1555 5305 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:TSOT-23_HandSoldering" H 1550 5450 50  0001 C CNN
F 3 "~" H 1350 5350 50  0001 C CNN
F 4 "ON Semiconductor" H 1350 5350 50  0001 C CNN "Manufacturer"
F 5 "NTR4003NT1G" H 1350 5350 50  0001 C CNN "Part Number"
	1    1350 5350
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_NMOS_GSD Q8
U 1 1 5C0C9CCB
P 3700 4450
F 0 "Q8" H 3905 4496 50  0000 L CNN
F 1 "Q_NMOS_SGD" H 3905 4405 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:TSOT-23_HandSoldering" H 3900 4550 50  0001 C CNN
F 3 "~" H 3700 4450 50  0001 C CNN
F 4 "ON Semiconductor" H 3700 4450 50  0001 C CNN "Manufacturer"
F 5 "NTR4003NT1G" H 3700 4450 50  0001 C CNN "Part Number"
	1    3700 4450
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_NMOS_GSD Q14
U 1 1 5C0D5861
P 6050 4450
F 0 "Q14" H 6255 4496 50  0000 L CNN
F 1 "Q_NMOS_SGD" H 6255 4405 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:TSOT-23_HandSoldering" H 6250 4550 50  0001 C CNN
F 3 "~" H 6050 4450 50  0001 C CNN
F 4 "ON Semiconductor" H 6050 4450 50  0001 C CNN "Manufacturer"
F 5 "NTR4003NT1G" H 6050 4450 50  0001 C CNN "Part Number"
	1    6050 4450
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_NMOS_GSD Q20
U 1 1 5C0E13FC
P 8400 4450
F 0 "Q20" H 8605 4496 50  0000 L CNN
F 1 "Q_NMOS_SGD" H 8605 4405 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:TSOT-23_HandSoldering" H 8600 4550 50  0001 C CNN
F 3 "~" H 8400 4450 50  0001 C CNN
F 4 "ON Semiconductor" H 8400 4450 50  0001 C CNN "Manufacturer"
F 5 "NTR4003NT1G" H 8400 4450 50  0001 C CNN "Part Number"
	1    8400 4450
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_NMOS_GSD Q21
U 1 1 5C0ECF9A
P 8400 5350
F 0 "Q21" H 8605 5396 50  0000 L CNN
F 1 "Q_NMOS_SGD" H 8605 5305 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:TSOT-23_HandSoldering" H 8600 5450 50  0001 C CNN
F 3 "~" H 8400 5350 50  0001 C CNN
F 4 "ON Semiconductor" H 8400 5350 50  0001 C CNN "Manufacturer"
F 5 "NTR4003NT1G" H 8400 5350 50  0001 C CNN "Part Number"
	1    8400 5350
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_NMOS_GSD Q15
U 1 1 5C0F8B3D
P 6050 5350
F 0 "Q15" H 6255 5396 50  0000 L CNN
F 1 "Q_NMOS_SGD" H 6255 5305 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:TSOT-23_HandSoldering" H 6250 5450 50  0001 C CNN
F 3 "~" H 6050 5350 50  0001 C CNN
F 4 "ON Semiconductor" H 6050 5350 50  0001 C CNN "Manufacturer"
F 5 "NTR4003NT1G" H 6050 5350 50  0001 C CNN "Part Number"
	1    6050 5350
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_NMOS_GSD Q9
U 1 1 5C1046DF
P 3700 5350
F 0 "Q9" H 3905 5396 50  0000 L CNN
F 1 "Q_NMOS_SGD" H 3905 5305 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:TSOT-23_HandSoldering" H 3900 5450 50  0001 C CNN
F 3 "~" H 3700 5350 50  0001 C CNN
F 4 "ON Semiconductor" H 3700 5350 50  0001 C CNN "Manufacturer"
F 5 "NTR4003NT1G" H 3700 5350 50  0001 C CNN "Part Number"
	1    3700 5350
	1    0    0    -1  
$EndComp
$EndSCHEMATC
