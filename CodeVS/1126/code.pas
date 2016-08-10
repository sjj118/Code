var
  l,r,i,j,sum:longint;
  s:string;
begin
  readln(l,r);
  sum:=0;
  for i:=l to r do begin
    str(i,s);
	for j:=1 to length(s) do if s[j]='2' then inc(sum);
  end;
  writeln(sum);
end.