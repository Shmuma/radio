<Qucs Schematic 0.0.15>
<Properties>
  <View=0,0,909,636,1,0,0>
  <Grid=10,10,1>
  <DataSet=rc-int.dat>
  <DataDisplay=rc-int.dpl>
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
  <GND * 1 230 260 0 0 0 0>
  <Vrect V1 1 60 210 18 -26 0 1 "1 V" 1 "1 ms" 1 "1 ms" 1 "1 ns" 0 "1 ns" 0 "1 ms" 0>
  <C C1 1 230 210 17 -26 0 1 "1 uF" 1 "" 0 "neutral" 0>
  <R R1 1 180 150 -26 15 0 0 "100" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <.TR TR1 1 50 340 0 57 0 0 "lin" 1 "0" 1 "3 ms" 1 "1001" 0 "Trapezoidal" 0 "2" 0 "1 ns" 0 "1e-16" 0 "150" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "26.85" 0 "1e-3" 0 "1e-6" 0 "1" 0 "CroutLU" 0 "no" 0 "yes" 0 "0" 0>
</Components>
<Wires>
  <230 240 230 260 "" 0 0 0 "">
  <60 260 230 260 "" 0 0 0 "">
  <60 240 60 260 "" 0 0 0 "">
  <230 150 230 180 "" 0 0 0 "">
  <210 150 230 150 "" 0 0 0 "">
  <60 150 60 180 "" 0 0 0 "">
  <60 150 150 150 "" 0 0 0 "">
  <230 150 230 150 "Uout" 260 120 0 "">
  <60 150 60 150 "Uin" 90 120 0 "">
</Wires>
<Diagrams>
  <Rect 366 423 503 308 3 #c0c0c0 1 00 1 0 0.0002 0.003 1 -1.2 0.2 1.2 1 -1 0.2 1 315 0 225 "" "" "">
	<"Uout.Vt" #0000ff 2 3 0 0 0>
	<"Uin.Vt" #ff0000 2 3 0 0 0>
  </Rect>
</Diagrams>
<Paintings>
</Paintings>
