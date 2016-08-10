var
  i:longint;
  c,k:real;
begin
  while true do begin
    readln(c);
	if c=0 then break;
	k:=0;
	i:=1;
	while k<c do begin
	  inc(i);
	  k:=k+1/i;
	end;
	writeln(i-1,' card(s)');
  end;
end.