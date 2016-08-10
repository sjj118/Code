type
  big=record
    data:array[1..501]of longint;
	len:longint;
  end;
var
  p:longint;

  function new2():big;
  var
    t:big;
  begin
    with t do begin
	  len:=1;
	  fillchar(data,sizeof(data),0);
	  data[1]:=2;
	end;
	exit(t);
  end;

  function min(a,b:longint):longint;
  begin
    if a>b then exit(b) else exit(a);
  end;

  function cheng(a,b:big):big;
  var
    i,j:longint;
	t:big;
  begin
    with t do begin
	  len:=min(a.len+b.len-1,499);
	  fillchar(data,sizeof(data),0);
	end;
	for i:=1 to a.len do begin
	  for j:=1 to min(b.len,501-i) do begin
	    t.data[i+j-1]:=t.data[i+j-1]+a.data[i]*b.data[j];
		t.data[i+j]:=t.data[i+j]+t.data[i+j-1]div 10;
		t.data[i+j-1]:=t.data[i+j-1]mod 10;
	  end;
	end;
	if t.data[t.len+1]>0 then inc(t.len);
	exit(t);
  end;

  function cheng2(a:big):big;
  var
    i,j:longint;
	t:big;
  begin
    with t do begin
	  len:=min(a.len,499);
	  fillchar(data,sizeof(data),0);
	end;
	for i:=1 to a.len do begin
	  t.data[i]:=t.data[i]+a.data[i]*2;
	  t.data[i+1]:=t.data[i+1]+t.data[i]div 10;
	  t.data[i]:=t.data[i]mod 10;
	end;
	if t.data[t.len+1]>0 then inc(t.len);
	exit(t);
  end;

  function mi2(n:longint):big;
  var
    t,k:big;
  begin
    if n=1 then exit(new2);
    t:=mi2(n div 2);
	if n mod 2=0 then exit(cheng(t,t)) else exit(cheng2(cheng(t,t)));
  end;

  function jian1(a:big):big;
  begin
    a.data[1]:=a.data[1]-1;
	exit(a);
  end;

  procedure output(a:big);
  var
    i,j:longint;
  begin
    for i:=9 downto 0 do begin
	  for j:=50 downto 1 do begin
	    write(a.data[i*50+j]);
	  end;
	  writeln;
	end;
  end;
begin
  readln(p);
  writeln(trunc(p*ln(2)/ln(10))+1);
  output(jian1(mi2(p)));
end.
