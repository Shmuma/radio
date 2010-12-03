<Qucs Schematic 0.0.15>
<Properties>
  <View=0,0,1353,800,1,0,0>
  <Grid=10,10,1>
  <DataSet=rc.dat>
  <DataDisplay=rc.dpl>
  <OpenDisplay=1>
  <showFrame=0>
  <FrameText0=\x041D\x0430\x0437\x0432\x0430\x043D\x0438\x0435>
  <FrameText1=\x0427\x0435\x0440\x0442\x0438\x043B:>
  <FrameText2=\x0414\x0430\x0442\x0430:>
  <FrameText3=\x0412\x0435\x0440\x0441\x0438\x044F:>
</Properties>
<Symbol>
</Symbol>
<Components>
  <GND * 1 220 230 0 0 0 0>
  <Vrect V1 1 50 180 18 -26 0 1 "1 V" 1 "1 ms" 1 "1 ms" 1 "1 ns" 0 "1 ns" 0 "1 ms" 0>
  <C C1 1 150 120 -26 17 0 0 "1 uF" 1 "" 0 "neutral" 0>
  <R R1 1 220 180 15 -26 0 1 "100" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <.TR TR1 1 40 310 0 57 0 0 "lin" 1 "0" 1 "3 ms" 1 "10001" 0 "Trapezoidal" 0 "2" 0 "1 ns" 0 "1e-16" 0 "150" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "26.85" 0 "1e-3" 0 "1e-6" 0 "1" 0 "CroutLU" 0 "no" 0 "yes" 0 "0" 0>
</Components>
<Wires>
  <180 120 220 120 "" 0 0 0 "">
  <220 120 220 150 "" 0 0 0 "">
  <220 210 220 230 "" 0 0 0 "">
  <50 120 120 120 "" 0 0 0 "">
  <50 120 50 150 "" 0 0 0 "">
  <50 230 220 230 "" 0 0 0 "">
  <50 210 50 230 "" 0 0 0 "">
  <220 120 220 120 "Uout" 250 90 0 "">
  <50 120 50 120 "Uin" 80 90 0 "">
</Wires>
<Diagrams>
  <Rect 356 393 503 308 3 #c0c0c0 1 00 1 0 0.0002 0.003 1 -1.2 0.2 1.2 1 -1 0.2 1 315 0 225 "" "" "">
	<"Uout.Vt" #0000ff 2 3 0 0 0>
	<"Uin.Vt" #ff0000 2 3 0 0 0>
  </Rect>
</Diagrams>
<Paintings>
</Paintings>
