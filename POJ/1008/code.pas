var
  n,i,y,d,yd,j,l,t:longint;
  s,s2,m:string;
begin
  readln(n);
  writeln(n);
  for i:=1 to n do begin
    readln(s);
	j:=1;
	while s[j]<>'.' do inc(j);
	s2:=copy(s,1,j-1);
	val(s2,d);
	j:=j+2;
	l:=j;
	while s[l]<>' ' do inc(l);
	m:=copy(s,j,l-j);
	l:=l+1;
	s2:=copy(s,l,length(s)-l+1);
	val(s2,y);
	if m='pop' then yd:=0 else
	 if m='no' then yd:=1 else
	 if m='zip' then yd:=2 else
	 if m='zotz' then yd:=3 else
	 if m='tzec' then yd:=4 else
	 if m='xul' then yd:=5 else
	 if m='yoxkin' then yd:=6 else
	 if m='mol' then yd:=7 else
	 if m='chen' then yd:=8 else
	 if m='yax' then yd:=9 else
	 if m='zac' then yd:=10 else
	 if m='ceh' then yd:=11 else
	 if m='mac' then yd:=12 else
	 if m='kankin' then yd:=13 else
	 if m='muan' then yd:=14 else
	 if m='pax' then yd:=15 else
	 if m='koyab' then yd:=16 else
	 if m='cumhu' then yd:=17 else
	 if m='uayet' then yd:=18;
	t:=y*365+yd*20+d;
	y:=t div 260;
	yd:=t mod 20;
	case yd of
	  0:m:='imix';
	  1:m:='ik';
	  2:m:='akbal';
	  3:m:='kan';
	  4:m:='chicchan';
	  5:m:='cimi';
	  6:m:='manik';
	  7:m:='lamat';
	  8:m:='muluk';
	  9:m:='ok';
	  10:m:='chuen';
	  11:m:='eb';
	  12:m:='ben';
	  13:m:='ix';
	  14:m:='mem';
	  15:m:='cib';
	  16:m:='caban';
	  17:m:='eznab';
	  18:m:='canac';
	  19:m:='ahau';
	end;
	d:=t mod 13+1;
	writeln(d,' ',m,' ',y);
  end;
end.
