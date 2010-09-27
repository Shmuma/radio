<Qucs Schematic 0.0.14>
<Properties>
  <View=-331,13,800,454,1,171,60>
  <Grid=10,10,1>
  <DataSet=transistor.dat>
  <DataDisplay=transistor.dpl>
  <OpenDisplay=1>
  <showFrame=0>
  <FrameText0=Title>
  <FrameText1=Drawn By:>
  <FrameText2=Date:>
  <FrameText3=Revision:>
</Properties>
<Symbol>
</Symbol>
<Components>
  <R R2 1 460 150 15 -26 0 1 "50 Ohm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <GND * 1 310 250 0 0 0 0>
  <.DC DC1 1 -50 280 0 37 0 0 "26.85" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "no" 0 "150" 0 "no" 0 "none" 0 "CroutLU" 0>
  <Vdc V1 1 170 220 18 -26 0 1 "1 V" 1>
  <_BJT BC547BP_1 1 310 110 8 -26 1 0 "npn" 0 "1.8e-14" 0 "0.9955" 0 "1.005" 0 "0.14" 0 "0.03" 0 "80" 0 "12.5" 0 "5e-14" 0 "1.46" 0 "1.72e-13" 0 "1.27" 0 "400" 0 "35.5" 0 "0" 0 "0" 0 "0.25" 0 "0.6" 0 "0.56" 0 "1.3e-11" 0 "0.75" 0 "0.33" 0 "4e-12" 0 "0.54" 0 "0.33" 0 "1" 0 "0" 0 "0.75" 0 "0" 0 "0.5" 0 "6.4e-10" 0 "0" 0 "0" 0 "0" 0 "5.072e-08" 0 "26.85" 0 "0" 0 "1" 0 "1" 0 "0" 0 "1" 0 "1" 0 "0" 0 "0" 0 "3" 0 "1.11" 0 "26.85" 0 "1" 0>
  <.SW SW1 1 -60 70 0 59 0 0 "DC1" 1 "lin" 1 "R1" 1 "1" 1 "1 kOhm" 1 "201" 1>
  <R R1 1 220 110 -26 15 0 0 "Rbase" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <Eqn Eqn1 1 190 290 -35 17 0 0 "Rbase=1000000/R1" 1 "yes" 0>
</Components>
<Wires>
  <460 80 460 120 "" 0 0 0 "">
  <310 250 460 250 "" 0 0 0 "">
  <460 180 460 250 "" 0 0 0 "">
  <170 250 310 250 "" 0 0 0 "">
  <170 180 170 190 "" 0 0 0 "">
  <310 140 310 180 "" 0 0 0 "">
  <170 180 310 180 "" 0 0 0 "">
  <310 80 460 80 "Emitter" 470 50 127 "">
  <250 110 280 110 "Base" 260 60 11 "">
  <170 110 170 180 "" 0 0 0 "">
  <170 110 190 110 "" 0 0 0 "">
</Wires>
<Diagrams>
</Diagrams>
<Paintings>
</Paintings>
