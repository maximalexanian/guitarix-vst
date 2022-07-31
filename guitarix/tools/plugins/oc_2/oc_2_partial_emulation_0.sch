v 20130925 2
C 40000 40000 0 0 0 title-B.sym
T 45600 50400 9 14 1 0 0 0 2
Common notes:

T 45600 49800 9 14 1 0 0 0 2
2) Elements refdes's are not the same as at original schematic (cap;)

C 55500 50300 1 270 0 voltage-3.sym
{
T 56200 50100 5 8 0 0 270 0 1
device=VOLTAGE_SOURCE
T 56000 49800 5 10 1 1 0 0 1
refdes=V1
T 56000 49600 5 10 1 1 0 0 1
value=DC 4.5
}
C 56100 49100 1 0 0 ground.sym
N 55000 49400 56300 49400 4
C 55500 49300 1 270 0 voltage-3.sym
{
T 56200 49100 5 8 0 0 270 0 1
device=VOLTAGE_SOURCE
T 56000 48800 5 10 1 1 0 0 1
refdes=V2
T 56000 48600 5 10 1 1 0 0 1
value=DC 4.5
}
N 55700 49300 55700 49400 4
N 55700 50300 56300 50300 4
{
T 56200 50300 5 10 1 1 0 0 1
netname=Vcc
}
N 55000 48400 56300 48400 4
{
T 56200 48400 5 10 1 1 0 0 1
netname=Vdd
}
T 54500 50300 9 14 1 0 0 0 2
Power supply chain

C 54800 49300 1 270 0 capacitor-2.sym
{
T 55500 49100 5 10 0 0 270 0 1
device=POLARIZED_CAPACITOR
T 55200 49100 5 10 1 1 0 0 1
refdes=Cdec
T 55700 49100 5 10 0 0 270 0 1
symversion=0.1
T 54800 49000 5 10 1 1 0 0 1
model=C
T 54600 48600 5 10 1 1 0 0 1
value=220u
}
N 55000 49300 55000 49400 4
C 40900 47300 1 270 0 voltage-3.sym
{
T 41600 47100 5 8 0 0 270 0 1
device=VOLTAGE_SOURCE
T 41400 46800 5 10 1 1 0 0 1
refdes=V3
T 41400 46600 5 10 1 1 0 0 1
value=DC 1
}
C 41400 47700 1 0 0 resistor-1.sym
{
T 41700 48100 5 10 0 0 0 0 1
device=RESISTOR
T 41300 47500 5 10 1 1 0 0 1
refdes=Rd1
T 41700 47500 5 10 1 1 0 0 1
value=100
T 42100 47500 5 10 1 1 0 0 1
model=R
}
C 42800 46100 1 90 0 diode-1.sym
{
T 42200 46500 5 10 0 0 90 0 1
device=DIODE
T 42500 47000 5 10 1 1 180 0 1
refdes=D1
T 42800 46100 5 10 1 1 0 0 1
model-name=1n34a
T 40100 45200 5 10 1 1 0 0 1
model=1n34a D (bv=75 cjo=0.5e-12 eg=0.67 ibv=18e-3 is=2e-7 rs=7 n=1.3 vj=0.1 m=0.27 )
}
C 42600 48100 1 0 0 resistor-1.sym
{
T 42900 48500 5 10 0 0 0 0 1
device=RESISTOR
T 42800 48400 5 10 1 1 0 0 1
refdes=R1
T 42700 48000 5 10 1 1 0 0 1
model=R
T 43100 48400 5 10 1 1 0 0 1
value=47k
}
C 42600 47300 1 0 0 resistor-1.sym
{
T 42900 47700 5 10 0 0 0 0 1
device=RESISTOR
T 42700 47500 5 10 1 1 0 0 1
refdes=R2
T 43000 47500 5 10 1 1 0 0 1
value=47k
T 42700 47200 5 10 1 1 0 0 1
model=R
}
C 44600 48500 1 0 0 resistor-1.sym
{
T 44900 48900 5 10 0 0 0 0 1
device=RESISTOR
T 44800 48800 5 10 1 1 0 0 1
refdes=R3
T 45100 48800 5 10 1 1 0 0 1
value=27k
T 44700 48400 5 10 1 1 0 0 1
model=R
}
C 46000 46900 1 90 0 resistor-1.sym
{
T 45600 47200 5 10 0 0 90 0 1
device=RESISTOR
T 45700 47300 5 10 1 1 180 0 1
refdes=R4
T 45500 47000 5 10 1 1 0 0 1
value=22k
T 46000 47200 5 10 1 1 0 0 1
model=R
}
C 46000 46000 1 90 0 resistor-1.sym
{
T 45600 46300 5 10 0 0 90 0 1
device=RESISTOR
T 46600 46600 5 10 1 1 180 0 1
refdes=Rload1
T 46000 46300 5 10 1 1 0 0 1
value=100k
T 46100 46100 5 10 1 1 0 0 1
model=R
}
C 45300 46000 1 90 0 capacitor-1.sym
{
T 44600 46200 5 10 0 0 90 0 1
device=CAPACITOR
T 45000 46700 5 10 1 1 180 0 1
refdes=C1
T 44400 46200 5 10 0 0 90 0 1
symversion=0.1
T 44500 46200 5 10 1 1 0 0 1
value=0.022u
T 45200 46200 5 10 1 1 0 0 1
model=C
}
C 44400 47400 1 0 0 opamp-1.sym
{
T 45100 48200 5 10 0 0 0 0 1
device=OPAMP
T 45100 48000 5 10 1 1 0 0 1
refdes=U1
T 45100 48800 5 10 0 0 0 0 1
symversion=0.1
T 45300 47900 5 10 1 1 0 0 1
model-name=OP777
T 44400 47200 5 10 1 1 0 0 1
file=op777.mod
}
N 41100 47300 41100 47800 4
N 41100 47800 41400 47800 4
C 40900 45500 1 0 0 ground.sym
N 42300 47800 42600 47800 4
N 42600 47000 42600 48200 4
N 43500 48200 44400 48200 4
N 44400 48200 44400 48000 4
N 43500 47400 44400 47400 4
N 44400 47400 44400 47600 4
N 41100 45800 41100 46400 4
C 42400 45500 1 0 0 ground.sym
N 42600 45800 42600 46100 4
N 45900 47800 45900 48600 4
N 44600 48600 44100 48600 4
N 44100 48600 44100 48200 4
N 45500 48600 45900 48600 4
N 45400 47800 45900 47800 4
C 44000 46200 1 90 0 resistor-1.sym
{
T 43600 46500 5 10 0 0 90 0 1
device=RESISTOR
T 43700 46600 5 10 1 1 180 0 1
refdes=R_SW1
T 44000 46400 5 10 1 1 0 0 1
value=100
T 44000 46200 5 10 1 1 0 0 1
model=R
}
N 43900 47100 43900 47400 4
C 43700 45500 1 0 0 ground.sym
N 43900 45800 43900 46200 4
N 45100 46900 46700 46900 4
{
T 46500 47000 5 10 1 1 0 0 1
netname=sw_out_opened
}
C 44900 45700 1 0 0 ground.sym
C 45700 45700 1 0 0 ground.sym
T 40100 50100 9 14 1 0 0 0 2
Switches (SW1 and SW2) emulation:

T 41200 47800 9 10 1 0 0 0 3
Avoid V3 to D1 
direct connection

T 45600 50100 9 14 1 0 0 0 2
1) See boss-oc2octaver.odg in the same folder

T 40100 48900 9 10 1 0 0 0 7
We will compute DC for two equal circuits, where
R_SW is resistror, which connected in parallel with
FET transistor. 
In the first case - open state (R_SW = 100 Ohm for example),
In the second - closed state (R_SW = 100k), it's original value.


T 40500 48700 9 10 1 0 0 0 1
Opened state
N 44900 48200 45400 48200 4
{
T 45300 48200 5 10 1 1 0 0 1
netname=Vcc
}
N 44900 47400 45400 47400 4
{
T 45300 47400 5 10 1 1 0 0 1
netname=Vdd
}
T 45600 49200 9 14 1 0 0 0 3
3) Elements, which are not present on the original schematic have non-trivial refdes's, 
like "Rload1"

T 45600 48900 9 14 1 0 0 0 2
4) OP777 model used for opamp emulation, included from file op777.mod,
should be placed at the same folder, as current .sch file
C 40900 43300 1 270 0 voltage-3.sym
{
T 41600 43100 5 8 0 0 270 0 1
device=VOLTAGE_SOURCE
T 41400 42800 5 10 1 1 0 0 1
refdes=V4
T 41400 42600 5 10 1 1 0 0 1
value=DC 1
}
C 41400 43700 1 0 0 resistor-1.sym
{
T 41700 44100 5 10 0 0 0 0 1
device=RESISTOR
T 41300 43500 5 10 1 1 0 0 1
refdes=Rd2
T 41700 43500 5 10 1 1 0 0 1
value=100
T 42100 43500 5 10 1 1 0 0 1
model=R
}
C 42800 42100 1 90 0 diode-1.sym
{
T 42200 42500 5 10 0 0 90 0 1
device=DIODE
T 42500 43000 5 10 1 1 180 0 1
refdes=D2
T 42800 42100 5 10 1 1 0 0 1
model-name=1n34a
T 40100 41200 5 10 1 1 0 0 1
model=1n34a D (bv=75 cjo=0.5e-12 eg=0.67 ibv=18e-3 is=2e-7 rs=7 n=1.3 vj=0.1 m=0.27 )
}
C 42600 44100 1 0 0 resistor-1.sym
{
T 42900 44500 5 10 0 0 0 0 1
device=RESISTOR
T 42800 44400 5 10 1 1 0 0 1
refdes=R5
T 42700 44000 5 10 1 1 0 0 1
model=R
T 43100 44400 5 10 1 1 0 0 1
value=47k
}
C 42600 43300 1 0 0 resistor-1.sym
{
T 42900 43700 5 10 0 0 0 0 1
device=RESISTOR
T 42700 43500 5 10 1 1 0 0 1
refdes=R6
T 43000 43500 5 10 1 1 0 0 1
value=47k
T 42700 43200 5 10 1 1 0 0 1
model=R
}
C 46000 42900 1 90 0 resistor-1.sym
{
T 45600 43200 5 10 0 0 90 0 1
device=RESISTOR
T 45700 43300 5 10 1 1 180 0 1
refdes=R8
T 45500 43000 5 10 1 1 0 0 1
value=22k
T 46000 43200 5 10 1 1 0 0 1
model=R
}
C 46000 42000 1 90 0 resistor-1.sym
{
T 45600 42300 5 10 0 0 90 0 1
device=RESISTOR
T 46600 42600 5 10 1 1 180 0 1
refdes=Rload2
T 46000 42300 5 10 1 1 0 0 1
value=100k
T 46100 42100 5 10 1 1 0 0 1
model=R
}
C 45300 42000 1 90 0 capacitor-1.sym
{
T 44600 42200 5 10 0 0 90 0 1
device=CAPACITOR
T 44400 42200 5 10 0 0 90 0 1
symversion=0.1
T 45000 42700 5 10 1 1 180 0 1
refdes=C2
T 44500 42200 5 10 1 1 0 0 1
value=0.022u
T 45200 42200 5 10 1 1 0 0 1
model=C
}
C 44400 43400 1 0 0 opamp-1.sym
{
T 45100 44200 5 10 0 0 0 0 1
device=OPAMP
T 45100 44800 5 10 0 0 0 0 1
symversion=0.1
T 45100 44000 5 10 1 1 0 0 1
refdes=U2
T 45300 43900 5 10 1 1 0 0 1
model-name=OP777
T 44400 43200 5 10 1 1 0 0 1
file=op777.mod
}
N 41100 43300 41100 43800 4
N 41100 43800 41400 43800 4
C 40900 41500 1 0 0 ground.sym
N 42300 43800 42600 43800 4
N 42600 43000 42600 44200 4
N 43500 44200 44400 44200 4
N 44400 44200 44400 44000 4
N 43500 43400 44400 43400 4
N 44400 43400 44400 43600 4
N 41100 41800 41100 42400 4
C 42400 41500 1 0 0 ground.sym
N 42600 41800 42600 42100 4
N 45900 43800 45900 44600 4
N 44600 44600 44100 44600 4
N 44100 44600 44100 44200 4
N 45500 44600 45900 44600 4
N 45400 43800 45900 43800 4
C 44000 42200 1 90 0 resistor-1.sym
{
T 43600 42500 5 10 0 0 90 0 1
device=RESISTOR
T 43700 42600 5 10 1 1 180 0 1
refdes=R_SW2
T 44000 42400 5 10 1 1 0 0 1
value=100k
T 44000 42200 5 10 1 1 0 0 1
model=R
}
N 43900 43100 43900 43400 4
C 43700 41500 1 0 0 ground.sym
N 43900 41800 43900 42200 4
N 45100 42900 46700 42900 4
{
T 46500 43000 5 10 1 1 0 0 1
netname=sw_out_closed
}
C 44900 41700 1 0 0 ground.sym
C 45700 41700 1 0 0 ground.sym
N 44900 44200 45400 44200 4
{
T 45300 44200 5 10 1 1 0 0 1
netname=Vcc
}
N 44900 43400 45400 43400 4
{
T 45300 43400 5 10 1 1 0 0 1
netname=Vdd
}
C 44600 44500 1 0 0 resistor-1.sym
{
T 44700 44400 5 10 1 1 0 0 1
model=R
T 44800 44800 5 10 1 1 0 0 1
refdes=R7
T 45100 44800 5 10 1 1 0 0 1
value=27k
T 44900 44900 5 10 0 0 0 0 1
device=RESISTOR
}
T 40500 44700 9 10 1 0 0 0 1
Closed state
T 46700 47900 9 14 1 0 0 0 2
Filters emulation
see .odg file
C 49100 46900 1 90 0 voltage-1.sym
{
T 48600 47000 5 10 0 0 90 0 1
device=VOLTAGE_SOURCE
T 48600 47400 5 10 1 1 180 0 1
refdes=V5
T 48100 47000 5 10 1 1 0 0 1
value=ac 1 sin
}
C 49000 47800 1 0 0 resistor-1.sym
{
T 49300 48200 5 10 0 0 0 0 1
device=RESISTOR
T 49200 48100 5 10 1 1 0 0 1
refdes=R9
T 49100 47700 5 10 1 1 0 0 1
model=R
T 49500 48000 5 10 1 1 0 0 1
value=22k
}
C 50100 47800 1 0 0 resistor-1.sym
{
T 50400 48200 5 10 0 0 0 0 1
device=RESISTOR
T 50300 48100 5 10 1 1 0 0 1
refdes=R10
T 50200 47700 5 10 1 1 0 0 1
model=R
T 50500 47600 5 10 1 1 0 0 1
value=330k
}
C 51200 47500 1 0 0 resistor-1.sym
{
T 51500 47900 5 10 0 0 0 0 1
device=RESISTOR
T 51400 47800 5 10 1 1 0 0 1
refdes=R11
T 51200 47400 5 10 1 1 0 0 1
model=R
T 51500 47300 5 10 1 1 0 0 1
value=330k
}
C 54200 47000 1 90 0 resistor-1.sym
{
T 53800 47300 5 10 0 0 90 0 1
device=RESISTOR
T 54800 47900 5 10 1 1 180 0 1
refdes=Rload3
T 54200 47400 5 10 1 1 0 0 1
model=R
T 54200 47100 5 10 1 1 0 0 1
value=100k
}
C 50200 46900 1 90 0 capacitor-1.sym
{
T 49500 47100 5 10 0 0 90 0 1
device=CAPACITOR
T 49900 47600 5 10 1 1 180 0 1
refdes=C3
T 49300 47100 5 10 0 0 90 0 1
symversion=0.1
T 49700 47100 5 10 1 1 0 0 1
model=C
T 50100 47100 5 10 1 1 0 0 1
value=0.01u
}
C 51200 48100 1 0 0 capacitor-1.sym
{
T 51400 48800 5 10 0 0 0 0 1
device=CAPACITOR
T 51400 48600 5 10 1 1 0 0 1
refdes=C4
T 51400 49000 5 10 0 0 0 0 1
symversion=0.1
T 51700 48100 5 10 1 1 0 0 1
value=0.0022u
T 51200 48100 5 10 1 1 0 0 1
model=C
}
C 52500 46700 1 90 0 capacitor-1.sym
{
T 51800 46900 5 10 0 0 90 0 1
device=CAPACITOR
T 52200 47400 5 10 1 1 180 0 1
refdes=C5
T 51600 46900 5 10 0 0 90 0 1
symversion=0.1
T 52000 46900 5 10 1 1 0 0 1
model=C
T 52400 46900 5 10 1 1 0 0 1
value=220p
}
C 52400 48400 1 180 1 opamp-1.sym
{
T 53100 47600 5 10 0 0 180 6 1
device=OPAMP
T 53100 47800 5 10 1 1 180 6 1
refdes=U3
T 53100 47000 5 10 0 0 180 6 1
symversion=0.1
T 53300 47900 5 10 1 1 180 6 1
model-name=OP777
T 52400 48600 5 10 1 1 180 6 1
file=op777.mod
}
T 49900 48200 9 14 1 0 0 0 1
F1
C 48700 46500 1 0 0 ground.sym
C 49800 46500 1 0 0 ground.sym
C 52100 46300 1 0 0 ground.sym
C 53900 46300 1 0 0 ground.sym
N 48900 46800 48900 46900 4
N 48900 47800 48900 47900 4
N 48900 47900 49000 47900 4
N 50000 47800 50000 47900 4
N 49900 47900 50100 47900 4
N 50000 46800 50000 46900 4
N 51000 47600 51000 48300 4
N 51000 48300 51200 48300 4
N 51000 47600 51200 47600 4
N 52100 48300 52400 48300 4
N 52400 48300 52400 48200 4
N 52100 47600 52400 47600 4
N 52400 47800 52400 47600 4
N 53400 48000 54900 48000 4
{
T 54500 48000 5 10 1 1 0 0 1
netname=out_f1
}
N 54100 47900 54100 48000 4
N 54100 46600 54100 47000 4
N 52200 48300 52200 48800 4
N 52200 48800 53600 48800 4
N 53600 48800 53600 48000 4
N 52300 46600 52300 46700 4
N 52900 47600 52900 47400 4
N 52900 47400 53300 47400 4
{
T 53200 47400 5 10 1 1 0 0 1
netname=Vcc
}
N 52900 48400 53300 48400 4
{
T 53200 48200 5 10 1 1 0 0 1
netname=Vdd
}
C 48400 45500 1 0 0 resistor-1.sym
{
T 48700 45900 5 10 0 0 0 0 1
device=RESISTOR
T 48600 45800 5 10 1 1 0 0 1
refdes=R13
T 48500 45400 5 10 1 1 0 0 1
model=R
T 48800 45300 5 10 1 1 0 0 1
value=330k
}
C 49500 45200 1 0 0 resistor-1.sym
{
T 49800 45600 5 10 0 0 0 0 1
device=RESISTOR
T 49700 45500 5 10 1 1 0 0 1
refdes=R14
T 49500 45100 5 10 1 1 0 0 1
model=R
T 49800 45000 5 10 1 1 0 0 1
value=330k
}
C 52500 44700 1 90 0 resistor-1.sym
{
T 52100 45000 5 10 0 0 90 0 1
device=RESISTOR
T 53100 45600 5 10 1 1 180 0 1
refdes=Rload4
T 52500 45100 5 10 1 1 0 0 1
model=R
T 52500 44800 5 10 1 1 0 0 1
value=100k
}
C 48500 44600 1 90 0 capacitor-1.sym
{
T 47800 44800 5 10 0 0 90 0 1
device=CAPACITOR
T 47600 44800 5 10 0 0 90 0 1
symversion=0.1
T 48200 45300 5 10 1 1 180 0 1
refdes=C6
T 48000 44800 5 10 1 1 0 0 1
model=C
T 48400 44800 5 10 1 1 0 0 1
value=0.0022u
}
C 49500 45800 1 0 0 capacitor-1.sym
{
T 49700 46500 5 10 0 0 0 0 1
device=CAPACITOR
T 49700 46700 5 10 0 0 0 0 1
symversion=0.1
T 49700 46300 5 10 1 1 0 0 1
refdes=C7
T 50000 45800 5 10 1 1 0 0 1
value=0.0047u
T 49500 45800 5 10 1 1 0 0 1
model=C
}
C 50800 44400 1 90 0 capacitor-1.sym
{
T 50100 44600 5 10 0 0 90 0 1
device=CAPACITOR
T 49900 44600 5 10 0 0 90 0 1
symversion=0.1
T 50500 45100 5 10 1 1 180 0 1
refdes=C8
T 50300 44600 5 10 1 1 0 0 1
model=C
T 50700 44600 5 10 1 1 0 0 1
value=470p
}
C 50700 46100 1 180 1 opamp-1.sym
{
T 51400 45300 5 10 0 0 180 6 1
device=OPAMP
T 51400 44700 5 10 0 0 180 6 1
symversion=0.1
T 51400 45500 5 10 1 1 180 6 1
refdes=U4
T 51600 45600 5 10 1 1 180 6 1
model-name=OP777
T 50700 46300 5 10 1 1 180 6 1
file=op777.mod
}
C 48100 44200 1 0 0 ground.sym
C 50400 44000 1 0 0 ground.sym
C 52200 44000 1 0 0 ground.sym
N 48300 45500 48300 45600 4
N 48200 45600 48400 45600 4
N 48300 44500 48300 44600 4
N 49300 45300 49300 46000 4
N 49300 46000 49500 46000 4
N 49300 45300 49500 45300 4
N 50400 46000 50700 46000 4
N 50700 46000 50700 45900 4
N 50400 45300 50700 45300 4
N 50700 45500 50700 45300 4
N 51700 45700 53400 45700 4
{
T 53000 45700 5 10 1 1 0 0 1
netname=out_f2
}
N 52400 45700 52400 45600 4
N 52400 44300 52400 44700 4
N 50500 46000 50500 46500 4
N 50500 46500 51900 46500 4
N 51900 46500 51900 45700 4
N 50600 44300 50600 44400 4
N 51200 45300 51200 45100 4
N 51200 45100 51600 45100 4
{
T 51500 45100 5 10 1 1 0 0 1
netname=Vcc
}
N 51200 46100 51600 46100 4
{
T 51500 45900 5 10 1 1 0 0 1
netname=Vdd
}
C 47300 45500 1 0 0 resistor-1.sym
{
T 47400 45800 5 10 1 1 0 0 1
refdes=R12
T 47400 45400 5 10 1 1 0 0 1
model=R
T 47800 45700 5 10 1 1 0 0 1
value=22k
T 47600 45900 5 10 0 0 0 0 1
device=RESISTOR
}
N 47200 45500 47200 45600 4
C 47000 44200 1 0 0 ground.sym
N 47200 44500 47200 44600 4
C 47400 44600 1 90 0 voltage-1.sym
{
T 46900 45100 5 10 1 1 180 0 1
refdes=V6
T 46500 44700 5 10 1 1 0 0 1
value=ac 1 sin
T 46900 44700 5 10 0 0 90 0 1
device=VOLTAGE_SOURCE
}
T 51600 43700 9 14 1 0 0 0 1
F3
C 51800 43200 1 0 0 resistor-1.sym
{
T 52100 43600 5 10 0 0 0 0 1
device=RESISTOR
T 52000 43500 5 10 1 1 0 0 1
refdes=R16
T 51900 43100 5 10 1 1 0 0 1
model=R
T 52200 43000 5 10 1 1 0 0 1
value=330k
}
C 52900 42900 1 0 0 resistor-1.sym
{
T 53200 43300 5 10 0 0 0 0 1
device=RESISTOR
T 53100 43200 5 10 1 1 0 0 1
refdes=R17
T 52900 42800 5 10 1 1 0 0 1
model=R
T 53200 42700 5 10 1 1 0 0 1
value=330k
}
C 55900 42400 1 90 0 resistor-1.sym
{
T 55500 42700 5 10 0 0 90 0 1
device=RESISTOR
T 56500 43300 5 10 1 1 180 0 1
refdes=Rload5
T 55900 42800 5 10 1 1 0 0 1
model=R
T 55900 42500 5 10 1 1 0 0 1
value=100k
}
C 51900 42300 1 90 0 capacitor-1.sym
{
T 51200 42500 5 10 0 0 90 0 1
device=CAPACITOR
T 51000 42500 5 10 0 0 90 0 1
symversion=0.1
T 51600 43000 5 10 1 1 180 0 1
refdes=C9
T 51400 42500 5 10 1 1 0 0 1
model=C
T 51800 42500 5 10 1 1 0 0 1
value=0.0047u
}
C 52900 43500 1 0 0 capacitor-1.sym
{
T 53100 44200 5 10 0 0 0 0 1
device=CAPACITOR
T 53100 44400 5 10 0 0 0 0 1
symversion=0.1
T 53100 44000 5 10 1 1 0 0 1
refdes=C10
T 53400 43500 5 10 1 1 0 0 1
value=0.01u
T 52900 43500 5 10 1 1 0 0 1
model=C
}
C 54200 42100 1 90 0 capacitor-1.sym
{
T 53500 42300 5 10 0 0 90 0 1
device=CAPACITOR
T 53300 42300 5 10 0 0 90 0 1
symversion=0.1
T 53900 42800 5 10 1 1 180 0 1
refdes=C11
T 53700 42300 5 10 1 1 0 0 1
model=C
T 54100 42300 5 10 1 1 0 0 1
value=0.001u
}
C 54100 43800 1 180 1 opamp-1.sym
{
T 54800 43000 5 10 0 0 180 6 1
device=OPAMP
T 54800 42400 5 10 0 0 180 6 1
symversion=0.1
T 54800 43200 5 10 1 1 180 6 1
refdes=U5
T 55000 43300 5 10 1 1 180 6 1
model-name=OP777
T 54100 44000 5 10 1 1 180 6 1
file=op777.mod
}
C 51500 41900 1 0 0 ground.sym
C 53800 41700 1 0 0 ground.sym
C 55600 41700 1 0 0 ground.sym
N 51700 43200 51700 43300 4
N 51600 43300 51800 43300 4
N 51700 42200 51700 42300 4
N 52700 43000 52700 43700 4
N 52700 43700 52900 43700 4
N 52700 43000 52900 43000 4
N 53800 43700 54100 43700 4
N 54100 43700 54100 43600 4
N 53800 43000 54100 43000 4
N 54100 43200 54100 43000 4
N 55100 43400 56500 43400 4
{
T 56100 43400 5 10 1 1 0 0 1
netname=out_f3
}
N 55800 43400 55800 43300 4
N 55800 42000 55800 42400 4
N 53900 43700 53900 44200 4
N 53900 44200 55300 44200 4
N 55300 44200 55300 43400 4
N 54000 42000 54000 42100 4
N 54600 43000 54600 42800 4
N 54600 42800 55000 42800 4
{
T 54900 42800 5 10 1 1 0 0 1
netname=Vcc
}
N 54600 43800 55000 43800 4
{
T 54900 43600 5 10 1 1 0 0 1
netname=Vdd
}
C 50700 43200 1 0 0 resistor-1.sym
{
T 50900 43500 5 10 1 1 0 0 1
refdes=R15
T 50800 43100 5 10 1 1 0 0 1
model=R
T 51200 43400 5 10 1 1 0 0 1
value=22k
T 51000 43600 5 10 0 0 0 0 1
device=RESISTOR
}
N 50600 43200 50600 43300 4
C 50400 41900 1 0 0 ground.sym
N 50600 42200 50600 42300 4
C 50800 42300 1 90 0 voltage-1.sym
{
T 50300 42800 5 10 1 1 180 0 1
refdes=V7
T 49900 42400 5 10 1 1 0 0 1
value=ac 1 sin
T 50300 42400 5 10 0 0 90 0 1
device=VOLTAGE_SOURCE
}
T 51400 44500 9 14 1 0 0 0 1
F2
N 47200 45600 47300 45600 4
N 50600 43300 50700 43300 4
