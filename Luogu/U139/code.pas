var
  n,i,a1,a2,t:longint;
begin
  readln(n);
  a1:=1;
  a2:=1;
  i:=0;
  while n-a2>=0 do begin
    n:=n-a2;
    t:=a1+a2;
	a1:=a2;
	a2:=t;
	inc(i);
  end;
  writeln(i);
end.