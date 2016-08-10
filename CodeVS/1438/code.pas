var
  i,j,n:longint;
begin
  readln(n);
  for i:=1 to n do begin
    for j:=i to n-1 do write(' ');
	write('/');
	for j:=1 to 2*(i-1) do write('_');
	writeln('\');
  end;
end.