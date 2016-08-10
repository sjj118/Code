var
  n,s:real;
  i:longint;
begin
  s:=0;
  for i:=1 to 12 do begin
    readln(n);
    s:=s+n;
  end;
  s:=s/12;
  write('$',s:0:2);
end.