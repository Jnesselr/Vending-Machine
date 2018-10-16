EESchema Schematic File Version 4
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 2
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
L Device:Q_NMOS_DGS Q?
U 1 1 5BA767F7
P 1900 1450
AR Path="/5BA767F7" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BA767F7" Ref="Q?"  Part="1" 
F 0 "Q?" H 2105 1496 50  0000 L CNN
F 1 "Q_NMOS_DGS" H 2105 1405 50  0000 L CNN
F 2 "" H 2100 1550 50  0001 C CNN
F 3 "~" H 1900 1450 50  0001 C CNN
	1    1900 1450
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5BA767FE
P 1400 1450
AR Path="/5BA767FE" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BA767FE" Ref="R?"  Part="1" 
F 0 "R?" V 1193 1450 50  0000 C CNN
F 1 "R" V 1284 1450 50  0000 C CNN
F 2 "" V 1330 1450 50  0001 C CNN
F 3 "~" H 1400 1450 50  0001 C CNN
	1    1400 1450
	0    1    1    0   
$EndComp
Wire Wire Line
	1550 1450 1700 1450
$Comp
L Device:R R?
U 1 1 5BA76806
P 2150 900
AR Path="/5BA76806" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BA76806" Ref="R?"  Part="1" 
F 0 "R?" H 2220 946 50  0000 L CNN
F 1 "1K" H 2220 855 50  0000 L CNN
F 2 "" V 2080 900 50  0001 C CNN
F 3 "~" H 2150 900 50  0001 C CNN
	1    2150 900 
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5BA7680D
P 1850 1900
AR Path="/5BA7680D" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BA7680D" Ref="R?"  Part="1" 
F 0 "R?" V 2057 1900 50  0000 C CNN
F 1 "1K" V 1966 1900 50  0000 C CNN
F 2 "" V 1780 1900 50  0001 C CNN
F 3 "~" H 1850 1900 50  0001 C CNN
	1    1850 1900
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1700 1900 1700 1450
Connection ~ 1700 1450
Wire Wire Line
	2000 1650 2000 1750
$Comp
L power:GND #PWR?
U 1 1 5BA76817
P 2200 1750
AR Path="/5BA76817" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BA76817" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 2200 1500 50  0001 C CNN
F 1 "GND" H 2205 1577 50  0000 C CNN
F 2 "" H 2200 1750 50  0001 C CNN
F 3 "" H 2200 1750 50  0001 C CNN
	1    2200 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 1750 2000 1750
Connection ~ 2000 1750
Wire Wire Line
	2000 1750 2000 1900
$Comp
L power:+24V #PWR?
U 1 1 5BA76820
P 2000 750
AR Path="/5BA76820" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BA76820" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 2000 600 50  0001 C CNN
F 1 "+24V" H 2015 923 50  0000 C CNN
F 2 "" H 2000 750 50  0001 C CNN
F 3 "" H 2000 750 50  0001 C CNN
	1    2000 750 
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_PMOS_DGS Q?
U 1 1 5BA76826
P 1800 950
AR Path="/5BA76826" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BA76826" Ref="Q?"  Part="1" 
F 0 "Q?" H 2006 904 50  0000 L CNN
F 1 "Q_PMOS_DGS" H 2006 995 50  0000 L CNN
F 2 "" H 2000 1050 50  0001 C CNN
F 3 "~" H 1800 950 50  0001 C CNN
	1    1800 950 
	-1   0    0    1   
$EndComp
Wire Wire Line
	1700 750  2000 750 
Wire Wire Line
	1700 1150 1200 1150
Wire Wire Line
	1250 1450 1200 1450
$Comp
L Device:Q_NMOS_DGS Q?
U 1 1 5BA76835
P 4100 1450
AR Path="/5BA76835" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BA76835" Ref="Q?"  Part="1" 
F 0 "Q?" H 4305 1496 50  0000 L CNN
F 1 "Q_NMOS_DGS" H 4305 1405 50  0000 L CNN
F 2 "" H 4300 1550 50  0001 C CNN
F 3 "~" H 4100 1450 50  0001 C CNN
	1    4100 1450
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5BA7683C
P 3600 1450
AR Path="/5BA7683C" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BA7683C" Ref="R?"  Part="1" 
F 0 "R?" V 3393 1450 50  0000 C CNN
F 1 "R" V 3484 1450 50  0000 C CNN
F 2 "" V 3530 1450 50  0001 C CNN
F 3 "~" H 3600 1450 50  0001 C CNN
	1    3600 1450
	0    1    1    0   
$EndComp
Wire Wire Line
	3750 1450 3900 1450
$Comp
L Device:R R?
U 1 1 5BA76844
P 4350 900
AR Path="/5BA76844" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BA76844" Ref="R?"  Part="1" 
F 0 "R?" H 4420 946 50  0000 L CNN
F 1 "1K" H 4420 855 50  0000 L CNN
F 2 "" V 4280 900 50  0001 C CNN
F 3 "~" H 4350 900 50  0001 C CNN
	1    4350 900 
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5BA7684B
P 4050 1900
AR Path="/5BA7684B" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BA7684B" Ref="R?"  Part="1" 
F 0 "R?" V 4257 1900 50  0000 C CNN
F 1 "1K" V 4166 1900 50  0000 C CNN
F 2 "" V 3980 1900 50  0001 C CNN
F 3 "~" H 4050 1900 50  0001 C CNN
	1    4050 1900
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3900 1900 3900 1450
Connection ~ 3900 1450
Wire Wire Line
	4200 1650 4200 1750
$Comp
L power:GND #PWR?
U 1 1 5BA76855
P 4400 1750
AR Path="/5BA76855" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BA76855" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 4400 1500 50  0001 C CNN
F 1 "GND" H 4405 1577 50  0000 C CNN
F 2 "" H 4400 1750 50  0001 C CNN
F 3 "" H 4400 1750 50  0001 C CNN
	1    4400 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 1750 4200 1750
Connection ~ 4200 1750
Wire Wire Line
	4200 1750 4200 1900
$Comp
L power:+24V #PWR?
U 1 1 5BA7685E
P 4200 750
AR Path="/5BA7685E" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BA7685E" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 4200 600 50  0001 C CNN
F 1 "+24V" H 4215 923 50  0000 C CNN
F 2 "" H 4200 750 50  0001 C CNN
F 3 "" H 4200 750 50  0001 C CNN
	1    4200 750 
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_PMOS_DGS Q?
U 1 1 5BA76864
P 4000 950
AR Path="/5BA76864" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BA76864" Ref="Q?"  Part="1" 
F 0 "Q?" H 4206 904 50  0000 L CNN
F 1 "Q_PMOS_DGS" H 4206 995 50  0000 L CNN
F 2 "" H 4200 1050 50  0001 C CNN
F 3 "~" H 4000 950 50  0001 C CNN
	1    4000 950 
	-1   0    0    1   
$EndComp
Wire Wire Line
	3900 750  4200 750 
Wire Wire Line
	3900 1150 3400 1150
Wire Wire Line
	3450 1450 3400 1450
$Comp
L Device:Q_NMOS_DGS Q?
U 1 1 5BA76873
P 6250 1450
AR Path="/5BA76873" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BA76873" Ref="Q?"  Part="1" 
F 0 "Q?" H 6455 1496 50  0000 L CNN
F 1 "Q_NMOS_DGS" H 6455 1405 50  0000 L CNN
F 2 "" H 6450 1550 50  0001 C CNN
F 3 "~" H 6250 1450 50  0001 C CNN
	1    6250 1450
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5BA7687A
P 5750 1450
AR Path="/5BA7687A" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BA7687A" Ref="R?"  Part="1" 
F 0 "R?" V 5543 1450 50  0000 C CNN
F 1 "R" V 5634 1450 50  0000 C CNN
F 2 "" V 5680 1450 50  0001 C CNN
F 3 "~" H 5750 1450 50  0001 C CNN
	1    5750 1450
	0    1    1    0   
$EndComp
Wire Wire Line
	5900 1450 6050 1450
$Comp
L Device:R R?
U 1 1 5BA76882
P 6500 900
AR Path="/5BA76882" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BA76882" Ref="R?"  Part="1" 
F 0 "R?" H 6570 946 50  0000 L CNN
F 1 "1K" H 6570 855 50  0000 L CNN
F 2 "" V 6430 900 50  0001 C CNN
F 3 "~" H 6500 900 50  0001 C CNN
	1    6500 900 
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5BA76889
P 6200 1900
AR Path="/5BA76889" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BA76889" Ref="R?"  Part="1" 
F 0 "R?" V 6407 1900 50  0000 C CNN
F 1 "1K" V 6316 1900 50  0000 C CNN
F 2 "" V 6130 1900 50  0001 C CNN
F 3 "~" H 6200 1900 50  0001 C CNN
	1    6200 1900
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6050 1900 6050 1450
Connection ~ 6050 1450
Wire Wire Line
	6350 1650 6350 1750
$Comp
L power:GND #PWR?
U 1 1 5BA76893
P 6550 1750
AR Path="/5BA76893" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BA76893" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 6550 1500 50  0001 C CNN
F 1 "GND" H 6555 1577 50  0000 C CNN
F 2 "" H 6550 1750 50  0001 C CNN
F 3 "" H 6550 1750 50  0001 C CNN
	1    6550 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	6550 1750 6350 1750
Connection ~ 6350 1750
Wire Wire Line
	6350 1750 6350 1900
$Comp
L power:+24V #PWR?
U 1 1 5BA7689C
P 6350 750
AR Path="/5BA7689C" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BA7689C" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 6350 600 50  0001 C CNN
F 1 "+24V" H 6365 923 50  0000 C CNN
F 2 "" H 6350 750 50  0001 C CNN
F 3 "" H 6350 750 50  0001 C CNN
	1    6350 750 
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_PMOS_DGS Q?
U 1 1 5BA768A2
P 6150 950
AR Path="/5BA768A2" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BA768A2" Ref="Q?"  Part="1" 
F 0 "Q?" H 6356 904 50  0000 L CNN
F 1 "Q_PMOS_DGS" H 6356 995 50  0000 L CNN
F 2 "" H 6350 1050 50  0001 C CNN
F 3 "~" H 6150 950 50  0001 C CNN
	1    6150 950 
	-1   0    0    1   
$EndComp
Wire Wire Line
	6050 750  6350 750 
Wire Wire Line
	6050 1150 5550 1150
Wire Wire Line
	5600 1450 5550 1450
$Comp
L Device:Q_NMOS_DGS Q?
U 1 1 5BA768B1
P 1900 3000
AR Path="/5BA768B1" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BA768B1" Ref="Q?"  Part="1" 
F 0 "Q?" H 2105 3046 50  0000 L CNN
F 1 "Q_NMOS_DGS" H 2105 2955 50  0000 L CNN
F 2 "" H 2100 3100 50  0001 C CNN
F 3 "~" H 1900 3000 50  0001 C CNN
	1    1900 3000
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5BA768B8
P 1400 3000
AR Path="/5BA768B8" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BA768B8" Ref="R?"  Part="1" 
F 0 "R?" V 1193 3000 50  0000 C CNN
F 1 "R" V 1284 3000 50  0000 C CNN
F 2 "" V 1330 3000 50  0001 C CNN
F 3 "~" H 1400 3000 50  0001 C CNN
	1    1400 3000
	0    1    1    0   
$EndComp
Wire Wire Line
	1550 3000 1700 3000
$Comp
L Device:R R?
U 1 1 5BA768C0
P 2200 2450
AR Path="/5BA768C0" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BA768C0" Ref="R?"  Part="1" 
F 0 "R?" H 2270 2496 50  0000 L CNN
F 1 "1K" H 2270 2405 50  0000 L CNN
F 2 "" V 2130 2450 50  0001 C CNN
F 3 "~" H 2200 2450 50  0001 C CNN
	1    2200 2450
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5BA768C7
P 1850 3450
AR Path="/5BA768C7" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BA768C7" Ref="R?"  Part="1" 
F 0 "R?" V 2057 3450 50  0000 C CNN
F 1 "1K" V 1966 3450 50  0000 C CNN
F 2 "" V 1780 3450 50  0001 C CNN
F 3 "~" H 1850 3450 50  0001 C CNN
	1    1850 3450
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1700 3450 1700 3000
Connection ~ 1700 3000
Wire Wire Line
	2000 3200 2000 3300
$Comp
L power:GND #PWR?
U 1 1 5BA768D1
P 2200 3300
AR Path="/5BA768D1" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BA768D1" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 2200 3050 50  0001 C CNN
F 1 "GND" H 2205 3127 50  0000 C CNN
F 2 "" H 2200 3300 50  0001 C CNN
F 3 "" H 2200 3300 50  0001 C CNN
	1    2200 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 3300 2000 3300
Connection ~ 2000 3300
Wire Wire Line
	2000 3300 2000 3450
$Comp
L power:+24V #PWR?
U 1 1 5BA768DA
P 2000 2300
AR Path="/5BA768DA" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BA768DA" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 2000 2150 50  0001 C CNN
F 1 "+24V" H 2015 2473 50  0000 C CNN
F 2 "" H 2000 2300 50  0001 C CNN
F 3 "" H 2000 2300 50  0001 C CNN
	1    2000 2300
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_PMOS_DGS Q?
U 1 1 5BA768E0
P 1800 2500
AR Path="/5BA768E0" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BA768E0" Ref="Q?"  Part="1" 
F 0 "Q?" H 2006 2454 50  0000 L CNN
F 1 "Q_PMOS_DGS" H 2006 2545 50  0000 L CNN
F 2 "" H 2000 2600 50  0001 C CNN
F 3 "~" H 1800 2500 50  0001 C CNN
	1    1800 2500
	-1   0    0    1   
$EndComp
Wire Wire Line
	1700 2300 2000 2300
Wire Wire Line
	1700 2700 1200 2700
Wire Wire Line
	1250 3000 1200 3000
$Comp
L Device:Q_NMOS_DGS Q?
U 1 1 5BA768EF
P 10500 1450
AR Path="/5BA768EF" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BA768EF" Ref="Q?"  Part="1" 
F 0 "Q?" H 10705 1496 50  0000 L CNN
F 1 "Q_NMOS_DGS" H 10705 1405 50  0000 L CNN
F 2 "" H 10700 1550 50  0001 C CNN
F 3 "~" H 10500 1450 50  0001 C CNN
	1    10500 1450
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5BA768F6
P 10000 1450
AR Path="/5BA768F6" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BA768F6" Ref="R?"  Part="1" 
F 0 "R?" V 9793 1450 50  0000 C CNN
F 1 "R" V 9884 1450 50  0000 C CNN
F 2 "" V 9930 1450 50  0001 C CNN
F 3 "~" H 10000 1450 50  0001 C CNN
	1    10000 1450
	0    1    1    0   
$EndComp
Wire Wire Line
	10150 1450 10300 1450
$Comp
L Device:R R?
U 1 1 5BA768FE
P 10800 900
AR Path="/5BA768FE" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BA768FE" Ref="R?"  Part="1" 
F 0 "R?" H 10870 946 50  0000 L CNN
F 1 "1K" H 10870 855 50  0000 L CNN
F 2 "" V 10730 900 50  0001 C CNN
F 3 "~" H 10800 900 50  0001 C CNN
	1    10800 900 
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5BA76905
P 10450 1900
AR Path="/5BA76905" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BA76905" Ref="R?"  Part="1" 
F 0 "R?" V 10657 1900 50  0000 C CNN
F 1 "1K" V 10566 1900 50  0000 C CNN
F 2 "" V 10380 1900 50  0001 C CNN
F 3 "~" H 10450 1900 50  0001 C CNN
	1    10450 1900
	0    -1   -1   0   
$EndComp
Wire Wire Line
	10300 1900 10300 1450
Connection ~ 10300 1450
Wire Wire Line
	10600 1650 10600 1750
$Comp
L power:GND #PWR?
U 1 1 5BA7690F
P 10800 1750
AR Path="/5BA7690F" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BA7690F" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 10800 1500 50  0001 C CNN
F 1 "GND" H 10805 1577 50  0000 C CNN
F 2 "" H 10800 1750 50  0001 C CNN
F 3 "" H 10800 1750 50  0001 C CNN
	1    10800 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	10800 1750 10600 1750
Connection ~ 10600 1750
Wire Wire Line
	10600 1750 10600 1900
$Comp
L power:+24V #PWR?
U 1 1 5BA76918
P 10600 750
AR Path="/5BA76918" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BA76918" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 10600 600 50  0001 C CNN
F 1 "+24V" H 10615 923 50  0000 C CNN
F 2 "" H 10600 750 50  0001 C CNN
F 3 "" H 10600 750 50  0001 C CNN
	1    10600 750 
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_PMOS_DGS Q?
U 1 1 5BA7691E
P 10400 950
AR Path="/5BA7691E" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BA7691E" Ref="Q?"  Part="1" 
F 0 "Q?" H 10606 904 50  0000 L CNN
F 1 "Q_PMOS_DGS" H 10606 995 50  0000 L CNN
F 2 "" H 10600 1050 50  0001 C CNN
F 3 "~" H 10400 950 50  0001 C CNN
	1    10400 950 
	-1   0    0    1   
$EndComp
Wire Wire Line
	10300 750  10600 750 
Wire Wire Line
	10300 1150 9800 1150
Wire Wire Line
	9850 1450 9800 1450
$Comp
L Device:Q_NMOS_DGS Q?
U 1 1 5BA7692D
P 8350 1450
AR Path="/5BA7692D" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BA7692D" Ref="Q?"  Part="1" 
F 0 "Q?" H 8555 1496 50  0000 L CNN
F 1 "Q_NMOS_DGS" H 8555 1405 50  0000 L CNN
F 2 "" H 8550 1550 50  0001 C CNN
F 3 "~" H 8350 1450 50  0001 C CNN
	1    8350 1450
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5BA76934
P 7850 1450
AR Path="/5BA76934" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BA76934" Ref="R?"  Part="1" 
F 0 "R?" V 7643 1450 50  0000 C CNN
F 1 "R" V 7734 1450 50  0000 C CNN
F 2 "" V 7780 1450 50  0001 C CNN
F 3 "~" H 7850 1450 50  0001 C CNN
	1    7850 1450
	0    1    1    0   
$EndComp
Wire Wire Line
	8000 1450 8150 1450
$Comp
L Device:R R?
U 1 1 5BA7693C
P 8600 900
AR Path="/5BA7693C" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BA7693C" Ref="R?"  Part="1" 
F 0 "R?" H 8670 946 50  0000 L CNN
F 1 "1K" H 8670 855 50  0000 L CNN
F 2 "" V 8530 900 50  0001 C CNN
F 3 "~" H 8600 900 50  0001 C CNN
	1    8600 900 
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5BA76943
P 8300 1900
AR Path="/5BA76943" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BA76943" Ref="R?"  Part="1" 
F 0 "R?" V 8507 1900 50  0000 C CNN
F 1 "1K" V 8416 1900 50  0000 C CNN
F 2 "" V 8230 1900 50  0001 C CNN
F 3 "~" H 8300 1900 50  0001 C CNN
	1    8300 1900
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8150 1900 8150 1450
Connection ~ 8150 1450
Wire Wire Line
	8450 1650 8450 1750
$Comp
L power:GND #PWR?
U 1 1 5BA7694D
P 8650 1750
AR Path="/5BA7694D" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BA7694D" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 8650 1500 50  0001 C CNN
F 1 "GND" H 8655 1577 50  0000 C CNN
F 2 "" H 8650 1750 50  0001 C CNN
F 3 "" H 8650 1750 50  0001 C CNN
	1    8650 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	8650 1750 8450 1750
Connection ~ 8450 1750
Wire Wire Line
	8450 1750 8450 1900
$Comp
L power:+24V #PWR?
U 1 1 5BA76956
P 8450 750
AR Path="/5BA76956" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BA76956" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 8450 600 50  0001 C CNN
F 1 "+24V" H 8465 923 50  0000 C CNN
F 2 "" H 8450 750 50  0001 C CNN
F 3 "" H 8450 750 50  0001 C CNN
	1    8450 750 
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_PMOS_DGS Q?
U 1 1 5BA7695C
P 8250 950
AR Path="/5BA7695C" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BA7695C" Ref="Q?"  Part="1" 
F 0 "Q?" H 8456 904 50  0000 L CNN
F 1 "Q_PMOS_DGS" H 8456 995 50  0000 L CNN
F 2 "" H 8450 1050 50  0001 C CNN
F 3 "~" H 8250 950 50  0001 C CNN
	1    8250 950 
	-1   0    0    1   
$EndComp
Wire Wire Line
	8150 750  8450 750 
Wire Wire Line
	8150 1150 7650 1150
Wire Wire Line
	7700 1450 7650 1450
$Comp
L Device:Q_NMOS_DGS Q?
U 1 1 5BA7696B
P 4100 3000
AR Path="/5BA7696B" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BA7696B" Ref="Q?"  Part="1" 
F 0 "Q?" H 4305 3046 50  0000 L CNN
F 1 "Q_NMOS_DGS" H 4305 2955 50  0000 L CNN
F 2 "" H 4300 3100 50  0001 C CNN
F 3 "~" H 4100 3000 50  0001 C CNN
	1    4100 3000
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5BA76972
P 3600 3000
AR Path="/5BA76972" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BA76972" Ref="R?"  Part="1" 
F 0 "R?" V 3393 3000 50  0000 C CNN
F 1 "R" V 3484 3000 50  0000 C CNN
F 2 "" V 3530 3000 50  0001 C CNN
F 3 "~" H 3600 3000 50  0001 C CNN
	1    3600 3000
	0    1    1    0   
$EndComp
Wire Wire Line
	3750 3000 3900 3000
$Comp
L Device:R R?
U 1 1 5BA7697A
P 4400 2450
AR Path="/5BA7697A" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BA7697A" Ref="R?"  Part="1" 
F 0 "R?" H 4470 2496 50  0000 L CNN
F 1 "1K" H 4470 2405 50  0000 L CNN
F 2 "" V 4330 2450 50  0001 C CNN
F 3 "~" H 4400 2450 50  0001 C CNN
	1    4400 2450
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5BA76981
P 4050 3450
AR Path="/5BA76981" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BA76981" Ref="R?"  Part="1" 
F 0 "R?" V 4257 3450 50  0000 C CNN
F 1 "1K" V 4166 3450 50  0000 C CNN
F 2 "" V 3980 3450 50  0001 C CNN
F 3 "~" H 4050 3450 50  0001 C CNN
	1    4050 3450
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3900 3450 3900 3000
Connection ~ 3900 3000
Wire Wire Line
	4200 3200 4200 3300
$Comp
L power:GND #PWR?
U 1 1 5BA7698B
P 4400 3300
AR Path="/5BA7698B" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BA7698B" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 4400 3050 50  0001 C CNN
F 1 "GND" H 4405 3127 50  0000 C CNN
F 2 "" H 4400 3300 50  0001 C CNN
F 3 "" H 4400 3300 50  0001 C CNN
	1    4400 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 3300 4200 3300
Connection ~ 4200 3300
Wire Wire Line
	4200 3300 4200 3450
$Comp
L power:+24V #PWR?
U 1 1 5BA76994
P 4200 2300
AR Path="/5BA76994" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BA76994" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 4200 2150 50  0001 C CNN
F 1 "+24V" H 4215 2473 50  0000 C CNN
F 2 "" H 4200 2300 50  0001 C CNN
F 3 "" H 4200 2300 50  0001 C CNN
	1    4200 2300
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_PMOS_DGS Q?
U 1 1 5BA7699A
P 4000 2500
AR Path="/5BA7699A" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BA7699A" Ref="Q?"  Part="1" 
F 0 "Q?" H 4206 2454 50  0000 L CNN
F 1 "Q_PMOS_DGS" H 4206 2545 50  0000 L CNN
F 2 "" H 4200 2600 50  0001 C CNN
F 3 "~" H 4000 2500 50  0001 C CNN
	1    4000 2500
	-1   0    0    1   
$EndComp
Wire Wire Line
	3900 2300 4200 2300
Wire Wire Line
	3900 2700 3400 2700
Wire Wire Line
	3450 3000 3400 3000
$Comp
L Device:Q_PMOS_SGD Q?
U 1 1 5BA8E115
P 1250 4400
AR Path="/5BA8E115" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BA8E115" Ref="Q?"  Part="1" 
F 0 "Q?" H 1456 4446 50  0000 L CNN
F 1 "Q_PMOS_SGD" H 1456 4355 50  0000 L CNN
F 2 "" H 1450 4500 50  0001 C CNN
F 3 "~" H 1250 4400 50  0001 C CNN
	1    1250 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	950  4400 1050 4400
$Comp
L Device:R R?
U 1 1 5BA8E124
P 1200 4900
AR Path="/5BA8E124" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BA8E124" Ref="R?"  Part="1" 
F 0 "R?" V 993 4900 50  0000 C CNN
F 1 "1K" V 1084 4900 50  0000 C CNN
F 2 "" V 1130 4900 50  0001 C CNN
F 3 "~" H 1200 4900 50  0001 C CNN
	1    1200 4900
	0    1    1    0   
$EndComp
Wire Wire Line
	1350 4900 1350 4750
Wire Wire Line
	1550 4750 1350 4750
Connection ~ 1350 4750
Wire Wire Line
	1350 4750 1350 4600
Wire Wire Line
	1050 4900 1050 4400
Connection ~ 1050 4400
Wire Wire Line
	950  4200 1350 4200
$Comp
L Device:Q_PMOS_SGD Q?
U 1 1 5BA8F9BB
P 3000 4400
AR Path="/5BA8F9BB" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BA8F9BB" Ref="Q?"  Part="1" 
F 0 "Q?" H 3206 4446 50  0000 L CNN
F 1 "Q_PMOS_SGD" H 3206 4355 50  0000 L CNN
F 2 "" H 3200 4500 50  0001 C CNN
F 3 "~" H 3000 4400 50  0001 C CNN
	1    3000 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2700 4400 2800 4400
$Comp
L Device:R R?
U 1 1 5BA8F9C9
P 2950 4900
AR Path="/5BA8F9C9" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BA8F9C9" Ref="R?"  Part="1" 
F 0 "R?" V 2743 4900 50  0000 C CNN
F 1 "1K" V 2834 4900 50  0000 C CNN
F 2 "" V 2880 4900 50  0001 C CNN
F 3 "~" H 2950 4900 50  0001 C CNN
	1    2950 4900
	0    1    1    0   
$EndComp
Wire Wire Line
	3100 4900 3100 4750
Wire Wire Line
	3300 4750 3100 4750
Connection ~ 3100 4750
Wire Wire Line
	3100 4750 3100 4600
Wire Wire Line
	2800 4900 2800 4400
Connection ~ 2800 4400
Wire Wire Line
	2700 4200 3100 4200
$Comp
L Device:Q_PMOS_SGD Q?
U 1 1 5BA944B5
P 4750 4400
AR Path="/5BA944B5" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BA944B5" Ref="Q?"  Part="1" 
F 0 "Q?" H 4956 4446 50  0000 L CNN
F 1 "Q_PMOS_SGD" H 4956 4355 50  0000 L CNN
F 2 "" H 4950 4500 50  0001 C CNN
F 3 "~" H 4750 4400 50  0001 C CNN
	1    4750 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4450 4400 4550 4400
$Comp
L Device:R R?
U 1 1 5BA944C3
P 4700 4900
AR Path="/5BA944C3" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BA944C3" Ref="R?"  Part="1" 
F 0 "R?" V 4493 4900 50  0000 C CNN
F 1 "1K" V 4584 4900 50  0000 C CNN
F 2 "" V 4630 4900 50  0001 C CNN
F 3 "~" H 4700 4900 50  0001 C CNN
	1    4700 4900
	0    1    1    0   
$EndComp
Wire Wire Line
	4850 4900 4850 4750
Wire Wire Line
	5050 4750 4850 4750
Connection ~ 4850 4750
Wire Wire Line
	4850 4750 4850 4600
Wire Wire Line
	4550 4900 4550 4400
Connection ~ 4550 4400
Wire Wire Line
	4450 4200 4850 4200
$Comp
L Device:Q_PMOS_SGD Q?
U 1 1 5BA97F05
P 6600 4400
AR Path="/5BA97F05" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BA97F05" Ref="Q?"  Part="1" 
F 0 "Q?" H 6806 4446 50  0000 L CNN
F 1 "Q_PMOS_SGD" H 6806 4355 50  0000 L CNN
F 2 "" H 6800 4500 50  0001 C CNN
F 3 "~" H 6600 4400 50  0001 C CNN
	1    6600 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 4400 6400 4400
$Comp
L Device:R R?
U 1 1 5BA97F13
P 6550 4900
AR Path="/5BA97F13" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BA97F13" Ref="R?"  Part="1" 
F 0 "R?" V 6343 4900 50  0000 C CNN
F 1 "1K" V 6434 4900 50  0000 C CNN
F 2 "" V 6480 4900 50  0001 C CNN
F 3 "~" H 6550 4900 50  0001 C CNN
	1    6550 4900
	0    1    1    0   
$EndComp
Wire Wire Line
	6700 4900 6700 4750
Wire Wire Line
	6900 4750 6700 4750
Connection ~ 6700 4750
Wire Wire Line
	6700 4750 6700 4600
Wire Wire Line
	6400 4900 6400 4400
Connection ~ 6400 4400
Wire Wire Line
	6300 4200 6700 4200
$Comp
L Device:Q_PMOS_SGD Q?
U 1 1 5BA9A216
P 8100 4400
AR Path="/5BA9A216" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BA9A216" Ref="Q?"  Part="1" 
F 0 "Q?" H 8306 4446 50  0000 L CNN
F 1 "Q_PMOS_SGD" H 8306 4355 50  0000 L CNN
F 2 "" H 8300 4500 50  0001 C CNN
F 3 "~" H 8100 4400 50  0001 C CNN
	1    8100 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	7800 4400 7900 4400
$Comp
L Device:R R?
U 1 1 5BA9A224
P 8050 4900
AR Path="/5BA9A224" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BA9A224" Ref="R?"  Part="1" 
F 0 "R?" V 7843 4900 50  0000 C CNN
F 1 "1K" V 7934 4900 50  0000 C CNN
F 2 "" V 7980 4900 50  0001 C CNN
F 3 "~" H 8050 4900 50  0001 C CNN
	1    8050 4900
	0    1    1    0   
$EndComp
Wire Wire Line
	8200 4900 8200 4750
Wire Wire Line
	8400 4750 8200 4750
Connection ~ 8200 4750
Wire Wire Line
	8200 4750 8200 4600
Wire Wire Line
	7900 4900 7900 4400
Connection ~ 7900 4400
Wire Wire Line
	7800 4200 8200 4200
$Comp
L Device:Q_PMOS_SGD Q?
U 1 1 5BAA0E9C
P 9900 4400
AR Path="/5BAA0E9C" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BAA0E9C" Ref="Q?"  Part="1" 
F 0 "Q?" H 10106 4446 50  0000 L CNN
F 1 "Q_PMOS_SGD" H 10106 4355 50  0000 L CNN
F 2 "" H 10100 4500 50  0001 C CNN
F 3 "~" H 9900 4400 50  0001 C CNN
	1    9900 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	9600 4400 9700 4400
$Comp
L Device:R R?
U 1 1 5BAA0EAA
P 9850 4900
AR Path="/5BAA0EAA" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BAA0EAA" Ref="R?"  Part="1" 
F 0 "R?" V 9643 4900 50  0000 C CNN
F 1 "1K" V 9734 4900 50  0000 C CNN
F 2 "" V 9780 4900 50  0001 C CNN
F 3 "~" H 9850 4900 50  0001 C CNN
	1    9850 4900
	0    1    1    0   
$EndComp
Wire Wire Line
	10000 4900 10000 4750
Wire Wire Line
	10200 4750 10000 4750
Connection ~ 10000 4750
Wire Wire Line
	10000 4750 10000 4600
Wire Wire Line
	9700 4900 9700 4400
Connection ~ 9700 4400
Wire Wire Line
	9600 4200 10000 4200
$Comp
L Connector_Generic:Conn_01x18 J?
U 1 1 5BAA6946
P 6600 6650
AR Path="/5BAA6946" Ref="J?"  Part="1" 
AR Path="/5BA75957/5BAA6946" Ref="J?"  Part="1" 
F 0 "J?" V 6700 7400 50  0000 L CNN
F 1 "Motor connector" V 6700 5700 50  0000 L CNN
F 2 "" H 6600 6650 50  0001 C CNN
F 3 "~" H 6600 6650 50  0001 C CNN
	1    6600 6650
	1    0    0    -1  
$EndComp
NoConn ~ 6400 6250
NoConn ~ 6400 6350
NoConn ~ 6400 6450
NoConn ~ 6400 6550
NoConn ~ 6400 6650
Wire Wire Line
	6350 5850 6400 5850
Wire Wire Line
	6350 5950 6400 5950
Wire Wire Line
	6350 6050 6400 6050
Wire Wire Line
	6350 6150 6400 6150
Wire Wire Line
	6350 6750 6400 6750
Wire Wire Line
	6350 6850 6400 6850
Wire Wire Line
	6350 6950 6400 6950
Wire Wire Line
	6350 7050 6400 7050
Wire Wire Line
	6350 7150 6400 7150
Wire Wire Line
	6350 7250 6400 7250
Wire Wire Line
	6350 7350 6400 7350
Wire Wire Line
	6350 7450 6400 7450
Wire Wire Line
	6350 7550 6400 7550
Text Label 1200 1150 2    50   ~ 0
motor_white_red
Text Label 6350 7550 2    50   ~ 0
motor_white_red
Text HLabel 1200 1450 0    50   Input ~ 0
row_a_ctrl
Text Label 3400 1150 2    50   ~ 0
motor_white_green
Text Label 6350 7450 2    50   ~ 0
motor_white_green
Text HLabel 3400 1450 0    50   Input ~ 0
row_b_ctrl
Text Label 5550 1150 2    50   ~ 0
motor_white_blue
Text Label 6350 7350 2    50   ~ 0
motor_white_blue
Text HLabel 5550 1450 0    50   Input ~ 0
row_c_ctrl
Text Label 7650 1150 2    50   ~ 0
motor_white_tan
Text Label 6350 7250 2    50   ~ 0
motor_white_tan
Text HLabel 7650 1450 0    50   Input ~ 0
row_d_ctrl
Text Label 9800 1150 2    50   ~ 0
motor_white_gray
Text Label 6350 7150 2    50   ~ 0
motor_white_gray
Text HLabel 9800 1450 0    50   Input ~ 0
row_e_ctrl
Text Label 1200 2700 2    50   ~ 0
motor_white_pink
Text Label 6350 7050 2    50   ~ 0
motor_white_pink
Text HLabel 1200 3000 0    50   Input ~ 0
row_f_ctrl
Text Label 3400 2700 2    50   ~ 0
motor_white_purple
Text Label 6350 6950 2    50   ~ 0
motor_white_purple
Text HLabel 3400 3000 0    50   Input ~ 0
row_g_ctrl
Text Label 950  4200 2    50   ~ 0
motor_red
Text Label 6350 6750 2    50   ~ 0
motor_red
Text HLabel 950  4400 0    50   Input ~ 0
col_1_ctrl
Text Label 6350 6850 2    50   ~ 0
motor_red_white
Text Label 2700 4200 2    50   ~ 0
motor_red_white
Text HLabel 2700 4400 0    50   Input ~ 0
col_2_ctrl
Text Label 4450 4200 2    50   ~ 0
motor_green_red
Text Label 6350 5850 2    50   ~ 0
motor_green_red
Text HLabel 4450 4400 0    50   Input ~ 0
col_3_ctrl
Text Label 6300 4200 2    50   ~ 0
motor_green_white
Text Label 6350 5950 2    50   ~ 0
motor_green_white
Text HLabel 6300 4400 0    50   Input ~ 0
col_4_ctrl
Text Label 7800 4200 2    50   ~ 0
motor_blue
Text Label 6350 6050 2    50   ~ 0
motor_blue
Text HLabel 7800 4400 0    50   Input ~ 0
col_5_ctrl
Text Label 9600 4200 2    50   ~ 0
motor_blue_white
Text Label 6350 6150 2    50   ~ 0
motor_blue_white
Text HLabel 9600 4400 0    50   Input ~ 0
col_6_ctrl
Text Label 1550 4750 0    50   ~ 0
motor_common_gnd
Text Label 3300 4750 0    50   ~ 0
motor_common_gnd
Text Label 5050 4750 0    50   ~ 0
motor_common_gnd
Text Label 6900 4750 0    50   ~ 0
motor_common_gnd
Text Label 8400 4750 0    50   ~ 0
motor_common_gnd
Text Label 10200 4750 0    50   ~ 0
motor_common_gnd
Text Label 3450 6100 0    50   ~ 0
motor_common_gnd
$Comp
L Device:R R?
U 1 1 5BB1C4B9
P 3250 6250
F 0 "R?" H 3320 6296 50  0000 L CNN
F 1 ".1" H 3320 6205 50  0000 L CNN
F 2 "" V 3180 6250 50  0001 C CNN
F 3 "~" H 3250 6250 50  0001 C CNN
	1    3250 6250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3250 6400 3150 6400
Wire Wire Line
	3150 6400 3150 6300
Wire Wire Line
	3150 6300 2900 6300
Wire Wire Line
	2900 6200 3150 6200
Wire Wire Line
	3150 6200 3150 6100
Wire Wire Line
	3150 6100 3250 6100
Wire Wire Line
	3450 6100 3250 6100
Connection ~ 3250 6100
$Comp
L power:GND #PWR?
U 1 1 5BB27603
P 3450 6400
F 0 "#PWR?" H 3450 6150 50  0001 C CNN
F 1 "GND" H 3455 6227 50  0000 C CNN
F 2 "" H 3450 6400 50  0001 C CNN
F 3 "" H 3450 6400 50  0001 C CNN
	1    3450 6400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 6400 3250 6400
Connection ~ 3250 6400
Wire Wire Line
	3150 6400 2900 6400
Connection ~ 3150 6400
$Comp
L power:VCC #PWR?
U 1 1 5BB2FE84
P 3050 6500
F 0 "#PWR?" H 3050 6350 50  0001 C CNN
F 1 "VCC" H 3068 6673 50  0000 C CNN
F 2 "" H 3050 6500 50  0001 C CNN
F 3 "" H 3050 6500 50  0001 C CNN
	1    3050 6500
	-1   0    0    1   
$EndComp
Wire Wire Line
	3050 6500 2900 6500
Text HLabel 1750 6500 0    50   Input ~ 0
SCL
Wire Wire Line
	1750 6500 1900 6500
Text HLabel 1750 6400 0    50   Input ~ 0
SDA
Wire Wire Line
	1750 6400 1900 6400
Wire Wire Line
	2000 750  2150 750 
Connection ~ 2000 750 
Wire Wire Line
	2000 950  2000 1050
Wire Wire Line
	2150 1050 2000 1050
Connection ~ 2000 1050
Wire Wire Line
	2000 1050 2000 1250
Wire Wire Line
	4350 750  4200 750 
Connection ~ 4200 750 
Wire Wire Line
	4200 950  4200 1050
Wire Wire Line
	4350 1050 4200 1050
Connection ~ 4200 1050
Wire Wire Line
	4200 1050 4200 1250
Wire Wire Line
	6500 750  6350 750 
Connection ~ 6350 750 
Wire Wire Line
	6350 950  6350 1050
Wire Wire Line
	6500 1050 6350 1050
Connection ~ 6350 1050
Wire Wire Line
	6350 1050 6350 1250
Wire Wire Line
	8600 750  8450 750 
Connection ~ 8450 750 
Wire Wire Line
	8450 950  8450 1050
Connection ~ 8450 1050
Wire Wire Line
	8450 1050 8450 1250
Wire Wire Line
	8450 1050 8600 1050
Wire Wire Line
	10800 750  10600 750 
Connection ~ 10600 750 
Wire Wire Line
	10600 950  10600 1050
Wire Wire Line
	10800 1050 10600 1050
Connection ~ 10600 1050
Wire Wire Line
	10600 1050 10600 1250
Wire Wire Line
	2200 2300 2000 2300
Connection ~ 2000 2300
Wire Wire Line
	2000 2500 2000 2600
Wire Wire Line
	2200 2600 2000 2600
Connection ~ 2000 2600
Wire Wire Line
	2000 2600 2000 2800
Wire Wire Line
	4400 2300 4200 2300
Connection ~ 4200 2300
Wire Wire Line
	4200 2500 4200 2600
Wire Wire Line
	4400 2600 4200 2600
Wire Wire Line
	4200 2600 4200 2800
$Comp
L Device:Q_PMOS_DGS Q?
U 1 1 5BCCBAF4
P 6500 2550
AR Path="/5BCCBAF4" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BCCBAF4" Ref="Q?"  Part="1" 
F 0 "Q?" V 6850 2500 50  0000 L CNN
F 1 "Q_PMOS_DGS" V 6750 2500 50  0000 L CNN
F 2 "" H 6700 2650 50  0001 C CNN
F 3 "~" H 6500 2550 50  0001 C CNN
	1    6500 2550
	0    1    -1   0   
$EndComp
$Comp
L power:+24V #PWR?
U 1 1 5BCCBC60
P 6100 2450
AR Path="/5BCCBC60" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BCCBC60" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 6100 2300 50  0001 C CNN
F 1 "+24V" H 6115 2623 50  0000 C CNN
F 2 "" H 6100 2450 50  0001 C CNN
F 3 "" H 6100 2450 50  0001 C CNN
	1    6100 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 2450 6200 2450
$Comp
L Device:R R?
U 1 1 5BCD1BC4
P 6200 2650
AR Path="/5BCD1BC4" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BCD1BC4" Ref="R?"  Part="1" 
F 0 "R?" H 6270 2696 50  0000 L CNN
F 1 "1K" H 6270 2605 50  0000 L CNN
F 2 "" V 6130 2650 50  0001 C CNN
F 3 "~" H 6200 2650 50  0001 C CNN
	1    6200 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 2500 6200 2450
Connection ~ 6200 2450
Wire Wire Line
	6200 2450 6100 2450
Wire Wire Line
	6200 2800 6200 2900
Wire Wire Line
	6200 2900 6500 2900
Wire Wire Line
	6500 2900 6500 2750
Connection ~ 4200 2600
$Comp
L Device:Q_NMOS_DGS Q?
U 1 1 5BCEAFC3
P 6400 3100
AR Path="/5BCEAFC3" Ref="Q?"  Part="1" 
AR Path="/5BA75957/5BCEAFC3" Ref="Q?"  Part="1" 
F 0 "Q?" H 6605 3146 50  0000 L CNN
F 1 "Q_NMOS_DGS" H 6605 3055 50  0000 L CNN
F 2 "" H 6600 3200 50  0001 C CNN
F 3 "~" H 6400 3100 50  0001 C CNN
	1    6400 3100
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5BCEAFCA
P 5800 3100
AR Path="/5BCEAFCA" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BCEAFCA" Ref="R?"  Part="1" 
F 0 "R?" V 5900 3100 50  0000 C CNN
F 1 "R" V 6000 3100 50  0000 C CNN
F 2 "" V 5730 3100 50  0001 C CNN
F 3 "~" H 5800 3100 50  0001 C CNN
	1    5800 3100
	0    1    1    0   
$EndComp
Wire Wire Line
	5950 3100 6100 3100
$Comp
L Device:R R?
U 1 1 5BCEAFD2
P 6100 3350
AR Path="/5BCEAFD2" Ref="R?"  Part="1" 
AR Path="/5BA75957/5BCEAFD2" Ref="R?"  Part="1" 
F 0 "R?" H 6200 3400 50  0000 C CNN
F 1 "1K" H 6200 3300 50  0000 C CNN
F 2 "" V 6030 3350 50  0001 C CNN
F 3 "~" H 6100 3350 50  0001 C CNN
	1    6100 3350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5BCEAFDC
P 6500 3700
AR Path="/5BCEAFDC" Ref="#PWR?"  Part="1" 
AR Path="/5BA75957/5BCEAFDC" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 6500 3450 50  0001 C CNN
F 1 "GND" H 6505 3527 50  0000 C CNN
F 2 "" H 6500 3700 50  0001 C CNN
F 3 "" H 6500 3700 50  0001 C CNN
	1    6500 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 3100 5500 3100
Text HLabel 5500 3100 0    50   Input ~ 0
row_g_ctrl
Connection ~ 6500 2900
Wire Wire Line
	6500 3300 6500 3600
Wire Wire Line
	6100 3100 6100 3200
Connection ~ 6100 3100
Wire Wire Line
	6100 3100 6200 3100
Wire Wire Line
	6100 3500 6100 3600
Wire Wire Line
	6100 3600 6500 3600
Connection ~ 6500 3600
Wire Wire Line
	6500 3600 6500 3700
Wire Wire Line
	6700 2450 7550 2450
Text Label 7550 2450 2    50   ~ 0
motor_white_purple
$Comp
L Snack_Machine:INA219 U?
U 1 1 5BC6BBF3
P 2400 6350
F 0 "U?" H 2400 6765 50  0000 C CNN
F 1 "INA219" H 2400 6674 50  0000 C CNN
F 2 "" H 2400 6350 50  0001 C CNN
F 3 "" H 2400 6350 50  0001 C CNN
	1    2400 6350
	1    0    0    -1  
$EndComp
$EndSCHEMATC
